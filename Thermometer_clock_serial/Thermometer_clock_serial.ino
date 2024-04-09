#include <Wire.h>   // Library I2C comunicacion
#include <RTClib.h> // Library RTC
#include <DHT.h>    // Library DHT

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  if(! rtc.begin()) {
    Serial.println("RTC is not find");
  while(1);
    }
  rtc.adjust(DateTime(__DATE__,__TIME__));
}

void loop() {
  DateTime date = rtc.now();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
   
  Serial.print(date.day());
  Serial.print("/");
  Serial.print(date.month());
  Serial.print("/");
  Serial.print(date.year());
  Serial.print(" ");
  Serial.print(date.hour());
  Serial.print(":");
  Serial.print(date.minute());
  Serial.print(":");
  Serial.println(date.second());
  
  Serial.print("Temperature: ");  // Write the text
  Serial.print(t);
  Serial.println(" ºC ");
  Serial.println(" ");
  delay(900000);                  // Wait 15 minutes
}
