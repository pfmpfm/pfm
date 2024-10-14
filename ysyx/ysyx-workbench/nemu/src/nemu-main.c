/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
 
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
#define word_t uint32_t
uint32_t expr(char *e, bool *success);
 
int main(int argc, char *argv[])
{
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
/*
// 测试表达式生成器
FILE *file;  // 文件指针
char line[65536 + 128];  // 存储每一行的数组
char exprbuf[65536];  // 存储表达式的数组
uint32_t result;  // 存储结果的变量

// 打开文件
file = fopen("/home/pfm/ysyx/ysyx-workbench/nemu/tools/gen-expr/input", "r");
assert(file != NULL);  // 确保文件打开成功

// 逐行读取文件
while (fgets(line, 65536 + 128, file) != NULL)
{
  int i = 0;
  int j = 0;

  // 从行中读取结果
  int cnt = sscanf(line, "%u", &result);
  assert(cnt == 1);  // 确保结果读取成功

  // 跳过结果和空格
  while (line[i] != ' ')
  {
    i++;
  }

  // 读取表达式
  while (line[i] != '\n' && i < 65536)
  {
    exprbuf[j] = line[i];
    j++;
    i++;
  }
  exprbuf[j] = '\0';  // 添加字符串结束符

  bool success = true;

  // 计算表达式的值
  word_t ans = expr(exprbuf, &success);

  // 如果计算失败或者结果不正确，打印错误信息并返回
  if (success == false && result - ans != 0)
  {
    printf("- origin line: %s- success: %d\n- exprbuf: %s\n- result:%u\n- ans: %u\n",
           line, success, exprbuf, result, ans);
    return 0;
  }
}
  // 所有行都处理完毕，返回
  return 0;
  */
  /* Start engine. */
  engine_start();
 
  return is_exit_status_bad();
}