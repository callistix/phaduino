#ifndef CONTROL_PORT_H
#define CONTROL_PORT_H

#include "mux.h"


struct s_control_pot {
    struct s_mux mux;
    char mux_channel;
    char midi_channel;
    char lag;
};


struct s_control_pot control_pot_lfo_rate;
struct s_control_pot control_pot_lfo_delay;


int control_pot_scan(struct s_control_pot control_pot);


int control_pot_scan(struct s_control_pot control_pot) {
}

#endif
