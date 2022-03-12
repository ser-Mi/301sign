/********************************Copyright (c)**********************************\
**
**                   (c) Copyright 2021, Main, China, QD.
**                           All Rights Reserved
**
**                           By(菏泽学院——————301)
**                           http://
**
**----------------------------------文件信息------------------------------------
** 文件名称: My_Time.h
** 创建人员: Main
** 创建日期: 2021-05-06
** 文档描述:
**
**----------------------------------版本信息------------------------------------
** 版本代号: V0.1
** 版本说明: 初始版本
**
**------------------------------------------------------------------------------
\********************************End of Head************************************/
#ifndef _MY_TIME_H
#define _MY_TIME_H

#include <ArduinoJson.h>
#include <HTTPClient.h>

class My_Time
{
public: // 公有成员
    HTTPClient TimeHttp;
    const char *TimeHOST = "http://quan.suning.com/";  //苏宁
    String TimeGetUrl;                                              //拼接后的天气URL
    char TimeInput[64];

    My_Time(const char *Api);
    void Init();
    void Time();
    void test();
};

#endif /* _MY_TIME_H */
