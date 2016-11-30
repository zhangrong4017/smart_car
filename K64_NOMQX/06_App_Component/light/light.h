//==========================================================================
//文件名称：light.h
//功能概要：小灯应用驱动程序头文件
//==========================================================================

#ifndef _LIGHT_H
#define _LIGHT_H

#include "common.h"
#include "gpio.h"

//定义小灯所使用引脚
#define LIGHT_RED      (COM_PORTD|3)   //D3，红灯
#define LIGHT_GREEN    (COM_PORTD|4)   //D4，绿灯
#define LIGHT_BLUE     (COM_PORTD|5)   //D5，蓝灯

//定义小灯状态
#define LIGHT_ON	GPIO_LEVEL_LOW	//低电平时灯亮
#define LIGHT_OFF	GPIO_LEVEL_HIGH	//高电平时灯暗

//==========================================================================
//函数名称: light_init
//函数返回: 无
//参数说明: light:小灯:
//               LIGHT_RED:  红灯;
//               LIGHT_GREEN:绿灯;
//               LIGHT_BLUE: 蓝灯;
//         state:小灯初始状态:
//               LIGHT_ON: 灯亮;
//               LIGHT_OFF:灯暗;
//功能概要: 初始化小灯，并设置初始状态
//==========================================================================
void light_init(uint8 light, uint8 state);

//==========================================================================
//函数名称: light_set
//函数返回: 无
//参数说明: light:小灯:
//               LIGHT_RED:  红灯;
//               LIGHT_GREEN:绿灯;
//               LIGHT_BLUE: 蓝灯;
//         state:小灯状态:
//               LIGHT_ON: 灯亮;
//               LIGHT_OFF:灯暗;
//功能概要: 设置小灯状态，小灯需要被初始化
//==========================================================================
void light_set(uint8 light, uint8 state);

//==========================================================================
//函数名称: light_change
//函数返回: 无
//参数说明: light:小灯:
//               LIGHT_RED:  红灯;
//               LIGHT_GREEN:绿灯;
//               LIGHT_BLUE: 蓝灯;
//功能概要: 切换小灯状态，小灯需要被初始化
//==========================================================================
void light_change(uint8 light);

#endif
