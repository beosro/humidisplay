#include <Wire.h>
#include <arduino.h>
#include "SHT21.h"

SHT21::SHT21 () {
  Wire.begin();
  Wire.beginTransmission(si7021Addr);
  Wire.endTransmission();
}

float SHT21::getHumidity(void) {
  unsigned int data[2];

  Wire.beginTransmission(si7021Addr);
  //Send humidity measurement command
  Wire.write(0xF5);
  Wire.endTransmission();
  delay(200);

  // Request 2 bytes of data
  Wire.requestFrom(si7021Addr, 2);
  // Read 2 bytes of data to get humidity
  if (Wire.available() == 2) {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  float humidity  = ((data[0] * 256.0) + data[1]);
  return ((125 * humidity) / 65536.0) - 6;
}

float SHT21::getTemperature(void) {
  unsigned int data[2];

  Wire.beginTransmission(si7021Addr);
  // Send temperature measurement command
  Wire.write(0xF3);
  Wire.endTransmission();
  delay(200);

  // Request 2 bytes of data
  Wire.requestFrom(si7021Addr, 2);

  // Read 2 bytes of data for temperature
  if (Wire.available() == 2) {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  // Convert the data
  float temp  = ((data[0] * 256.0) + data[1]);
  return ((175.72 * temp) / 65536.0) - 46.85;
}
