void setIO(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AUDIO, OUTPUT);

  //Pulse LED for 1000ms to indicate boot
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}
