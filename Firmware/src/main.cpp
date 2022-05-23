/* Copyright (c) 2022 Khairulmizam Samsudin <xource@gmail.com
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

#include <avr/io.h>
#include <util/delay.h>

// pinout                Phy  |   AVR |   Arduino
#define LEDPIN1     1  // 6       PB1         1
#define LEDPIN2     3  // 2       PB3         3
#define LEDPIN3     4  // 3       PB4         4
#define GATEPIN     0  // 5       PB0         0
#define TEMPPIN     A0 // 1       PB5         A0
#define SWITCHPIN   2  // 7       PB2         2

#define TEMP_GAIN	    1
#define TEMP_OFFSET	    410     // Biased at 2V. 2/5*1024=410
#define TEMP_SCALE      500     // LM35: 10mV per Celcius i.e. 5V/0.010 = 500
#define VRef            1.1                 
#define ITEMP_GAIN	    1
#define ITEMP_OFFSET    275     // Offet for 0deg Celcius	
#define ITEMP_SCALE     1       // AVR temp sensor: 1LSB per celcius    

static inline void initADC(void) {
    ADCSRA |= ((1 << ADPS1)| (1 << ADPS2)); // ADC clock prescaler /64. 8Mhz/64 = 125kHz
    ADCSRA |= (1 << ADEN);                  // enable ADC
}

uint16_t getTemp(void) { 
    uint16_t temp;
    ADMUX &= (~(1 << REFS1) | ~(1 << REFS0));   // Vcc as Voltage Ref 
    ADMUX &= 0xf0;                              // Select PB5 (ADC0)
    ADCSRA |= (1 << ADSC);                      // Start conversion
    loop_until_bit_is_clear(ADCSRA, ADSC);
    temp = TEMP_GAIN * (ADC - TEMP_OFFSET) * TEMP_SCALE / 1024; 
    return (temp); 
}

uint16_t getInternalTemp(void) { 
    uint16_t temp;
    ADMUX |= (1 << REFS1);   // Internal 1.1V Voltage Ref 
    ADMUX |= 0xff;           // Select ADC4
    ADCSRA |= (1 << ADSC);   // Start conversion
    loop_until_bit_is_clear(ADCSRA, ADSC);
    temp = ITEMP_GAIN * (ADC - ITEMP_OFFSET);
    return (temp);           
}

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
