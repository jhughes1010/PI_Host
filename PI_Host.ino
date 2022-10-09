
#include "config.h"
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23X17.h>

//=================================
//Global Instances
//=================================
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();


//=================================
//Externs
//=================================
extern float coilPulseWidthArray[];
extern float targetSampleWidthArray[];
extern int audioFreq[];

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
  //setTimingOffsets(1 US, 2.7 US, 3 US, 2 US, 2 US, 2 US);
  //Debug offsets
  setTimingOffsets(4 US, 0, 3.5 US, 0, 0, 0);
  //Load struct only
  setTimingTargets(50 US, 7 US, 50 US, 100 US, 50 US, 1 MS);

  //Calculate counter values for sending to PI controller
  loadCounters();
  printCounters();

  debugln("setup completed");
}

void loop()
{
  unsigned long msec;
  static unsigned long pressedTime = 0;
  static bool pressed = false;
  static bool revertScreen = false;
  static int txPos = 0;
  static int samplePos = 0;
  static int audioPos = 0;
  bool lowBat = false;
  msec = millis();

  //Check for low battery

  lowBat = lowBattery(msec);
  if (lowBat)
  {
    lcd.clear();
    lcd.print("Low Battery");
    //while(1){}
  }
  if (msec < 15000)
  {
    if (lcd.readButtons() & BUTTON_SELECT)
    {
      pressedTime = msec;
      if (!pressed)
      {
        debugln("button pressed");
        reportBatteryStatus();
      }
      pressed = true;
      revertScreen = true;
    }


    //Update TX coil
    else if (lcd.readButtons() & BUTTON_UP)
    {
      pressedTime = msec;
      if (!pressed)
      {
        debugln("button pressed");
        txPos ++;
        txPos = txPos % 4;
        timing.txWidth = coilPulseWidthArray[txPos];
        loadCounters();
        printCounters();
        sendI2C();
        LCDprintTX(coilPulseWidthArray[txPos]);
      }
      pressed = true;
      revertScreen = true;
    }

    //Update Sample and EFE
    else if (lcd.readButtons() & BUTTON_DOWN)
    {
      pressedTime = msec;
      if (!pressed)
      {
        debugln("button pressed - Sample");
        samplePos ++;
        samplePos = samplePos % 4;
        timing.sampleWidth = targetSampleWidthArray[samplePos];
        timing.efeWidth = targetSampleWidthArray[samplePos];
        loadCounters();
        printCounters();
        sendI2C();
        LCDprintSample(targetSampleWidthArray[samplePos]);
      }
      pressed = true;
      revertScreen = true;
    }
    //Audio
    else if (lcd.readButtons() & BUTTON_LEFT)
    {
      pressedTime = msec;
      if (!pressed)
      {
        debugln("button pressed - Audio");
        audioPos ++;
        audioPos = audioPos % 4;
        tone(AUDIO, audioFreq[audioPos]);
        LCDPrintFreq(audioFreq[audioPos]);
      }
      pressed = true;
      revertScreen = true;
    }


    else
    {
      if (pressed && ((msec - pressedTime) > 500))
      {
        debugln("button cleared");
        pressed = false;
      }
      if (revertScreen && ((msec - pressedTime) > 2000))
      {
        debugln("Screen reverted");
        lcd.clear();
        lcd.print(NAME);
        revertScreen = false;
      }
    }
  }
}
