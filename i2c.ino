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
