/*
 * racebench2.0
 * Filename:svp_simple_021_001
 * Template File:svp_simple_021
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_021_001_main
 * 中断入口:svp_simple_021_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"
#define svp_simple_021_001_CNT (volatile unsigned int *)0x10000000

volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes_ch1;
volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes_ch2;
volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes;
volatile unsigned8 svp_simple_021_001_tc_chan1_buff[256];
volatile unsigned8 svp_simple_021_001_tc_chan2_buff[256];
volatile unsigned8 *svp_simple_021_001_tc_buff_p;
void svp_simple_021_001_init();
struct svp_simple_021_001_tc_block_data {
  unsigned8 type;
  unsigned8 id;
  unsigned8 valid_len;
};

void svp_simple_021_001_init() {
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 = rand();
  svp_simple_021_001_tc_block_rcvd_bytes_ch2 = rand();

  init();
}

void svp_simple_021_001_RecvTcBlock() {
  unsigned svp_simple_021_001_flag_chan1;
  svp_simple_021_001_flag_chan1 = 0;

  if (svp_simple_021_001_tc_block_rcvd_bytes_ch1 >= 16) {
    svp_simple_021_001_tc_block_rcvd_bytes_ch1 = 0;       
    int i;
    for (i = 0; i < 256; i++) {
      svp_simple_021_001_tc_chan1_buff[i] = 0;
    }
    svp_simple_021_001_flag_chan1 = 0xFF;
  }
}

void svp_simple_021_001_main() {
  struct svp_simple_021_001_tc_block_data tc_block;

  svp_simple_021_001_init();

  svp_simple_021_001_RecvTcBlock();
  int ichan;
  for (ichan = 0; ichan < 2; ichan++) {
    if (ichan == 0) {
      svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan1_buff;
      svp_simple_021_001_tc_block_rcvd_bytes =
          svp_simple_021_001_tc_block_rcvd_bytes_ch1;  
    } else {
      svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan2_buff;
      svp_simple_021_001_tc_block_rcvd_bytes =
          svp_simple_021_001_tc_block_rcvd_bytes_ch2;
    }

    tc_block.type = *(svp_simple_021_001_tc_buff_p + 2);
    tc_block.id = *(svp_simple_021_001_tc_buff_p + 4);
    tc_block.valid_len = *(svp_simple_021_001_tc_buff_p + 5);
  }
}

void svp_simple_021_001_isr_1() {
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 =
      (*(svp_simple_021_001_CNT) >> 3) & 0x1FFF;  
}