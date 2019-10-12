#ifndef RACEBENCH_H_
#define RACEBENCH_H_

#include "case1.h"
#include "case2.h"
#include "case3.h"
#include "case4.h"
#include "case5.h"
#include "case6.h"
#include "case7.h"
#include "case8.h"
#include "case9.h"
#include "case10.h"
#include "case11.h"
#include "case12.h"
#include "case13.h"
#include "case14.h"


void TIME1_int(void);
void Default_int(void);
void IO0_int(void);
void IO3_int(void);
void UART1_int(void);
void can_int(void);
void racebench_entry(void);

void bench_task1(void);
void bench_task2(void);
void bench_task3(void);
void bench_task4(void);
void bench_task5(void);

void bench_isr1(void);
void bench_isr2(void);
void bench_isr3(void);
void bench_isr4(void);


#endif
