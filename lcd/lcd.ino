#include "Arduino.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 2, 3, 4, 5); // pins RS, E, DB4, DB5, DB6, DB7

int trig = 46; // trigger pin
int echo = 50; // echo pin

int LEDPIN = 10; // LED pin

float distance;

void setup () {
	Serial.begin(9600); // open the serial bus to the computer
	pinMode(trig, OUTPUT); // set trigger pin to OUTPUT mode
	pinMode(echo, INPUT); // set echo pin to INPUT mode

	pinMode(LEDPIN, OUTPUT); // set LED pin to OUTPUT mode
	digitalWrite(LEDPIN, LOW); // turn off LED

	lcd.begin(16, 2); // inform the library that the LCD display is 16 columns and 2 rows

	lcd.print("hello"); // print "hello" to the LCD display
}

void loop () {
	bool DEBUG = true; // turn to false to disable the program

	if (DEBUG) {
		digitalWrite(trig, HIGH); // trigger the pulse
		delayMicroseconds(10); // trigger should last 10 microsends
		digitalWrite(trig, LOW); // 10 microseconds has passed, turn off the trigger

		unsigned long time = pulseIn(echo, HIGH, 30000UL); // wait for the echo, record how many microseconds it took to receive, timeout if it takes more than 30 milliseconds

		if (time == 0) { // recorded time is zero in case of timeout, this means there's no object detected
			Serial.println("nada"); // print to computer
			lcd.print("nada"); // print to LCD display
		} else {
			distance = (time / 58.0); // 58 microseconds of echo delay per 1 centimeter of distance between the sensor and object

			lcd.setCursor(0, 1);
			lcd.print("Distance:       "); // print to LCD display

			lcd.setCursor(10, 1);
			lcd.print(distance, 2); // print to LCD display
			Serial.println(distance); // print to the computer

			if (distance < 4) { // if closer than 4 centimeters
				digitalWrite(LEDPIN, HIGH); // turn on the LED
			} else {
				digitalWrite(LEDPIN, LOW); // turn off the LED
			}
		}

		delay(100); // wait 100 milliseconds before looping again
	}
}

