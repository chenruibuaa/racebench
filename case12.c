/*
 * case12.c
 * 模式3：单变量单次访问的原子性违反
 *
 * 指针解引用 中断与中断 变量读写
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case12.h"
volatile unsigned long g1_case12;

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack_12;
volatile U_Pack_12 packet_case12;


void case12_isr_low(){
	volatile unsigned long* tmp = &g1_case12;
	*tmp = 1;;
	packet_case12.header = 0x1;
	idlerun();
}

void case12_isr_high(){
	g1_case12 = 0x2;  /* bug　*/
	packet_case12.data = 0x2;  /* bug　*/
}

