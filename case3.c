/*
 * case3.c
 * 模式1：单变量多次访问之间的原子性违反
 *
 * R-W-W 结构体 任务与中断 变量读写 函数嵌套
 *
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case3.h"

typedef struct Time{
	int second;
	int misecond;
} Time;

/* 共享变量为结构体类型 */
volatile Time star_time_case3;

void case3_main(){
	idlerun();
	if(star_time_case3.misecond==1000){
		star_time_case3.second++;
		star_time_case3.misecond = 0;
	}

}

void case3_isr(){
	idlerun();
	/* 嵌套函数  */
	case3_nestedfunc();

}

void case3_nestedfunc(){
	star_time_case3.second = 1; /* bug */
}
