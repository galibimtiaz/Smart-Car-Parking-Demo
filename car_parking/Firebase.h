/*
 * Firebase.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Galib
 */

#ifndef FIREBASE_H_
#define FIREBASE_H_

#include "Arduino.h"
#include "SPI.h"
#include "Ethernet.h"


class Firebase {

public:
	Firebase();
	void update(bool slot1, bool slot2, bool slot3,bool slot4, unsigned long currentMillis);
	void post(bool slot1, bool slot2, bool slot3, bool slot4);

private:
	unsigned long _previousMillis = 0;
	const unsigned long updateInterval = 1.5L * 1000L;
	char server = { "www.twiined.com" };
	byte mac[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

	EthernetClient client;
	bool preSlot1 = false;
	bool preSlot2 = false;
	bool preSlot3 = false;
	bool preSlot4 = false;
};


#endif /* CAR_PARKING_FIREBASE_H_ */
