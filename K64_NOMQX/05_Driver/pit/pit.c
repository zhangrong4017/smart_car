//==========================================================================
//文件名称：pit.h
//功能概要：K64 PIT底层驱动程序源文件
//==========================================================================

#include "pit.h"

//PIT模块各通道的中断请求号
static const IRQn_Type pit_irq[4] =
		{ PIT0_IRQn, PIT1_IRQn, PIT2_IRQn, PIT3_IRQn };

//==========================================================================
//函数名称: pit_init
//函数返回: 无
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//       ms:该通道产生中断的时间周期，单位ms，范围0-89478ms
//功能概要: PIT模块通道初始化
//==========================================================================
void pit_init(uint8 PIT_CHx, uint32 ms) {
	uint32 load_value;		//该通道加载值寄存器的值

	REG_SET_MASK(SIM_SCGC6, SIM_SCGC6_PIT_MASK);	//开PIT时钟门
	REG_CLR_MASK(PIT_MCR, PIT_MCR_MDIS_MASK);		//PIT模块定时器时钟使能
	REG_SET_MASK(PIT_MCR, PIT_MCR_FRZ_MASK);		//在调试模式下定时器停止
	load_value = PIT_WORK_FREQ * ms;	//根据产生中断的时间周期计算加载值寄存器的值
	REG_SET_VAL(PIT_LDVAL(PIT_CHx), load_value);	//设置该通道加载值寄存器的值
	REG_SET_MASK(PIT_TCTRL(PIT_CHx), PIT_TCTRL_TEN_MASK);	//该通道定时器时钟使能
	REG_CLR_MASK(PIT_TCTRL(PIT_CHx), PIT_TCTRL_TIE_MASK);	//禁止该通道发送中断请求
}

//==========================================================================
//函数名称: pit_enable_int
//函数返回: 无                                              
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 使能PIT通道中断
//==========================================================================
void pit_enable_int(uint8 PIT_CHx) {
	REG_SET_MASK(PIT_TFLG(PIT_CHx), PIT_TFLG_TIF_MASK);	//先清除该通道中断标志，以防止使能中断后立即产生中断
	REG_SET_MASK(PIT_TCTRL(PIT_CHx), PIT_TCTRL_TIE_MASK);	//允许该通道发送中断请求
	ENABLE_IRQ(pit_irq[PIT_CHx]);							//允许接收该通道发送的中断请求
}

//==========================================================================
//函数名称: pit_disable_int
//函数返回: 无                                              
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 关闭PIT通道中断
//==========================================================================
void pit_disable_int(uint8 PIT_CHx) {
	REG_CLR_MASK(PIT_TCTRL(PIT_CHx), PIT_TCTRL_TIE_MASK);	//禁止该通道发送中断请求
	DISABLE_IRQ(pit_irq[PIT_CHx]);							//禁止接收该通道发送的中断请求
}

//==========================================================================
//函数名称: pit_get_int
//函数返回: PIT_INT_TRUE:该通道产生中断；PIT_INT_FALSE:该通道未产生中断
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 获取PIT通道中断标志
//==========================================================================
uint8 pit_get_int(uint8 PIT_CHx) {
	//获取该通道定时器标志寄存器中中断标志的值，并根据值判断是否产生中断
	return REG_GET_MASK(PIT_TFLG(PIT_CHx),
			PIT_TFLG_TIF_MASK) == PIT_TFLG_TIF_MASK ?
			PIT_INT_TRUE : PIT_INT_FALSE;
}

//==========================================================================
//函数名称: pit_disable_int
//函数返回: 无
//参数说明: PIT_CHx:PIT通道号，请使用宏定义
//功能概要: 清除PIT通道中断标志
//==========================================================================
void pit_clear_int(uint8 PIT_CHx) {
	REG_SET_MASK(PIT_TFLG(PIT_CHx), PIT_TFLG_TIF_MASK);	//清除该通道中断标志
}
