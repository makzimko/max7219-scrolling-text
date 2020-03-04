#define DATA_PIN 12
#define CLC_PIN 11
#define CS_PIN 10

int devices = 4;

unsigned long data[8] = {};

void spiTransfer(int com, byte data) {
  shiftOut(DATA_PIN, CLC_PIN, MSBFIRST, com);
  shiftOut(DATA_PIN, CLC_PIN, MSBFIRST, data);
}

void writeRow(int addr, int row, int data) {
  digitalWrite(CS_PIN, LOW);
  for (int i = devices; i > 0; i--) {
    if (i - 1 == addr) {
      spiTransfer(row + 1, data);
    } else {
      spiTransfer(0, 0);
    }
  }
  digitalWrite(CS_PIN, HIGH);
}

void clear() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(CS_PIN, LOW);
    for (int j = 0; j < devices; j++) {
      spiTransfer(i + 1, 0);
    }
    digitalWrite(CS_PIN, HIGH);
  }
}

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLC_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  digitalWrite(CS_PIN, LOW);
  for (int i = 0; i < devices; i++) {
    spiTransfer(11, 7);
  }
  digitalWrite(CS_PIN, HIGH);
  digitalWrite(CS_PIN, LOW);
  for (int i = 0; i < devices; i++) {
    spiTransfer(9, 0);
  }
  digitalWrite(CS_PIN, HIGH);
  digitalWrite(CS_PIN, LOW);
  for (int i = 0; i < devices; i++) {
    spiTransfer(12, 1);
  }
  digitalWrite(CS_PIN, HIGH);
  digitalWrite(CS_PIN, LOW);
  for (int i = 0; i < devices; i++) {
    spiTransfer(10, 0);
  }
  digitalWrite(CS_PIN, HIGH);
  digitalWrite(CS_PIN, LOW);
  for (int i = 0; i < devices; i++) {
    spiTransfer(15, 0);
  }
  digitalWrite(CS_PIN, HIGH);

  clear();

  for (int i = 0; i < 8; i++) {
    data[i] = random(2);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {

    //    for(int j = 0; j < devices; j++) {
    //      writeRow(j, i, data[i] >> (j * 8));
    //    }

    digitalWrite(CS_PIN, LOW);
    for (int j = devices - 1; j >= 0; j--) {
      spiTransfer(i + 1, data[i] >> (j * 8));
    }
    digitalWrite(CS_PIN, HIGH);

    data[i] = data[i] << 1;
    bitWrite(data[i], 0, !random(100));
  }

//  delay(30);
}
