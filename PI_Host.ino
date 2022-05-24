
#include "config.h"
#include <Wire.h>



int count = 0;


void setup()
{
  Serial.begin(115200);
  //Serial.println(NAME);

  //setIO();
  
  Wire.begin();
  //Wire.onReceive(receiveEvent);
  //debugln("setup completed");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AUDIO, OUTPUT);
  tone(AUDIO,440);
}

void loop()
{
  /*
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
  */
}
