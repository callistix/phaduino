#include "Adafruit_TLC5947.h"


#define TLC_INDEX 1
#define TLC_PIN_DATA 6
#define TLC_PIN_CLOCK 7
#define TLC_PIN_LATCH 8
#define TLC_DATA_MAX 4059


Adafruit_TLC5947 tlc = Adafruit_TLC5947(TLC_INDEX, TLC_PIN_CLOCK, TLC_PIN_DATA, TLC_PIN_LATCH);


typedef struct {
    int block;
    int pin;
} triplet_t;


void tlc_init();
void tlc_led_on(int led);
void tlc_led_off(int led);
triplet_t lin_to_triplet(int n);


void tlc_init(void) {
    tlc.begin();

    for (int i = 0; i <= 23; i++) {
        tlc_led_off(i);
    }
}


void tlc_led_on(int led) {
    triplet_t triplet = lin_to_triplet(led);

    int pin[3] = {0, 0, 0};

    if (triplet.pin == 0) pin[0] = TLC_DATA_MAX;
    if (triplet.pin == 1) pin[1] = TLC_DATA_MAX;
    if (triplet.pin == 2) pin[2] = TLC_DATA_MAX;

    tlc.setLED(triplet.block, pin[0], pin[1], pin[2]);

    tlc.write();
}


void tlc_led_off(int led) {
    triplet_t triplet = lin_to_triplet(led);

    tlc.setLED(triplet.block, 0, 0, 0);

    tlc.write();
} 


triplet_t lin_to_triplet(int n) {
    triplet_t triplet;

    triplet.block = int(n / 3);
    triplet.pin = n % 3;

    return triplet;
}
