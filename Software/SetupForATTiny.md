# Setup For Programming ATTiny85
**Warning: Before you attempt to flash ATTiny85 chips, you need to prepare the Arduino UNO device by flashing the 'ArduinoISP' sketch on it.**  
*The Arduino ISP sketch can be found as an example in the Arduino IDE. Go to Examples -> ArduinoISP -> ArduinoISP:*  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/ArduinoISPSketch.png)  
**Notes:**
- This sketch must be flashed on the Arduino with no adpter connected.
- This operation needs to be done only one time, if you dedicate the Arduino to this task. The ESP adapter does not require any sketch.  

Once the Arduino is prepared, you only need to switch the IDE to flash ATTiny chips.  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/SelectATTinyBoard.png)  
First select the board: select "ATTiny25/45/85". 
Then make sure you select the Programmer: "Arduino as ISP" (*this is only important for ATTiny*).  

## Menu Options
- **Board:** This is the type of board to compile the code for.  
  Select ***ATTiny25/45/85***.
- **Chip:** This is the specific kind of chip to be flashed.
  Select ***ATTiny85***.
- **Clock:** This is the clock frequency for the chip.
	- **1MHz (internal)**. This is the low power settings, it does not need external components.
	  This is good for a sensor that reads data every few minutes and sends it to some cetnral processor, it will save some battery life.
	- **8MHz (internal)**. This consumes a bit more power and it still does not require external components.
	- **20MHz (external)**. This requires an external 20MHz crystal. According to the page ***29*** of the [datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet.pdf)
	the electrical diagram looks like this:  
	![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/ATTiny85_ExternalCrystal.png)  
	 Connect the crystal to pin **2** and pin **3**. Connect ***22pF*** caps from pin **2** to **GND**, and pin **3** to **GND**.  
	- There are a bunch of other options, but I think these three cover most of the interesting cases.  
	 **Note: Every time you change the clock option you have to *reset the fuses*. To do that you need to go to Tools -> *Burn Bootloader*, before flashing the code.**
- **B.O.D. Level:** This 
- **Save EEPROM:** This
- **Timer 1 Clock:** This
- **LTO (1.6.11+ only):** This
- **millis()/micros():** This
- **Port:** This is the computer port where the Arduino UNO is connected. This depends on your machine.

# Libraries