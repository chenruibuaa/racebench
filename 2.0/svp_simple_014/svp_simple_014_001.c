/*
 * racebench2.0
 * Filename:svp_simple_014_001
 * Template File:svp_simple_014
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_014_001_main
 * 中断入口:svp_simple_014_001_isr_1，svp_simple_014_001_isr_2，svp_simple_014_001_isr_3
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 100
#define TRIGGER 99

volatile int svp_simple_014_001_global_var1 = 0x01;
volatile int svp_simple_014_001_global_var2 = 0x02;

int svp_simple_014_001_global_flag1 = 0;
int svp_simple_014_001_global_flag2 = 1;

void svp_simple_014_001_main() {
  init();
  idlerun();
}

void svp_simple_014_001_isr_1() {
  disable_isr(3);
  int reader1, reader2;
  int reader3, reader4;

  for (int i = 0; i < MAX_LENGTH; i++)
    if (i == TRIGGER) reader1 = svp_simple_014_001_global_var1;

  reader2 = svp_simple_014_001_global_var1;

  reader3 = svp_simple_014_001_global_var2;

  reader4 = svp_simple_014_001_global_var2;
}

void svp_simple_014_001_isr_2() {
  svp_simple_014_001_global_flag1 = 1;
  svp_simple_014_001_global_flag2 = 0;

  enable_isr(3);

  idlerun();
}

void svp_simple_014_001_isr_3() {
  if (svp_simple_014_001_global_flag1 == 1) svp_simple_014_001_global_var1 = 0x09;
  if (svp_simple_014_001_global_flag2 == 1) svp_simple_014_001_global_var2 = 0x09;
}
//bug://svp_simple_014_001_global_var1<R#39>,<W#58>,<R#41>
