/*
  Author: Samuel Hafen
  Description: Example code on how to use the Artnet-C library inside arduino for a esp32 ArtNet Node
  Dependency: Artnet-C v0.0.1
*/

#include <artnet_c_common.h>

#include <AsyncUDP.h>

void callback(AsyncUDPPacket packet);

AsyncUDP udp;

void setup() {
  Serial.begin(115000);
  Serial.println("Starting Artnet-C Example");

  // Try to write a constant value from the library
  Serial.println(artnet_id);


  udp.listen(6465);
  udp.onPacket(callback);

}

void callback(AsyncUDPPacket packet) {
  Serial.println("recieved Packet!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
