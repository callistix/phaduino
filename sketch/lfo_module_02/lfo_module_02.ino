#include "channel.h"
#include "serial.h"


#define DELAY 1


void setup() {
    serial_init();
    tlc_init();
    mux_init();
}


void loop() {
    for (int chan = 0; chan < 3; chan++) read_channel(chan);

    delay(DELAY);
}
