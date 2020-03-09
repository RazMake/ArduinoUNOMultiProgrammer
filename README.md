# Backstory
I had an ideea for a larger project that would use multiple ATTiny85 microcontrollers and an ESP8266 (to control all of the ATTinys while communicating over WiFi with my
home automation system).
It was sitting in my notebook for a while unil I realized I kept putting it off because it did not feel like fun to start digging up again
how to program each of these devices, set up my computer with the necessary software, go through the pain of trail and error until succesfully programming each device.
I remember that the cheap FTDI adapters are finiky to get to work in windows (the drivers do not always want to work with clone chips and you have to go find an older
version on some more-or-less shady site).

# Project Overview
I decided to start collecting the information in a document or something. Then I realized this means it is easily sharable so I decided to put everything on github.  
This way I have a repository that is versioned and also the information is
*"out there"* hopefully saving somebody else some time.
The ideea is to use an Arduino UNO to facilitate communication between PC and the two chips mentioned above. I think this can work with a lot of other microcontrollers,
but so far I only have done and tested the two.  
I had an Arduino UNO R3 lying around in a drawer, collecting dust so I decided to make it a dedicated programming device.
I will describe bellow all the necesary steps, but first here is a table of content so one can jump quickly to the interesting part:
* **Hardware**  
	* **[Building the ATTiny85 adapter for programming](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Hardware/ATTin85ProgrammingAdapter.md)**  
	*Such an adapter allows connecting the ATTiny85 chip to a computer (through an Arduino) so you can flash new software on it (aka. a new sketch)*  
	* **[Building the ESP-07/12 adapter for breadboard](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Hardware/ESP07BreadboardAdapter.md)**  
	*This adapter allows connecting an ESP-07 to a breadboard (without modifying the chip).  
	The goal being that you make the temporary/test circuits using jumper wires without altering the microcontroller (like soldering wires to it, etc.).  
	Only when you are sure your circuit is good you create the PCB and solder the chip making a more permanent and robust circuit for the final project*  
	* **[Building the ESP-07/12 adapter for programming](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Hardware/ESP07ProgrammingAdapter.md)**  
	*This adapter has the correspoding female headers so you can connect the above breadboard adapter to it.  
	This alows you to move the ESP microcontroller between the breadboard and the programming adapter without taking it out (which reduces the wear on the pads)*
* **Software**
  *This is only about Arduino IDE, I don't know how to use the other programming environments (like [PlatformIO](https://platformio.org/)).*  
	* **[Setup your computer for programming microcontrollers, using Arduino IDE.](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Software/SetupArduinoIDE.md)**    
	*How to install Arduino IDE, add libraries and add the boards you're going to program with it*
	* **[Setup for programming ATTiny85](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Software/SetupForATTiny.md)**  
	*How to setup Arduino IDE for programming ATTiny. You'll need to do these steps when programming different microcontrollers, when returning to program the ATTiny.*  
	* **[Setup for programming ESP-07 (or ESP-12)](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Software/SetupForESP.md)**  
	*How to setup Arduino IDE for programming ESP microcontrollers. You'll need to do these steps when programming different microcontrollers, when returning to program a ESP.  
	**Note**: When flashing your first sketch you will loose the AT firmware from ESP. Not a big loss, but I thought I'd mention it. It possible to get it back, but I never tried that.*  

## Actual Devices
### Programming *'device'*
*This is just an Arduino UNO R3...*  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ArduinoUno.jpg?raw=true)  
*...encased in a 3D printed skin.  
In order to prevent accidentals short circuit when carelesly placing it over some wire or pin on the table.*  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ArduinoUno_InCase_Open.jpg?raw=true)  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ArduinoUno_InCase_Closed.jpg?raw=true)  

### ATTiny85 programming adapter
*The programming adapter connects to the Arduino, which in turn connects to the computer over USB.*  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ATTinyFlashingAdapter_Front.jpg?raw=true)  

### ESP-07/12 breadboard adapter
*The breadboard adapter has pins with the right spacing so you can plug it in.*  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ESPBreadBoardAdapter_Front.jpg?raw=true)  

### ESP-07/12 programming adapter
*The programming adapter is design to connect to the breadboard and programming adapter.  
This remove the need to move the ESP chip from one adapter to another, which can wear out the castelated pads.*  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/?ESPFlashingAdapter_Front.jpgraw=true)  \