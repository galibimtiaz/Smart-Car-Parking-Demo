/*
 * Barrier.cpp
 *
 *  Created on: Sep 21, 2018
 *      Author: Galib
 */

#include "../car_parking/Barrier.h"

Barrier::Barrier(int inc) {
	updateInterval = 1;
	increment = inc;

}

void Barrier::attach(int pin) {
	servo.attach(pin);
	servo.write(0);
}

void Barrier::detach() {
	servo.detach();
}

void Barrier::update(unsigned long currentMillis) {
	if (currentMillis - _previousMillis >= updateInterval) // time to update
			{

		_previousMillis = currentMillis;

		if (current_state == opened) {
			if (pos >= 186) {
				pause();
			} else {
				pos += increment;
				servo.write(pos);
				//Serial.println("openging");
			}

		} else if (current_state == closed) {
			if (pos <= 6) {
				pause();
			} else {
				pos -= increment;
				servo.write(pos);
				//Serial.println("closing");
			}

		} else {

			_moving = false;
		}
		//Serial.println(pos);
	}

}

void Barrier::open() {
	if (!_moving) {
		current_state = opened;
		_moving = true;
		//Serial.println("command open");
	}
}

void Barrier::close() {
	if (!_moving) {
		current_state = closed;
		_moving = true;
		//Serial.println("command close");
	}

}

void Barrier::pause() {
	if (current_state != previous_state) {
		previous_state = current_state;
		Serial.println("delaying");
		delay(1000);

	}
	current_state = paused;
}

Barrier::~Barrier() {
	// TODO Auto-generated destructor stub
}

