/*
 * case9.c
 * 模式2：多变量关联
 * 结构体 + 任务与中断 + 中断嵌套
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */

#include "case9.h"

typedef struct Time{
	int second;
	int misecond;
} S_Time;

volatile S_Time time_case9;

void case9_main(){
	float starTime;
	int f1, f2;

	/* struct member access */
	idlerun();

	f1 = time_case9.second;
	f2 = time_case9.misecond;

	starTime = f1 + f2*0.001;
}

void case9_isr_low(){
	idlerun();
	/* should be interrupted by case7_isr_high */
	idlerun();
}


void case9_isr_high(){
	time_case9.second = 0x1;
	time_case9.misecond = 0xff;  /* bug */
}
