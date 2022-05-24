
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

}
