/* MEMCMP()
#include "trap.h"
#include <string.h>
#define N 32
#define COLOR_RED   "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_NONE  "\033[0m"
char data[N];
char src[N];

void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    data[i] = i + 1;
    src[i] = 'A' + (i % 26); // 初始化src为A-Z循环
  }
}

void main(){
  int l, r;
  bool success=true;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      memcpy(data + l, src, r - l);
      if (memcmp(data + l, src, r - l) != 0) {
        success = false;
        printf(COLOR_RED "FALSE!!!\n" COLOR_NONE);
        break;
      }
    }
  }
  if(success){
    printf(COLOR_GREEN "TRUE!!!\n" COLOR_NONE);
  }
}
*/
/* STRLEN()
#include "trap.h"
#include <string.h>
#define N 32
#define COLOR_RED   "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_NONE  "\033[0m"
char data[N];

void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    data[i] = '\0';
  }
}

void main(){
  int l, r;
  bool success=true;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      memset(data, 'A', r - l);
      data[r - l] = '\0'; // 确保字符串以null结尾
      if (strlen(data) != (r - l)) {
        success = false;
        printf(COLOR_RED "FALSE!!!\n" COLOR_NONE);
        break;
      }
    }
  }
  if(success){
    printf(COLOR_GREEN "TRUE!!!\n" COLOR_NONE);
  }
}
*/
