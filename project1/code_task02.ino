//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// NWTEC2-2 - project 1
// 
// Made by rog ellenberger
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/1762969-nwtec2-2-project-1

// libraries
#include <avr/interrupt.h>
#include <avr/io.h>

// declare constants for pins used
const int inPin = A0;
const int outPin = 6;

// and vars for calculations
int sensorValue = 0;        // value read from the pot
float voltage = 0.0;

void setup() {
  // init fast PWM
  TCCR0A = 131;
  TCCR0B = 3;
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  pinMode(outPin, OUTPUT);
  
  // wait 5 sec that users have time to open serial monitor
  delay(5000);
  // display that programm starts
  Serial.println("start");
  
  
  // set OCR0A as needed (0 - 255)
  OCR0A = 0;
  
  // set count-register (0 - 255)
  TCNT0 = 55;
  
  int i;
  
  for (i = 0; i <= 255; i++) {
    messure_in_pin();
    
    // set OCR0A as needed (0 - 255)
    OCR0A++;
  }
}

void loop() {

}

void messure_in_pin() {
  // print out time elapsed since start (in ms)
  Serial.print(millis());
  // print semicolon for csv export
  Serial.print(";");
  // read the input on analog pin 0:
  sensorValue = analogRead(inPin);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}

