## Synopsis

Test arduino's capability to trigger an event once each 10th of a second for 5 seconds, then pause for 15 seconds (on loop).

## Settings

int activeInterval = 5000;         // in milliseconds - interval to run application

int inactiveInterval = 15000;      // in milliseconds - interval to pause application

int applicationClockSpeed = 100;   // in milliseconds - clock speed interval / speed in which the board loops program

## Motivation

Software developed towards the development of the EcoSystem Aeroponic hardware/software program.

## Installation

Download and install Arduino IDE: https://www.arduino.cc/en/main/software

Download and install Master Timer: http://playground.arduino.cc/Code/Timer

Connect Arduino host and install/Run timer_sketch

## Tests

Open Arduion IDE > Select "Tools" > Select "Serial Monitor"

Run "timer_sketch"

See serial monitor output

## License

MIT

## Author

Nick Taras (EcoSystem project team 2017).
