#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

int const potpins[] = {A0, A1, A2, A3, A4};
int const cc_offset = 16;
int const smoothing = 2;

int potval[] = {0, 0, 0, 0, 0};
int potval_old[] = {0, 0, 0, 0, 0};


void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
}


void loop() {
    int midi_cc_val;

    for (int pin = 0; pin < 5; pin++) {
        potval[pin] = analogRead(potpins[pin]);

        if (potval[pin] > potval_old[pin] + smoothing or potval[pin] < potval_old[pin] - smoothing) {
            potval_old[pin] = potval[pin];

            /* potval[] ranges from 0 to 1023, map to MIDI CC range 0 to 127 */
            midi_cc_val = potval[pin] / 8.0551;

            MIDI.sendControlChange(cc_offset + pin, midi_cc_val, 1);
        }
    }
}
