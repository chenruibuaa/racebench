/*
 * racebench2.0
 * Filename:svp_simple_002_001
 * Template File:svp_simple_002
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_002_001_main
 * 中断入口:svp_simple_002_001_isr_1,svp_simple_002_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 10000
#define TRIGGER 9999

volatile int svp_simple_002_001_global_array[MAX_LENGTH];
volatile int casee2_global_var;

void svp_simple_002_001_main() {
  init();
  idlerun();
}

void svp_simple_002_001_isr_1() {
  int mininum, maxnum;
  for (int i = 0; i < MAX_LENGTH; i++) {
    if (i == TRIGGER) svp_simple_002_001_global_array[TRIGGER] = 1;
    if (i == MAX_LENGTH + 1)
      svp_simple_002_001_global_array[TRIGGER] = 1;
  }
  mininum = svp_simple_002_001_global_array[TRIGGER] - 10;

  maxnum = svp_simple_002_001_global_array[0] + 10;
}

void svp_simple_002_001_isr_2() {
  idlerun();
  svp_simple_002_001_global_array[TRIGGER] = 999;

}