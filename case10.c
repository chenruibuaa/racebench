/*
 * case10.c
 * ģʽ3�����������η��ʵ�ԭ����Υ��
 *
 * �������� �������ж� ������д
 *
 *  Created on: 2013��11��6��
 *      Author: chenrui
 */
#include "case10.h"

volatile unsigned long shared1_case10;


void case10_main(){
	unsigned char tmp;

	tmp = shared1_case10;
}

void case10_isr(){

	idlerun();
	shared1_case10 = 1;  /* bug */
	idlerun();
}
