#include <Arduino.h>
#include <SoftwareSerial.h>
//#include <TinySoftwareSerial.h> //Use Pin 5/0 and Pin 6/1 on ATTiny85/Arduino
//SoftwareSerial mySerial(4, 3); // RX, TX

// pinout                Phy  |   AVR |   Arduino
#define ledPin1     1  // 6       PB1         1
#define ledPin2     3  // 2       PB3         3
#define ledPin3     4  // 3       PB4         4
#define gatePin     0  // 5       PB0         0
#define tempPin     A0 // 1       PB5         A0
#define switchPin   2  // 7       PB2         2

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(gatePin, OUTPUT);
    //pinMode(tempPin, INPUT);
    pinMode(switchPin, INPUT);

    //	Serial.begin(9600);
    //	mySerial.begin(9600);
    //    OSCCAL=200;
}

void loop() {
}
