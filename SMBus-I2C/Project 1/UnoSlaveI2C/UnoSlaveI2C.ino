//
// Carpenter Software
// Folder: UnoSlaveI2C/UnoSlaveI2C.ino
// Github: MageMCU
// Repository: Raspberry Pi - Uno - I2C Communication
// Folder: SMBus-I2C/Project 1
//
// By Jesse Carpenter (carpentersoftware.com)
//
// Testing Platform:
//  * Raspberry Pi 3 Modole B v1.2 (2015)
//  * Arduino Uno Rev.3
//  * Arduino IDE - UnoSlaveI2C.ino
//  * Code::Blocks - main.cpp
//
// MIT LICENSE
//

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
