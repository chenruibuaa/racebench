/*
 * case1.c
 * ģʽ1����������η���֮���ԭ����Υ��
 *
 * R-W-R �������� �������ж� ������д
 *
 *  Created on: 2013��11��6��
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
