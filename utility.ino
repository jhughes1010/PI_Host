//Audio settings
int audioFreq[4] = { 220, 330, 440, 660 };

void setIO(void) {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AUDIO, OUTPUT);

  //Pulse LED for 500mS to indicate boot
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}