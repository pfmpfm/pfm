#ifndef MY_HEADER_H
#define MY_HEADER_H
#define word_t uint32_t
word_t *init_mem(word_t size);
word_t gust_to_host(word_t addr);
word_t pmem_read(word_t *memory, word_t vaddr);

#endif 

