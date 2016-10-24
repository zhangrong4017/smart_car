//==============================================================
//�ļ����ƣ�reed_switch.h
//���ܸ�Ҫ���ɻɹ�ͷ�ļ�
//��Ȩ���У����ݴ�ѧ��˼����Ƕ��ʽ����(sumcu.suda.edu.cn)
//==============================================================

#ifndef _REED_SWITCH_H
#define _REED_SWITCH_H

#include "common.h"    //��������Ҫ��ͷ�ļ�
#include "gpio.h"

//�ɻɹ�����������Ŷ���
#define REED_SWITCH_INPUT  (COM_PORTD|2)
#define REED_SWITCH_OUTPUT (COM_PORTD|3)

//==============================================================
//�������ƣ�reed_switch_init
//�������أ���
//����˵������
//���ܸ�Ҫ���ɻɹܳ�ʼ��������GPIO������ɶԸɻɹܵĳ�ʼ�������������
//==============================================================
void reed_switch_init(void);

//==============================================================
//�������ƣ�reed_switch_enable_int
//�������أ���
//����˵������
//���ܸ�Ҫ���ɻɹ������ж�ʹ�ܡ����������
//==============================================================
void reed_switch_enable_int(void);

#endif /* _REED_SWITCH_H */