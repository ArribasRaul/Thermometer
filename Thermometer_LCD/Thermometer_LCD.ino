#include <Wire.h>               // Library I2C comunicacion
#include <LCD.h>                // Library LCD funtions
#include <LiquidCrystal_I2C.h>  // Library I2C LCD display 
#include <DHT.h>                // Library DHT

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7);  // DIR, E, RW, RS, D4, D5, D6, D7

void setup() {
 Serial.begin(9600);
  dht.begin();
 
  lcd.setBacklightPin(3,POSITIVE);  // P3 port PCF8574 - positive
  lcd.setBacklight(HIGH);           // LCD light on
  lcd.begin(16, 2);                 // 16 columns x 2 rows - LCD 1602A
  lcd.clear();                      // Clear display
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  lcd.setCursor(0, 0);        // Start at column 0 and row 0
  lcd.print("Temperature: "); // Write the text
  lcd.print(t);
  lcd.setCursor(0, 1);        // Start at column 0 and row 1
  lcd.print("Humidity: "); 
  lcd.print(h); 
}
