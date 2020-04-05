# High quality paid tool
There is a very nice tool for debugging on embedded devices like ESP or ATTiny, called [Visual Micro](https://www.visualmicro.com/page/shop.aspx).  
This is an addin for Visual Studio which allows you to step through the code live on the device.  
These guys are building an awesome product, so do give them a thought (I am not affiliated with them in any way, I just appreciate good quality product).  
Unfortunately they are not free anymore and I considered their price ([$100 / 5 years](https://www.visualmicro.com/page/shop.aspx)) is too high for me,
at least for now, while doing hobby projects from time to time.  
So that brings me to the poor man's debugger..

# Poor Man's Debugger
The principle is trivial, and actually old as dirt: you add print statements through your code to write out state and the decisions taken by the code.  
When you need to slow down things, so you have time to react, add delays and that is all.  
## In the sketch  
On **ESP devices** you can do this by using some of the [**Serial**](https://www.arduino.cc/reference/en/language/functions/communication/serial/) APIs.
- **println(..)**  
	Writes to the serial, appending a new line after the message.
- **print(..)**  
	Writes to the serial. Multiple calls to this method can be used to print a more complex message to the serial (when data to be printed is comming from multiple variables for example).

Method Parameter:
- first parameter is value to write (the value can be of any data type: int, double, string, etc.).  
  You can pass strings that are stored in the flash memory by wrapping the string in **F()**.
- second parameter (***optional***) is the format to use (only for **int** data type):  
  - **BIN**: prints the binarary format of the number
  - **OCT**: prints the octal format of the number
  - **DEC**: prints the decimal format of the number
  - **HEX**: prints the hexadecimal format of the number
  - or you can pass a number as the format parameter, which would dictate how many decimal digits to use when formatting the number  

**Examples of print/println (*they have the same signature*):**  
- Serial.print(78) *outputs "78"*  
- Serial.print(1.23456) *outputs "1.23"*  
- Serial.print('N') *outputs "N"*  
- Serial.print("Hello world.") *outputs "Hello world."*  
- Serial.print(78, BIN) *outputs "1001110"*  
- Serial.print(78, OCT) *outputs "116"*  
- Serial.print(78, DEC) *outputs "78"*  
- Serial.print(78, HEX) *outputs "4E"*  
- Serial.print(1.23456, 0) *outputs "1"*  
- Serial.print(1.23456, 2) *outputs "1.23"*  
- Serial.print(1.23456, 4) *outputs "1.2345"* 
- Serial.print(F("This will be kept in flash memory"))  *outputs "This will be kept in flash memory"*

**Full Example**
```
    // First initialize the Serial:
    Serial.begin(115200);

    // Then you can use it to write debug messages:
    Serial.println(status, DEC);
    Serial.println(F("Led is OFF"));
```

## Seeing the output   
To see the output on the computer, you first need to wire the ESP to the computer.  
For that you can simply use the [**ArduinoUNOMultiProgrammer**](https://github.com/RazMake/ArduinoUNOMultiProgrammer), with the
[**ESP 07/12 Adapter**](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Hardware/ESP07ProgrammingAdapter.md) connected to it (the same way you used it to program the ESP).  
You can use jumper wires, since the adapter has female headers. Make sure you connect the same pins together (**RX-RX, TX-TX, GND-GND**).  
**Note:** ***It is important to have the ground connected, otherwise the communication won't work and you won't see the prints from the device.***  
Once you have the connections made, start the Serial Monitor from Arduino IDE:  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/StartSerialMonitor.png)  
Then make sure the monitor settings are like this:  
-**LineEnding**: No line ending  
-**Baud Rate**: 115200 baud
-**Autoscroll**: checked  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/SerialMonitor.png)  
That's it, you should see the Serial.print() and Serial.println() values in the monitor on your computer.  
Prety nifty, since you don't need anything more than the tools you should already have for programming the device.

