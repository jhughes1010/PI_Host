
#include "config.h"
#include <Wire.h>



int count = 0;


void setup()
{
  Serial.begin(115200);
  //Serial.println(NAME);

  setIO();

  Wire.begin();
  //debugln("setup completed");

  tone(AUDIO, 440);
}

void loop()
{
  while (1)
  {

  }
  //int bytes = 12;
  delay(2000);
  /*
  Wire.beginTransmission(8);
  //for (int x = 0; x < bytes; x++)
  {
    //TX LB/HB
    Wire.write(0x00);
    Wire.write(0x03);

    //Delay 1
    Wire.write(0x0E);
    Wire.write(0x00);

    //Sample
    Wire.write(0x00);
    Wire.write(0x03);

    //Delay 2
    Wire.write(0x00);
    Wire.write(0x0C);

    //EFE
    Wire.write(0x00);
    Wire.write(0x03);

    //Delay 3
    Wire.write(0x00);
    Wire.write(0x38);
  }
  Wire.endTransmission();

  delay(2000);
  Wire.beginTransmission(8);
  //for (int x = 0; x < bytes; x++)
  {
    //TX LB/HB
    Wire.write(0x00);
    Wire.write(0x06);

    //Delay 1
    Wire.write(0x0E);
    Wire.write(0x00);

    //Sample
    Wire.write(0x00);
    Wire.write(0x06);

    //Delay 2
    Wire.write(0x00);
    Wire.write(0x0C);

    //EFE
    Wire.write(0x00);
    Wire.write(0x06);

    //Delay 3
    Wire.write(0x00);
    Wire.write(0x2F);
  }
  Wire.endTransmission();
  */
}
