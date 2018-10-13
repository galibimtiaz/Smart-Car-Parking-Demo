/*
 * Firebase.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Galib
 */

#include "../car_parking/Firebase.h"

Firebase::Firebase() {

	Serial.println("FB is init");

	// start the Ethernet connection:
	/*if (Ethernet.begin(mac) == 0) {
		Serial.println("Failed to configure Ethernet using DHCP");
		Ethernet.begin(mac, IPAddress(server));
	}*/
	//Serial.println(Ethernet.localIP());

}

void Firebase::update(bool slot1, bool slot2, bool slot3, bool slot4,
		unsigned long currentMillis) {

	if (currentMillis - _previousMillis >= updateInterval) // time to update
			{

		_previousMillis = currentMillis;

		/*if (client.available()) {
			char c = client.read();
			Serial.write(c);
		}*/

		if (preSlot1 != slot1 || preSlot2 != slot2 || preSlot3 != slot3) {
			preSlot1 = slot1;
			preSlot2 = slot2;
			preSlot3 = slot3;
			//post(slot1, slot2, slot3, slot4);
			Serial.println(slot1 + slot2 + slot3 + slot4);
		}

	}

}

void Firebase::post(bool slot1, bool slot2, bool slot3, bool slot4) {

	client.stop();
	if (client.connect(server, 80)) {
		Serial.println("Connecting");
		client.print("GET /firebase.php?car1=");
		client.print(slot1);
		client.print("&car2=");
		client.print(slot2);
		client.print("&car3=");
		client.print(slot3);
		client.print("&car4=");
		client.print(slot4);
		client.println(" HTTP/1.1");
		client.println("Host: www.twiined.com");
		client.println("Connection: close");
		client.println();

		Serial.println("Request sent");

		Serial.println(client.status());

	} else {
		// if you didn't get a connection to the Firebase:
		Serial.println("connection failed");
	}

}
