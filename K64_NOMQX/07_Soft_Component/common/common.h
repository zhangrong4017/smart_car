//==========================================================================
//�ļ����ƣ�common.h
//���ܸ�Ҫ��ͨ���ļ���ͷ�ļ�
//==========================================================================

#ifndef _COMMON_H
#define _COMMON_H

//оƬ�Ĵ���ӳ���ļ����������ں������ļ�
#include "core_cmFunc.h"
#include "core_cmInstr.h"
#include "core_cm4.h"
#include "core_cmSimd.h"
#include "MK64F12.h"           //����оƬͷ�ļ�
#include "system_MK64F12.h"    //����оƬϵͳ��ʼ���ļ�

//���忪���ж�
#define ENABLE_INTERRUPTS   __enable_irq   //�����ж�
#define DISABLE_INTERRUPTS  __disable_irq  //�����ж�
#define ENABLE_IRQ(IRQn)	NVIC_EnableIRQ(IRQn)	//���������ж������ΪIRQn���жϣ��ж�����ŵĶ�����"MK64F12.h"��171��
#define DISABLE_IRQ(IRQn)	NVIC_DisableIRQ(IRQn)	//��ֹ�����ж������ΪIRQn���ж�

//�Ĵ��������꺯��
//����ƫ�ƽ��в���
#define REG_SET_SHIFT(reg,shift)	((reg) |= (0x1 << (shift)))		//�üĴ�����һλ
#define REG_CLR_SHIFT(reg,shift)	((reg) &= ~(0x1 << (shift)))	//��Ĵ�����һλ
#define REG_GET_SHIFT(reg,shift)	(((reg) >> (shift)) & 0x1)		//��ȡ�Ĵ���һλ��״̬
//����������в���
#define REG_SET_MASK(reg,mask)		((reg) |= (mask))				//�üĴ���������λ
#define REG_CLR_MASK(reg,mask)		((reg) &= ~(mask))				//��Ĵ���������λ
#define REG_GET_MASK(reg,mask)		((reg) & (mask))				//��ȡ�Ĵ�������λ��ֵ
//���üĴ�����ֵ
#define REG_SET_VAL(reg,val)		((reg) = (val))

//�ض�������������ͣ����ͱ����궨�壩
typedef unsigned char uint8;		//�޷���8λ�����ֽ�
typedef unsigned short int uint16;	//�޷���16λ������
typedef unsigned long int uint32;	//�޷���32λ��������
typedef unsigned long long uint64;	//�޷���64λ����������

typedef signed char int8;			//�з��ŵ�8λ�����ֽ�
typedef signed short int int16;		//�з��ŵ�16λ������
typedef signed long int int32;		//�з��ŵ�32λ��������
typedef signed long long int64;		//�з��ŵ�64λ����������

typedef volatile uint8 vuint8;		//���Ż��޷���8λ�����ֽ�
typedef volatile uint16 vuint16;	//���Ż��޷���16λ������
typedef volatile uint32 vuint32;	//���Ż��޷���32λ��������
typedef volatile uint64 vuint64;	//���Ż��޷���64λ����������

typedef volatile int8 vint8;		//���Ż��з���8λ�����ֽ�
typedef volatile int16 vint16;		//���Ż��з���16λ������
typedef volatile int32 vint32;		//���Ż��з���32λ��������
typedef volatile int64 vint64;		//���Ż��з���64λ����������

//����ϵͳʹ�õ�ʱ��Ƶ��
#define  SYSTEM_CLK_KHZ   (SystemCoreClock/1000)     //оƬϵͳʱ��Ƶ��(KHz)
#define  BUS_CLK_KHZ      (SYSTEM_CLK_KHZ/2)         //оƬ����ʱ��Ƶ��(KHz)

//�˿ںŵ�ַƫ�����궨�壬������COM_PORTA|0��ֵ��ʾA�˿�0���ţ�
//Ϊ�˷�ֹ�궨���������������Ӧ�ļ������ƣ������COMΪcommon�ļ�д
#define COM_PORTA     (0<<8)
#define COM_PORTB     (1<<8)
#define COM_PORTC     (2<<8)
#define COM_PORTD     (3<<8)
#define COM_PORTE     (4<<8)

#endif