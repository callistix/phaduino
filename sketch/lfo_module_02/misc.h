#include <math.h>


int val_to_midicc(float val) {
    int midi_cc = round(val / 8.0551);

    return(midi_cc);
}
