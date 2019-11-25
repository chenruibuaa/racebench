/*
 * racebench2.1_remarks
 * Filename:svp_simple_028_001
 * Template File:svp_simple_028
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_028_001_main
 * 中断入口:svp_simple_028_001_isr_1，svp_simple_028_001_isr_2，svp_simple_028_001_isr_3
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

void svp_simple_028_001_init();

volatile int svp_simple_028_001_isr_1_flag;
volatile int svp_simple_028_001_gloable_var;

int svp_simple_028_001__main() {
  svp_simple_028_001_init();

  disable_isr(-1);
  enable_isr(1);
  if (svp_simple_028_001_gloable_var > 12) {  
    svp_simple_028_001_gloable_var = 0;     
  }
  return 0;
}

void svp_simple_028_001_init() {
  svp_simple_028_001_gloable_var = rand();
  svp_simple_028_001_isr_1_flag = rand();

  init();
}

void svp_simple_028_001_isr_1() {
  svp_simple_028_001_gloable_var++; 
  svp_simple_028_001_isr_1_flag = 0;
  enable_isr(2);
}
void svp_simple_028_001_isr_2() {
  if (svp_simple_028_001_isr_1_flag) {
    svp_simple_028_001_gloable_var++;  
  }
}
void svp_simple_028_001_isr_3() {
  svp_simple_028_001_gloable_var++;  
}

// bug点：
// 1.svp_simple_028_001_gloable_var <R, #29>, <W, #43>, <W, #30>

// 误报点：
// 1.svp_simple_028_001_gloable_var <R, #29>, <W, #49>, <W, #30>
// 2.svp_simple_028_001_gloable_var <R, #29>, <W, #53>, <W, #30>