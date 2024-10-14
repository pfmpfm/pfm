#include "verilated.h"
#include "Vtop.h"
#include "Vtop___024root.h" 
#include "verilated_vcd_c.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h> 
#include "../memory.h"

#define word_t uint32_t

extern "C" void ebreak(){
    printf("\33[1;31mHIT GOOD TRAP\n");
    _exit(0);
}

extern "C" void itrace(int inst){
    printf("inst : %u\n",inst);
}

void single_cycle(Vtop* top,VerilatedContext* contextp,VerilatedVcdC* tfp) {
    top->clk=1;
    for(int i=0;i<2;i++){
    top->clk = !top->clk;
    top->eval();
    tfp->dump(contextp->time());
    contextp->timeInc(1);
    }
}

static void reset(int n,Vtop* top,VerilatedContext* contextp,VerilatedVcdC* tfp) {
    top->rst = 1;
    while (n-- > 0) single_cycle(top,contextp,tfp);
    top->rst = 0;
}

void printRegfile(Vtop* top){
    for(int i=0;i<32;i++) printf("Reg%2d value : %d\n",i,top->rootp->top__DOT__rf[i]);
}

void scanMemory(word_t* memory,int count,word_t addr){
    uint32_t memoryValue;
    for(int i=0;i<count;i++){
    addr = addr+i*4;
    memoryValue=pmem_read(memory, addr);
    printf("addr [0x%x] : %x\n",addr,memoryValue);
    }
}



int main() {
    word_t* memory;
    memory = init_mem(4);

    VerilatedContext* contextp = new VerilatedContext;
    Verilated::mkdir("logs");
    VerilatedVcdC* tfp = new VerilatedVcdC();
    
    Vtop* top = new Vtop(contextp);
    Verilated::traceEverOn(true); 
    top->trace(tfp, 0);
    tfp->open("./logs/wave.vcd");

    word_t pc = 0x80000000;
    //printRegfile(top);//打印寄存器
    //scanMemory(memory,10,0x80000000);//打印内存 nemu当中x 10 0x80000000
    for (int i = 0; i <= 4; i++) {
        top->inst = pmem_read(memory, pc);
        pc += 4;
        //printf("%u\n",top->inst);
        single_cycle(top,contextp,tfp);
    }
    top->final();
    tfp->close();
    
    delete top;
    delete contextp;
    delete tfp;
    
    return 0;
}


