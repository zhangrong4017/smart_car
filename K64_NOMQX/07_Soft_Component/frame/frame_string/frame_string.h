//==========================================================================
//文件名称：frame_string.h
//功能概要：组帧通信协议字符串组件程序头文件
//==========================================================================

#ifndef _FRAME_STRING_H
#define _FRAME_STRING_H

#include "common.h"
#include "frame.h"

//==========================================================================
//说明: 帧的<数据>字段存储的是一个不含'\0'的字符串;
//     字符串长度不能超过255字节，不包括'\0';
//     允许存储空字符串;
//传输顺序: 字符串头-字符串尾，如:"KamiJ"，最先传输K，最后传输J
//==========================================================================

//定义字符串组件所使用的帧类型，不能与其他组件冲突
#define FRAME_STRING_TYPE	(0x00)

//定义字符串组件发送结果枚举类型
typedef enum {
	StringSendSuccess,			//发送字符串成功
	StringSendIllegalString,	//非法字符串，即字符串长度超过255字节
	StringSendInfoFail			//发送帧信息结构体失败
} FrameStringSendResult;

//定义字符串组件解析结果枚举类型
typedef enum {
	StringParseSuccess, 		//字符串解析成功
	StringParseWrongType, 		//帧类型错误
	StringParseIllegalString	//字符串非法，即在帧指示的字符串长度内出现'\0'
} FrameStringParseResult;

//==========================================================================
//函数名称: frame_string_send
//函数返回: 字符串发送结果:
//         StringSendSuccess:      发送字符串成功;
//         StringSendIllegalString:非法字符串，即字符串长度超过255字节;
//         StringSendInfoFail:     发送帧信息结构体失败;
//参数说明: str:要发送的字符串首地址
//功能概要: 发送以'\0'结束的字符串，自动组装帧信息结构体
//备注: 需先使能组帧通信协议;字符串长度不能超过255字节，不包括'\0'，不发送'\0'
//==========================================================================
FrameStringSendResult frame_string_send(uint8* str);

//==========================================================================
//函数名称: frame_string_parse
//函数返回: 字符串解析结果:
//         StringParseSuccess:      字符串解析成功;
//         StringParseWrongType:    帧类型错误;
//         StringParseIllegalString:字符串非法，即在帧指示的字符串长度内出现'\0';
//参数说明: info:要解析的帧信息结构体
//         str:存储字符串的首地址
//功能概要: 解析帧信息结构体，解析成功时，存储相应字符串
//备注: 会自动在字符串结束时添加'\0'
//==========================================================================
FrameStringParseResult frame_string_parse(FrameInfo info, uint8* str);

#endif
