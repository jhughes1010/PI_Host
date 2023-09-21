//--------------------
//Battery read and LCD clear/display
//--------------------
void reportBatteryStatus(void) {
  float voltage;
  voltage = readBatteryV();
  LCDPrintBattery(voltage);
}

//--------------------
//Battery read
//--------------------
float readBatteryV(void) {
  float batteryVoltage;
  int batteryADC;
  batteryADC = analogRead(VBAT);
  batteryVoltage = (float)batteryADC * CAL_BATTERY;
  debug("Battery ADC: ");
  debugln(batteryADC);
  debug("Battery Voltage: ");
  debugln(batteryVoltage);
  return batteryVoltage;
}


//--------------------
//Check for low battery
//--------------------
bool lowBattery(unsigned long msec) {
  bool lowBat = false;
  float voltage;
  voltage = readBatteryV();
  if ((batteryType == 0) & (voltage < 9.0)) {
    lowBat = true;
  }
  return lowBat;
}