# Setup For Programming ATTiny85
**Warning: Before you attempt to flash ATTiny85 chips, you need to prepare the Arduino UNO device by flashing the 'ArduinoISP' sketch on it.**  
*The Arduino ISP sketch can be found as an example in the Arduino IDE. Go to Examples -> ArduinoISP -> ArduinoISP:*  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/ArduinoISPSketch.png)  
**Notes:**
- This sketch must be flashed on the Arduino with no adpter connected.
- This operation needs to be done only one time, if you dedicate the Arduino to this task. The ESP adapter does not require any sketch.  

Once the Arduino is prepared, you only need to switch the IDE to flash ATTiny chips.  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/SelectATTinyBoard.png)  
First select the board: "ATTiny25/45/85". 
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
	 **Note: Every time you change the clock option you have to *reset the fuses*.  
	 To do that you need to go to Tools -> *Burn Bootloader*, before flashing the code.**
- **B.O.D. Level:** This is the Brown-out-detection setting. When the power source voltage varies (i.e. when the chip is powered by solar power) the chip can freeze.  
  To prevent that, turn on brown-out-detection. The result will be that the chip resets if the power goes to low, rather than freezing.  
  **Note: Every time you change the B.O.D. option you have to *reset the fuses*.**  
- **Save EEPROM:** When this option is set to ***Enabled*** the EEPROM (the memory that survives power loss) is cleared when you flash new code on the ATTiny.  
  I keep this ***Disabled*** unless I intend to reset the persistent storage because EEPROMs have a finite number of writes before they start failing  
  and while prototyping I tend to re-flash multiple times as I learn how to do things right and fix bugs.
- **Timer 1 Clock:** *??*. It is set to ***CPU*** by default. I left it like that.
- **LTO (1.6.11+ only):** *??*. It is set to ***Enabled*** by default. I left it like that.
- **millis()/micros():** This menu allows enabling or disabling the timers for returning the number of milliseconds or microseconds.  
  If set to **disabled**, Serial methods with take a timeout as an argument will **not** have accurate timeout (though the actual time will be still proportional to the suplied value).  
  delay calls will still work. While this option is disabled, eliminates mills interrupt every 1-2 ms and saves a few hundred bytes of flash.  
  I keep this **enabled** (the default value) to avoid forgetting it is off and chasing around wired timing issues.  
  **Notes:** The value returned by either of this functions rolls over, make sure you [handle that case](https://www.baldengineer.com/arduino-how-do-you-reset-millis.html) (or [this](https://arduino.stackexchange.com/questions/22212/using-millis-and-micros-inside-an-interrupt-routine)),
  if you use the methods.
- **Port:** This is the computer port where the Arduino UNO is connected. This depends on your machine.

# ATTiny85 Pinout
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/ATTiny85Pinout.png)

# Libraries
- [**I2C**](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Software/Libraries/ATTiny/I2C.md).
  This protocol is used for comunicating with other I2C capable devices using only 2 wires (*SCL*-clock, *SDA*-data).



