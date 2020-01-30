# Get Arduino
First you need the Arduino IDE program. Just get the latest version from [Arduino web site](https://www.arduino.cc/en/Main/Software), if you don't already have it.

# Configuration
Then configure the IDE for programming the two boards.
Add the two URLs for the board definitions sources (see bellow), one for ATTiny85 and one for ESP8266 (ESP-07). For both you can follow the same steps:
* **Step 1:** Go to settings (by pressing control key and comma: Ctrl+**,**). Then add one of the URLs bellow to the "**Additional Board Manager URLs**":  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/AddATTinyBoardSource.png?raw=true)
* **Step 2:** Go to the boards manager (Menu -> Board -> **Boards Manager**) and install ATTiny85:
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/InstallATTniyCore.png?raw=true)
* **Step 3:** From the menu select the board and configure its properties.  
Also make sure you select **_Arduino as ISP_** for the Programmer:  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/SelectATTinyBoard.png?raw=true)

## ATTiny85
* I found that **ATTinyCore** ([GitHub](https://github.com/SpenceKonde/ATTinyCore/blob/master/Installation.md)) works well for me so I am using this one.  
_(according to [this](https://forum.arduino.cc/index.php?topic=609034.0) discussion on Arduino forum, this is he most advanced core, at least around Apr-2019)_
```
	http://drazzy.com/package_drazzy.com_index.json
```
	
* Another option, if you are curious to try it, is **David's** ([GitHub](https://github.com/damellis/attiny/)):
``` 
	https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json
```


## ESP 07
