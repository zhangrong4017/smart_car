//==========================================================================
//�ļ����ƣ�crc16_modbus.h
//���ܸ�Ҫ��CRC16_MODBUS��������ͷ�ļ�
//==========================================================================

#ifndef _CRC16_MODBUS_H
#define _CRC16_MODBUS_H

#include "common.h"

//==========================================================================
//˵��: ����MODBUS��׼��CRC-16У�飬���ɶ���ʽΪx^16+x^15+x^2+1�����ʽΪ0x8005
//==========================================================================

//�����ֽ�����ʽУ�����ݵĳ�ʼCRCУ����ֵ
#define CRC16_MODBUS_STREAM_INIT_CRC	(0xFFFF)

//==========================================================================
//��������: crc16_modbus_block
//��������: 16λ��CRCУ����
//����˵��: data:У�����ݵ��׵�ַ
//         len:У�����ݵ��ֽ���
//���ܸ�Ҫ: У��һ�����ȵ����ݣ��������ɵ�16λCRCУ����
//==========================================================================
uint16 crc16_modbus_block(uint8* data, uint32 len);

//==========================================================================
//��������: crc16_modbus_stream
//��������: �����ɵ�16λCRCУ����
//����˵��: last_crc:��һ�ε�CRCУ����
//         data:У������
//���ܸ�Ҫ: ���ֽ����ķ�ʽУ�����ݣ����������ɵ�16λCRCУ����
//��ע: �״�У��ʱ��last_crcΪ CRC16_MODBUS_STREAM_INIT_CRC(0xFFFF);
//     ������У��ʱ����У�����յ�������
//==========================================================================
uint16 crc16_modbus_stream(uint16 last_crc, uint8 data);

#endif