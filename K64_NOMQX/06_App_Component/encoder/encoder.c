//============================================================================
//文件名称：encoder.c
//功能概要：编码器源文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2013-02-02   V2.0
//============================================================================

#include "encoder.h"

//============================================================================
//函数名称：encoder_init
//函数参数：port_pin：设定接收速度信号的的引脚，
//          格式为：(端口号)|(引脚号)（如：(U_PORTD)|(1) 表示为D口一号脚）
//函数返回：无
//功能概要：编码器初始化。
//============================================================================
void encoder_init(uint16_t port_pin)
{
	//对应引脚的初始化，配置
	gpio_init(port_pin, GPIO_IN, 0);			//将传入的引脚初始化为输入，初始状态为低电平
	gpio_pull(port_pin, 1);						//将传入的引脚拉高电平
}

//============================================================================
//函数名称：encoder_get_speed
//函数参数：conter:一个采集周期内编码器脉冲个数
//		 speed:存放该编码器对应轮子速度的指针，单位m/s
//函数返回：无
//功能概要：获得当前速度。
//============================================================================
void encoder_get_speed(uint16_t conter, float *speed)
{
	// 根据齿轮半径求出速度
	*speed = (conter / (ENCODER_RES * 1.0)) * (6.28 * ENCODER_GEAR_R) / ENCODER_PERIOD;//2 * PI = 6.28
}

//============================================================================
//函数名称：encoder_enable_int
//函数参数：port_pin：想要开启中断的引脚，
//          格式为：(端口号)|(引脚号)（如：(U_PORTD)|(1) 表示为D口一号脚）
//函数返回：无
//功能概要：开启引脚中断。
//============================================================================
void encoder_enable_int(uint16_t port_pin)
{
	gpio_enable_int(port_pin, FALLING_EDGE);	//引脚中断类型设定为下降沿触发
}

//============================================================================
//函数名称：encoder_disable_int
//函数参数：port_pin：想要关闭中断的引脚，
//          格式为：(端口号)|(引脚号)（如：(U_PORTD)|(1) 表示为D口一号脚）
//函数返回：无
//功能概要：关闭引脚中断。
//============================================================================
void encoder_disable_int(uint16_t port_pin)
{
	gpio_disable_int(port_pin);
}
