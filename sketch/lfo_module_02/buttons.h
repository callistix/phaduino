#include "tlc.h"


#define BUTTON_RANGE 10


struct button_t {
    bool pressed;
    bool pressed_old;
    bool state;
    char led;
    int value[4];
};


struct button_t button_lfo[] = {
    {false, false, false, 1, {367, 429, 398, 453}},
    {false, false, false, 6, {157, 429, 213, 453}},
    {false, false, false, 9, {80, 398, 213, 453}}
};


void read_buttons_lfo(int val);
void button_lfo_trigger(int button);


void read_buttons_lfo(int val) {
    for (int b = 0; b < 3; b++) {
        button_lfo[b].pressed = false;

        for (int v = 0; v < 4; v++) {
            if ((val >= button_lfo[b].value[v] - BUTTON_RANGE) && (val <= button_lfo[b].value[v] + BUTTON_RANGE)) {
                button_lfo[b].pressed = true;

                if (button_lfo[b].pressed_old == false) {
                    button_lfo[b].pressed_old = true;
                    button_lfo_trigger(b);
                }
            }
        }

        if (button_lfo[b].pressed == false) {
            button_lfo[b].pressed_old = false;
        }
    }
}


void button_lfo_trigger(int button) {
    if (button_lfo[button].state == false) {

        button_lfo[button].state = true;
        tlc_led_on(button_lfo[button].led);

    } else {

        button_lfo[button].state = false;
        tlc_led_off(button_lfo[button].led);

    }
}
