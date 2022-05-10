
//#include "config.h"
#include <Wire.h>

int count = 0;

void setup()
{
  Serial.begin(115200);
  //Serial.println(NAME);

  //setIO();
  //setInterruptDetails();
  Wire.begin();
  //Wire.onReceive(receiveEvent);
  //debugln("setup completed");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int size = 6;
  byte lowByte, highByte;
  unsigned int countArray[6];
  int position;
  //unsigned int countArray[6];
  delay(2000);

  if (count % 2 == 0)
  {
    for (position = 0 ; position < size; position++)
    {
      countArray[position] = 0x8000;
    }
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LOW");
  }
  else
  {
    for (position = 0 ; position < size; position++)
    {
      countArray[position] = 0x0002;
    }
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("HIGH");
  }
  count++;

  //Send I2C
  Wire.beginTransmission(8);


  for (position = 0 ; position < size; position++)
  {
    Serial.println(countArray[position]);
    lowByte = byte (countArray[position] & 0xff);
    highByte = byte ((countArray[position] >> 8) & 0xff);
    Wire.write(lowByte);
    Wire.write(highByte);
  }
  Wire.endTransmission();
}

/*
  void setIO(void)
  {
  pinMode(txPin, OUTPUT);           // Set TX pin to output mode
  pinMode(mainSamplePin, OUTPUT);   // Set main sample pin to output mode
  pinMode(efeSamplePin, OUTPUT);    // Set EFE sample pin to output mode

  //LED and A1 defined
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A1, INPUT);
  //Pulse LED for 1000ms to indicate boot
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  }

  void DelayPotRead( void)
  {
  delayVal = analogRead(delayPin);                   // Read the delay pot
  }

  void receiveEvent(int howMany) {
  byte in[12];
  int position = 0;

  while (Wire.available())
  {
    position = position % 12;
    in[position] = Wire.read();
    debug(in[position]);
    position++;
  }

  //Data is expected in LB/HB ordering
  txOnCount = in[0];
  txOnCount |= in[1] << 8;

  mainDelayCount = in[2];
  mainDelayCount |= in[3] << 8;

  mainSampleCount = in[4];
  mainSampleCount |= in[5] << 8;

  efeDelayCount = in[6];
  efeDelayCount |= in[7] << 8;

  efeSampleCount = in[8];
  efeSampleCount |= in[9] << 8;

  txPeriodCount = in[10];
  txPeriodCount |= in[11] << 8;
  }

*/
