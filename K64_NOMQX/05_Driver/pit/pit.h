//==========================================================================
//文件名称：pit.h
//功能概要：K64 PIT底层驱动程序头文件
//==========================================================================

#ifndef _PIT_H
#define _PIT_H

//包含公共头文件
#include "common.h"

//定义PIT模块的通道号
#define PIT_CH0 (0)
#define PIT_CH1 (1)
#define PIT_CH2 (2)
#define PIT_CH3 (3)

//定义PIT模块工作时钟频率，其使用的是总线时钟，单位kHz（FREQ为frequency简写）
#define PIT_WORK_FREQ	BUS_CLK_KHZ

//定义PIT模块中断标志（INT为interruption简写）
#define PIT_INT_TRUE	(1)
#define PIT_INT_FALSE	(0)

//==========================================================================
//函数名称: pit_init
//函数返回: 无
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//       ms:该通道产生中断的时间周期，单位ms，范围0-71582ms
//功能概要: PIT模块通道初始化
//==========================================================================
void pit_init(uint8 PIT_CHx, uint32 ms);

//==========================================================================
//函数名称: pit_enable_int
//函数返回: 无                                              
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 使能PIT通道中断
//==========================================================================
void pit_enable_int(uint8 PIT_CHx);

//==========================================================================
//函数名称: pit_disable_int
//函数返回: 无                                              
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 关闭PIT通道中断
//==========================================================================
void pit_disable_int(uint8 PIT_CHx);

//==========================================================================
//函数名称: pit_get_int
//函数返回: PIT_INT_TRUE:该通道产生中断；PIT_INT_FALSE:该通道未产生中断
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 获取PIT通道中断标志
//==========================================================================
uint8 pit_get_int(uint8 PIT_CHx);

//==========================================================================
//函数名称: pit_disable_int
//函数返回: 无
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 清除PIT通道中断标志
//==========================================================================
void pit_clear_int(uint8 PIT_CHx);

#endif
