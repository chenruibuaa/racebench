/*
 * racebench2.1_remarks
 * Filename:svp_simple_017_001
 * Template File:svp_simple_017
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_017_001_main
 * 中断入口:svp_simple_017_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 100
#define TRIGGER 50

volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[MAX_LENGTH];

void svp_simple_017_001_main() {
  init();
  int i = 0;

  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < MAX_LENGTH;
       svp_simple_017_001_global_var++)
  {
    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }
}

void svp_simple_017_001_isr_1() {
  idlerun();

  svp_simple_017_001_global_var = TRIGGER;

  svp_simple_017_001_local_array[TRIGGER] = 0;
}
//bug点:
//1.svp_simple_017_001_global_var<R#29>,<W#39>,<R#29>
//2.svp_simple_017_001_global_var<R#29>,<W#39>,<R#32>
//3.svp_simple_017_001_global_var<R#32>,<W#39>,<W#30>
//4.svp_simple_017_001_global_var<W#30>,<W#39>,<R#29>
//误报点:
//1.svp_simple_017_001_local_array<R#32>,<W#41>,<R#32>