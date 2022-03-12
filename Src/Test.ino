#include "My_WiFi.h"
#include "My_Weather.h"
#include "My_Saying.h"
#include "My_Time.h"

#include <Ticker.h>

#define My_SSID "ESP"
#define My_PSK "66666666"


#define WEATHERKEY "SXygZHJn6d3INMfzC"
#define SITE "heze"

My_WiFi IWifi(My_SSID, My_PSK);
My_Weather IWeather(WEATHERKEY, SITE);
My_Saying ISaying("d");
My_Time ITime("getSysTime.do");

Ticker FlushWeather;

void flip()
{
  ISaying.Saying();
  ITime.Time();
  IWeather.Weather();
}

void setup()
{
  Serial.begin(115200, SERIAL_8O2);

  IWifi.Init();    
  IWeather.Init(); 
  ISaying.Init(); 
  ITime.Init(); 

  FlushWeather.attach(60.0, flip);
  ISaying.Saying();
  ITime.Time();
  IWeather.Weather();
}

void loop()
{
    Serial.print("words.txt=\"你好\"");
    Serial.print(0XFF,HEX);
    Serial.print(0XFF,HEX);   
    Serial.print(0XFF,HEX);
}