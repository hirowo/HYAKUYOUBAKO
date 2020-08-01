
#include<dht.h>
#include <TinyWireM.h> 
#include <ST7032.h>
#define DHT11PIN 0

ST7032 lcd;
dht DHT11;

void setup() {
  pinMode(1,OUTPUT);
  digitalWrite(1,HIGH);
}

void loop() {
  float sokuteiti;
  String str;

  // 温度と湿度を測定:
  DHT11.read11(DHT11PIN);
  delay(1000);
 
  //表示する
  lcd.begin(8, 2);
  lcd.setContrast(40);
  //1行目/
  sokuteiti = DHT11.temperature;
  lcd.setCursor(0,0);
  str= String(sokuteiti);
  lcd.printf( str.c_str());
 //2行目
  sokuteiti = DHT11.humidity;
  lcd.setCursor(0,1);
  str = String(sokuteiti);
  lcd.printf( str.c_str());
  delay(1000);

}
