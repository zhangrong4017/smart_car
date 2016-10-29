//==========================================================================
//文件名称：pit.h
//功能概要：K64 PIT底层驱动程序头文件
//==========================================================================

#ifndef _PIT_H
#define _PIT_H

//包含公共头文件
#include "common.h"

//定义PIT模块的通道号
#define PIT_CH0 (0)			//PIT模块0通道
#define PIT_CH1 (1)			//PIT模块1通道
#define PIT_CH2 (2)			//PIT模块2通道
#define PIT_CH3 (3)			//PIT模块3通道

//定义PIT模块工作时钟频率，其使用的是总线时钟，单位kHz（FREQ为frequency简写）
#define PIT_WORK_FREQ	BUS_CLK_KHZ

//==========================================================================
//函数名称: pit_init
//函数返回: 无
//参数说明: ch:PIT通道号，PIT_CHx，x为通道号
//         ms:该通道产生中断的时间周期，单位ms，范围0-89478ms
//功能概要: PIT模块通道初始化，默认关闭中断
//==========================================================================
void pit_init(uint8 ch, uint32 ms);

//==========================================================================
//函数名称: pit_enable_int
//函数返回: 无                                              
//参数说明: ch:PIT通道号，PIT_CHx，x为通道号
//功能概要: 使能PIT通道中断
//==========================================================================
void pit_enable_int(uint8 ch);

//==========================================================================
//函数名称: pit_disable_int
//函数返回: 无                                              
//参数说明: ch:PIT通道号，PIT_CHx，x为通道号
//功能概要: 关闭PIT通道中断
//==========================================================================
void pit_disable_int(uint8 ch);

//==========================================================================
//函数名称: pit_get_int
//函数返回: true:该通道产生中断; false:该通道未产生中断
//参数说明: ch:PIT通道号，PIT_CHx，x为通道号
//功能概要: 获取PIT通道中断标志
//==========================================================================
bool pit_get_int(uint8 ch);

//==========================================================================
//函数名称: pit_disable_int
//函数返回: 无
//参数说明: ch:PIT通道号，PIT_CHx，x为通道号
//功能概要: 清除PIT通道中断标志
//==========================================================================
void pit_clear_int(uint8 ch);

#endif
