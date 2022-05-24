/*void receiveEvent(int howMany) {
  byte in[12];
  int position = 0;

  while (Wire.available())
  {
    position = position % 12;
    in[position] = Wire.read();
    //debug(in[position]);
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
