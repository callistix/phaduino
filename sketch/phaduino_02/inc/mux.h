#ifndef MUX_H
#define MUX_H

const int mux_msg[16][4]={
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


struct s_mux {
    char pin_control[4];
    char pin_signal;
};


struct s_mux mux;


int mux_init(struct s_mux *mux);
int mux_channel(struct s_mux *mux, char channel);


int mux_init(struct s_mux *mux) {
    for (int pin = 0; pin < 3; pin++) {
        pinMode(mux->pin_control[pin], OUTPUT);
    }

    mux_channel(mux, 0);
}


int mux_channel(struct s_mux *mux, char channel) {
	for (int pin = 0; pin < 4; pin++) {
        digitalWrite(mux->pin_control[pin], mux_msg[channel][pin]);
	}
}

#endif
