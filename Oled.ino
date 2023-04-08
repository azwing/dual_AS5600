#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;


void oled_init() {
  Wire.begin();
  Wire.setClock(400000L);  // original 400000L
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Adafruit5x7);
  oled.set2X();
  oled.clear();
  oled.println("Azimuth= ");
  oled.println(" ");
  oled.println("Altitude= ");
  oled.println(" ");
}

void oled_print(char *azimuth, char *hauteur){
  //oled.clear(); // just print over so no flicker
  oled.setCursor(0, 0);
  oled.println("Azimuth= ");
  oled.println(azimuth);
  oled.println("Altitude= ");
  oled.println(hauteur);
}
