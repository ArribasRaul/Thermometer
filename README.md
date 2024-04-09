# Arduino Thermometer Projects

This repository contains two Arduino projects for temperature measurement using different components: one with an LCD display (`Thermometer_LCD`) and another with a real-time clock and serial output (`Thermometer_clock_serial`).

## Thermometer_LCD

### Description
The `Thermometer_LCD` project utilizes an Arduino board along with a DHT11 temperature and humidity sensor to measure environmental conditions. The measured data is displayed on a 16x2 LCD screen using I2C communication. This project demonstrates how to interface with an LCD display and read sensor data from a DHT11 sensor.

### Components Used
- Arduino board
- DHT11 temperature and humidity sensor
- 16x2 LCD display with I2C backpack
- Libraries: Wire.h, LCD.h, LiquidCrystal_I2C.h, DHT.h

### Setup
1. Connect the DHT11 sensor and LCD display to the Arduino board.
2. Upload the `Thermometer_LCD` sketch to the Arduino.
3. View temperature and humidity readings on the LCD display.

## Thermometer_clock_serial

### Description
The `Thermometer_clock_serial` project combines temperature measurement using the DHT11 sensor with real-time clock functionality provided by the DS3231 RTC module. The Arduino reads temperature and humidity data periodically and timestamps the readings with the current date and time from the RTC. The data is then transmitted over the serial port for monitoring or logging purposes.

### Components Used
- Arduino board
- DHT11 temperature and humidity sensor
- DS3231 RTC module
- Libraries: Wire.h, RTClib.h, DHT.h

### Setup
1. Connect the DHT11 sensor and DS3231 RTC module to the Arduino board.
2. Upload the `Thermometer_clock_serial` sketch to the Arduino.
3. Monitor temperature, humidity, and timestamped data through the Arduino Serial Monitor.

## License
These projects are open-source and available under the [MIT License](LICENSE).
