#include "UTILSTD.h"
#include "racebench.h"




void bench_task1(void);
extern void delay(unsigned int time);

void racebench_entry(){
	print2("Data Race Benchmark Program Starting...");
	OSTaskSpawn(0xb003, 10, 0, 0x2000, (FUNCPTR)bench_task1, 0, 0, 0, 0);
	OSTaskSpawn(0xb004, 9, 0, 0x2000, (FUNCPTR)bench_task2, 0, 0, 0, 0);
	OSTaskSpawn(0xb005, 8, 0, 0x2000, (FUNCPTR)bench_task3, 0, 0, 0, 0);

	OSTaskSpawn(0xb006, 7, 0, 0x2000, (FUNCPTR)bench_task4, 0, 0, 0, 0);
	OSTaskSpawn(0xb007, 6, 0, 0x2000, (FUNCPTR)bench_task5, 0, 0, 0, 0);
}

void Default_int(void)
{
	#ifdef DEBUG
	print2("\n\rDefault_int");
	#endif
}



/** 5个任务 */

/**
覆盖的case：
case 1: 与中断1
case 2: 与中断2

*/
void bench_task1(void)
{
	while(1)
	{
		print2("\n\rTask1 running....");

		case1_main();
		idlerun();
		case2_main();
		idlerun();
		case14_task1();
		OSTaskDelay(OS_TIME_TICKS_PER_SEC/100);
	}

}

void bench_task2(void)
{
	while(1)
	{
		print2("\r\nTask2 running....");

		case3_main();
		idlerun();
		case4_main();
		OSTaskDelay(OS_TIME_TICKS_PER_SEC/100);
	}
}

void bench_task3(void)
{
	while(1)
	{
		print2("\r\nTask3 running....");
		case5_main();
		case6_main();
		idlerun();
		case14_task2();
		OSTaskDelay(OS_TIME_TICKS_PER_SEC/100);	}

}

void bench_task4(void)
{
	while(1)
	{
		print2("\r\nTask4 running....");
		case7_main();
		idlerun();
		case9_main();
		OSTaskDelay(OS_TIME_TICKS_PER_SEC/100);
	}

}

void bench_task5(void)
{
	while(1)
	{
		print2("\r\nTask5 running....");
		case10_main();
		idlerun();
		case13_main();
		OSTaskDelay(OS_TIME_TICKS_PER_SEC/100);
	}

}


void bench_isr1(){
	print2("\r\nEntering <ISR1>....");
	case1_isr();
	case4_isr();
	case8_isr_low();
	case12_isr_low();
	case14_isr_low();
	print2("\r\nLeaving <ISR1>....");
}

void bench_isr2(){
	print2("\r\nEntering <ISR2>....");

	case2_isr();
	case5_isr();
	case9_isr_low();
	case11_isr_low();
	case13_isr_low();
	print2("\r\nLeaving <ISR2>....");

}

void bench_isr3(){
	print2("\r\nEntering <ISR3>....");

	case3_isr();
	case6_isr();
	case8_isr_high();
	case11_isr_high();
	case13_isr_high();
	case14_isr_high();

	print2("\r\nLeaving <ISR3>....");

}

void bench_isr4(){
	print2("\r\nEntering <ISR4>....");

	case7_isr();
	case9_isr_high();
	case10_isr();
	case12_isr_high();

	print2("\r\nLeaving <ISR4>....");

}


