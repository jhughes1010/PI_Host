
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
  //readBatteryV();

  tone(AUDIO, 440);

  debugln("setup completed");
}

void loop()
{
  unsigned long msec;
  static unsigned long pressedTime = 0;
  static bool pressed = false;
  bool lowBat = false;
  msec = millis();

  //Check for low battery
  lowBat = lowBattery(msec);
  if(lowBat)
  {
    lcd.clear();
    lcd.print("Low Battery");
    while(1){}
  }

  if (lcd.readButtons() & BUTTON_SELECT)
  {

    pressedTime = msec;
    if (!pressed)
    {
      debugln("button pressed");
      reportBatteryStatus();
    }
    pressed = true;
  }
  else
  {
    if (pressed && ((msec - pressedTime) > 2000))
    {
      debugln("button cleared");
      lcd.clear();
      lcd.print(NAME);
      pressed = false;
    }
  }
}
