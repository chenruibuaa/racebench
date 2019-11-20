/*
 * racebench2.0
 * Filename:svp_simple_026_001
 * Template File:svp_simple_026
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_026_001_main
 * 中断入口:svp_simple_026_001_isr_1，svp_simple_026_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

void svp_simple_026_001_init();

volatile int svp_simple_026_001_gloable_var;
int svp_simple_026_001_main() {
  svp_simple_026_001_init();

  disable_isr(1);
  if (svp_simple_026_001_gloable_var > 12) {
    svp_simple_026_001_gloable_var = 0;
  }
  enable_isr(1);

  return 0;
}
void svp_simple_026_001_init() {
  svp_simple_026_001_gloable_var = rand();

  init();
}

void svp_simple_026_001_isr_1() {
  svp_simple_026_001_gloable_var = 12;
}
void svp_simple_026_001_isr_2() {
  svp_simple_026_001_gloable_var--;
}