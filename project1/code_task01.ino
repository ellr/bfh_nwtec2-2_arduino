//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// NWTEC2-2 - project 1
// 
// Made by rog ellenberger
// License: CC-BY-SA 3.0

// declare constants for pins used
const int inPin = A0;  // Analog input pin that the potentiometer is attached to
const int outPin = 6; // Analog output pin that the LED is attached to

// and vars for calculations
int sensorValue = 0;        // value read from the pot
float voltage = 0.0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
    
  // wait 5 sec that users have time to open serial monitor
  delay(5000);
  
  // display that programm starts
  Serial.println("start");
  
  // power on pin 6
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin, HIGH);
  
  // give the capacitor 5 sec time to fully load
  delay(5000);   
  
  messure_in_pin();
  
  // power off pin 6
  digitalWrite(outPin, LOW);
}

void loop() {
  messure_in_pin();
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

