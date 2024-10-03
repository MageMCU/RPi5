//
// Carpenter Software
// Folder: PiMasterI2C/main.cpp
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

#include <iostream>
#include <wiringPi.h>
#include <wiringPiI2C.h>

using namespace std;

// Arduino Uno Slave Address
#define SLAVE_ADDRESS 0x10

// Global Variables
int g_fd = 0;
int g_data = 174;
int g_result = 0;
bool g_sendFlag = true;
bool g_i2cFailed = false;

// Arduino like function
void setup()
{
    g_fd = wiringPiI2CSetup(SLAVE_ADDRESS);
    if (g_fd == -1)
    {
        cout << "Failed to init I2C Comms... fd: " << g_fd << endl;
    }
    else
    {
        cout << "I2C Comms. successfully setup. fd: " << g_fd <<endl;
        //
        int dataSize = sizeof(g_data);
        cout << "data value:" << g_data << " size of data: " << dataSize << endl;
    }
}

// Arduino like function
void loop()
{
    if (g_sendFlag)
    {
        // This will call Arduino Wire.onReceive()
        g_result = wiringPiI2CWrite(g_fd, g_data);
        cout << "wiringPiI2CWrite result: " << g_result << endl;

        g_sendFlag = false;
    }
    else
    {
        // This will call Arduino Wire.onRequest()
        g_result = wiringPiI2CRead(g_fd);
        cout << "wiringPiI2CRead result: " << g_result << endl;

        if (g_result == 103)
            g_sendFlag = true;
    }
    delay(1000);
}

int main()
{
    // Arduino like Setup function
    setup();
    // Check fd result
    if (g_fd == -1)
    {
        cout << "main exit: " << g_fd <<endl;
        return -1;
    }
    // Arduino like Loop function
    // To Exit - Press CTRL 'C'
    while(true) loop();
    return 0;
}
