## SMBus-I2C Project 1
- Code
  - PiMasterI2C folder
    - main.cpp
  - UnoSlaveI2C folder
    - UnoSlaveI2C.ino

### WiringPi
- [Source](https://github.com/WiringPi/WiringPi)

### Pi and Uno functions
- *Single Value* is sent from the Pi Host to the Slave Arduino's callback **Wire.onReceive**()
  - g_result = **wiringPiI2CWrite**(g_fd, g_data);
- *Single Value* is received to the Pi Host from the Slave Arduino's callback **Wire.onRequest**()
  - g_result = **wiringPiI2CRead**(g_fd);
- Further development Project 2

### This libaray is not recommended but used to study the underlying code...