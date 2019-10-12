/*
 * common.c
 *
 *  Created on: 2013Äê11ÔÂ6ÈÕ
 *      Author: chenrui
 */
#include "common.h"

void idlerun(){
	int i=0;
	for(i=0; i<=100; i++){
//		print2("Running....");
	}
}


void writeVariable(volatile unsigned char* var){
	*var = 0x000;
}

void readVariable(volatile unsigned char* var){
	int tmp;
	tmp = (int)*var;
}

void lock(){

}

void unlock(){

}
