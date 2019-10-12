/*
 * case14.h
 *
 *  Created on: 2013Äê11ÔÂ8ÈÕ
 *      Author: chenrui
 */

#ifndef CASE14_H_
#define CASE14_H_

#include "common.h"

typedef struct{
	unsigned char x;
	unsigned char y;
	unsigned char z;
} S_Vector;

void case14_task1();


void case14_task2();

void case14_isr_low();

void case14_isr_high();

void writeVector(volatile S_Vector *p);

int readVector(volatile S_Vector *p);

#endif /* CASE14_H_ */
