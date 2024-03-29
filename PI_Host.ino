#include "config.h"
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23X17.h>

//=================================
// 1.0.1  - 04/15/2023 Change button ordering to accomodate for new PCB button layout
// 1.0.2  - 05/06/2023 Removed debug statement that disables keypresses after 30 sec
//                     LCD default to light green
// 1.0.3  - 09/21/2023 Fix battery warning code. Sample window of 10mS is too small and also ensure warning stays on screen, now 100mS
//                     Now checks for low battery every 15 sec

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

//=================================
//setup
//=================================
void setup() {
  Serial.begin(115200);
  Serial.println("\n\n");
  Serial.println(NAME);
  Serial.println(VERSION);

  setIO();

  lcd.begin(16, 2);
  lcd.setBacklight(0x01);
  createCustomChar();

  Wire.begin();

  tone(AUDIO, 440);
  //setTimingOffsets(1 US, 2.7 US, 3 US, 2 US, 2 US, 2 US);
  //Debug offsets
  setTimingOffsets(4 US, 0, 3.5 US, 0, 0, 0);
  //Load struct only
  setTimingTargets(50 US, 7 US, 50 US, 100 US, 50 US, 1 MS);

  //Calculate counter values for sending to PI controller
  loadCounters();
  printCounters();

  LCDPrintBoot();
  LCDPrintInit();
  delay(2000);
  lcd.setBacklight(LCD_START);

  debugln("setup completed");
}

//=================================
//loop
//=================================
void loop() {
  byte keypress;
  static byte backlight = LCD_START;
  unsigned long msec;
  static unsigned long pressedTime = 0;
  static bool pressed = false;
  static bool revertScreen = true;
  //static bool backlight = true;
  static int txPos = 3;
  static int samplePos = 3;
  static int audioPos = 2;
  static bool lowBat = false;
  msec = millis();

  //Check for low battery
  //screen warning on LCD and builtin LED turns on if debug enabled
  if (msec % 15000 <= 50) {
    lowBat = lowBattery(msec);
    revertScreen = true;
    pressedTime = msec;

    if (lowBat) {
      lcd.clear();
      lcd.print("Low Battery");
#if DEBUG == 1
      digitalWrite(LED_BUILTIN, HIGH);
#endif
      debugln("Battery Low");
    } else {
#if DEBUG == 1
      digitalWrite(LED_BUILTIN, LOW);
#endif
    }
  }


  //Keypress evaluation
  keypress = lcd.readButtons();
  if (keypress & BUTTON_SELECT) {
    pressedTime = msec;
    if (!pressed) {
      debugln("button pressed - Battery check");
      reportBatteryStatus();
    }
    pressed = true;
    revertScreen = true;
  }


  //Update TX coil
  else if (keypress & BUTTON_LEFT) {
    pressedTime = msec;
    if (!pressed) {
      debugln("button pressed - TX width");
      txPos++;
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
  else if (keypress & BUTTON_RIGHT) {
    pressedTime = msec;
    if (!pressed) {
      debugln("button pressed - Sample width");
      samplePos++;
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
  else if (keypress & BUTTON_UP) {
    pressedTime = msec;
    if (!pressed) {
      debugln("button pressed - Audio");
      audioPos++;
      audioPos = audioPos % 4;
      tone(AUDIO, audioFreq[audioPos]);
      LCDPrintFreq(audioFreq[audioPos]);
    }
    pressed = true;
    revertScreen = true;
  }

  //toggle backlight
  else if (keypress & BUTTON_DOWN) {
    pressedTime = msec;
    if (!pressed) {
      debugln("button pressed - Toggle backlight");
      backlight += 1;
      backlight &= 0x07;
      lcd.setBacklight(backlight);
    }
    pressed = true;
    revertScreen = true;
  }


  else {
    if (pressed && ((msec - pressedTime) > 250)) {
      debugln("button cleared");
      pressed = false;
    }
    if (!lowBat && revertScreen && ((msec - pressedTime) > 2000)) {
      debugln("Screen reverted");
      lcd.clear();
      lcd.print(NAME);
      revertScreen = false;
    }
    if ((msec - pressedTime) > 2000) {
      LCDBar();
    }
  }
}
