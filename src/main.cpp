#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"
#include "SHT21.h"

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);
SHT21 sht21;

void disp(float humidity, float temp) {
  char buf[10];
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  sprintf(buf, "%2d%%", (int)humidity);
  display.print(buf);

  display.setCursor(0, 25);
  sprintf(buf, "%2d C", (int)temp);
  display.print(buf);

  display.display();
  delay(1000);
}

void setup()   {
  // disable wifi to save power and prevent interrupts
  WiFi.disconnect();
  WiFi.mode(WIFI_OFF);
  WiFi.forceSleepBegin();

  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)

}

void loop() {
  disp(sht21.getHumidity(), sht21.getTemperature());

  delay(1000);
}
