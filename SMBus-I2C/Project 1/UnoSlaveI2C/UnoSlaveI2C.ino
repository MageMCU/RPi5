
#include <Wire.h>

#define SLAVE_ADDRESS 0x10

// Single byte
byte data = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  // Wire-I2C-Setup
  Wire.begin(SLAVE_ADDRESS);
  // Call back event
  Wire.onReceive(receiveEvent);
  Wire.onRequest(acknowledge);
}

void loop() {
  delay(100);
}

// Receive Event from Master-Pi
void receiveEvent(int byteCount) {
  Serial.print("Uno Recv'd Event: ");
  Serial.println(byteCount);
  while (Wire.available() > 0) {
    data = Wire.read();
  }
  // User Serial Monitor for testing
  Serial.print("Data Recv'd: ");
  Serial.println(data);
}

void acknowledge() {
  Wire.write(103);
}
