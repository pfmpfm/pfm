#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// 缓冲区大小
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // 比 `buf` 大一点的缓冲区

// 生成的代码格式
static char *code_format = 
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

// 缓冲区索引
static int buf_index = 0;

/* 生成小于 n 的随机数 */
static uint32_t choose(uint32_t n) {
    return (uint32_t)((double)rand() / ((double)RAND_MAX + 1) * n);
}

/* 在缓冲区中添加字符 */
static void gen(char c) {
    buf[buf_index++] = c;
    buf[buf_index] = '\0';
}

/* 生成随机数字符串 */
static void gen_num() {
    /*
     * 无符号整数的最大值为 4294967295
     * 为简化处理，gen_num 函数生成 0 到 9 位的数字
     */
    uint32_t len = choose(10);
    if (len == 0) len += 1;

    if (len == 1) {
        gen((char)(choose(10) + '0'));
        return;
    }

    uint32_t firstNum = choose(10);
    /* 数字不能以 0 开头 */
    if (firstNum == 0) firstNum += 1;
    gen((char)(firstNum + '0'));

    for (uint32_t i = 2; i <= len; i++) {
        gen((char)(choose(10) + '0'));
    }
}

/* 随机生成 0 到 10 个空格 */
static void gen_space() {
    uint32_t len = choose(11);
    for (uint32_t i = 1; i <= len; i++) {
        gen(' ');
    }
}

/* 生成随机操作符 */
static void gen_rand_op() {
    switch (choose(4)) {
        case 0: gen('+'); break;
        case 1: gen('-'); break;
        case 2: gen('*'); break;
        default: gen('/'); break;
    }
}

/* 生成随机表达式 */
static void gen_rand_expr(uint32_t n) {
    uint32_t chooseAns = choose(3);
    /*
     * 最多递归十层
     * 超过十层时，gen_rand_expr 不再递归
     */
    if (n >= 10) {
        chooseAns = 0;
    }

    switch (chooseAns) {
        case 0: 
            gen_space(); 
            gen_num();  
            gen_space(); 
            break;
        case 1: 
            gen('('); 
            gen_space(); 
            gen_rand_expr(n + 1); 
            gen_space(); 
            gen(')'); 
            break;
        default: 
            gen_rand_expr(n + 1); 
            gen_space(); 
            gen_rand_op(); 
            gen_space(); 
            gen_rand_expr(n + 1); 
            break; 
    }
}

int main(int argc, char *argv[]) {
    // 设置随机种子
    int seed = time(0);
    srand(seed);

    int loop = 1;
    if (argc > 1) {
        sscanf(argv[1], "%d", &loop);
    }

    for (int i = 0; i < loop; i++) {
        /* 重置 buf_index，这非常重要，否则会出现错误 */
        buf_index = 0;
        gen_rand_expr(1);

        sprintf(code_buf, code_format, buf);

        // 写入生成的 C 代码到临时文件
        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        // 编译生成的 C 代码
        int ret = system("gcc -o /tmp/.expr -Wall -Werror /tmp/.code.c");
        if (ret != 0) continue;
        
        // 执行编译生成的可执行文件
        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        int status;
        ret = fscanf(fp, "%d", &result);
        status = pclose(fp);

        /* 检查是否因除以零而退出。在Linux系统中，如果一个进程试图进行除零操作，
        那么它会收到一个名为SIGFPE的信号，这个信号的编号是8。然后，子进程会因为
        这个未捕获的信号而终止，WEXITSTATUS(status)会返回这个信号编号的乘以16的结果，也就是128+8=136。*/
        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) == 136) {
                continue;
            }
        }
        printf("%u %s\n", result, buf);
    }
    return 0;
}
