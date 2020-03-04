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
  clearDisplay();

  for (int i = 0; i < ROWS_COUNT; i++) {
    data[i] = random(2);
  }
}
