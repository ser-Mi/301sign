/********************************Copyright (c)**********************************\
**
**                   (c) Copyright 2021, Main, China, QD.
**                           All Rights Reserved
**
**                           By(菏泽学院——————301)
**                           http://
**
**----------------------------------文件信息------------------------------------
** 文件名称: My_saying.h
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
#ifndef MY_SAYING_H
#define MY_SAYING_H

#include <ArduinoJson.h>
#include <HTTPClient.h>

// a  动画
// b 漫画
// c 游戏
// d 文学
// e 原创
// f 来自网络
// g 其他
// h 影视
// i 诗词
// j 网易云
// k 哲学
// l 抖机灵

class My_Saying
{
public: // 公有成员
    HTTPClient SayingHttp;
    const char *SayingHOST = "https://v1.hitokoto.cn"; //心知天气网API
    String SayingGetUrl;                               //拼接后的天气URL
    char SayingInput[512];

    My_Saying(const char *ch);
    void Init();
    void Saying();
    void test();
};

#endif /* MY_WEATHER_H */
