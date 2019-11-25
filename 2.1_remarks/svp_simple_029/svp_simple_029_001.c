/*
 * racebench2.1_remarks
 * Filename:svp_simple_029_001
 * Template File:svp_simple_029
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_029_001_main
 * 中断入口:svp_simple_029_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

volatile unsigned8 svp_simple_029_001_tm_blocks[4096];
volatile unsigned8 svp_simple_029_001_average_adjust_flag;
volatile unsigned8 svp_simple_029_001_average_adjust_count;
volatile unsigned8 (*svp_simple_029_001_ptr_GetTmData)(unsigned32);
void (*svp_simple_029_001_ptr_SetTmData)(unsigned32, unsigned8);
void (*svp_simple_029_001_ptr_SetSelfCtrlFlag)(unsigned32, unsigned8, unsigned8);

void svp_simple_029_001_TmOrgFuncMap();
void svp_simple_029_001_SetSelfCtrlFlag(unsigned32 tm_para, unsigned8 ctrl_flag,
                                    unsigned8 flag_pos);
unsigned8 svp_simple_029_001_GetTmData(unsigned32 tm_name);
void svp_simple_029_001_SetTmData(unsigned32 tm_name, unsigned8 tm_data);

void svp_simple_029_001_init();

void svp_simple_029_001_main() {
  unsigned8 svp_simple_029_001_local_status = 1;
  svp_simple_029_001_init();
  svp_simple_029_001_TmOrgFuncMap();
  
  if (svp_simple_029_001_local_status == 1) {
    svp_simple_029_001_ptr_SetSelfCtrlFlag(36, 0xFF, 0);
  }
}
void svp_simple_029_001_init() {
  for (int i = 0; i < 4096; i++) {
    svp_simple_029_001_tm_blocks[i] = rand();
  }
  svp_simple_029_001_average_adjust_flag = 0xFF;

  init();
}

void svp_simple_029_001_TmOrgFuncMap() {
  svp_simple_029_001_ptr_SetTmData = svp_simple_029_001_SetTmData;
  svp_simple_029_001_ptr_GetTmData = svp_simple_029_001_GetTmData;
  svp_simple_029_001_ptr_SetSelfCtrlFlag = svp_simple_029_001_SetSelfCtrlFlag;
}
void svp_simple_029_001_SetSelfCtrlFlag(unsigned32 tm_para, unsigned8 ctrl_flag,
                                    unsigned8 flag_pos) {
  unsigned8 tmp1;
  unsigned8 tmp2;
  unsigned8 ctrl_sts;

  if (ctrl_flag > 0x80) {
    tmp1 = 1;
  } else {
    tmp1 = 0;
  }

  tmp1 <<= flag_pos;
  tmp2 = 1;
  tmp2 <<= ~tmp2;

  ctrl_sts = svp_simple_029_001_ptr_GetTmData(tm_para);       
  ctrl_sts -= svp_simple_029_001_ptr_GetTmData(tm_para + 1);  
  ctrl_sts |= tmp1;

  svp_simple_029_001_ptr_SetTmData(tm_para, ctrl_sts);  
}
unsigned8 svp_simple_029_001_GetTmData(unsigned32 tm_name) {
  return svp_simple_029_001_tm_blocks[tm_name]; 
}
void svp_simple_029_001_SetTmData(unsigned32 tm_name, unsigned8 tm_data) {
  svp_simple_029_001_tm_blocks[tm_name] = tm_data; 
}

void svp_simple_029_001_isr_1() {
  if (svp_simple_029_001_average_adjust_flag == 0xFF) {
    svp_simple_029_001_average_adjust_count++;
    svp_simple_029_001_ptr_SetTmData(
        36, svp_simple_029_001_average_adjust_count); 
  } else {
    svp_simple_029_001_average_adjust_count = 0;
    svp_simple_029_001_ptr_SetTmData(36, svp_simple_029_001_average_adjust_count);
  }
}

// bug点：
// 1.svp_simple_029_001_tm_blocks[36] <R, #80>, <W, #83>, <W, #83>

// 误报点：
//1.svp_simple_029_001_tm_blocks[36] <R, #80>, <W, #83>, <R, #80>
