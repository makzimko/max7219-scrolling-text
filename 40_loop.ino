void loop() {
  for (int i = 0; i < ROWS_COUNT; i++) {
    spiBeginTransfer();
    for (int j = DEVICES - 1; j >= 0; j--) {
      spiTransfer(i + 1, data[i] >> (j * ROWS_COUNT));
    }
    spiCompleteTransfer();

    data[i] = data[i] << 1;
    bitWrite(data[i], 0, !random(10));
  }
}
