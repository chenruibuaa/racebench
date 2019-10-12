/*
 * case1.c
 * 模式1：单变量多次访问之间的原子性违反
 *
 * R-W-R 基本类型 任务与中断 变量读写
 *
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case1.h"

volatile unsigned char shared1_uchar;


void case1_main(){

	unsigned char tmp;
	/*  R-W-R */
	if(shared1_uchar > 0){
		tmp = shared1_uchar;
	}
}

void case1_isr(){

	idlerun();
	shared1_uchar = 1;  /* bug */
	idlerun();
}
