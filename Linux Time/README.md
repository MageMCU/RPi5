## Linux Time
- Raspberry Pi Linux (Operating System) a Debian-based operating system optimized for the Raspberry Pi hardware. The latest version of Raspberry Pi OS is based on Debian Bookworm. System 64-bit, Kernel version 6.6, Debian version 12(bookworm)
  - millis() function

### Hardware
- The Raspberry Pi 3 Model B v1.2 (2015) with 1-GB RAM (minimum hardware setup)

### Test (Code::Blocks))
- LinuxTime.h
- Timer.h
- main.cpp

### Code
```
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
```