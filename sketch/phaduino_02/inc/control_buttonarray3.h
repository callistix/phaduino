#ifndef CONTROL_BUTTONARRAY3
#define CONTROL_BUTTONARRAY3

#include "mux.h"
#include "tlc.h"


struct s_control_buttonarray3 {
    struct s_mux mux;
    char mux_channel;
    struct s_tlc_led led[3];
    int resistor[3];
    int state[3];
    char bracket;
    char midi_channel;
};


struct s_control_buttonarray3 control_buttonarray3_lfo;


int control_buttonarray3_scan(struct s_control_buttonarray3 control_buttonarray3);


int control_buttonarray3_scan(struct s_control_buttonarray3 control_buttonarray3) {
}

#endif
