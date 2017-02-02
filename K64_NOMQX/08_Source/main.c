//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//============================================================================

#define GLOBLE_VAR  //只需在main.c中定义一次，用来防止全局变量的重复定义

#include "includes.h"   //包含总头文件

int main(void) {
	//1. 声明主函数使用的变量
	uint8 light_state;		//当前灯状态
	uint32 crc;
	uint8 data[1024];
	uint32 stream;
	uint32 reg;
	uint32 i, j;
	float temp;
	FrameInfo frame;
	FrameCmdInfo cmd;
	double d;
	float f;
	uint16 crcres;
	uint8 uvar8;
	uint16 uvar16;
	uint32 uvar32;
	uint32 uvar322;
	int8 var8;
	int16 var16;
	int32 var32;
	uint32 addr;
	uint8* ptr;
	uint16 offset;
	uint16 num;
	uint8 sector;
	FlashResult result;
	uint8 dflash_size;
	uint8 eeprom_size;
	uint8 eeprom_split;
	uint32* ptr32;

	/* 小车相关参数变量 */
	Car car;

	/*串口调试工具用临时变量*/
	float data_out[4];

	//2. 关总中断
	DISABLE_INTERRUPTS;
//vsprintf()
	//3. 初始化外设模块
	light_init(LIGHT_BLUE, LIGHT_ON); //蓝灯初始化
//	light_init(LIGHT_GREEN, LIGHT_OFF);
//	light_init(LIGHT_RED, LIGHT_OFF);
			//light_init(LIGHT_BLUE, LIGHT_OFF);
//	uart_init(UART_USE, 9600, UART_PARITY_DISABLED, UART_STOP_BIT_1,
//	UART_BIT_ORDER_LSB); //uart1初始化，蓝牙用，蓝牙模块波特率9600，无法在5ms中断中传输数据
//	uart_init(UART_USE, 115200);   //uart1初始化，串口用
	pit_init(PIT_CH0, 5);  //pit0初始化，周期5ms
	pit_init(PIT_CH1, 89478);
//	gpio_init(COM_PORTC | 0, GPIO_OUTPUT, GPIO_LEVEL_LOW);
//	gpio_init(COM_PORTB | 19, GPIO_OUTPUT, GPIO_LEVEL_LOW);
//	pit_init(PIT_CH2,1);
	rng_init();
//	motor_init(MOTOR0);			//左电机初始化
//	motor_init(MOTOR1);			//右电机初始化
//	gyro_acce_init();			//陀螺仪加速度计初始化
//	encoder_init(ENCODER0);		//左编码器初始化
//	encoder_init(ENCODER1);		//右编码器初始化
//	ems_init();					//电磁传感器初始化
//	reed_switch_init();			//干簧管初始化
//ftm_init(FTM_MOD0,FTM_CLK_DIV_128,FTM_COUNTER_MODE_UP,100000);
//
//ftm_pwm_single_init(FTM_MOD0,FTM_CH4,FTM_PWM_MODE_EDGE_ALIGNED,FTM_PWM_POL_NEGATIVE,5000);

//ftm_oc_init(FTM_MOD0,FTM_CH4,FTM_OC_MODE_TOGGLE,5000);

//	crc_init_protocol(CRC_CRC16_MODBUS);
	frame_init();

//	spi_master_init(SPI_MOD2, SPI_CONFIG0, SPI_BAUD_SCALER_12,
//	SPI_FORMAT_CPOL0_CPHA0, 8, SPI_BIT_ORDER_MSB,
//	SPI_DELAY_SCALER_12, SPI_DELAY_SCALER_12,
//	SPI_DELAY_SCALER_12);
	oled_init();
	//4. 给有关变量赋初值
	time0_flag.f_1s = 0;
	time0_flag.f_50ms = 0;
//	d = 1.3;
	f = 1.3f;
	//5. 使能模块中断
	pit_enable_int(PIT_CH0);   		//使能pit中断
//	pit_enable_int(PIT_CH2);   		//使能pit中断
//	uart_enable_re_int(UART_USE);   //使能uart1接收中断
	frame_enable_re_int();
//	reed_switch_enable_int();
//	ftm_timer_enable_int(FTM_MOD0,10);

	frame.len = 255;
	memset(data, 0xEE, 1024);
//	FMC_PFB0CR |= FMC_PFB0CR_S_B_INV_MASK;
	uint8 read_data[1024];
	memset(read_data, 0xCC, 1024);

	cmd.type = 0x00;
	cmd.len = 1;
	cmd.data[0] = 7;

//	oled_display_str(0, 0, "123");
//	oled_display_str(0, 2, "happy new year:)");
//	oled_display_str(0, 6, "happy new year:)");
//	oled_set_scroll(OLED_SCROLL_DIR_RIGHT, OLED_PAGE0, OLED_PAGE1,
//	OLED_SCROLL_INTERVAL_FRAMES_2);
//	oled_set_start_line(16);
//	oled_set_scroll_with_vertical(OLED_SCROLL_DIR_RIGHT, 2, 3,
//			OLED_SCROLL_INTERVAL_FRAMES_25, 0, 16, 1);
//	oled_scroll_start();

	i = 1;

//	result = flash_partition(FLASH_DFLASH_SIZE_32, FLASH_EEPROM_SIZE_128,
//			FLASH_EEPROM_SPLIT_1_7);
//	uart_send1(UART_USE, result);


	oled_set_scroll(OLED_SCROLL_DIR_LEFT,0,1,OLED_SCROLL_INTERVAL_FRAMES_2);
	oled_set_contrast(255);
//	oled_set_display_clk(15,2);
//	oled_set_precharge_period(8,8);
//	oled_set_remap(false,false);
//

//	oled_display_str(0, 2, "123");

//	oled_set_multiplex_ratio(48);
//	oled_display_str(0, 0, "1");
//	oled_display_str(0, 2, "2");
//	oled_display_str(0, 4, "3");
//	oled_display_str(0, 6, "4");
//	oled_set_display_offset(16);

	//6. 开总中断
	ENABLE_INTERRUPTS;

	//进入主循环
	//主循环开始==================================================================
	for (;;) {

		if (time0_flag.f_50ms) {
			time0_flag.f_50ms = 0;
		}
		if (time0_flag.f_1s) {
			time0_flag.f_1s = 0;
			light_change(LIGHT_BLUE);

			uvar32 = pit_get_time_us(1);

			f = arm_sin_f32(f);

			ptr32 = (uint32*)malloc(sizeof(uint32)*1024);
			uart_send1(1,ptr32[0]);
//			if (i == 1) {
//				oled_set_contrast(0);
////				oled_scroll_stop();
//				i = 0;
//			} else {
//				oled_set_contrast(255);
////				oled_scroll_start();
//				i = 1;
//			}

//			oled_display_str(0, 0, "[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
//			oled_scroll_start();
//			pit_delay_ms(1, 1000);
//
//
//
//			oled_scroll_stop();
//			pit_delay_ms(1, 1000);

			uvar322 = pit_get_time_us(1);
//			printf("%d\r\n", (int32) (uvar322 - uvar32));

		}

//		//处理接收到的帧
//		if (frame_get_info(&frame)) {
//			//根据帧的类型做相应操作
//			switch (frame.type) {
//			case FRAME_STRING_TYPE:	//字符串帧
//				//发送字符串回去
//				frame_send_info(frame);
//				break;
//			case FRAME_CMD_TYPE:	//命令帧
//				//解帧，获取命令信息
//				if (frame_cmd_parse(frame, &cmd) == CmdParseSuccess) {
//					//解帧成功时，根据命令类型做相应操作
//					switch (cmd.type) {
//					case 0x00:	//设置灯状态
//
//						//light_state位0表示蓝灯状态，位1表示绿灯状态，位2表示红灯状态
//						cmd.data[0] & 0x1 ?
//								light_set(LIGHT_BLUE, LIGHT_ON) :
//								light_set(LIGHT_BLUE, LIGHT_OFF);
//						cmd.data[0] & 0x2 ?
//								light_set(LIGHT_GREEN, LIGHT_ON) :
//								light_set(LIGHT_GREEN, LIGHT_OFF);
//						cmd.data[0] & 0x4 ?
//								light_set(LIGHT_RED, LIGHT_ON) :
//								light_set(LIGHT_RED, LIGHT_OFF);
//						break;
//					}
//				}
//				break;
//			}
//		}

	} //主循环end_for
//主循环结束==================================================================
}
