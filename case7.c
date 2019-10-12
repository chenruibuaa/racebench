/*
 * case7.c
 * 模式2：多变量关联
 * 结构体 + 任务与中断
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */

#include "case7.h"

typedef struct Time{
	int second;
	int misecond;
} S_Time;

volatile S_Time time_case7;

void case7_main(){
	float starTime;
	int f1, f2;

	/* struct member access */
	idlerun();

	f1 = time_case7.second;
	f2 = time_case7.misecond;

	starTime = f1 + f2*0.001;
}

void case7_isr(){
	time_case7.second = 0x1;
	time_case7.misecond = 0xff;  /* bug */
}
