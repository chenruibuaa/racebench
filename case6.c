/*
 * case6.c
 * ģʽ2�����������
 * �������� + �������ж�
 *  Created on: 2013��11��6��
 *      Author: chenrui
 */

#include "case6.h"

volatile unsigned char arr_case6[10];
int case6_count = 0;

void case6_main(){
	int i=0;
	//int count = 0;
	for(i=0; i<10; i++){
		case6_count += arr_case6[i];
	}
}

void case6_isr(){
	int j = 0;
	for(j=0; j<10; j++)
		arr_case6[j] = j;  /* bug */
}
