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

# Print settings

* filament:
    * SUNLU PLA+ black (main)
    * SUNLU PLA+ white (labels)

* nozzle temp.: 220 degrees
* build plate temp.: 75 degrees
* wall line count: 3
* top / bottom layers: 3
* infill: gyroid 20%
* print speed: 50mm/s
* infill speed: 75mm/s
* support speed: 75mm/s
* travel speed: 200mm/s
* retraction distance: 8.0mm
* fan speed: 100%
* support pattern: Zig Zag
* support density: 10%
* use adaptive layers: no

* "Pause at height" setting for filament changing:
    * pause layer: last layer before labels
    * method: BQ
    * keep motors engaged
    * park print: yes
    * retraction: 450mm
    * standby temperature: 220 deg.
    * beep at pause
* enable draft shield: yes (to prime extruder after filament change)

# Notes

* let hot bed cool down entirely before attempting to remove print, or otherwise it will warp

# To-do

* build plate needs leveling, right side seems more faint
* when changing to white filament layers, increase nozzle temperature and retraction distance to i.e. 9 or 10mm
    * for black filament, lower to i.e. 6 or 7 mm retraction distance and 220 degrees
* make pot labels font size 1 pixel bigger for better readability
* test and define the way the pieces attach to each other
    * maybe remove screws 5 and 6 again, then print intermediate connector parts

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
