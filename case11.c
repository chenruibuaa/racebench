/*
 * case11.c
 * ģʽ3�����������η��ʵ�ԭ����Υ��
 *
 * ������ �ж����ж� ������д
 *  Created on: 2013��11��6��
 *      Author: chenrui
 */
#include "case11.h"

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack;
volatile U_Pack packet_case11;

void case11_isr_low(){
	unsigned char tmp;
	packet_case11.header = 0x1;
	idlerun();
	tmp = packet_case11.data;
}

void case11_isr_high(){
	packet_case11.data = 0x2;  /* bug��*/
}


