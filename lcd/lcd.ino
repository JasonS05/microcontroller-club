#include "Arduino.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 2, 3, 4, 5); // pins RS, E, DB4, DB5, DB6, DB7

int trig = 46; // container for trig input
int echo = 50; // container

int LEDPIN = 10;

float distance;

void setup () {
	Serial.begin(9600);
	pinMode(trig, OUTPUT); // going to transmit the 10 microsecond
	pinMode(echo, INPUT);

	pinMode(LEDPIN, OUTPUT);
	digitalWrite(LEDPIN, LOW);

	lcd.begin(16, 2); // display is 16 columns and 2 rows

	lcd.print("hello");
}

void loop () {
	bool DEBUG = true;

	if (DEBUG) {
		digitalWrite(trig, HIGH); // trigger the pulse
		delayMicroseconds(10);

		digitalWrite(trig, LOW);

		unsigned long time; // make a contrainer to hold the time elapsed

		time = pulseIn(echo, HIGH, 30000UL);

		if (time == 0) {
			Serial.println("nada");
			lcd.print("nada");
		} else {
			distance = (time / 58.0);

			lcd.setCursor(0, 1);
			lcd.print("Distance:       ");

			lcd.setCursor(10, 1);
			lcd.print(distance, 2);
			Serial.println(distance); // print out the damn thing

			if (distance < 4) {
				digitalWrite(LEDPIN, HIGH);
			} else {
				(digitalWrite(LEDPIN, LOW));
			}
		}

		delay(100); // milliseconds
	}
}

