void shiftData(byte offset = 1) {
  for(int i = 0; i < ROWS_COUNT; i++) {
    for(int j = ROW_SIZE - 1; j >= 0; j--) {
      data[i][j] = data[i][j] << offset;
      if (j > 0) {
        for (int k = 0; k < offset; k++) {
           bitWrite(data[i][j], k, bitRead(data[i][j - 1], 8 - offset + k));
        }
      }
    }
    bitWrite(data[i][0], 0, random(2));
  }
}

void loop() {
  for(int i = 0; i < ROWS_COUNT; i++) {
    spiBeginTransfer();
    for(int j = ROW_SIZE - 2; j > 0; j--) {
      spiTransfer(i+1, data[i][j]);
    }
    spiCompleteTransfer();
  }

  shiftData();
  delay(50);
}
