#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include "../memory.h"
#define word_t uint32_t
static const word_t img[]={
	0b00000000010100000000000010010011,
	0b00000000001000000000000100010011,
  0b00000000001000000000000100010011,
	0b00000000010100001000000100010011
};
word_t *init_mem(word_t size){
	word_t *memory=(word_t*)malloc(size*sizeof(word_t));
	memcpy(memory,img,sizeof(img));
	if(memory==NULL) exit(0);
	return memory;
}
word_t guest_to_host(word_t addr){return addr-0x80000000;}
word_t pmem_read(word_t *memory, word_t vaddr){
	word_t paddr=guest_to_host(vaddr);
	return memory[paddr/4];
}
