//
// Carpenter Software
// File: main.cpp - I2C-Slave2
// Project: I2C-Project-006 - RPi3 I2C Feasibility Test
// Github: MageMCU
// Repository:
// Folder:
//
// By Jesse Carpenter (carpentersoftware.com)
//
// Testing Platform:
//  * COMPUTER:Raspberry Pi 3 Model B v1.2 2015 (See note.)
//  * Raspberry Pi OS (Bookworm 64-bits)
//  * Editor: Code::Blocks (or VSCode)
//  * MCU:Arduino Uno Rev.3 (Atmega328P)
//  * IDE:PlatformIO
//  * Editor: VSCode
//  * NOTE Computer may not run VSCode.
//
// MIT LICENSE
//

#include <Arduino.h>
#include <Wire.h>

#include "Timer.h"
#include "TypeConv.h"
//
#define I2C_ADDRESS_MOTORS 0x16

using namespace csjc;

// GLOBAL variables
uint8_t dataWX[7];
uint8_t dataRX[7];
int cntBytes = 7;
Timer timer;
TypeConv typeConv;

// PROTOTYPES
void receiveReadEvent(int byteCount);
void requestWriteEvent();

void Debug(uint8_t data[], int size)
{
  // I2C Address
  Serial.print("A: ");
  Serial.print((int)data[0]);
  // Button State
  Serial.print(" B: ");
  Serial.print((int)data[1]);
  // FSM State
  Serial.print(" F: ");
  Serial.print((int)data[2]);
  // xDigital
  int x = (int)typeConv.BytesToWord(data[3], data[4]);
  Serial.print(" X: ");
  Serial.print(x);
  // yDigital
  int y = (int)typeConv.BytesToWord(data[5], data[6]);
  Serial.print(" Y: ");
  Serial.println(y);
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  // Wire-I2C-Setup
  Wire.begin(I2C_ADDRESS_MOTORS);
  // Call back event
  Wire.onReceive(receiveReadEvent);
  Wire.onRequest(requestWriteEvent);

  //
  timer = Timer();
  //
  typeConv = TypeConv();
  //
  dataWX[0] = (uint8_t)I2C_ADDRESS_MOTORS;
}

void updateJoystick(int xDigital, int yDigital)
{
  // Note: Joystick is used only for data...
  Debug(dataRX, 7);
}

void updateADC()
{
  int xDigital = typeConv.BytesToWord(dataRX[3], dataRX[4]);
  int yDigital = typeConv.BytesToWord(dataRX[5], dataRX[6]);

  updateJoystick(xDigital, yDigital);
}

void loop() {
  // Timer
  if (timer.isTimer(250))
  {
    // FSM - NOT USED
    // ADC
    updateADC();
  }
}

// Motors MCU-2 ----------------- working
// Joystick used only for testing data
void receiveReadEvent(int byteCount)
{
  int cnt = 0;
  Serial.println("Read Event MCU2: ");

  while (Wire.available() > 0) {
    dataRX[cnt] = Wire.read();
    // Serial.print(cnt);
    // Serial.print(": ");
    // Serial.println(dataRX[cnt]);
    cnt++;
  }
  cntBytes = cnt;
}

// NOT USED ---------------------------- 
void requestWriteEvent() {
  int cnt = 0;
  Serial.println("Write Event MCU2..");
  while (cnt < cntBytes)
  {
    // Serial.print(cnt);
    // Serial.print(": ");
    // Serial.println(dataWX[cnt]);
    Wire.write(dataWX[cnt]);
    cnt++;
  }
}
