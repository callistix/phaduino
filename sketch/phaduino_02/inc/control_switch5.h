#ifndef CONTROL_SWITCH5
#define CONTROL_SWITCH5

#include "mux.h"


struct s_control_switch5 {
    struct s_mux mux;
    char mux_channel;
    int resistor[5];
    char bracket;
    char midi_channel;
};


struct s_control_switch5 control_switch5_lfo_wave;


int control_switch5_scan(struct s_control_switch5 control_switch5);


int control_switch5_scan(struct s_control_switch5 control_switch5) {
}

#endif
