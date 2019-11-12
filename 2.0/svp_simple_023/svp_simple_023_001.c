/*
 * racebench2.0
 * Filename:svp_simple_023_001
 * Template File:svp_simple_023
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_023_001_main
 * 中断入口:svp_simple_023_001_isr_1
 * 中断优先级以数字作为标准，越大优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_023_001_global_var;
void svp_simple_023_001_func_1(int x);
void svp_simple_023_001_init();

void svp_simple_023_001_main() {
  svp_simple_023_001_func_1(svp_simple_023_001_global_var);
}
void svp_simple_023_001_init() {
  svp_simple_023_001_global_var = rand();

  init();
}

void svp_simple_023_001_func_1(int var) {
  if (var > 0 && var < 12) {
    svp_simple_023_001_global_var = svp_simple_023_001_global_var + 1;
  }
}
void svp_simple_023_001_isr_1() {
  svp_simple_023_001_global_var = 0
}

// 1: svp_simple_023_001_global_var <R, #24>, <W, #38>, <R, #34> 
// 2: svp_simple_023_001_global_var <R, #34>, <W, #38>, <W, #34> 
