//
// Carpenter Software
// File: main.cpp - I2C-Slave1
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
//
#include "Button.h"
#include "Timer.h"
#include "TypeConv.h"
//
#define I2C_ADDRESS_JOYSTICK 0x14
//
using namespace csjc;

// PROTOTYPES
void receiveReadEvent(int byteCount);
void requestWriteEvent();

// GLOBAL variables
uint8_t dataWX[7];
uint8_t dataRX[7];
int cntBytes = 7;
Button button;
Timer timer;
TypeConv typeConv;

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
  Wire.begin(I2C_ADDRESS_JOYSTICK);
  // Call back event
  Wire.onReceive(receiveReadEvent);
  Wire.onRequest(requestWriteEvent);

  //
  timer = Timer();
  //
  int buttonPin = 4;
  int ledPin = 2;
  button = Button(buttonPin, ledPin);
  //
  typeConv = TypeConv();
  //
  dataWX[0] = (uint8_t)I2C_ADDRESS_JOYSTICK;
  //
  updateFSMState(1);
}

void updateButtonState(uint8_t buttonState)
{
  dataWX[1] = buttonState;
}

void updateFSMState(uint8_t fsmState)
{
  dataWX[2] = fsmState;
}

void updateWriteI2C(int xAnalog, int yAnalog)
{
  // Input-X
  typeConv.WordTo2Bytes(xAnalog);
  dataWX[3] = typeConv.GetHiByte();
  dataWX[4] = typeConv.GetLoByte();
  // Input-Y
  typeConv.WordTo2Bytes(yAnalog);
  dataWX[5] = typeConv.GetHiByte();
  dataWX[6] = typeConv.GetLoByte();
  
  Debug(dataWX, 7);
}

void updateADC()
{
  // Note: Joystick is used only for data...
  // (1)
  // Analog to Digital (10-bit) Conversion
  // Digital Values from 0 to 1023
  // Read Article 1009 L298N Supplemental
  int xDigital = 1023 - analogRead(A0);
  int yDigital = 1023 - analogRead(A1);

  updateWriteI2C(xDigital, yDigital);
}

void loop() {
  button.updateButton();
  // Timer
  if (timer.isTimer(250))
  {
    // Button
    if (button.isButtonOn())
      updateButtonState((uint8_t)1);
    else
      updateButtonState((uint8_t)0);
    // FSM - NOT USED
    // ADC
    updateADC();
  }
}

// NOT USED ------------------------------
void receiveReadEvent(int byteCount)
{
  int cnt = 0;
  // Serial.print("Read Event MCU1: ");
  // Serial.println(byteCount);

  while (Wire.available() > 0) {
    dataRX[cnt] = Wire.read();
    // Serial.println(dataRX[cnt]);
    cnt++;
  }
  cntBytes = cnt;
  // Serial.println(cnt);
}

// Joystick MCU-1 ------------------ working
// Joystick used only for test data
void requestWriteEvent() {
  int cnt = 0;
  Serial.println("Write Event MCU1..");
  while (cnt < cntBytes)
  {
    // Serial.print(cnt);
    // Serial.print(": ");
    // Serial.println(dataWX[cnt]);
    Wire.write(dataWX[cnt]);
    cnt++;
  }
}
