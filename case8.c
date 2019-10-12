/*
 * case8.c
 * 模式2：多变量关联
 * 基本变量 + 中断中断 + 函数嵌套
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */

#include "case8.h"



volatile unsigned char g1_case8;
volatile unsigned char g2_case8;

void case8_isr_low(){
	int result;

	idlerun();

	if(g1_case8 > 10){
		result = g1_case8 + g2_case8;
	}

}

void case8_isr_high(){
	case8_nestedfunc();
}

void case8_nestedfunc(){
	g1_case8=0;  /* bug */
	g2_case8=1;  /* bug */
}
