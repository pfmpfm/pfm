#include "trap.h"
#define N 32
#define COLOR_RED   "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_NONE  "\033[0m"

void main(){
  char buf[100];
  int a=10,b=20,c;
  c=a+b;
  sprintf(buf,"sum of %d and %d is %d",a,b,c);
  printf(COLOR_GREEN "%s\n" COLOR_NONE, buf);

}
