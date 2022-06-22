
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
