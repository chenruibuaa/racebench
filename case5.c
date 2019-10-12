/*
 * case5.c
 *
 * 模式2：多变量关联
 * 基本类型 + 任务与中断
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */

#include "case5.h"

volatile unsigned char case5_x;
volatile unsigned char case5_y;
volatile unsigned char case5_z;

void case5_main(){
	int f1, f2, f3;

	/* primary variable */

	f1 = case5_x*case5_x*case5_x;       /* bug */
	f2 = case5_y*case5_y*case5_y;
	f3 = case5_z*case5_z*case5_z;

	f1 = f1 + f2 + f3;
}


void case5_isr(){
	idlerun();
	writeVariable(&case5_x); /* write by address ref. */
	writeVariable(&case5_y); /* write by address ref. */
	writeVariable(&case5_y); /* write by address ref. */
}
