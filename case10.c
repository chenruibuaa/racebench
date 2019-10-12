/*
 * case10.c
 * 模式3：单变量单次访问的原子性违反
 *
 * 基本类型 任务与中断 变量读写
 *
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case10.h"

volatile unsigned long shared1_case10;


void case10_main(){
	unsigned char tmp;

	tmp = shared1_case10;
}

void case10_isr(){

	idlerun();
	shared1_case10 = 1;  /* bug */
	idlerun();
}
