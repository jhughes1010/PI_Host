//--------------------
//LCD display Initial settings
//--------------------
void LCDPrintInit(void)
{
  float vbat;
  lcd.clear();
  lcd.print("TX: 50uS AU:440");
  lcd.setCursor(0, 1);
  lcd.print("SA: 50uS VB:");
  lcd.print(readBatteryV());
  delay(3000);
}
//--------------------
//LCD display TX
//--------------------
void LCDprintTX(float value)
{
  int i_value;
  i_value = (int)(value / 1E-6);
  lcd.clear();
  lcd.print("TX Coil Width:");
  lcd.setCursor(0, 1);
  lcd.print(i_value);
  lcd.print(" US");
}


//--------------------
//LCD display Sample
//--------------------
void LCDprintSample(float value)
{
  int i_value;
  i_value = (int)(value / 1E-6);
  lcd.clear();
  lcd.print("Sample Width:");
  lcd.setCursor(0, 1);
  lcd.print(i_value);
  lcd.print(" US");
}

//--------------------
//LCD display VBAT
//--------------------
void LCDPrintBattery(float batteryVoltage)
{
  debug("Battery Voltage: ");
  debugln(batteryVoltage);

  lcd.clear();
  lcd.print("Battery Voltage");
  lcd.setCursor(0, 1);
  lcd.print(batteryVoltage, 2);
  lcd.print(" V");
}

//--------------------
//LCD display AudioFrequency
//--------------------
void LCDPrintFreq(int freq)
{
  debug("Audio: ");
  debugln(freq);

  lcd.clear();
  lcd.print("Audio:");
  lcd.setCursor(0, 1);
  lcd.print(freq);
  lcd.print(" Hz");
}

//=================================
//LCDBar()
//=================================
void LCDBar ( void)
{
  byte bar[16] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
  int pixels;
  int pos;
  int columns;
  int pixPortion;
  int signalValue;

  signalValue = analogRead(SIGNAL);
  if (signalValue > 400)
  {
    signalValue -= 400;
  }
  else
  {
    signalValue == 0;
  }

  //convert 10 bit value to pixel 0-79
  pixels = (float)signalValue / 623 * 80;
  columns = (int)(pixels / 5);
  pixPortion = (int)pixels % 5;

  debugln(columns);
  debugln(pixPortion);
  //fill columns
  for (pos = 0; pos < columns; pos++)
  {
    bar[pos] = 4;
  }
  bar[columns] = pixPortion;

  //Write full row
  lcd.setCursor(0, 1);
  for (pos = 0; pos < 16; pos++)
  {
    lcd.write(bar[pos]);
  }
}
