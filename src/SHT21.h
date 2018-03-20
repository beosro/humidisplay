#ifndef SHT21_H
#define SHT21_H

#include <Wire.h>

#define si7021Addr 0x40

class SHT21 {
public:
  SHT21();
  float getHumidity(void);
  float getTemperature(void);
};

#endif
