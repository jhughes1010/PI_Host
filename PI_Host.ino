
#include "config.h"
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23X17.h>

//=================================
//Global Instances
//=================================
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();


int count = 0;


void setup()
{
  Serial.begin(115200);
  Serial.println("\n\n");
  Serial.println(NAME);
  Serial.println(VERSION);

  setIO();

  lcd.begin(16, 2);
  lcd.setBacklight(0x01);
  lcd.print(NAME);

  Wire.begin();
  readBatteryV();

  tone(AUDIO, 440);
  
  debugln("setup completed");
}

void loop()
{
  readBatteryV();
  delay(2000);
}
