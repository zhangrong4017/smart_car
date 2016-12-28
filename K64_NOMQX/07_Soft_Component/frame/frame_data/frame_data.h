//==========================================================================
//文件名称：frame_data.h
//功能概要：组帧通信协议数据组件程序头文件
//==========================================================================

#ifndef _FRAME_DATA_H
#define _FRAME_DATA_H

#include "common.h"
#include "frame.h"

//==========================================================================
//说明: 帧的<数据>字段格式:<数据类型> <数据信息长度> <数据信息>
//     <数据类型>为1个字节，表明该数据的类型;
//     <数据信息长度>为1个字节，表示数据信息的长度，不能超过253;
//     <数据信息>为剩余字节，具体格式由数据类型决定，长度最多不能超过253字节;
//传输顺序: 数据类型-数据信息长度-数据信息低字节-数据信息高字节
//==========================================================================

//定义数据组件所使用的帧类型，不能与其他组件冲突
#define FRAME_DATA_TYPE	(0x03)

//定义帧数据信息结构体，每个帧数据信息结构体占用255字节的RAM
typedef struct {
	uint8 type;		//数据类型
	uint8 len;			//数据信息长度
	uint8 data[253];	//数据信息
} FrameDataInfo;

//定义数据组件发送结果枚举类型
typedef enum {
	DataSendSuccess,	//发送数据成功
	DataSendIllegalLen,	//非法数据信息长度
	DataSendInfoFail	//发送帧信息结构体失败
} FrameDataSendResult;

//定义数据组件解析结果枚举类型
typedef enum {
	DataParseSuccess, 			//数据解析成功
	DataParseWrongType, 		//帧类型错误
	DataParseIllegalInfoLen, 	//帧数据长度非法
	DataParseIllegalDataLen		//数据信息长度非法
} FrameDataParseResult;

//==========================================================================
//函数名称: frame_data_send
//函数返回: 数据发送结果:
//         DataSendSuccess:   发送数据成功;
//         DataSendIllegalLen:非法数据信息长度;
//         DataSendInfoFail:  发送帧信息结构体失败;
//参数说明: data:要发送的帧数据信息结构体
//功能概要: 发送帧数据信息结构体，自动组装帧信息结构体
//备注: 需先使能组帧通信协议
//==========================================================================
FrameDataSendResult frame_data_send(FrameDataInfo data);

//==========================================================================
//函数名称: frame_data_parse
//函数返回: 数据解析结果:
//         DataParseSuccess:       数据解析成功;
//         DataParseWrongType:     帧类型错误;
//         DataParseIllegalInfoLen:帧数据长度非法;
//         DataParseIllegalDataLen:数据信息长度非法;
//参数说明: info:要解析的帧信息结构体
//         data:存储帧数据信息结构体的首地址
//功能概要: 解析帧信息结构体，解析成功时，存储相应帧数据信息结构体
//==========================================================================
FrameDataParseResult frame_data_parse(FrameInfo info, FrameDataInfo* data);

#endif
