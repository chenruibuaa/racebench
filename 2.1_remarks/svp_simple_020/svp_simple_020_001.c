/*
 * racebench2.1_remarks
 * Filename:svp_simple_020_001
 * Template File:svp_simple_020
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_020_001_main
 * 中断入口:svp_simple_020_001_isr_1，svp_simple_020_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_020_001_global_var;

volatile int svp_simple_020_001_global_para;

volatile int svp_simple_020_001_global_flag = 0;

void svp_simple_020_001_main() {
  init();
  disable_isr(2);
  int reader1, reader2;
  int svp_simple_020_001_local_var1, svp_simple_020_001_local_var2;
  svp_simple_020_001_local_var1 = rand();
  svp_simple_020_001_local_var2 = rand();
  

  

  if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 > svp_simple_020_001_global_para)
    reader1 = svp_simple_020_001_global_var;

  if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 < svp_simple_020_001_global_para)
    reader2 = svp_simple_020_001_global_var;
}

void svp_simple_020_001_isr_1() {
  svp_simple_020_001_global_var = 0x01;
  
  svp_simple_020_001_global_flag = 1;
  enable_isr(2);
}

void svp_simple_020_001_isr_2() {
  if (svp_simple_020_001_global_flag == 1) {
    svp_simple_020_001_global_para = 11;
    svp_simple_020_001_global_var = 0x05;
  }
}
//bug点:
//1.svp_simple_020_001_global_var<R#37>,<W#53>,<R#40>
//2.svp_simple_020_001_global_para<R#36>,<W#52>,<R#39>
//误报点:
//1.svp_simple_020_001_global_var<R#37>,<W#44>,<R#40>