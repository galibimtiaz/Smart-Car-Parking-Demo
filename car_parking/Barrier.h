/*
 * Barrier.h
 *
 *  Created on: Sep 21, 2018
 *      Author: Galib
 */

#ifndef BARRIER_H_
#define BARRIER_H_

#include "Arduino.h"
#include "Servo.h"

class Barrier {
public:
	Barrier(int interval);
	void update(unsigned long currentMillis);
	void attach(int pin);
	void detach();
	void open();
	void close();
	virtual ~Barrier();

private:
	Servo servo;                   // the servo
	int pos = 0;                       // current servo position
	int increment = 0;                 // increment to move for each interval
	int updateInterval = 0;            // interval between updates
	unsigned long _previousMillis = 0; // last update of position

	void pause();

	int closed = 0;
	int opened = 1;
	int paused = 2;

	int current_state = closed;
	int previous_state = closed;
	bool _moving = false;
};

#endif /* BARRIER_H_ */
