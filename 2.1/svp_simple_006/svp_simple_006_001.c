/*
 * racebench2.0
 * Filename:svp_simple_006_001
 * Template File:svp_simple_006
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_006_001_main
 * 中断入口:svp_simple_006_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 10000
#define TRIGGER 9999

volatile int svp_simple_006_001_global_var1;
volatile int svp_simple_006_001_global_var2;
volatile unsigned char flag = 0x55;
void svp_simple_006_001_main() {
  init();
  int reader1, reader2;
  
  for (int i = 0; i < 5; i++)
    for (int j = 0; i < 5; j++) {
      if (i == j) {
        if (i == 0)
          reader1 = svp_simple_006_001_global_var1;
        else if (i == 4)
          reader2 = svp_simple_006_001_global_var1;
        else if (i == 6)
          reader2 = svp_simple_006_001_global_var1;
      }
    }

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (((i + j) == 6) && (i < j))
        svp_simple_006_001_global_var2 = 0x02;
    }
}

void svp_simple_006_001_isr_1() {
  int reader2;
  idlerun();

  svp_simple_006_001_global_var1 = 0;
  reader2 = svp_simple_006_001_global_var2;
}