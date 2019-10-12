/*
 * case11.c
 * 模式3：单变量单次访问的原子性违反
 *
 * 联合体 中断与中断 变量读写
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case11.h"

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack;
volatile U_Pack packet_case11;

void case11_isr_low(){
	unsigned char tmp;
	packet_case11.header = 0x1;
	idlerun();
	tmp = packet_case11.data;
}

void case11_isr_high(){
	packet_case11.data = 0x2;  /* bug　*/
}


