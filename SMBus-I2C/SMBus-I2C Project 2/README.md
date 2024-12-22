## SMBus-I2C Project 2
After studying the code, the SMBus as well as WiringPi incorporated the Input-Output Control (IOCTL) which is further discussed in the article 1013 SMBus-I2C Supplemental.
- Code
  - PiMasterI2C folder
    - bin folder
      - I2C-Master
        - executable binary - use Terminal command: **./I2C-Master** to run
    - obj folder
      - main.o
    - Bitwise.h file
    - Debug.h file
    - I2C-Master.cbp
      - CodeBlocks file
    - I2C-Master.layout
      - CodeBlocks file
    - LinuxTime.h file
    - main.cpp file
    - Timer.h file
    - TypeConv.h file
  - I2C-Slave1 folder
    - Bitwise.h file
    - Button.h file
    - I2C-Slave1.ino
    - MiscMath.h
    - Timer.h file
    - TypeConv.h file
  - I2C-Slave2 folder
    - Bitwise.h file
    - I2C-Slave2.ino
    - MiscMath.h
    - Timer.h file
    - TypeConv.h file

### IOCTL (Input-Output Control)
- Will not be using WiringPi, SMBus but IOCTL...

### Development
- 20241221 updated