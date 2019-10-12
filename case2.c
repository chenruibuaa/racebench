/*
 * case2.c
 *
 * 模式1：单变量多次访问之间的原子性违反
 *
 * W-W-R 联合体 任务与中断 变量读写
 *
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case2.h"

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack;
volatile U_Pack packet_case2;

void case2_main(){
	unsigned char tmp;
	packet_case2.header = 0x1;
	idlerun();
	tmp = packet_case2.data;
}

void case2_isr(){
	packet_case2.data = 0x2;  /* bug　*/
}


