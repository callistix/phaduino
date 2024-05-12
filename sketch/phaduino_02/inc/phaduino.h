#ifndef PHADUINO_H
#define PHADUINO_H

#include "control_buttonarray3.h"
#include "control_port.h"
#include "control_switch5.h"


void scan_lfo(void);


void scan_lfo(void) {
    control_pot_scan(control_pot_lfo_rate);
    control_pot_scan(control_pot_lfo_delay);
    control_buttonarray3_scan(control_buttonarray3_lfo);
    control_switch5_scan(control_switch5_lfo_wave);
}

#endif
