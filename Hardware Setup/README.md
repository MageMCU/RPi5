## Hardware Setup
- Unsure whether any particular model will have any effect (on the software), so just for now,  go with the flow... 

### Older Raspberry Pi models with Atmega328PU - I2C communication
- The Raspberry Pi 3 Model B v1.2 (2015) with 1-GB RAM and the Arduino Uno Rev3
  - See Code - SMBus-I2C - Project 1
    - Code::Blocks was used as a light weight IDE for the Pi.
    - Arduino IDE was used for the Arduino Uno.
  - See Article 1013 for details
- Others coming soon...

### Raspberry Pi 5 model with Atmega328PU - I2C communication
- pending

### Raspberry Pi 5 as a computer (FYI)
- I used Samsung SSD for fast processing with the Raspberry Pi 5 for testing circuits and code connected by USB to the Uno (atmega328PU) while debugging with a serial monitor.
  - Raspberry Pi 5 with 8GB [Hardware](https://www.raspberrypi.com/products/raspberry-pi-5/)
  - GeeekPi Metal Case for Raspberry Pi 5 [Å](https://www.amazon.com/GeeekPi-Raspberry-Active-Support-Peripheral/dp/B0CMZ84GM8?ref_=ast_sto_dp)
  - 52.PI M.2 MVNE SSD Adapter - NO4 for RP|5 [Å](https://www.amazon.com/GeeekPi-NVMe-Adapter-Raspberry-Support/dp/B0CRK4YB4C?ref_=ast_sto_dp)
  - SAMSUNG 990 EVO SSD [Å](https://www.amazon.com/Samsung-Internal-Computer-MZ-V9E1T0B-AM/dp/B0CRCC9863?th=1)
- 52Pi - N04 M.2 2280 PCIe to NVMe
  - N04 is compatible with the standard HAT size of Raspberry Pi 5  [52Pi Wiki EP-0210](https://wiki.52pi.com/index.php?title=EP-0210)
    - 52Pi GPIO connects to the two rows of five pins as shown in the images. This is to power and to communicate to the SSD.]
- Raspberry Pi 5 Metal case with NVMe by 52Pi [youtube Instructions](https://www.youtube.com/watch?v=kUBHWhdpbco). Note that he begins with a smaller hat but he continues with the larger hat... Amazon once sold all these parts as a kit except the SSD...
- Raspberry Pi Operating System
  - Use **Raspberry Pi Imager** to install of the [Raspberry Pi Operating System](https://www.raspberrypi.com/software/) onto the SD card.
  - Insert the card into RPi5, power up the board and follow the installation instructions.
  - The EEPROM Boot Order applies to the Raspberry Pi Operating System and whether this includes different Operating Systems.

### EEPROM Boot Order for Raspberry Pi Operating System (OS)
- The EEPROM boot order among the **USB**, the **SD Card** and the **SSD card** might be puzzling and frustrating.
  - If you have both a SD and a SSD card installed and you're having difficulty booting one over the other...
- EEPROM Boot Order in **Hexidecimal** Values
  - **f** = **start again**  - *0xf = bits 1111* (What dois it equal in the **decimal** number system?)
  - **1** = check **SD Card**  - *0x1 = bits 0001*
  - **4** = check **USB drive**  - *0x4 = bits 0100*
  - **6** = check **PCie NVME**  - *0x8 = bits 0110*
- The EEPROM boot order might look like **0xf416** (*0xf416 = bits 1111 0100 0001 0110*) and will execute the following in the order listed...
  - RPi will start again first
  - RPi will then check the USB (usually for the OS)
  - RPi will then check the SD Card (usually for the OS)
  - RPi will finally check the PCie NVME (SSD card -  (usually for the OS)
- How to boot the RPi5 with the SD Card first (which is the default)
  - Use the EEPROM boot order **0xf416**
  - It is unsure from which card is booting the OS but the SD Card was used to install the OS onto the SSD card.
  - Once installed on the SSD card, the SD card maybe pulled from the RPi.
- How to boot the RPi5 with the PCie NVME (SSD card) first before the CD Card
  - Use the EEPROM boot order **0xf461**
  - It is unsure whether the blank SD Card can be used as memory (storage) in this configuration.
- How to edit the EEPROM boot order
  - (1) open a terminal panel
  - (2) Type in the following command
     - ***sudo rpi-eeprom-config --edit*** (see link below for more information
       - You might see the following:
       ```
         [all]
         BOOT_UART=1
         POWER_OFF_ON_HALT=0
         BOOT_ORDER=0xf416
       ```
  - (3) The statement ***BOOT_ORDER=0xf416*** is where the EEPROM boot order can be edited...
  - Edit EEPROM boot order source [Raspberry Pi Documentation](https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#edit-eeprom-boot-order)

