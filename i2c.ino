void sendI2C(void) {

  Wire.beginTransmission(8);
  //Words are sent LB/HB

  //TX coil width
  Wire.write(cycleCNT.txWidthCount & 0xff);
  Wire.write(cycleCNT.txWidthCount >> 8);

  //Delay after TX
  Wire.write(cycleCNT.sampleDelayCount & 0xff);
  Wire.write(cycleCNT.sampleDelayCount >> 8);

  //Sample width
  Wire.write(cycleCNT.sampleWidthCount & 0xff);
  Wire.write(cycleCNT.sampleWidthCount >> 8);

  //EFE delay
  Wire.write(cycleCNT.efeDelayCount & 0xff);
  Wire.write(cycleCNT.efeDelayCount >> 8);

  //EFE width
  Wire.write(cycleCNT.efeWidthCount & 0xff);
  Wire.write(cycleCNT.efeWidthCount >> 8);

  //Delay  for remainder of the period
  Wire.write(cycleCNT.aquirePeriodCount & 0xff);
  Wire.write(cycleCNT.aquirePeriodCount >> 8);

  Wire.endTransmission();
}