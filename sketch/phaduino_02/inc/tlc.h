#ifndef TLC_H
#define TLC_H

#include <Adafruit_TLC5947.h>

#define TLC_INDEX 1
#define TLC_PIN_DATA 6
#define TLC_PIN_CLOCK 7
#define TLC_PIN_LATCH 8
#define TLC_DATA_MAX 4095

#define LED_ID_LFO_SYNC 9
#define LED_ID_LFO_TRIG 6
#define LED_ID_LFO_INV 1


struct s_tlc {
    int id;
    int pin_data;
    int pin_clock;
    int pin_latch;
};

struct s_tlc_led {
    struct s_tlc tlc;
    int id;
};


struct s_tlc tlc = { TLC_INDEX, TLC_PIN_DATA, TLC_PIN_CLOCK, TLC_PIN_LATCH };
struct s_tlc_led led_lfo_sync;
struct s_tlc_led led_lfo_trig;
struct s_tlc_led led_lfo_inv;


int tlc_init(struct s_tlc &tlc);
int tlc_led_on(struct s_tlc_led &led);
int tlc_led_off(struct s_tlc_led &led);


Adafruit_TLC5947 tlc_data = Adafruit_TLC5947(tlc.id, tlc.pin_clock, tlc.pin_data, tlc.pin_latch);


int tlc_init(struct s_tlc &tlc) {
    tlc_data.begin();

    led_lfo_sync.tlc = tlc;
    led_lfo_sync.id = LED_ID_LFO_SYNC;

    led_lfo_trig.tlc = tlc;
    led_lfo_trig.id = LED_ID_LFO_TRIG;

    led_lfo_inv.tlc = tlc;
    led_lfo_inv.id = LED_ID_LFO_INV;

    tlc_led_off(led_lfo_sync);
    tlc_led_off(led_lfo_trig);
    tlc_led_off(led_lfo_inv);
}


int tlc_led_on(struct s_tlc_led &led) {
    tlc_data.setPWM(led.id, TLC_DATA_MAX);
    tlc_data.write();
}


int tlc_led_off(struct s_tlc_led &led) {
    tlc_data.setPWM(led.id, 0);
    tlc_data.write();
}

#endif
