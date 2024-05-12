#define SERIAL_BAUD 9600


void serial_init(void) {
    Serial.begin(SERIAL_BAUD);
}
