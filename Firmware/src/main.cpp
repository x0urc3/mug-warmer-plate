/* (c) 2022 Khairulmizam Samsudin <xource@gmail.com
 *
 * Firmware for mug warmer plate  
 */

/* Design Notes
 * - Switch pin should use AVR internal pullup
 * - Temperature sensor Vout connected to PB5/Reset
 * 	- ATTiny85 PB5/RESET would reset if input <0.3*Vcc i.e. 0.3*5=1.5V
 * 	- LM35 sensor 200-800mV for temperature between 20-80 celcius i.e. 10mV/Celcius 
 * 	- LM35 Vout connected to ground with 18KOhm can measure value between -55 to 150 celcius
 * 		- Resolution would be reduced
 */
#include <Arduino.h>
#include <SoftwareSerial.h>
//#include <TinySoftwareSerial.h> //Use Pin 5/0 and Pin 6/1 on ATTiny85/Arduino
//SoftwareSerial mySerial(4, 3); // RX, TX

// pinout                Phy  |   AVR |   Arduino
#define LEDPIN1     1  // 6       PB1         1
#define LEDPIN2     3  // 2       PB3         3
#define LEDPIN3     4  // 3       PB4         4
#define GATEPIN     0  // 5       PB0         0
#define TEMPPIN     A0 // 1       PB5         A0
#define SWITCHPIN   2  // 7       PB2         2


void setup() {
    pinMode(LEDPIN1, OUTPUT);
    pinMode(LEDPIN2, OUTPUT);
    pinMode(LEDPIN3, OUTPUT);
    pinMode(GATEPIN, OUTPUT);
    pinMode(TEMPPIN, INPUT);
    pinMode(SWITCHPIN, INPUT_PULLUP);

    //	Serial.begin(9600);
    //	mySerial.begin(9600);
    //    OSCCAL=200;
}

void loop() {


}
