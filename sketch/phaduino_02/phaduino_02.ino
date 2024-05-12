#include "inc/phaduino.h"
#include "inc/serial.h"


void setup(void) {
    serial_init();
    mux_init(&mux);
    tlc_init(tlc);
}


void loop(void) {
    scan_lfo();
}
