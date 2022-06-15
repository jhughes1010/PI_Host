void setIO(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AUDIO, OUTPUT);

  //Pulse LED for 500mS to indicate boot
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

float readBatteryV(void)
{
  float batteryVoltage;
  int batteryADC;
  batteryADC = analogRead(VBAT);
  batteryVoltage = (float)batteryADC * .0078;

  debug("Battery Voltage:");
  debugln(batteryVoltage);
  lcd.setCursor(0, 1);
  lcd.print(batteryVoltage);
  return batteryVoltage;
}
