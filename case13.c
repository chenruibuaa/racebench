/*
 * case13.c
 * 模式4：lock-lock-unlock-unlock
 * 基本类型 + 任务和中断 +
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case13.h"



volatile unsigned long g1_case13;

void case13_main(){

	lock(); //disable high priority isr;
	/* case13_isr_low might be triggerd here */
	if(g1_case13 == 0)
		g1_case13 = 0xff;

	unlock();

}

void case13_isr_low(){

	lock();
	idlerun();
	unlock();

}

void case13_isr_high(){
	g1_case13 = 0x01;  /* bug */
}
