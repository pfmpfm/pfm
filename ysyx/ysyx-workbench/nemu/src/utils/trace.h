#ifndef TRACE_HEADER_H
#define TRACE_HEADER_H

#include <stdint.h> 
#include <elf.h>

typedef uint32_t word_t;
typedef struct {
    char name[64];
    uint32_t addr;      //the function head address
    Elf32_Xword size;
} Symbol;

extern Symbol *symbol;  //dynamic allocate memory  or direct allocate memory (Symbol symbol[NUM])

void trace_inst(word_t pc, uint32_t inst);
void display_inst();
void display_memory_read(uint32_t addr, int len);
void display_memory_write(uint32_t addr, int len, word_t data);
void display_call_func(word_t pc, word_t func_addr);
void display_ret_func(word_t pc);




#endif 

