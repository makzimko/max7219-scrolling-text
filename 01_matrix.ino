void spiBeginTransfer() {
  digitalWrite(CS_PIN, LOW);
}

void spiCompleteTransfer() {
  digitalWrite(CS_PIN, HIGH);
}

void spiTransfer(int com, byte data) {
  shiftOut(DATA_PIN, CLC_PIN, MSBFIRST, com);
  shiftOut(DATA_PIN, CLC_PIN, MSBFIRST, data);
}

void clearDisplay() {
  for (int i = 0; i < ROWS_COUNT; i++) {
    spiBeginTransfer();
    for (int j = 0; j < DEVICES; j++) {
      spiTransfer(i + 1, 0);
    }
    spiCompleteTransfer();
  }
}

void setScanLimit() {
  spiBeginTransfer();
  for (int i = 0; i < DEVICES; i++) {
    spiTransfer(11, 7);
  }
  spiCompleteTransfer();
}

void useLedMatrix() {
  spiBeginTransfer();
  for (int i = 0; i < DEVICES; i++) {
    spiTransfer(9, 0);
  }
  spiCompleteTransfer();
}

void setShutdownMode(bool mode) {
  spiBeginTransfer();
  for (int i = 0; i < DEVICES; i++) {
    spiTransfer(12, mode);
  }
  spiCompleteTransfer();
}

void setIntensity(byte intensity) {
  spiBeginTransfer();
  for (int i = 0; i < DEVICES; i++) {
    spiTransfer(10, intensity);
  }
  spiCompleteTransfer();
}

void testDisplay() {
  spiBeginTransfer();
  for (int i = 0; i < DEVICES; i++) {
    spiTransfer(15, 0);
  }
  spiCompleteTransfer();
}
