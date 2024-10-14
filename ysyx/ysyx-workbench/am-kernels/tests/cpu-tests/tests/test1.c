/* MEMSET()
#include "trap.h"
#define N 32
#define COLOR_RED   "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_NONE  "\033[0m"
uint8_t data[N];

void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    data[i] = i + 1;
  }
}
// 检查[l,r)区间中的值是否依次为val, val + 1, val + 2...
bool check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    if(data[i] != val + i - l) return false;
  }
  return true;
}

// 检查[l,r)区间中的值是否均为val
bool check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    if(data[i] != val) return false;
  }
  return true;
}

void main(){
  int l, r;
  bool success=true;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
      memset(data + l, val, r - l);
      success=check_seq(0, l, 1);
      success=check_eq(l, r, val);
      success=check_seq(r, N, r + 1);
      if(success==false){
      printf(COLOR_RED "FALSE!!!\n" COLOR_NONE);
      break;
      }
    }
  }
  printf(COLOR_GREEN "TRUE!!!\n" COLOR_NONE);
}
*/
/* STRCPY()
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
    src[i] = 'A'; // 初始化src为‘A’
  }
}

// 检查[l,r)区间中的值是否依次为val, val + 1, val + 2...
bool check_seq(int l, int r, char val) {
  int i;
  for (i = l; i < r; i ++) {
    if(data[i] != val + i - l) return false;
  }
  return true;
}

// 检查[l,r)区间中的值是否均为val
bool check_eq(int l, int r, char val) {
  int i;
  for (i = l; i < r; i ++) {
    if(data[i] != val) return false;
  }
  return true;
}

void main(){
  int l, r;
  bool success=true;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      strncpy(data + l, src, r - l);
      success=check_seq(0, l, 1);
      success=check_eq(l, r, 'A');
      success=check_seq(r, N, r + 1);
      if(success==false){
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
