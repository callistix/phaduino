#include <CD74HC4067.h>
#include <MIDI.h>


#define PINS_MUX 3
#define CC_OFS 16
#define SMOOTH 2


const int SIG_PINS[] = {A0, A1};


CD74HC4067 mux(2, 3, 4, 5);  // (S0, S1, S2, S3)

MIDI_CREATE_DEFAULT_INSTANCE();


int val_old[] = {0, 0, 0, 0, 0, 0};
int midi_cc_old[] = {0, 0, 0, 0, 0, 0};


void setup() {
    MIDI.begin(MIDI_CHANNEL_OMNI);
}


void loop() {
    int midi_cc, chan, pin, port, val;

    for(int chan = 0; chan < PINS_MUX; chan++) {
        mux.channel(chan); 

        for(int pin = 0; pin < sizeof(SIG_PINS); pin++) {
            port = pin * PINS_MUX + chan;

            val = analogRead(SIG_PINS[pin]);

            if (val > val_old[port] + SMOOTH or val < val_old[port] - SMOOTH) {
                val_old[port] = val;

                /* val[] ranges from 0 to 1023, map to MIDI CC range 0 to 127 */
                midi_cc = int(val / 8.0551);

                if (midi_cc != midi_cc_old[port]) {
                    midi_cc_old[port] = midi_cc;

                    if (port >= 0 and port <= 5) {
                        MIDI.sendControlChange(CC_OFS + port, midi_cc, 1);
                    }
                }
            }
        }
    }
}
