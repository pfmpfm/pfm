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

#include <isa.h>
#include "local-include/reg.h"
#include "local-include/reg.h"
#define word_t uint32_t

const char *regs[] = {
  "$0", "$ra", "$sp", "$gp", "$tp", "$t0", "$t1", "$t2",
  "$s0", "$s1", "$a0", "$a1", "$a2", "$a3", "$a4", "$a5",
  "$a6", "$a7", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
  "$s8", "$s9", "$s10", "$s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
    for(int index = 0; index < sizeof(regs)/sizeof(regs[0]); index++) {
      if((index == 1) || (index == 2) || (index == 3) || (index == 8) || (index == 9))
        printf("Register %-4s =  0x%x\n", regs[index], cpu.gpr[index]);
      else 
        printf("Register %-4s =  %u\n", regs[index], cpu.gpr[index]);
    }
    printf("Register %-4s =  0x%x\n", "pc", cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  bool haveFind = false;
  word_t regVal;

  for (int i = 0; i < (sizeof(regs) / sizeof(char *)); i++){
    if (strcmp(s, regs[i]) == 0){
      haveFind = true;
      regVal = cpu.gpr[i];
      break;
    }
  }
  if (strcmp(s, "$pc") == 0){
      haveFind = true;
      regVal = cpu.pc;
      printf("Reg:$pc = 0x%X\n", regVal);
  }
  if (haveFind){
    *success = true;
    return regVal;
  }
  *success = false;
  return 0;
}
