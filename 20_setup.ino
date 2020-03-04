void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLC_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  setScanLimit();
  useLedMatrix();
  setShutdownMode(1);
  setIntensity(0);
  testDisplay();

  delay(1000);
  clearDisplay();
}
