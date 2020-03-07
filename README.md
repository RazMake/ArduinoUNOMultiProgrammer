# Backstory
I had an ideea for a larger project that would use multiple ATTiny85 microcontrollers and an ESP8266 (to control all of the ATTinys while communicating over WiFi with my
home automation system).
It was sitting in my notebook for a while unil I realized I kept putting it off because it did not feel like fun to start digging up again
how to program each of these devices, set up my computer with the necessary software, go through the pain of trail and error until succesfully programming each device.
I remember that the cheap FTDI adapters are finiky to get to work in windows (the drivers do not always want to work with clone chips and you have to go find an older
version on some more-or-less shady site).

# Solution
I decided to start collecting the information in a document or something. Then I realized this means it is easily sharable so I decided to put everything on github.  
This way I have a repository that is versioned and also the information is
*"out there"* hopefully saving somebody else some time.
The ideea is to use an Arduino UNO to facilitate communication between PC and the two chips mentioned above. I think this can work with a lot of other microcontrollers,
but so far I only have done and tested the two.  
I had an Arduino UNO R3 lying around in a drawer, collecting dust so I decided to make it a dedicated programming device.
I will describe bellow all the necesary steps, but first here is a table of content so one can jump quickly to the interesting part:
* **Hardware**  
	* **[Building the ATTiny85 adapter for programming]()**  
	*Such an adapter allows connecting the ATTiny85 chip to a computer (through an Arduino) so you can flash new software on it (aka. a new sketch)*  
	* **[Building the ESP-07/12 adapter for breadboard]()**  
	*This adapter allows connecting an ESP-07 to a breadboard (without modifying the chip).  
	The goal being that you make the temporary/test circuits using jumper wires without altering the microcontroller (like soldering wires to it, etc.).  
	Only when you are sure your circuit is good you create the PCB and solder the chip making a more permanent and robust circuit for the final project*  
	* **[Building the ESP-07/12 adapter for programming]()**  
	*This adapter has the correspoding female headers so you can connect the above breadboard adapter to it.  
	This alows you to move the ESP microcontroller between the breadboard and the programming adapter without taking it out (which reduces the wear on the pads)*
* **Software**
  *This is only about Arduino IDE, I don't know how to use the other programming environments (like [PlatformIO](https://platformio.org/)).*  
	* **[Setup your computer for programming microcontrollers, using Arduino IDE.]()**    
	*How to install Arduino IDE, add libraries and add the boards you're going to program with it*
	* **[Setup for programming ATTiny85]()**  
	*How to setup Arduino IDE for programming ATTiny. You'll need to do these steps when programming different microcontrollers, when returning to program the ATTiny.*  
	* **[Setup for programming ESP-07 (or ESP-12)]()**  
	*How to setup Arduino IDE for programming ESP microcontrollers. You'll need to do these steps when programming different microcontrollers, when returning to program a ESP.  
	**Note**: When flashing your first sketch you will loose the AT firmware from ESP. Not a big loss, but I thought I'd mention it. It possible to get it back, but I never tried that.*  

# Actual Devices
## Programming *'device'*
*This is just an Arduino UNO R3, encased in a 3D printed skin.  
 The intent is to prevent causing an accidentals short circuit when carelesly placing it over some wire on the table.*

## ATTiny85 programming adapter
*The programming adapter connects to the Arduino, which in turn connects to the computer over USB.*

## ESP-07/12 breadboard adapter
*The breadboard adapter has pins with the right spacing so you can plug it in.*

## ESP-07/12 programming adapter
*The programming adapter is design to connect to the breadboard adapter, to avoid having to move the ESP chip from one adapter to another.*

# BOM (2019)
**Shared between the two adapters**
* Arduno UNO [**$2.79**/1pcs](https://www.banggood.com/Geekcreit-UNO-R3-ATmega328P-Development-Board-For-No-Cable-p-964163.html?rmmds=search&cur_warehouse=CN)
  
**ESP adapter**  
* 1k rezistor [**$1.78**/10pcs](https://www.ebay.com/itm/1-2w-Watt-1-Tolerance-Metal-Film-Resistor-10-Pieces-USA-SELLER/123051802992?_trkparms=ispr%3D1&hash=item1ca6758170:m:mWteoVJtEWPHAGEtIwxO9Lw&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea)
* 2.2K rezistor [**$1.78**/10pcs](https://www.ebay.com/itm/1-2w-Watt-1-Tolerance-Metal-Film-Resistor-10-Pieces-USA-SELLER/123051802992?_trkparms=ispr%3D1&hash=item1ca6758170:m:mWteoVJtEWPHAGEtIwxO9Lw&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea)
* Pogo Pins [**$4.77**/50pcs](https://www.ebay.com/itm/US-Stock-50pcs-P100-Q2-Dia-1-36mm-180g-Spring-Test-Probe-Pogo-Pin/371912543788?_trkparms=aid%3D1110002%26algo%3DSPLICE.SOI%26ao%3D1%26asc%3D20200122160600%26meid%3D0881a15aa9744e3085db59527660863c%26pid%3D100011%26rk%3D2%26rkt%3D12%26sd%3D401303915326%26itm%3D371912543788%26pmt%3D1%26noa%3D0%26pg%3D2047675&_trksid=p2047675.c100011.m1850)
* 8 pin socket  [**$2.99**/20pcs](https://www.ebay.com/itm/20Pcs-8Pin-Dip-20-Ic-Socket-Double-In-Line-Integrated-Circuit-Solder-Type/163040422083?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D20160908105057%26meid%3D204107da225f4390aaa244fe15edeac8%26pid%3D100675%26rk%3D2%26rkt%3D15%26mehot%3Dag%26sd%3D282315166074%26itm%3D163040422083%26pmt%3D0%26noa%3D1%26pg%3D2380057&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3Af472dd74-4240-11ea-978e-74dbd180e3a4%7Cparentrq%3Aef2d7d2316f0ac3d5c8ad1b3fff6eed4%7Ciid%3A1&autorefresh=true)

**ATTiny adapter**  
* Capacitor 10uF (needed for the ATTiny85 adapter) [**$1.08**/20pcs](https://www.ebay.com/itm/25V-10uF-100uF-220uF-330uF-470uF-1000uF-2200uF-10000uF-Electrolytic-Capacitor/392203315804?ssPageName=STRK%3AMEBIDX%3AIT&var=661139768154&_trksid=p2057872.m2749.l2649)  

**Microcontrollers to test the adapters with**  
* ATTiny85 [**$8.9**/5pcs](https://www.ebay.com/itm/5-PCS-ATTINY85-20PU-ATTINY85-MCU-8BIT-8KB-MICROCONTROLLER-SHIPPED-FROM-USA/282315166074?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649)
* ESP07 [**$3.95**/1pcs](https://www.ebay.com/itm/ESP8266-ESP-07-Wireless-Remote-Serial-WiFi-Module-Transceiver-Board-AP-STA/121951859530?hash=item1c64e5b34a:g:t40AAOSwyXVbXqBh)


# Electrical circuit
Both circuits are very simple. I ended up just using wires, no PCB.

## ATTiny85 circuit  
![ATTiny85 Flash Electrical Diagram](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/ATTiny85Circuit.png?raw=true)

## ESP07/12 circuit  
![ESP07/12 Flash Electrical Diagram](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/ESPCircuit.png?raw=true)

# Code
* [***This***](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/EnvironmentSetup.md) is how to configure Arduino IDE for flashing ***ATTiny85**s* and ***ESP07/12**s*.
* Great news! There is no *new* code needed for this project: one of the adapters runs without any code the other one needs an example sketch falshed to Arduino UNO (which comes with the IDE).

# Endresult
I have now two adapters that fit on the same Arduino UNO headers, that I can use to flash an ESP07/ESP12/ATTiny85. Luckly for flashing ESPs Arduino needs to be disabled,
so by connecting the RESET pin to the ground, I don't need to reflash the Arduino with a different sketch. Basically I just swap the adapter, change the settings in the IDE and I flash the new bits.

## ATTiny85 adapter
This is how the adapter for ATTiny85 looks like, mounted on the Arduino UNO:  
![ATTiny85 adapter](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/Attiny85Adapter.jpg?raw=true)  

## ESP07/ESP12 adapter
This is how the adapter for ESP07 looks like, mounted on the Arduino UNO:  
![ESP 07 adapter](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/Esp07Adapter.jpg?raw=true)  

## _Disclaimer_
_**I'm no electrical engineer** which means take my notes with a grain of salt.  
There might be better implementations for any these but with what I had at my disposal (including the knowledge and the time to learn) the resulting two adapters are at least working.
The circuits I have used are minimalistic, and roughly built (no PCBs), but the adapters are easy to use and relatively handy (if you're building one off circuits for hobby projects or
at least not large batches they might be good enough)._

## Bonus
While working on my projects I realized that I also need an adapter for the breadboard for ESP-07, as it does not have pins and it was annoying to have to solder some wires to it just so I can try out stuff.
Since I did all those adapters using plastic, and also I had the model for the socket for ESP-07 already designed.. I thought, "Hey since I have a hammer, this problem looks like a nail" so I went ahead and printed
a quickly put together adapter. Now, after completing it, I think it turned out to be a bit more involved than I was imagining (the pins are really close together and 16 of them), but since I shared all the other models,
I'll share this one too (it's in the 3D Models folder). Here is a picture.. looks exotic :-)
![ESP Breadboard adapter](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ESPBreadboardAdapter.jpg?raw=true)