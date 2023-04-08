// --------------------------------------
// Dobson Azimuth / Altitude Display
// Alain Zwingelstein / azwing@free.fr
// Version 0.0
// License LGPL 3
// 
// Reads the angular value of two AS5600 sensors
// After positionning the Dobson roughly to AZ=0 and Alt=0 push the Zero button
// Now scope is oriented to Azimuth 0° (North) and Altitude 0° (Horizontal)
// (needs a rough calibration at built time) 
// then center a well known object in the scope and 
// with the button AZ+, AZ-, Alt+ and Alt- adjust display to object coordinates. 
// You are done.
// 

/* Example pinmap for BlackPill
        SDA   SCL
 I2C-1  PB7   PB6     Used for Oled Display
 I2C-2  PB3   PB10    Used to connect AS5600 Azimuth
 I2C-3  PB4   PA8     Used to connect AS5600 Altitude

 Button AZ+  PA0
 Button AZ-  PA1
 Button ALT+ PA2
 Button ALT- PA3
 Button Zero PA4
*/


#include <Wire.h>
// I2C-2 instance
TwoWire Wire2(PB3, PB10);
TwoWire Wire3(PB4, PA8);

int offset_az=0, offset_alt=0;
uint32_t temps=0;

void setup() {
  inputs_init();
  oled_init();
  Wire2.begin();
  Wire3.begin();
}


void loop() {
  char azimuth[10] = {0};
  char hauteur[10] = {0};
  float degres;
  int deg, minu, sec;
  
  degres = (float)(az()+offset_az)/4095*360;
  if (degres<0) degres += 360;
  deg= degres;
  minu=(degres-deg)*60;
  sec=(((degres-deg)*60)-minu)*60;
  sprintf(azimuth, "%03d:%02d:%02d", deg, minu, sec);
  //sprintf(azimuth, "%2.3f", (float)az()/4095*360);
  degres=(float)(alt()+offset_alt)/4095*360;
  if (degres<0) degres += 360;
  deg= degres;
  minu=(degres-deg)*60;
  sec=(((degres-deg)*60)-minu)*60;
  sprintf(hauteur, "%03d:%02d:%02d", deg, minu, sec);
  delay(10);
  oled_print(azimuth, hauteur);
  if ((millis()-temps)>200){
    get_button();
    temps=millis();
  }
}

uint16_t az()
{
  Wire2.beginTransmission(0x36);
  Wire2.write(0x0c);
  int error = Wire2.endTransmission();
  Wire2.requestFrom(0x36, (uint8_t)2);
  uint16_t data1 = Wire2.read();
  data1 <<= 8;
  data1 += Wire2.read();
  return data1;
}

uint16_t alt()
{
  Wire3.beginTransmission(0x36);
  Wire3.write(0x0c);
  int error = Wire3.endTransmission();
  Wire3.requestFrom(0x36, (uint8_t)2);
  uint16_t data = Wire3.read();
  data <<= 8;
  data += Wire3.read();
  return data;
}
