/*
 * case14.c
 *
 * 模式2：多变量访问
 * 综合考虑各种情况
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case14.h"


volatile S_Vector s1_case14;
volatile S_Vector s2_case14;
volatile S_Vector s3_case14;


void case14_task1(){
	writeVector(&s1_case14);
	writeVector(&s2_case14);

}


void case14_task2(){
	writeVector(&s1_case14); /*bug: against line 18*/

}

void case14_isr_low(){
	writeVector(&s2_case14); /* bug: against line 19*/
	writeVector(&s3_case14);
}

void case14_isr_high(){
	writeVector(&s3_case14);  /* bug: against line 31 */
}


void writeVector(volatile S_Vector *p){
	p->x = 1; /* bug */
	p->y = 2; /* bug */
	p->z = 3; /* bug */
}

int readVector(volatile S_Vector *p){
	int tmp;
	tmp = p->x + p->y + p->z;
	return tmp;
}
