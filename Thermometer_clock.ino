#include <Wire.h>
#include <RTClib.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  if(! rtc.begin()) {
    Serial.println("Modulo RTC no encontrado");
  while(1);
    }
  rtc.adjust(DateTime(__DATE__,__TIME__));
}

void loop() {
  DateTime fecha = rtc.now();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
   
  Serial.print(fecha.day());
  Serial.print("/");
  Serial.print(fecha.month());
  Serial.print("/");
  Serial.print(fecha.year());
  Serial.print(" ");
  Serial.print(fecha.hour());
  Serial.print(":");
  Serial.print(fecha.minute());
  Serial.print(":");
  Serial.println(fecha.second());
  
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" ºC ");
  Serial.println(" ");
  delay(900000);
}
