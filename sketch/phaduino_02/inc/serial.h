#ifndef SERIAL_H
#define SERIAL_H

#define SERIAL_BAUD 9600


int serial_init(void);


int serial_init(void) {
    Serial.begin(SERIAL_BAUD);
}

#endif
