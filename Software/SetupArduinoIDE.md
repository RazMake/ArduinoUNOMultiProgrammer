# Get Arduino IDE
*Arduino IDE* is one of the development environments that can be used to program various microcontrollers (including the two I am planning to use).  
It is free to download, donnations are accepted.
Just get the latest version from [Arduino web site](https://www.arduino.cc/en/Main/Software), if you don't already have it.

# Configuration
First thing to do is to set the path for sketches to a well known folder on your hard drive. This way it is easy to back it up, if needed.  
Press Ctrl+**,** (opens up File->Preferences dialog). Enter the desired path in "*Sketchbook Location*" field.  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/SettingSketchbookLocation.png)

## Setup board sources
You need to start by telling Arduino IDE where to find board definitions.  
Once that is setup, you can find the available boards in a list, in the board manager and install the ones you want to use.  

### ATTiny85
* I found that ***ATTinyCore*** works well for me (sources: [GitHub](https://github.com/SpenceKonde/ATTinyCore/blob/master/Installation.md)).  
**URL**: *http://drazzy.com/package_drazzy.com_index.json*.  
According to [this](https://forum.arduino.cc/index.php?topic=609034.0) thread, it is the most advanced core, at least around *Apr-2019*.  
* *Another option that seemed like a good contender, is David's (sources: [GitHub](https://github.com/damellis/attiny/)).  
**URL**: https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json*

### ESP8266
* There is this community maintained core that worked so far for me (sources: [GitHub](https://github.com/esp8266/Arduino)).  
**URL**: https://github.com/esp8266/Arduino/blob/master/doc/installing.rst

Press Ctrl+**,** (opens up File->Preferences dialog). Click on the button near the field "*Additional Boards Manager URLs*"   
Add, then, the URLs for the cores you want to program with the Arduino IDE.  
![](https://raw.githubusercontent.com/RazMake/ArduinoUNOMultiProgrammer/master/Screenshots/BoardSourceSetup.png)  

## Install boards
Once the sources are set, you need to go to the Boards Manager (Tools -> Board -> Boards Manager...):  
*Note: Board menu also has the name of the board currently setup, so it might look different than the screenshot bellow.*  
![](https://raw.githubusercontent.com/RazMake/ArduinoUNOMultiProgrammer/master/Screenshots/OpenBoardsManager.png)  
and install the boards one at a time:  
* ATTin85  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/InstallATTniyCore.png)  
* ESP8266 (all ESP boards)  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Screenshots/InstallEsp8266Core.png)  

## Install libraries