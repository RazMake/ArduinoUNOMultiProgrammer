# Setup For Programming ESP-07/12
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/SelectEspBoard.png)  
First select the board. Select "Generic ESP8266 Module".
## Menu Options
- **Builtin Led:** This is the number of built in LEDs on the board.  
  ESP-07 has ***2***.
- **Upload Speed:** This is the speed of the COM port used for flashing the microcontroller.  
  Leaving this to ***115200*** worked for me with ESP-07. I think this is a good value for all ESPs.
- **CPU Frequency:** This is the frequency of the CPU. This affects the delays in your code, when doing time sensitive bit banging or something like that.
  If you change this value, you need to recompile your program before deploying.  
  It is set to ***80MHz*** for ESP-07.
- **Crystal Frequency:** *??*. It to ***26Mhz*** by default, I left it like that.
- **Flash Size:** *??*. It is set to ***1MB*** by default. I left it like that.
- **Flash Mode:** *??*. It is set to ***DOUT (compatible)*** by default. I left it like that.
- **Flash Frequency:** *??*. It is set to ***40MHz*** by default. I left it like that.
- **Reset Method:** *??*. It is set to ***dtr (aka nodemcu)*** by default. I left it like that.
- **Debug Port:** *??*. It is set to ***Disabled*** by default. I left it like that.
- **Debug Level:** *??*. It is set to ***None*** by default. I left it like that.
- **IwP Variant:** *??*. It is set to ***v2 Lower Memory*** by default. I left it like that.
- **VTables:** *??*. It is set to ***Flash*** by default. I left it like that.
- **Exceptions:** *??*. It is set to *** *** by default. I left it like that.
- **Erase Flash:** This is specifying what components to reset when flashing a new sketch.  
	Most of the time I keep this set to *Only Sketch* to keep the WiFi settings and preserve EEPROM values.  
	- ***Only Sketch*** only changes the sketch, the wifi settings and the program written EEPROM values are left unchanged.
	- ***Sketch + WiFi settings*** this changes the sketch and wipes out WiFi settings,it leaves the program written EEPROM values unchanged.
	- ***All Flash contents*** this erases everything.  
- **Expressif FW** *??*. It is set to ***nonos-sdk.2.2.1+100 (190703)*** by default. I left it like that.
- **SSL Support:** *??*. It is set to ***All SSL ciphers (most compatible)*** by default. I left it like that.
- **Port:** This is the computer port where the Arduino UNO is connected. This depends on your machine.

# ESP-07/12 Pinout
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/ESP07Pinout.png)

# Libraries
One interesting thing to note before delving into differenc details for various libraries, is a simple way of debugging your code.  
Take a look at my "[***Poor Man's Debugger***](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Software/PoorMan'sDebugger.md)" notes.  

- [**EEPROM**](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Software/Libraries/EEPROM.md) This allows access to the non-volatile memory and works for both *ATTiny85* and *ESP 07/12*.  