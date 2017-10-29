# Mona-Platform
Mona robot's basic functions and test code in Arduino:
(www.monarobot.uk)

To configure your Arduino IDE (1.8.3 or higher, please download from: https://www.arduino.cc/en/Main/Software) and to connect and program Mona robot, please follow the setting:
- Boards: "Arduino Pro or Pro Mini"
- Processor: "ATmega328 (3.3V, 8MHz)"
- Programmer: ArduinoISP.org
- Bootloader: ATmegaBOOT_168_atmega328_pro_8MHz.hex 


The first test code which is complied in Arduino is Mona-Test.ino file. 
In this file, Mona reads IR values from its IR proximity sensors using ADC and sends the IR values (0-1023) to the PC via Serial port (9600 bps). Also, Mona controls its motors' speed (open loop) depends on the recorded IR values from proximity sensors. 
This code is a simple example to test your Mona robot without using any external library and also start to program the robot using Arduino. 


We will upload more codes soon to run more complex routines using Mona.
