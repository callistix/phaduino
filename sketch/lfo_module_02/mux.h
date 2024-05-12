const int mux_pin_signal = A0;
const int mux_pin_control[4] = { 2, 3, 4, 5 };


void mux_channel_switch(int channel);


void mux_init(void) {
    for (int pin = 0; pin < 3; pin++) {
        pinMode(mux_pin_control[pin], OUTPUT);
    }

    mux_channel_switch(0);
}


void mux_channel_switch(int channel) {
	for (int i = 0; i < 4; i++) {
        digitalWrite(mux_pin_control[i], mux_channel[channel][i]);
	}
}
