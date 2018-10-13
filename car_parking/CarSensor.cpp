/*
 * CarSensor.cpp
 *
 *  Created on: Sep 21, 2018
 *      Author: Galib
 */

#include "../car_parking/CarSensor.h"

#include <Arduino.h>

CarSensor::CarSensor(int trig, int echo, long intervel, int triggerDistance) {
	pinMode(trig, OUTPUT); // Sets the trigPin as an Output
	pinMode(echo, INPUT);  // Sets the echoPin as an Input

	_triggerDistance = triggerDistance;
	_available = false;
	_distance = 0;

	sonar = new NewPing(trig, echo, 100);
	median = new RunningMedian(10);

}

bool CarSensor::getAvability() {
	return _available;
}

float CarSensor::getDistance() {
	return _distance;
}

void CarSensor::update(unsigned long currentMillis) {

	median->add(sonar->ping_cm());
	_distance = median->getMedian();

	if (_distance <= _triggerDistance) {
		_available = false;
	} else {
		_available = true;
	}
}

CarSensor::~CarSensor() {
	// TODO Auto-generated destructor stub
}
