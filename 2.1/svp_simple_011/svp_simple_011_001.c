/*
 * racebench2.0
 * Filename:svp_simple_011_001
 * Template File:svp_simple_011
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_011_001_main
 * 中断入口:svp_simple_011_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

int svp_simple_011_001_global_var1;
int svp_simple_011_001_global_var2;
int svp_simple_011_001_global_var3;

volatile int *svp_simple_011_001_u;

void svp_simple_011_001_main() {
  init();
  int *p = &svp_simple_011_001_global_var1;
  int *q = &svp_simple_011_001_global_var1;

  *p = 0x01;
  *q = 0x02;

  svp_simple_011_001_u = &svp_simple_011_001_global_var2;
  *svp_simple_011_001_u = 0x01;
  svp_simple_011_001_u = &svp_simple_011_001_global_var3;
  *svp_simple_011_001_u = 0x02;
}

void svp_simple_011_001_isr_1() {
  int reader1, reader2;
  int *m = &svp_simple_011_001_global_var1;
  reader1 = *m;
  reader2 = *svp_simple_011_001_u;
}