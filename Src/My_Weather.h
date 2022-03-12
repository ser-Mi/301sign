/********************************Copyright (c)**********************************\
**
**                   (c) Copyright 2021, Main, China, QD.
**                           All Rights Reserved
**
**                           By(菏泽学院——————301)
**                           http://
**
**----------------------------------文件信息------------------------------------
** 文件名称: My_Weather.h
** 创建人员: Main
** 创建日期: 2021-05-05
** 文档描述:
**
**----------------------------------版本信息------------------------------------
** 版本代号: V0.1
** 版本说明: 初始版本
**
**------------------------------------------------------------------------------
\********************************End of Head************************************/
#ifndef _MY_WEATHER_H
#define _MY_WEATHER_H

// SXygZHJn6d3INMfzC
// 菏泽
#include <ArduinoJson.h>
#include <HTTPClient.h>

typedef struct weather
{
/*
    JsonObject results_0 = doc["results"][0];

    JsonObject results_0_location = results_0["location"];
    const char *results_0_location_id = results_0_location["id"];                           // "WW607X60CDS4"
    const char *results_0_location_name = results_0_location["name"];                       // "菏泽"
    const char *results_0_location_country = results_0_location["country"];                 // "CN"
    const char *results_0_location_path = results_0_location["path"];                       // "菏泽,菏泽,山东,中国"
    const char *results_0_location_timezone = results_0_location["timezone"];               // "Asia/Shanghai"
    const char *results_0_location_timezone_offset = results_0_location["timezone_offset"]; // "+08:00"

    JsonObject results_0_now = results_0["now"];
    const char *results_0_now_text = results_0_now["text"];               // "阴"
    const char *results_0_now_code = results_0_now["code"];               // "9"
    const char *results_0_now_temperature = results_0_now["temperature"]; // "23"

    const char *results_0_last_update = results_0["last_update"]; // "2021-05-06T10:15:00+08:00"

    // char pressure;              //气压，单位为mb百帕或in英寸
    // uint16_t humidity;              //相对湿度，0~100，单位为百分比
    // char wind_direction[6];         //风向文字
    // uint16_t wind_direction_degree; //风向角度，范围0~360，0为正北，90为正东，180为正南，270为正西
    // char wind_speed[4];             //风速，单位为km/h公里每小时或mph英里每小时
    // char wind_scale[2];             //风力等级
    // char feels_like[2];             //体感温度，单位为c摄氏度或f华氏度
*/
    char location[6];               //城市中文名
    char nowtext[21];                //天气现象文字
    char nowcode[2];                //天气现象代码
    char temperature[2];            //温度，单位为c摄氏度或f华氏度
    char last_update[25];           //数据更新时间
    int httpcode;
} WeatherStruct;

class My_Weather
{
public: // 公有成员
    HTTPClient WeatherHttp;
    const char *WeatherHOST = "http://api.seniverse.com/"; //心知天气网API
    String WeatherGetUrl;                                 //拼接后的天气URL
    const char *language = "zh-Hans";
    char WeatherInput[256];

    My_Weather(const char *ApiKey, const char *location);   // 个人密钥 查询位置
    void Init();
    void Weather();                                         // 打印所需的内容
    void test();
};

#endif /* MY_WEATHER_H */
