#define DATA_PIN 12
#define CLC_PIN 11
#define CS_PIN 10

#define DEVICES 4
#define ROWS_COUNT 8

const unsigned int ROW_SIZE = (int)(DEVICES + 2);

byte unsigned data[ROWS_COUNT][ROW_SIZE] = {};
const byte text[] PROGMEM = {"!\"#$%&#$#"};
