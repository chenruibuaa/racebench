/*
 * case2.c
 *
 * ģʽ1����������η���֮���ԭ����Υ��
 *
 * W-W-R ������ �������ж� ������д
 *
 *  Created on: 2013��11��6��
 *      Author: chenrui
 */
#include "case2.h"

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack;
volatile U_Pack packet_case2;

void case2_main(){
	unsigned char tmp;
	packet_case2.header = 0x1;
	idlerun();
	tmp = packet_case2.data;
}

void case2_isr(){
	packet_case2.data = 0x2;  /* bug��*/
}


