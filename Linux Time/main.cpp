//
// Carpenter Software
// File: main.cpp
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

#include <iostream>
#include "Timer.h"

using namespace std;
using namespace csjc;

// GLOBAL variables
Timer timer;

// Fatal Error
int _err_ = 0;

void setup()
{
    timer = Timer();
}

void loop()
{
    if (timer.isTimer(1000))
    {
        cout << "tick" << endl;
    }
}

int main()
{
    setup();
    while (_err_ == 0)
    {
        loop();
    }
    // List all errors here...
    if (_err_ == 1)
        cout << "err-1: ???" << endl;
    return _err_;
}
