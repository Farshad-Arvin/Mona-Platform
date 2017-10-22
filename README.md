# Mona-Platform
Mona robot's basic functions and test code in Arduino


To setup your Arduino IDE (1.8.3 or higher download from: https://www.arduino.cc/en/Main/Software), to connect and program Mona, please follow the setting:
- Boards: "Arduino Pro or Pro Mini
- Processor: "ATmega328 (3.3V, 8MHz)
- Programmer: ArduinoISP.org
- Bootloader: ATmegaBOOT_168_atmega328_pro_8MHz.hex 


The first test code which is complied in Arduino is Mona-Test.ino file. 
In this file, Mona reads its IR proximity sensors and sends the IR values (0-1023) to the PC via Serial port (9600 bps). Also, Mona controls its motors' speed depends on recorded IR values from proximity sensors. 
This code is a very simple program to test your Mona robot and also start to program the robot using Arduino. 


We will upload more codes soon to run more complex routines using Mona.
