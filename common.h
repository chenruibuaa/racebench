/*
 * common.h
 *
 *  Created on: 2013Äê11ÔÂ6ÈÕ
 *      Author: chenrui
 */

#ifndef COMMON_H_
#define COMMON_H_

void idlerun();

void writeVariable(volatile unsigned char* var);

void readVariable(volatile unsigned char* var);

void lock();

void unlock();

#endif /* COMMON_H_ */
