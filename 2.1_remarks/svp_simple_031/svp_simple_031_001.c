/*
 * racebench2.1_remarks
 * Filename:svp_simple_031_001
 * Template File:svp_simple_031
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_031_001_main
 * 中断入口:svp_simple_031_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

void svp_simple_031_001_init();
int svp_simple_031_001_func_1(int a, int b);
int svp_simple_031_001_func_2(int x);
void svp_simple_031_001_func_3();

#define svp_simple_031_001_CNT (volatile unsigned int *)0x10000000
volatile unsigned16 svp_simple_031_001_tc_block_rcvd_bytes_ch1;
volatile unsigned16 svp_simple_031_001_tc_block_rcvd_bytes_ch2;
volatile unsigned16 svp_simple_031_001_tc_block_rcvd_bytes;
volatile unsigned8 svp_simple_031_001_tc_chan1_buff[256];
volatile unsigned8 svp_simple_031_001_tc_chan2_buff[256];
volatile unsigned8 *svp_simple_031_001_tc_buff_p;
volatile unsigned32 svp_simple_031_001_gloable_var1;

struct svp_simple_031_001_tc_block_data {
  unsigned8 type;
  unsigned8 id;
  unsigned8 valid_len;
};
void svp_simple_031_001_main() {
  svp_simple_031_001_init();
  struct svp_simple_031_001_tc_block_data tc_block;

  int ichan = 0;
  if (ichan == 0) {
    svp_simple_031_001_tc_buff_p = svp_simple_031_001_tc_chan1_buff;
    svp_simple_031_001_tc_block_rcvd_bytes =
        svp_simple_031_001_tc_block_rcvd_bytes_ch1;  
  }

  tc_block.type = *(svp_simple_031_001_tc_buff_p + 2);
  tc_block.id = *(svp_simple_031_001_tc_buff_p + 4);
  tc_block.valid_len = *(svp_simple_031_001_tc_buff_p + 5);
  svp_simple_031_001_func_3();
}

int svp_simple_031_001_func_1(int a, int b) {
  int c;
  if (a < b) {
    c = a * b;
  } else {
    c = svp_simple_031_001_func_2(10);
  }
  return c;
}
int svp_simple_031_001_func_2(int x) {
  if (svp_simple_031_001_tc_block_rcvd_bytes_ch1 > 0) {  
    return x;
  } else {
    return 0;
  }
}

void svp_simple_031_001_init() {
  svp_simple_031_001_tc_block_rcvd_bytes_ch1 = rand();
  svp_simple_031_001_tc_block_rcvd_bytes_ch2 = rand();

  init();
}

void svp_simple_031_001_func_3() {
  unsigned svp_simple_031_001_flag_chan1;
  svp_simple_031_001_flag_chan1 = 0;

  if (svp_simple_031_001_tc_block_rcvd_bytes_ch1 >= 16) {  
    svp_simple_031_001_func_1(svp_simple_031_001_gloable_var1,
                          svp_simple_031_001_tc_block_rcvd_bytes_ch1);  
  }
}

void svp_simple_031_001_isr_1() {
  svp_simple_031_001_tc_block_rcvd_bytes_ch1 =
      (*(svp_simple_031_001_CNT) >> 3) & 0x1FFF;  
}

// bug点：
// 1.svp_simple_031_001_tc_block_rcvd_bytes_ch1 <#46,R> <#90,W>,<#83,R>
// 2.svp_simple_031_001_tc_block_rcvd_bytes_ch1 <#83,R> <#90,W>,<#85,R>
// 3.svp_simple_031_001_tc_block_rcvd_bytes_ch1 <#85,R> <#90,W>,<#65,R>