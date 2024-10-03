## SMBus-I2C Communication
- Raspberry Pi as a SMBus Host and Arduino Uno as Slave. Well it seems Raspberry Pi is one of those developing technologies that uses the so-called hybrid SMBus-I2C protocol technology. The external SMBus works on the Atmega328P chip, the brains of the Arduino Uno, but the Atmega328P uses only the byte-oriented 2-wire serial interface (Phillips I2C compatible) protocol. The SMBus-I2C can serve as the Host, Master or Slave on devices where Host is a special master. The Raspberry Pi serves as a SMBus-I2C Host. Between the two, the Pi & Uno, there is a minimum difference mostly in the names, SMBus and I2C. (article 1013)

### Testing Platform
- The MCU chip **Atmega328P** is well known and the price is affordable as well as most of the robotic hardware that is described here. The Arduino Uno board comes with a removable MCU.
  - **Arduino IDE** Legacy IDE 1.8.19 - Linux ARM 64 bits
    - See article 1013 for details
- The **Raspberry Pi** 3 Model B v1.2 (2015) with 1-GB RAM... For now, this Pi and other models will be used here only at this repository: Raspberry-Uno-Communication
  - **Code::Block** version svn-r13046 - used sudo apt install codeblocks codeblocks-contrib
    - See article 1013 for details

### SMBus-I2C
- Project 1
  - PiMasterI2C - Used Raspberry Pi 3 Model B v1.2 (2005) - Code::Blocks IDE
  - UnoSlaveI2C - Arduino Uno Rev.3 - Arduino IDE 1.8.19
- Project 2
  - PiMasterI2C pending
  - UnoSlaveI2C pending


### Articles
- [1013 - *Pi Uno* SMBus I2C Study](https://drive.google.com/file/d/1o1uuV1XeMvV8kKT-DoPhIqBPmvH65cOY)
- [1017 - RPi Cheat Sheet](https://drive.google.com/file/d/1gQcoghc7cdnsxAVVT9PBMUGY1FLKjWS2)

### Development
- 20240930 Preliminary testing complete - see article 1013 Pi Uno SMBus I2C Study.

### Disclaimer and Terms
- Please read the Disclaimer amd Terms
