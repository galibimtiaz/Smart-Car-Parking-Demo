#include <Arduino.h>

#include <SPI.h>
#include <Ethernet.h>

#include "car_parking/Barrier.h"
#include "car_parking/CarSensor.h"
#include "car_parking/Firebase.h"

CarSensor gateFront(22, 23, 100, 5);
CarSensor gateBack(24, 25, 100, 5);

CarSensor carSlot1(26, 27, 100, 10);
CarSensor carSlot2(28, 29, 100, 10);
CarSensor carSlot3(30, 31, 100, 10);
CarSensor carSlot4(32, 33, 100, 10);

Barrier barrier(10);
Firebase firebase;

String roundUp(long value);

void setup() {

	Serial.begin(115200);
	barrier.attach(A0);

}

void loop() {


	unsigned long currentMillis = millis();

	carSlot1.update(currentMillis);
	carSlot2.update(currentMillis);
	carSlot3.update(currentMillis);
	carSlot4.update(currentMillis);
	gateFront.update(currentMillis);
	gateBack.update(currentMillis);
	barrier.update(currentMillis);

	firebase.update(carSlot1.getAvability(), carSlot2.getAvability(),
			carSlot3.getAvability(), carSlot4.getAvability(), currentMillis);


	if (carSlot1.getAvability() || carSlot2.getAvability()
			|| carSlot3.getAvability() || carSlot4.getAvability()) {

		if (!gateFront.getAvability() || !gateBack.getAvability()) {
			barrier.open();
		} else {
			barrier.close();
		}
	}


	String valus = roundUp(carSlot1.getDistance()) + " "
				+  roundUp(carSlot2.getDistance()) + String(" ")
				+  roundUp(carSlot3.getDistance()) + String(" ")
				+ roundUp(carSlot4.getDistance());
		//Serial.println(valus);

		String gate = (int) gateFront.getDistance() + String(" ")
				+ (int) gateBack.getDistance();
		//Serial.println(gate);

		String va = (bool) carSlot1.getAvability() + String(" ")
				+ (bool) carSlot2.getAvability() + String(" ")
				+ (bool) carSlot3.getAvability() + String(" ")
				+ (bool) carSlot4.getAvability();
		//Serial.println(va);

}

String roundUp(float number) {

	if (number < 10) {
		return String("000") + number;
	} else if (number < 100) {
		return String("00") + number;
	} else if (number < 1000) {
		return String("0") + number;
	} else {
		return String("") + number;
	}

}

