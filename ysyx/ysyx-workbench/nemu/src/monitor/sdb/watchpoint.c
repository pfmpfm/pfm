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

#include "sdb.h"
#include "/home/pfm/ysyx/ysyx-workbench/nemu/include/utils.h"

#define NR_WP 32
#define word_t uint32_t

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  word_t LastValue; //监视点的上一个值
  char *expr;  //监视点的表达式

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL;
WP *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
  Assert(free_ != NULL, "free_ 链表中没有可返回的空闲监视点");
  /*从 free_ 中获取空闲监视点*/
  WP* freeWP = free_;
  free_ = free_->next;
  /*将空闲监视点链接到头部*/
  freeWP->next = head;
  head = freeWP;
  return head;
}

void free_wp(WP *wp){
  // 检查head是否为空链表
  Assert(head != NULL, "head链表中没有繁忙的监视点可以释放");

  WP* current = head;
  WP* previous = NULL;
  bool found = false;

  // 遍历链表寻找目标监视点
  while (current != NULL){
    if (current == wp){
      found = true;
      if (previous == NULL){
        // 如果目标监视点是链表的头部
        Assert(current == head, "当 previous == NULL 时,current 却不等于 head");
        head = head->next;
      } else {
        // 如果目标监视点不是链表的头部
        Assert(previous != NULL, "在 free_wp 中,previous == NULL");
        previous->next = current->next;
      }
      break;
    }
    previous = current;
    current = current->next;
  }
  // 确认已经找到并移除了目标监视点
  Assert(found == true, "在 head 链表中找不到对应的监视点");
  // 将目标监视点添加到空闲链表中
  current->next = free_;
  free_ = current;
}
void checkWatchPoint() {
  WP* freeWP = head;
  word_t newValue;
  bool success = true;
 
  while (freeWP != NULL){
    //Assert(freeWP->expr != NULL, "There are no express in watchpoint");
    newValue = expr(freeWP->expr, &success);
    Assert(success == true, "The error express was put into watchpoint");
    if(!strcmp(freeWP->expr,"$pc")){
        if (newValue == freeWP->LastValue){
        nemu_state.state = NEMU_STOP;
        printf("监视点 No.%d : %u\n\n", freeWP->NO, freeWP->LastValue);
        printf("Last value = %u\n", freeWP->LastValue);
        printf("New value  = %u\n", newValue);
    }
    }else {
    if (newValue != freeWP->LastValue){
      nemu_state.state = NEMU_STOP;
      printf("监视点 No.%d : %u\n\n", freeWP->NO, freeWP->LastValue);
      printf("Last value = %u\n", freeWP->LastValue);
      printf("New value  = %u\n", newValue);
    } }
    freeWP = freeWP->next;
  }
}
// 显示监视点信息
void infoWatchPoint(){
  // 如果没有监视点，则打印信息并返回
  if (head == NULL){
    printf("目前没有监视点\n");
    return;
  }
  printf("%-10s%s\n","序号","表达式");//左对齐并保留10个字符的空间。如果字符串的长度少于10，那么右边将用空格填充。
  // 遍历监视点链表并打印每个监视点的信息
  for (WP* wp = head; wp != NULL; wp = wp->next){
    printf("%-10d%s\n",wp->NO,wp->expr);
  }
}

// 根据编号释放监视点
void free_wpByNO(int NO, bool *success){
  // 遍历监视点链表，找到编号匹配的监视点并释放
  for (WP* wp = head; wp != NULL; wp = wp->next){
    if (wp->NO == NO){
      free_wp(wp);
      *success = true;
      return;
    }
  }
  // 如果没有找到编号匹配的监视点，则设置成功标志为false
  *success = false;
}

// 设置新的监视点
void new_wpSet(char *expr, word_t LastValue){
  // 创建新的监视点
  WP* wp = new_wp();
  // 断言新的监视点是否创建成功
  Assert(wp != NULL, "cmd_w中出错调用new_wp()时,返回值为NULL");
  // 设置监视点的表达式和旧值
  wp->expr = strdup(expr);
  if(expr!=NULL){
  wp->LastValue = LastValue;}
  // 打印监视点的信息
  printf("监视点 No.%d: %s LastValue:%u\n", wp->NO, wp->expr,wp->LastValue);
}

