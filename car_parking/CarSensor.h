/*
 * CarSensor.h
 *
 *  Created on: Sep 21, 2018
 *      Author: Galib
 */

#ifndef CARSENSOR_H_
#define CARSENSOR_H_

#include "Arduino.h"
#include <NewPing.h>
#include "RunningMedian.h"

class CarSensor {
public:
	CarSensor(int trig, int echo, long intervel, int triggerDistance);
	float getDistance();
	bool getAvability();
	void update(unsigned long currentMillis);
	virtual ~CarSensor();

private:
	float _distance;
	int _triggerDistance;
	bool _available;

	NewPing *sonar;
	RunningMedian *median;
};

#endif /* CARSENSOR_H_ */
