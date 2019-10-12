/*
 * case4.c
 *
 *  Created on: 2013Äê11ÔÂ6ÈÕ
 *      Author: chenrui
 */


#include "case4.h"

volatile unsigned char arr_case4[10];

void case4_main(){
//	volatile unsigned char * ptr = arr_case4;
	arr_case4[0] = 0x1;
	idlerun();
	arr_case4[0] = 0x2;
}

void case4_isr(){
	unsigned char tmp;
	tmp = arr_case4[0]; /* bug */
	idlerun();
}
