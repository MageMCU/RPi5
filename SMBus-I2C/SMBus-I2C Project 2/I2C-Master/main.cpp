//
// Carpenter Software
// File: main.cpp - I2C-Master
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


#ifdef _ARDUINO_
#include <Arduino.h>
#include <Wire.h>
#else
#include <iostream>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/types.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
#include <cmath>
#include <signal.h>
//
#include "LinuxTime.h"
#include "Timer.h"
#include "TypeConv.h"
#include "Debug.h"
// differs by a single letter (S)
#define String string
//
using namespace std;
using namespace csjc;
#endif

// Definition at fcntl-linux.h (BUGFIX) line-45
#define O_RDWR 02
// linux/i2c-dev.h (BUGFIX) line-28
#define I2C_SLAVE 0x0703
//
#define I2C_ADDRESS_JOYSTICK 0x14
#define I2C_ADDRESS_MOTORS 0x16
// Global Variables
char dataWX[7];
char dataRX[7];
int _count = 7;
Timer timer;
TypeConv typeConv;

// File Descriptor
int fd; // used for test 1
int fd1; // used for test 2
int fd2; // used for test 2

// Result Value
int rslt;

// Fatal Error
int _err_ = 0;

// Tested 20241218 OK
int MCU1()
{
    // Open the i2c device
    // Check Terminal: ls /dev/i2c*
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0)
    {
        cout << "Failed to open i2c device 1 ..." << fd << endl;
        return -1;
    }

    // MCU 1 - Address 0x14 - an arbitrary value
    rslt = ioctl(fd, I2C_SLAVE, I2C_ADDRESS_JOYSTICK);
    if (rslt < 0)
    {
        cout << "Failed to perform IOCTL 1 ..." << rslt << endl;
        return -2;
    }

    // READ MCU 1
    rslt = read(fd, dataRX, 7);
    Debug("Read rslt", (int)rslt);
    if (rslt < 0)
    {
        cout << "Failed to read dataRX..." << rslt << endl;
        return -3;
    }
    // Debug("Read data", (int)data2RX[0], (int)data2RX[1]);
    Debug("ReadI2C: ", dataRX, 7);

    close(fd);

    return 0;
}

// Tested 20241218 ok
int MCU2()
{
    // Open the i2c device
    // Check Terminal: ls /dev/i2c*
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0)
    {
        cout << "Failed to open i2c device 1 ..." << fd << endl;
        return -1;
    }

    // MCU 2 - Address 0x16 - an arbitrary value offset by 2
    rslt = ioctl(fd, I2C_SLAVE, I2C_ADDRESS_MOTORS);
    if (rslt < 0)
    {
        cout << "Failed to perform IOCTL 1 ..." << rslt << endl;
        return -2;
    }

    // READ MCU 2
    rslt = write(fd, dataRX, 7);
    if (rslt < 0)
    {
        cout << "Failed to write dataRX..." << endl;
        return -4;
    }

    close(fd);

    return 0;
}

int OpenI2C()
{
    // Open the i2c device
    // Check Terminal: ls /dev/i2c*
    int fileDescriptor = open("/dev/i2c-1", O_RDWR);
    if (fileDescriptor < 0)
    {
        cout << "Failed to open i2c device 1 ..." << fileDescriptor << endl;
        return -1;
    }
    return fileDescriptor;
}

int IOControl(int fileDescriptor, int address)
{
    rslt = ioctl(fileDescriptor, I2C_SLAVE, address);
    if (rslt < 0)
    {
        cout << "Failed to perform IOCTL 1 ..." << rslt << endl;
        return -2;
    }
    return 0;
}

int ReadI2C(int fileDescriptor)
{
    rslt = read(fileDescriptor, dataRX, 7);
    Debug("Read rslt", (int)rslt);
    if (rslt < 0)
    {
        cout << "Failed to read dataRX..." << rslt << endl;
        // BUGFIX commented-out
        // return -3;
    }
    // Debug("Read data", (int)data2RX[0], (int)data2RX[1]);
    Debug("ReadI2C: ", dataRX, 7);

    return 0;
}

int WriteI2C(int fileDescriptor)
{
    rslt = write(fileDescriptor, dataRX, 7);
    if (rslt < 0)
    {
        cout << "Failed to write iWX..." << endl;
        // BUGFIX commented-out
        // return -4;
    }
    return 0;
}

void CloseI2C(int fileDescriptor)
{
    close(fileDescriptor);
}

void setup()
{
    // Running two MCUs at the same time...
    //
    timer = Timer();
    //
    typeConv = TypeConv();
    //
    fd1 = OpenI2C();
    if (_err_ == 0) _err_ = IOControl(fd1, I2C_ADDRESS_JOYSTICK);
    //
    fd2 = OpenI2C();
    if (_err_ == 0) _err_ = IOControl(fd2, I2C_ADDRESS_MOTORS);
}

bool once = true;
void loop()
{
    // Slave baudrate 19200
    // Master is 1/2 of slave -------------------- README
    // Test 1 at 1000ms: all ok
    // Test 2 at 500ms: all ok
    // test 3 at 250ms: error occurs but working
    // Slave baudrate 115200: this may have little effect
    // test 3 at 250ms: error occurs but working
    // remove read & write errors to continue: all ok
    // Test 4 at 125ms: all ok
    // I'll stop here because MCU1 & MCU2 at 250ms has
    // shown in previous test that motors can be adjusted
    // sufficiently at this time interval...
    // The 250ms loop() allows time to process motors for
    // I2C interrupts to process read & write... more testing
    // for confirmation...
    // Conclusion: feasibility test - pass - jc 20241219
    if (timer.isTimer(125))
    {
        // Test 2: all ok
        if (once)
        {
            // Joystick MCU-1
            cout << "MCU1" << endl;
            _err_ = ReadI2C(fd1);
            // FIXED
            once = false;
        }
        else
        {
            // L298N MCU-2
            cout << "MCU2" << endl;
            _err_ = WriteI2C(fd2);
            // FIXED
            once = true;
        }

        // Test 1: all ok
        /*
        if (once)
        {
            // Joystick MCU-1
            cout << "MCU1" << endl;
            _err_ = MCU1();
            // FIXED
            once = false;
        }
        else
        {
            // L298N MCU-2
            cout << "MCU2" << endl;
            _err_ = MCU2();
            // FIXED
            once = true;
        }
        */
    }
}

void cleanup(int signo)
{
    _err_ = -5;
}

int main()
{
    // BUGFIX - Terminal ctrl-c
    signal(SIGINT, cleanup);
    signal(SIGTERM, cleanup);
    signal(SIGHUP, cleanup);

    // Arduino like setup function
    setup();
    // Arduino like loop function
    while (_err_ == 0)
    {
        loop();
    }
    // List all errors here...
    if (_err_ < 0)
        cout << " EXIT: cleanup: " << _err_ << endl;
    // TEST 2: comment otherwise
    if (fd1 > 0)
    {
        CloseI2C(fd1);
        cout << "Closed fd1: " << fd1 << endl;
    }
    if (fd2 > 0)
    {
        CloseI2C(fd2);
        cout << "Closed fd2: " << fd2 << endl;
    }
    return _err_;
}
