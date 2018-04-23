/* 
  timer_sketch
  
  Test arduino's capability to trigger an event once each 10th of a second
  for 5 seconds, then pause for 15 seconds (on loop).
  modified 4 Feb 2017
  by Nick Taras 
*/

//Library: http://playground.arduino.cc/Code/Timer
#include <Timer.h>

// Timer instance
Timer t;

// Application configuration settings:
int activeInterval = 5000;         // in milliseconds
int inactiveInterval = 15000;      // in milliseconds
int applicationClockSpeed = 100;   // in milliseconds

// Main Application State Machine:
// "ACTIVE"   : commuication with hardware is permitted.
// "INACTIVE" : commuication with hardware is not permitted.
String state = "ACTIVE"; 

// High pressure Filter hardware State Machine:
String hpfState  = "ON";      // high pressure filter turn on/off
//TODO easier way to toggle power when using actual pins on the board
//t.oscillate(13, 50, HIGH);

void setup() {
  Serial.begin(9600);
  Serial.println("Init App");
}

// Active State
void activeStateUpdate() {
  state = "ACTIVE";
}

// Inactive State
void inactiveStateUpdate() {
  state = "INACTIVE";
}

// Update application 
void appUpdate() {
  hpfUpdate();
}

// Update high pressure filter with current state
void hpfUpdate() {
  if(state == "ACTIVE"){
    hpfToggle();
  } else if(state == "INACTIVE"){
    hpfState = "OFF";
  }
  Serial.println("hpfState: " + hpfState);
}

// Toggle the High Pressure filter on / off at applications clock speed.
void hpfToggle(){
  if(hpfState == "ON"){
    hpfState = "OFF";
  } else {
    hpfState = "ON";
  }
}

void loop() {

  //Serial.println("state: " + state);

  // Application timeline
  t.every(activeInterval, inactiveStateUpdate);
  t.every(inactiveInterval + activeInterval, activeStateUpdate);

  appUpdate();
  
  delay(applicationClockSpeed);
  
  t.update();
  
}
