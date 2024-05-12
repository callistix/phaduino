#define POT_SMOOTH 2

#define POT_INIT { \
    .val = 0, \
    .midi_cc = 0 \
}


typedef struct {
    int val;
    int midi_cc;
} pot_t;


pot_t pot_lfo_rate POT_INIT;
pot_t pot_lfo_delay POT_INIT;


void read_pot(pot_t &pot, int val) {
    if ((val < pot.val - POT_SMOOTH) || (val > pot.val + POT_SMOOTH)) {
        pot.val = val;

        int midi_cc = val_to_midicc(val);

        if (midi_cc != pot.midi_cc) {
            pot.midi_cc = midi_cc;
        }
    }
}


bool read_lfo_wave(int val) {

    return(false);
}
