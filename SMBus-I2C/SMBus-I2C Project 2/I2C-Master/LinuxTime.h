//
// Carpenter Software
// File: Class LinuxTime.h
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

#ifndef _ARDUINO_

#ifndef LinuxTime_h
#define LinuxTime_h

#include <time.h>

namespace csjc
{
    class LinuxTime
    {
    private:
        struct timespec ts;
    public:
        LinuxTime() = default;
        ~LinuxTime() = default;

        long millis();
    };

    long LinuxTime::millis()
    {
        clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
        return (long)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
    }
}

#endif // LinuxTime_h
#endif // _ARDUINO_
