// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// NWTEC2-2 - project3
// 
// Made by Rog Ellenberger
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/2145249-nwtec2-2-projekt3


// libraries
#include <avr/interrupt.h>
#include <avr/io.h>

// declare constants for pins used
const int IN_PIN_E = A0;
const int IN_PIN_A = A1;
const int OUT_PIN= 6;

// and vars for calculations
int sensorValue = 0;        // value read from the analog input

void setup() {
  // init fast PWM
  TCCR0A = 131;
  TCCR0B = 3;        // specify clock-rate
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  // PWM-Pin
  pinMode(OUT_PIN, OUTPUT);
  
    // set OCR0A as needed (0 - 255) -> sets PWM UP for n/255
  OCR0A = 0;
  // set count-register (0 - 255) 
  TCNT0 = 55;
    
}

void loop() {
  // give yourself time to open serial monitor
  delay(3000);
  
  unsigned int value_E;
  unsigned int value_A;
  int i;
  int j;
  
  Serial.println("OCR0A,value_E,value_A");
  
  for (i=0; i < 256; i++) {
    OCR0A = i;
    
    // mesure an average value to be more precise
    for (j=0; j<16; j++) {
      value_E += analogRead(IN_PIN_E);
      value_A += analogRead(IN_PIN_A);
    }
    
    // calculate avg
    value_E = value_E/16;
    value_A = value_A/16;
    
    // print to serial output
    Serial.print(OCR0A);
    Serial.print(",");
    Serial.print(value_E);
    Serial.print(",");
    Serial.println(value_A);
  }
  
  // halt the programm in a weird way  
  delay(10000000);
    
}


