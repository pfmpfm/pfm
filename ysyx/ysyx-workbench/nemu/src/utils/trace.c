#include <common.h>
#include <elf.h>
#include <device/map.h>
#include "trace.h"
#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#define INST_NUM 16
typedef uint32_t word_t;
//ITRACE-START
typedef struct
{
    word_t pc;
    uint32_t inst;
}InstBuf;
InstBuf iringbuf[INST_NUM];

extern Symbol *symbol;

int cur_inst = 0;
int func_num = 0;

void trace_inst(word_t pc, uint32_t inst)
{
    iringbuf[cur_inst].pc = pc;
    iringbuf[cur_inst].inst = inst;
    cur_inst = (cur_inst + 1) % INST_NUM; 
}

void display_inst()
{
    /*** 注意出错的是前一条指令，当前指令可能由于出错已经无法正常译码 ***/
    int end = cur_inst;
    char buf[128];
    char *p;
    int i = cur_inst;

    if(iringbuf[i+1].pc == 0) i = 0;

    do
    {
        p = buf;
        //if(i == end) p += sprintf(buf, "-->");
        p += sprintf(buf, "%s" FMT_WORD ":  %08x\t", (i + 1) % INST_NUM == end ? "-->" : "   ", iringbuf[i].pc, iringbuf[i].inst);
	
	/*跑benchmarks需要注释掉*/
     //   void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
     //   disassemble(p, buf + sizeof(buf) - p, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, 4);

        puts(buf);
        i = (i + 1) % INST_NUM;
    } while (i != end);
     
}
//ITRACE-END
//MTRACE-START
void display_memory_read(paddr_t addr, int len)
{
    printf(ANSI_FMT("read memory: ", ANSI_FG_BLUE) FMT_PADDR ", the len is %d\n", addr, len);
}

void display_memory_write(paddr_t addr, int len, word_t data)
{
    printf(ANSI_FMT("write memory: ", ANSI_FG_YELLOW) FMT_PADDR ", the len is %d, the written data is " FMT_WORD "\n", addr, len, data);
}
//MTRACE-END
//FTRACE-START
int rec_depth = 1;
void display_call_func(word_t pc, word_t func_addr)
{
    /*for(int i = 0; i < func_num; i++)
    {
        printf("%s\t0x%08x\t%lu\n", symbol[i].name, symbol[i].addr, symbol[i].size);
    }
    exit(0);*/
    int i = 0;
    for(; i < func_num; i++)
    {
        if(func_addr >= symbol[i].addr && func_addr < (symbol[i].addr + symbol[i].size))
        {
            break;
        }
    }
    printf("0x%08x:", pc);

    for(int k = 0; k < rec_depth; k++) printf("  ");

    rec_depth++;

    printf("call  [%s@0x%08x]\n", symbol[i].name, func_addr);
}

void display_ret_func(word_t pc)
{
    int i = 0;
    for(; i < func_num; i++)
    {
        if(pc >= symbol[i].addr && pc < (symbol[i].addr + symbol[i].size))
        {
            break;
        }
    }
    printf("0x%08x:", pc);

    rec_depth--;

    for(int k = 0; k < rec_depth; k++) printf("  ");

    printf("ret  [%s]\n", symbol[i].name);
}
//FTRACE-END


