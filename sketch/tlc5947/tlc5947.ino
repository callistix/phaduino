/*************************************************** 
 * TLC5947 TEST base on adafruit library example 
 * electropeak
 * ALi Akbar Hosseini 
 These drivers uses SPI to communicate, 3 pins are required to 
 interface: Data, Clock and Latch. The boards are chainable

 Fixed typo in all occurences of NUM_TLC5947 (was 5974)
 ****************************************************/

#include "Adafruit_TLC5947.h"
// How many boards do you have chained?
#define NUM_TLC5947 1

#define data 4 //DIN changeable
#define clock 5 //CLK changeable
#define latch 6 //LAT changeable
#define oe -1 // set to -1 to not use the enable pin (its optional)

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);

void setup() {
 Serial.begin(9600); 
 Serial.println("TLC5947 test");
 tlc.begin();
 if (oe >= 0) {
 pinMode(oe, OUTPUT);
 digitalWrite(oe, LOW);
 }
}

void loop() {
    while (true) {
     tlc.setLED(0,4059,0,0);
     tlc.setLED(1,4059,0,0);
     tlc.setLED(3,0,0,4059);
     tlc.write();
     delay(50);
     tlc.setLED(0,0,0,0);
     tlc.setLED(1,0,0,0);
     tlc.setLED(3,0,0,0);
     tlc.write();
     delay(50);
    }
}


// Fill the dots one after the other with a color
void colorWipe(uint16_t r, uint16_t g, uint16_t b, uint8_t wait) {
 for(uint16_t i=0; i<8*NUM_TLC5947; i++) {
 tlc.setLED(i, r, g, b);
 tlc.write();
 delay(wait);
 }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
 uint32_t i, j;

 for(j=0; j<4096; j++) { // 1 cycle of all colors on wheel
 for(i=0; i< 8*NUM_TLC5947; i++) {
 Wheel(i, ((i * 4096 / (8*NUM_TLC5947)) + j) & 4095);
 }
 tlc.write();
 delay(wait);
 }
}

// Input a value 0 to 4095 to get a color value.
// The colours are a transition r - g - b - back to r.
void Wheel(uint8_t ledn, uint16_t WheelPos) {
 if(WheelPos < 1365) {
 tlc.setLED(ledn, 3*WheelPos, 4095 - 3*WheelPos, 0);
 } else if(WheelPos < 2731) {
 WheelPos -= 1365;
 tlc.setLED(ledn, 4095 - 3*WheelPos, 0, 3*WheelPos);
 } else {
 WheelPos -= 2731;
 tlc.setLED(ledn, 0, 3*WheelPos, 4095 - 3*WheelPos);
 }
}
