# Requirements

* `apt-get install arduino`
* in Arduino IDE install following libraries:
** MIDI Library
** `CD74HC4067`


# Usage

* flash the original firmware for uploading sketches:

```bash
cd sh
./flash_usbserial
```

* flash the midi firmware to make it appear as MIDI device:

```bash
cd sh
./flash_midi
```


# Code hierarchy

* Sections (LFO, DCO, ...)
    * Controls (LFO rate, LFO delay, 3 way buttons, ...) (objects are control types, i.e. pot, 3 way switch, 5 way switch)

# BOM

## clean up

* [ ] 9/9 LEDs
* [ ] 3/3 rotary switch 6 positions + caps
* [ ] 22/22 potentiometers + caps
* [ ] 0/4 potentiometers with middle notch + caps
* [ ] 20/29 slide potentiometers + caps
* [ ] 0/2 slide switch 3 positions + caps
* [ ] 0/6 slide switch 4 positions + caps
* [ ] 0/1 slide switch 5 positions + caps
* [ ] 0/21 push buttons + caps
* [ ] 0/1 rotary selector 5 positions + cap
* [ ] 0/2 double digits LED number display
* [ ] M3 round-head screws 20mm + washers + nuts


# To-do

* do not retract filament on when printing is paused for filament change, as this seems to drop a blob of material, just move the nozzle out of the way
* text looks messy due to above issue, but maybe increase font size as well to make it more readable, or would a second layer of white filament help maybe?
* add scale labels for reverb pots
* add a way to attach sections to each other with screws
* instantiate object rather than duplicating them

# Links

## Arduino basics

* [Arduino Push Button Tutorial (step by step)](https://www.youtube.com/watch?v=J_07uwur_MI&t=32s)
* [Arduino LED – Complete Tutorial](https://roboticsbackend.com/arduino-led-complete-tutorial/)

## Arduino MIDI controller

* [Quick Hack! - USB MIDI Controller with Arduino UNO](https://www.youtube.com/watch?v=3haK5QGbi_E)
* [Arduino MIDI Library Documentation](https://fortyseveneffects.github.io/arduino_midi_library/index.html)

## Multiplexing analogue pins

* [How can I connect multiple potentiometers (~20) to my Arduino without having to have 20 analogue pins?](https://electronics.stackexchange.com/questions/659309/how-can-i-connect-multiple-potentiometers-20-to-my-arduino-without-having-to)
* [Arduino CD74HC4067 Analog Multiplexer Library, Code Example](https://deepbluembedded.com/arduino-cd74hc4067-analog-multiplexer-library-code/)
* [Muxing Around With The CD74HC4067 + Arduino](https://adam-meyer.com/arduino/CD74HC4067)

## Multiplexing LEDs

* [Multiplexing 7 Segment Displays With Arduino and Shift Registers](https://www.instructables.com/Multiplexing-7-Segment-displays-with-Arduino-and-S/)
* [Charlieplexing](https://en.wikipedia.org/wiki/Charlieplexing)
* [Multiplexing With Arduino and the 74HC595](https://www.instructables.com/Multiplexing-with-Arduino-and-the-74HC595/)
* [Controlling LEDs with A Multiplexer and Arduino](https://makersportal.com/blog/2019/3/12/controlling-leds-with-multiplexer-and-arduino)

## `TLC5947`

* [TLC5947 and TLC59711 PWM LED Driver Breakouts](https://learn.adafruit.com/tlc5947-tlc59711-pwm-led-driver-breakout/overview)
* [Interfacing TLC5947 PWM Module with Arduino (12-Bit LED Drivers)](https://electropeak.com/learn/interfacing-tlc5947-pwm-module-with-arduino-12-bit-led-drivers/)

## 3D Print labelling

* [Labeling Your Parts with Engraver Filler](https://markforged.com/resources/blog/engraver-filler-labeling)
* [3D Print Inlay Lettering](https://www.youtube.com/watch?v=W2f5lI1R6dg)
* [Finishing 3D prints with nailpolish and acetone](https://www.youtube.com/watch?v=4iX6x2MLhH0)

## FreeCAD

* [Draft ShapeString](https://wiki.freecad.org/Draft_ShapeString)
* [Draft ShapeString tutorial](https://wiki.freecad.org/Draft_ShapeString_tutorial)
* [How to create solids from 2D image?](https://www.xsim.info/articles/FreeCAD/en-US/HowTo/Create-solids-from-2D-image.html)

## Measuring

* [How to Measure Amperage](https://www.wikihow.com/Measure-Amperage)

## C++
* [ArduinoSTL](https://github.com/mike-matera/ArduinoSTL)
