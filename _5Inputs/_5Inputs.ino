/*
  Calibration

 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.

 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.

 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground

 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Calibration

 This example code is in the public domain.

 */

// These constants won't change:
// pin that the sensor is attached to
const int sensorPin1 = A1;
const int sensorPin2 = A2;
const int sensorPin3 = A3;
const int sensorPin4 = A4;
const int sensorPin5 = A5;

// pin that the LED is attached to
const int ledPin1 = 3;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 9;
const int ledPin5 = 11;

// variables:
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  sensorValue5 = analogRead(sensorPin5);

  // apply the calibration to the sensor reading
  sensorValue1 = map(sensorValue1, 1, 1010, 0, 255);
  sensorValue2 = map(sensorValue2, 1, 1010, 0, 255);
  sensorValue3 = map(sensorValue3, 1, 1000, 0, 255);
  sensorValue4 = map(sensorValue4, 1, 1010, 0, 255);
  sensorValue5 = map(sensorValue5, 1, 1010, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue1 = constrain(sensorValue1, 0, 255);
  sensorValue2 = constrain(sensorValue2, 0, 255);
  sensorValue3 = constrain(sensorValue3, 0, 255);
  sensorValue4 = constrain(sensorValue4, 0, 255);
  sensorValue5 = constrain(sensorValue5, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin5, sensorValue1);
  analogWrite(ledPin4, sensorValue2);
  analogWrite(ledPin3, sensorValue3);
  analogWrite(ledPin2, sensorValue4);
  analogWrite(ledPin1, sensorValue5);

  //Values readable for Max
  Serial.print (sensorValue1);
  Serial.print (" ");
  Serial.print (sensorValue2);
  Serial.print (" ");
  Serial.print (sensorValue3);
  Serial.print (" ");
  Serial.print (sensorValue4);
  Serial.print (" ");
  Serial.print (sensorValue5);
  Serial.println(); 
 
  delay(100);
}
