/* TODO:
   * midi_cc are still unstable for potentiometers at certain positions
   * needs optimisation especially for reading LFO buttons
*/

#include "Adafruit_TLC5947.h"


#define BAUD 9600
#define DELAY 1
#define POT_AVG 3
#define MUX_COUNT 1
#define RES_TOLERANCE 5
#define SWITCH_TOLERANCE 10

#define TLC_NUM 1
#define TLC_DATA 6
#define TLC_CLOCK 7
#define TLC_LATCH 8
#define TLC_OE -1


const int mux_signal_pin = A0;

const int mux[MUX_COUNT][4] = {
	{2, 3, 4, 5},
};

const int mux_channel[16][4]={
	{0,0,0,0},
	{1,0,0,0},
	{0,1,0,0},
	{1,1,0,0},
	{0,0,1,0},
	{1,0,1,0},
	{0,1,1,0},
	{1,1,1,0},
	{0,0,0,1},
	{1,0,0,1},
	{0,1,0,1},
	{1,1,0,1},
	{0,0,1,1},
	{1,0,1,1},
	{0,1,1,1},
	{1,1,1,1}
};

const int btn_lfo_sync_res = 369;
const int btn_lfo_trig_res = 562;
const int btn_lfo_sync_trig_res = 654;
const int btn_lfo_inv_res = 811;
const int btn_lfo_sync_inv_res = 832;
const int btn_lfo_trig_inv_res = 865;

const int switch_6_pos_res[] = {802, 557, 365, 325, 286, 182};

typedef struct {
	int val[POT_AVG];
    int val_ptr = 0;
    int midi_cc = 0;
} potentiometer_t;


typedef struct {
    bool sync = false;
    bool sync_hold = false;
    bool trig = false;
    bool trig_hold = false;
    bool inv = false;
    bool inv_hold = false;
} buttons_lfo_t;

typedef struct {
    int midi_cc = 0;
} switch_6_pos_t;


Adafruit_TLC5947 tlc = Adafruit_TLC5947(TLC_NUM, TLC_CLOCK, TLC_DATA, TLC_LATCH);

potentiometer_t pot_lfo_rate;
potentiometer_t pot_lfo_delay;

buttons_lfo_t buttons_lfo;

switch_6_pos_t switch_lfo_wave;


void setup() {
    Serial.begin(BAUD);

    tlc.begin();

    tlc.setLED(0,4059,0,0);
    tlc.write();

	pot_init(pot_lfo_rate);
	pot_init(pot_lfo_delay);

    for (int i = 0; i < MUX_COUNT; i++) {
        mux_init_pins(mux[i]);
	    mux_switch_channel(mux[0], 0);
    }
}


void loop() {
    int midi_cc = 0;

    midi_cc = mux_read_pot(0, 0, pot_lfo_rate);

    if (midi_cc != pot_lfo_rate.midi_cc) {
        pot_lfo_rate.midi_cc = midi_cc;

        Serial.print("LFO RATE: ");
        Serial.println(pot_lfo_rate.midi_cc);
    }

    midi_cc = mux_read_pot(0, 1, pot_lfo_delay);

    if (midi_cc != pot_lfo_delay.midi_cc) {
        pot_lfo_delay.midi_cc = midi_cc;

        Serial.print("LFO DELAY: ");
        Serial.println(pot_lfo_delay.midi_cc);
    }

    mux_read_buttons_lfo(0, 2, buttons_lfo);

    midi_cc = mux_read_6_pos_switch(0, 3, switch_lfo_wave);

    if ((midi_cc != -1) && (midi_cc != switch_lfo_wave.midi_cc)) {
        switch_lfo_wave.midi_cc = midi_cc;

        Serial.print("LFO WAVE: ");
        Serial.println(switch_lfo_wave.midi_cc);
    }

    delay(DELAY);
}


int mux_read_pot(int mux_no, int channel, potentiometer_t &pot) {
    int midi_cc = 0;

    mux_switch_channel(mux_no, channel);

    pot.val[pot.val_ptr] = analogRead(A0);

    pot.val_ptr++;
    if (pot.val_ptr >= POT_AVG) pot.val_ptr = 0;

    midi_cc = val2midi_cc(avg(pot.val, POT_AVG));

    return(midi_cc);
}


void mux_read_buttons_lfo(int mux_no, int channel, buttons_lfo_t &btns) {
    mux_switch_channel(mux_no, channel);

    int btns_val = analogRead(A0);

//    Serial.println(btns_val);

    if ((btns_val > btn_lfo_sync_res - RES_TOLERANCE) && (btns_val < btn_lfo_sync_res + RES_TOLERANCE)) {
        if (btns.sync_hold == false) {
            Serial.print("LFO SYNC: ");
            button_toggle(btns.sync, btns.sync_hold);
        }

        btns.trig_hold = false;
        btns.inv_hold = false;
    } else if ((btns_val > btn_lfo_trig_res - RES_TOLERANCE) && (btns_val < btn_lfo_trig_res + RES_TOLERANCE)) {
        if (btns.trig_hold == false) {
            Serial.print("LFO TRIG: ");
            button_toggle(btns.trig, btns.trig_hold);
        }

        btns.sync_hold = false;
        btns.inv_hold = false;
    } else if ((btns_val > btn_lfo_sync_trig_res - RES_TOLERANCE) && (btns_val < btn_lfo_sync_trig_res + RES_TOLERANCE)) {
        if (btns.sync_hold == false) {
            Serial.print("LFO SYNC: ");
            button_toggle(btns.sync, btns.sync_hold);
        }

        if (btns.trig_hold == false) {
            Serial.print("LFO TRIG: ");
            button_toggle(btns.trig, btns.trig_hold);
        }

        btns.inv_hold = false;
    } else if ((btns_val > btn_lfo_inv_res - RES_TOLERANCE) && (btns_val < btn_lfo_inv_res + RES_TOLERANCE)) {
        if (btns.inv_hold == false) {
            Serial.print("LFO INV: ");
            button_toggle(btns.inv, btns.inv_hold);
        }

        btns.trig_hold = false;
        btns.sync_hold = false;
    } else if ((btns_val > btn_lfo_sync_inv_res - RES_TOLERANCE) && (btns_val < btn_lfo_sync_inv_res + RES_TOLERANCE)) {
        if (btns.sync_hold == false) {
            Serial.print("LFO SYNC: ");
            button_toggle(btns.sync, btns.sync_hold);
        }

        if (btns.inv_hold == false) {
            Serial.print("LFO INV: ");
            button_toggle(btns.inv, btns.inv_hold);
        }

        btns.trig_hold = false;
    } else if ((btns_val > btn_lfo_trig_inv_res - RES_TOLERANCE) && (btns_val < btn_lfo_trig_inv_res + RES_TOLERANCE)) {
        if (btns.trig_hold == false) {
            Serial.print("LFO TRIG: ");
            button_toggle(btns.trig, btns.trig_hold);
        }

        if (btns.inv_hold == false) {
            Serial.print("LFO INV: ");
            button_toggle(btns.inv, btns.inv_hold);
        }

        btns.sync_hold = false;
    } else if (btns_val < RES_TOLERANCE) {
        btns.sync_hold = false;
        btns.trig_hold = false;
        btns.inv_hold = false;
    }
}


int mux_read_6_pos_switch(int mux_no, int channel, switch_6_pos_t &swch) {
    int midi_cc = 0;

    mux_switch_channel(mux_no, channel);

    int swch_val = analogRead(A0);

    if ((swch_val > switch_6_pos_res[0] - SWITCH_TOLERANCE) && (swch_val < switch_6_pos_res[0] + SWITCH_TOLERANCE)) midi_cc = 0;
    else if ((swch_val > switch_6_pos_res[1] - SWITCH_TOLERANCE) && (swch_val < switch_6_pos_res[1] + SWITCH_TOLERANCE)) midi_cc = 25;
    else if ((swch_val > switch_6_pos_res[2] - SWITCH_TOLERANCE) && (swch_val < switch_6_pos_res[2] + SWITCH_TOLERANCE)) midi_cc = 51;
    else if ((swch_val > switch_6_pos_res[3] - SWITCH_TOLERANCE) && (swch_val < switch_6_pos_res[3] + SWITCH_TOLERANCE)) midi_cc = 76;
    else if ((swch_val > switch_6_pos_res[4] - SWITCH_TOLERANCE) && (swch_val < switch_6_pos_res[4] + SWITCH_TOLERANCE)) midi_cc = 102;
    else if ((swch_val > switch_6_pos_res[5] - SWITCH_TOLERANCE) && (swch_val < switch_6_pos_res[5] + SWITCH_TOLERANCE)) midi_cc = 127;
    else midi_cc = -1;

    return(midi_cc);
}


void button_toggle(bool &button, bool &hold) {
    hold = true;

    if (button == true) {
        button = false;

        tlc.setLED(0, 0, 0, 0);
        tlc.write();
    } else {
        button = true;

        tlc.setLED(0, 4059, 0, 0);
        tlc.write();
    }

    Serial.println(button);
}


void mux_switch_channel(int mux_no, int channel) {
	for (int i = 0; i < 4; i++) {
        digitalWrite(mux[mux_no][i], mux_channel[channel][i]);
	}
}


void pot_init(potentiometer_t &pot) {
    for (int i = 0; i < POT_AVG; i++) {
        pot.val[i] = 0;
    }
}


int avg(int *arr, int arr_size) {
    int val_avg = 0;

    for (int i = 0; i < arr_size; i++) {
        val_avg = val_avg + arr[i];
    }

    val_avg = val_avg / POT_AVG;

    return(val_avg);
}


int val2midi_cc(int val) {
    int midi_cc = 0;

    midi_cc = int(val / 8.0551);

    return (midi_cc);
}


int mux_init_pins(int *mux) {
    for (int pin = 0; pin < 3; pin++) {
        pinMode(mux[pin], OUTPUT);
    }
}
