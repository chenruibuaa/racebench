/*
 * racebench2.0
 * Filename:svp_simple_013_001
 * Template File:svp_simple_013
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_013_001_main
 * 中断入口:svp_simple_013_001_isr_1，svp_simple_013_001_isr_2，svp_simple_013_001_isr_3
 * 中断优先级以数字作为标准，越大优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 100
#define TRIGGER 99

volatile int svp_simple_013_001_global_var1;
volatile int svp_simple_013_001_global_var2;

int svp_simple_013_001_global_flag1 = 0;
int svp_simple_013_001_global_flag2 = 1;

void svp_simple_013_001_main() {
  init();
  disable_isr(2);
  disable_isr(3);

  svp_simple_013_001_global_var1 = 0x05;
  svp_simple_013_001_global_var2 = 0x05;
  int reader1, reader2;
  int reader3, reader4;

  for (int i = 0; i < MAX_LENGTH; i++)
    if (i == TRIGGER) reader1 = svp_simple_013_001_global_var1;

  reader2 = svp_simple_013_001_global_var1;

  reader3 = svp_simple_013_001_global_var2;

  reader4 = svp_simple_013_001_global_var2;
}

void svp_simple_013_001_isr_1() {
  idlerun();
  enable_isr(2);
  idlerun();
}

void svp_simple_013_001_isr_2() {
  idlerun();
  svp_simple_013_001_global_flag1 = 1;

  svp_simple_013_001_global_flag2 = 0;

  enable_isr(3);
  idlerun();
}

void svp_simple_013_001_isr_3() {
  if (svp_simple_013_001_global_flag1 == 1) svp_simple_013_001_global_var1 = 0x01;
  if (svp_simple_013_001_global_flag2 == 1) svp_simple_013_001_global_var2 = 0x01;
}
//bug://svp_simple_013_001_global_var1<R#39>,<W#65>,<R#41>
