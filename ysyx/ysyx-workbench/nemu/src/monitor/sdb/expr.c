#include "/home/pfm/ysyx/ysyx-workbench/nemu/src/isa/riscv32/local-include/reg.h"
#include <regex.h>
#include <memory/paddr.h>
#define word_t uint32_t

// 定义各种令牌类型
enum {
    TK_NOTYPE = 256,    // 未定义类型
    TK_EQ,              // 等于
    TK_NUMBER,          // 十进制整数
    TK_NEGATIVE,        // 负号
    TK_HEX,             // 十六进制数
    TK_REG,             // 寄存器名称
    TK_UNEQ,            // 不等于
    TK_AND,             // 逻辑与
    TK_POINTER          // 指针操作符
    /* TODO: 添加更多的令牌类型 */
};

// 定义规则结构体
static struct rule {
    const char *regex;  // 正则表达式
    int token_type;     // 令牌类型
} rules[] = {
    {" +", TK_NOTYPE},    // 空格（不产生令牌）
    {"\\+", '+'},         // 加法操作符
    {"==", TK_EQ},        // 等于操作符
    {"\\-", '-'},         // 减法操作符
    {"\\(", '('},         // 左括号
    {"\\)", ')'},         // 右括号
    {"\\*", '*'},         // 乘法操作符
    {"/", '/'},           // 除法操作符
    {"0x[0-9a-fA-F]+", TK_HEX},   // 十六进制数
    {"(0|[1-9][0-9]*)", TK_NUMBER}, // 十进制整数
    {"\\$[0-9a-zA-Z]+", TK_REG}, // 寄存器名称
    {"!=", TK_UNEQ},    // 不等于操作符
    {"&&", TK_AND},     // 逻辑与操作符
};

#define NR_REGEX ARRLEN(rules)  // 规则数量

static regex_t re[NR_REGEX] = {}; // 正则表达式数组

// 初始化正则表达式规则
void init_regex() {
    int i;
    char error_msg[128];  // 存储正则表达式编译错误信息
    int ret;

    for (i = 0; i < NR_REGEX; i++) {
        ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);  // 编译正则表达式
        if (ret != 0) {
            regerror(ret, &re[i], error_msg, 128);  // 获取编译错误信息
            panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);  // 编译失败时打印错误信息
        }
    }
}


typedef struct token {
    int type;           
    char str[32];       
} Token;

static Token tokens[65536] __attribute__((used)) = {}; 
static int nr_token __attribute__((used)) = 0;         

static bool make_token(char *e) {
    int position = 0;      // 当前处理的位置
    int i;                
    regmatch_t pmatch;    // 正则表达式匹配结果

    nr_token = 0;         

    while (e[position] != '\0') {  // 遍历表达式字符串
        // 尝试所有规则
        for (i = 0; i < NR_REGEX; i++) {
            if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
                char *substr_start = e + position;  // 匹配的子串起始位置
                int substr_len = pmatch.rm_eo;       // 匹配的子串长度

                Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
                    i, rules[i].regex, position, substr_len, substr_len, substr_start);

                position += substr_len;  

                switch (rules[i].token_type) {
                    case TK_NOTYPE:
                        break;
                    default:
                        strncpy(tokens[nr_token].str, substr_start, substr_len);  
                        tokens[nr_token].type = rules[i].token_type;  
                        tokens[nr_token].str[substr_len] = '\0';  
                        nr_token++;  
                        break;
                }

                break; 
            }
        }

        if (i == NR_REGEX) {  // 没有匹配任何规则
            printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
            return false;  
        }
    }

    return true;  
}

word_t eval(int p, int q, bool *success); //提前声明，后面要用

// 标记负号和指针操作符
void mark() {
    int i;
    // 标记负号,有两种情况：1.为第一个字符 2.前一位既不是数字也不是右括号
    for (i = 0; i < nr_token; i++) {
        if (tokens[i].type == (int)('-') && (i == 0 ||
            (tokens[i - 1].type != TK_NUMBER && tokens[i - 1].type != (int)(')')))) {
            tokens[i].str[0] = '-';
            tokens[i].str[1] = '\0';
            tokens[i].type = TK_NEGATIVE;  
        }
    }
    // 标记指针操作符，
    for (i = 0; i < nr_token; i++) {
        if (tokens[i].type == (int)('*') && (i == 0 ||
            (tokens[i - 1].type != TK_NUMBER && tokens[i - 1].type != (int)(')')))) {
            tokens[i].str[0] = '*';
            tokens[i].str[1] = '\0';
            tokens[i].type = TK_POINTER;  // 将指针操作符标记为TK_POINTER
        }
    }
}

// 打印表达式
void printfExpr(int p, int q, char *express) {
    if (express != NULL) printf("%s ", express);  // 打印表达式
    printf("expr:");
    for (int i = p; i <= q; i++) {
        if (tokens[i].type == TK_NUMBER || tokens[i].type == TK_AND ||
            tokens[i].type == TK_POINTER || tokens[i].type == TK_HEX ||
            tokens[i].type == TK_REG || tokens[i].type == TK_NEGATIVE ||
            tokens[i].type == TK_UNEQ || tokens[i].type == TK_EQ) {
            printf("%s", tokens[i].str);  
        } else {
            printf("%c", (char)tokens[i].type);  // 打印操作符
        }
    }
    printf("\n");
}

// 检查表达式的括号是否匹配,用栈结构存储括号
bool check_expr_parentheses(int p, int q) {
    int i;
    int stack_top = -1;  // 栈顶索引
    bool flag = true;    // 是否匹配标志

    for (i = p; i <= q; i++) {
        if (tokens[i].type == (int)('(')) {  // 遇到左括号
            stack_top++;
        } else if (tokens[i].type == (int)(')')) {  // 遇到右括号
            if (stack_top >= 0) {
                stack_top--;
            } else {  //异常情况
                flag = false;
                break;
            }
        }
    }
    return stack_top < 0 && flag;  // 确保所有的括号都匹配
}

// 检查表达式是否被一对匹配的括号包围
bool check_parentheses(int p, int q) {
    if (tokens[p].type == (int)('(') && tokens[q].type == (int)(')')) {
        return check_expr_parentheses(p + 1, q - 1);  // 检查括号内的内容
    }
    return false;  // 不是匹配的括号对
}

// 获取操作符的优先级
int priority(int op_type) {
    switch (op_type) {
        case '(':case ')': // 括号优先级最低
            return 0; 
        case '+':case '-':// 加法和减法优先级较低
            return 1;  
        case '*':case '/':// 乘法和除法优先级较高
            return 2;  
        case TK_EQ:case TK_UNEQ:// 等于和不等于优先级较高
            return 3;  
        case TK_AND:// 逻辑与优先级最高
            return 4;  
        case TK_NEGATIVE:case TK_POINTER:// 负号和指针操作符优先级最高
            return 5;  
        default:
            Assert(0, "无对应的操作符");  // 未知操作符
    }
}

// 定义栈节点结构体
struct stack_node {
    int idx;  // 栈节点索引
    int type; // 栈节点类型
};

// 评估表达式
word_t eval(int p, int q, bool *success) {
    word_t number = 0;

    if (p > q) {  // 处理错误情况
        *success = false;
        return 0;
    } 
    else if (p == q) {  
        if (tokens[p].type == TK_HEX) {  // 十六进制数
            if (sscanf(tokens[p].str, "%x", &number) < 1) {
                *success = false;
                return 0;
            }
        } else if (tokens[p].type == TK_REG) {  // 寄存器
            number = isa_reg_str2val(tokens[p].str , success);
            if (!*success) return 0;
        } else if (tokens[p].type == TK_NUMBER) {  // 十进制整数
            if (sscanf(tokens[p].str, "%u", &number) < 1) {
                *success = false;
                return 0;
            }
        }
        return number;
    } 
    else if (check_parentheses(p, q)) {  // 如果表达式被括号包围
        return eval(p + 1, q - 1, success);
    } 
    else {
        if (!check_expr_parentheses(p, q)) {  // 检查括号是否匹配
            *success = false;
            return 0;
        }

        int i;
        int top = -1;  // 栈顶索引
        int op_type;   // 操作符类型
        word_t val1;   // 操作数1
        word_t val2;   // 操作数2
        struct stack_node stack[1024];  // 操作符栈

        // 查找主运算符
        for (i = p; i <= q; i++) {
            Assert(top < 1024, "栈溢出!");  // 检查栈是否溢出

            if (tokens[i].type == TK_NUMBER || tokens[i].type == TK_HEX || tokens[i].type == TK_REG) continue;

            if (top < 0) {
                top++;
                stack[top].idx = i;
                stack[top].type = tokens[i].type;
                continue;
            }

            if (tokens[i].type == (int)('(')) {  // 遇到左括号
                top++;
                stack[top].idx = i;
                stack[top].type = tokens[i].type;
                continue;
            }

            if (tokens[i].type == (int)(')')) {  // 遇到右括号
                while (top >= 0 && stack[top].type != '(') {
                    top--;
                }
                top--;
                continue;
            }

            bool haveSub = false;
            while (top >= 0 && priority(tokens[i].type) <= priority(stack[top].type)) {
                haveSub = false;
                if (tokens[i].type == stack[top].type && 
                      (stack[top].type == TK_NEGATIVE || 
                       stack[top].type == TK_POINTER)) {
                    break;
                }
                top--;
                haveSub = true;
            }

            if (haveSub) {
                ++top;
                stack[top].idx = i;
                stack[top].type = tokens[i].type;
            }
        }

        Assert(top < 1024, "栈溢出!");  // 检查栈是否溢出

        if (top < 0) {  // 如果没有找到操作符
            *success = false;
            return 0;
        }

        if (stack[0].type == TK_NEGATIVE || stack[0].type == TK_POINTER) {
            val1 = -1;  // 负号操作数
            val2 = eval(stack[0].idx + 1, q, success);  // 评估操作数2
        } else {
            val1 = eval(p, stack[0].idx - 1, success);  // 评估操作数1
            val2 = eval(stack[0].idx + 1, q, success);  // 评估操作数2
        }
        op_type = stack[0].type;  // 当前操作符

        if (!*success) {
            return 0; 
        }

        switch (op_type) {
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
            case '/':
                if (val2 == 0) {  // 除数为0的情况
                    *success = false;
                    return 0;
                }
                return val1 / val2;
            case TK_NEGATIVE:
                return val1 * val2;  // 负号操作
            case TK_POINTER:
                return paddr_read(val2, 4);  // 指针操作符
            case TK_EQ:
                return val1 == val2;  // 等于操作
            case TK_UNEQ:
                return val1 != val2;  // 不等于操作
            case TK_AND:
                return val1 && val2;  // 逻辑与操作
            default:
                Assert(0, "没有找到对应的操作符");  // 未知操作符
        }
    }
}

// 计算表达式
word_t expr(char *e, bool *success) {
    bool evalSuccess;
    word_t exprAns;

    if (!make_token(e)) {  
        *success = false;
        return 0;
    }

    mark();  // 标记负号和指针操作符
    evalSuccess = true;
    exprAns = eval(0, nr_token - 1, &evalSuccess);  // 评估表达式
    *success = evalSuccess;  // 返回计算是否成功
    return evalSuccess ? exprAns : 0;
}