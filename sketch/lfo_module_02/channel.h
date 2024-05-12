#include "buttons.h"
#include "misc.h"
#include "mux.h"
#include "pot.h"


#define CHANNEL_DEBUG 1


void read_channel(int chan) {
    mux_channel_switch(chan);

    int val = analogRead(A0);

#if CHANNEL_DEBUG == 1
    Serial.print("A0: ");
    Serial.println(val);
#endif

    switch (chan) {
        case 0:
            read_pot(pot_lfo_delay, val);
            return;
        case 1:
            read_pot(pot_lfo_rate, val);
            return;
        case 2:
            read_buttons_lfo(val);
            return;
        case 3:
            read_lfo_wave(val);
            return;
    }
}
