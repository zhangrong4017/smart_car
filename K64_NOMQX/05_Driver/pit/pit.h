//==========================================================================
//文件名称：pit.h
//功能概要：K64 pit底层驱动程序文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//版本更新：2011-11-13  V1.0  初始版本。
//         2014-11-9   V2.0  KDS和新框架
//==========================================================================

#ifndef _PIT_H
#define _PIT_H
//1 头文件
#include "common.h"

//2 宏定义

#define U_PIT0 (0)
#define U_PIT1 (1)
#define U_PIT2 (2)
#define U_PIT3 (3)

//==========================================================================
//函数名称: pit_init
//函数返回: 无
//参数说明: pitNo:表示pit通道号。
//		 timeout:表示定时溢出开始递减的值
//功能概要: 设置相关寄存器的值        
//==========================================================================
void pit_init(uint8_t pitNo, uint32_t timeout);

//==========================================================================
//函数名称: pit_enable_int
//函数返回: 无                                              
//参数说明: pitNo: 表示pit通道号
//功能概要: 开PIT中断                                                                                                     
//==========================================================================
void pit_enable_int(uint8_t pitNo);

//==========================================================================
//函数名称: pit_disable_int
//函数返回: 无                                              
//参数说明: pitNo: 表示pit通道号
//功能概要: 关闭PIT中断                                                                                                     
//==========================================================================
void pit_disable_int(uint8_t pitNo);

#endif //_PIT_H
