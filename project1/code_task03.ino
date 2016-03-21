//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// NWTEC2-2 - project 1
// 
// Made by rog ellenberger
// License: CC-BY-SA 3.0

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
  TCCR0B = 5;
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  pinMode(outPin, OUTPUT);
  
  // wait 5 sec that users have time to open serial monitor
  // display that programm starts
  
  
  
  
  
  // set OCR0A as needed (0 - 255)
  OCR0A = 8;
  // set count-register (0 - 255) 
  TCNT0 = 55;
  
  
}

void loop() {
  
  delay(1000);
  
  unsigned int time[32];
  unsigned int value[32];
  int i=0;
  
  for (; i < 33; i++) {
    time[i] = micros();
    value[i] = analogRead(inPin);
  }
  
  unsigned int maxval = 0;
  unsigned int minval= 1024;
  unsigned int sum;
  unsigned int avg;
  
  for (i=0; i<33; i++) {
    if (value[i] > maxval) {
      maxval = value[i];
    }
    if (value[i] < minval) {
      minval = value[i];
    }
    
    sum = sum + value[i];
  }
  avg = sum / 128;
  
  
  Serial.print(OCR0A);
  Serial.print(",");
  Serial.print(maxval);
  Serial.print(",");
  Serial.print(minval);
  Serial.print(",");
  Serial.println(avg);
  
  OCR0A = OCR0A + 8;
  
  
  
}


