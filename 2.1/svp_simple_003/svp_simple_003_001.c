/*
 * racebench2.0
 * Filename:svp_simple_003_001
 * Template File:svp_simple_003
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_003_001_main
 * 中断入口:svp_simple_003_001_isr_1,svp_simple_003_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 10000
#define TRIGGER 9999

volatile int svp_simple_003_001_global_var1;
volatile int svp_simple_003_001_global_var2;

volatile int svp_simple_003_001_global_flag = 0;
volatile int svp_simple_003_001_global_flag1 = 0;
void svp_simple_003_001_main() {
  init();
  int reader1, reader2;
  int reader3, reader4;
  idlerun();

  disable_isr(1);
  disable_isr(2);

  for (int i = 0; i < MAX_LENGTH; i++) {
    if (i == TRIGGER) {
      reader3 = svp_simple_003_001_global_var2;
    }
  }
  for (int j = MAX_LENGTH; j > 0; j--) {
    if (j == TRIGGER) {
      reader4 = svp_simple_003_001_global_var2;
    }
  }
  
  enable_isr(1);
  for (int i = 0; i < MAX_LENGTH; i++) {
    if (i == TRIGGER) {
      reader1 = svp_simple_003_001_global_var1;
    }
  }
  for (int j = MAX_LENGTH; j > 0; j--) {
    if (j == TRIGGER) {
      reader2 = svp_simple_003_001_global_var1;
    }
  }
}

void svp_simple_003_001_isr_1() {
  enable_isr(2);
  svp_simple_003_001_global_var2 = 999;

  if (svp_simple_003_001_global_flag == 1) {
    svp_simple_003_001_global_var1 = 999;
  } else if (svp_simple_003_001_global_flag1 == 2) {
    svp_simple_003_001_global_var1 = 888;
  }
}

void svp_simple_003_001_isr_2() {
  idlerun();
  svp_simple_003_001_global_flag = 1;
}