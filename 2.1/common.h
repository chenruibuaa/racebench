/*
 * racebench2.0
 * Filename:common.h
 *
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 *
 *
 *
 *
 *
 *
 *
 *
 */

#ifndef common_h
#define common_h

typedef unsigned char unsigned8;
typedef unsigned short unsigned16;
typedef unsigned int unsigned32;
typedef unsigned long long unsigned64;

typedef signed char signed8;
typedef signed short signed16;
typedef signed int signed32;
typedef signed long long signed64;

void idlerun();

void enable_isr(int);

void disable_isr(int);

void init();

extern int rand();
#endif
