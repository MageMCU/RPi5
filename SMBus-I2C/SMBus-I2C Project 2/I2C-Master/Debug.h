//
// Carpenter Software
// File: Debug.h
// Github: MageMCU
// Repository: Numerics
// Folder: include
//
// By Jesse Carpenter (carpentersoftware.com)
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Debug_h
#define Numerics_Debug_h

#ifdef _ARDUINO_
#include <Arduino.h>
#else
#include <iostream>
#include <string>

#define String string

using namespace std;

#endif // _ARDUINO_

namespace csjc
{

void Debug(String msg, int data)
{
    cout << msg << ": " << data << endl;
}

void Debug(String msg, uint8_t data1, uint8_t data2)
{
    cout << msg << ": " << (int)data1 << ", " << (int)data2 << endl;
}

void Debug(String msg, char data[], int size)
{
    cout << msg << endl;
    for (int i = 0; i < size; i++)
    {
        cout << " data[" << i << "]: " << (int)data[i] << endl;
    }
}

}

#endif
