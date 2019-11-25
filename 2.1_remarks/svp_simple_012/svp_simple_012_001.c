/*
 * racebench2.1_remarks
 * Filename:svp_simple_012_001
 * Template File:svp_simple_012
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_012_001_main
 * 中断入口:svp_simple_012_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

int svp_simple_012_001_global_var;

int svp_simple_012_001_global_pointer;

void svp_simple_012_001_main() {
  init();
  int *p = &svp_simple_012_001_global_var;

  svp_simple_012_001_global_var = 0x01;

  *p = 0x02;
}

void svp_simple_012_001_isr_1() {
  int reader1;
  reader1 = svp_simple_012_001_global_var;
}
//bug点:
//1.svp_simple_012_001_global_var<W#27>,<R#34>,<W#29>