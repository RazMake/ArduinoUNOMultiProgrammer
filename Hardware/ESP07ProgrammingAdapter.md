# Overview
For this adapter I used the least amount of parts I could. Some/most of the components I decided to not add are meant to improve stability, so I expect this adapter is going to fail from time to time to program the chip.  
My experience has been so far (after a few hunderd writes) that it is sufficiently stable for hobby level work. So far I don't plan making it more complex.
I only had one occurence when it failed to write the chip and, upon retrying, it succesfully flasthed the new firmware. I consider this a sufficiently small annoyance so I kept the the adapter simple.  
The voltage from the ESP (3.3V) seems to be enough to register as HIGH for the Arduino so using a voltage divider to adapt the logic levels from Arduino to ESP and no adapter from ESP to Arduino works fine.

# BOM
This adapter needs just a few components.  
*Note: Prices are as of **Dec 2019**.*
* Arduino UNO [**$2.99**/1 pcs](https://www.banggood.com/Geekcreit-UNO-R3-ATmega328P-Development-Board-For-No-Cable-p-964163.html?rmmds=search&cur_warehouse=CN).
* Header pins [**$6.39**/20 sets of male/female pairs](https://www.ebay.com/itm/20pcs-Male-Female-Header-1x40-2-54mm-40-Pin-PCB-Through-Hole-Arduino-and-Pi/223054186518)  
* 1K rezistor [**$1.78**/10pcs](https://www.ebay.com/itm/1-2w-Watt-1-Tolerance-Metal-Film-Resistor-10-Pieces-USA-SELLER/123051802992?_trkparms=ispr%3D1&hash=item1ca6758170:m:mWteoVJtEWPHAGEtIwxO9Lw&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea)
* 2.2K rezistor [**$1.78**/10pcs](https://www.ebay.com/itm/1-2w-Watt-1-Tolerance-Metal-Film-Resistor-10-Pieces-USA-SELLER/123051802992?_trkparms=ispr%3D1&hash=item1ca6758170:m:mWteoVJtEWPHAGEtIwxO9Lw&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea&enc=AQAEAAACQBPxNw%2BVj6nta7CKEs3N0qU0gAuTT5sN90a7KTkp7GCYSeu2293aMTl%2FH9crKfV9LFW1cK8cWxm9u45N4fMj5RD8QWXkofz8p57TRLbs6vLbzXlB9GgvbGYd6cXxitC5Tbc2jR7cc8YWdC6jSBpf5fEe75Uv6HaaVVGDU5QHjBF%2F%2F73aZiOJqngC9DaafXVUdDhSfi0AeoK5M4%2BRQrWFEiAWAFtYRkmjwR5zW6t6ayDZYWQOtcYCvr04B%2BX4R%2BJsS9yAIPHcQEc%2B%2FTZj1ty%2BPJ3rvbCR1o%2FIqDBqEZTuH5nZHtkDgNubmGDxbLCfLui0ZZaarZIJStLs9aFazp2XV%2BE%2Ffpm5EzlUn7oZu5MLBvEKgTBJpIojvMMIou%2FAR5BgH4ORyzKz7OqkH2qOYK5eZSKH%2BskZ%2BAaL1Qhm9XfCo%2FLJqlxM0Z6X9nbAV1PuxbSQo9DeQ6dSqeAwVEZcMt0QNxGXB4V5CmGuEeInzoVpm9fk5pt3TPfwyvdE2up8xamZnV%2BJG1jZRKXYwkiDVX56PyfCKwhqud4%2Bap7Y06g07xNZEqMW7O1srWlPZnAaHPuQnfgbE%2Fth7bYCil7ieSySs5FacEZamkiAArQqDuw%2BcUH%2FPzndfnSdtZmYf9Vny6h7woUjx9R7W7pNoTShEdtBFNcIqT6Z3GVtkTAF1EzRiYZRprwGSsfTEyzgUgLla8i9%2F3sf4Zxkg3fVtiz05VNt9aRCCCh9iymtzNL76HsNWhCGNfmZKnJwiwvQ91FFAnUaQA%3D%3D&checksum=123051802992f0b655b981874f00af37d2523b5b17ea)

# Manufacturing the adapter
This is the circuit diagram manually drawn because it is a bit easier to follow when you're trying to verify your connections.  
![ATTiny85 Flash Electrical Diagram](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Hardware/ESPCircuit.png)  

## Designing the PCB
I have used [**KiCad**](https://kicad-pcb.org/download/windows/) for designing the PCB and using [**DRCNow (free version)**](https://www.numericalinnovations.com/pages/dfm-now-free-gerber-viewer) for validating them.  
Manufacturing the PCB takes about *1.5 weeks*, so it is worth '*optimizing for high latency*' here. That means:
* Go over the circuit multiple times. I also printed the circuits on paper and went over them with a pen.
* Use any verification you can before sending the design for manufacturing.
* Run the '***rule checks***' and also go over the circuit multiple times looking for errors.  

The [***KiCad project***](https://github.com/RazMake/KiCad/tree/master/Adapters/Adapters%20for%20programming/Esp07) containing the schematic and the PCB design of the adapters you see in the pictures (the one I have made and currently using).   
*Note: Once I had the PCBs, in my hand I realized to things (maybe they save you some money/effort):*
* *I had a few places where I noticed things can be improved, when trying to use the boards.*
* *I could have been a bit more efficient by putting all the boards on the same panel.  
   This way I could have ordered 5x of a little bigger pannel rather tha 5x 3 different small pannels.*  

This [**KiCad project**]() contains **all** boards with fixes to the minor issues above. I just did not order new PCBs yet so they're not really tested.

## Making the PCB
I have used the following two chinese manufacturers, and I think both deliver good results:
* [JLCPCB](https://jlcpcb.com/quote#/?orderType=1&stencilWidth=100&stencilLength=100&stencilCounts=5&stencilLayer=2&stencilPly=1.6&steelmeshSellingPriceRecordNum=A8256537-5522-491C-965C-646F5842AEC9&purchaseNumber=) seems to be a little cheaper,
  it has fewer color options for boards and maybe a tad faster in delivering the boards (I tried them when the COVID-19 outbreak was going on and it is possible that messed with the first impression).  
* [PCBWay](https://www.pcbway.com/orderonline.aspx) I think it has better ordering UI, it is a bit more expensive than JlcPCB.com, and it has more color options.  

Additionally I found this european one:
* [EuroCircuits](https://www.eurocircuits.com/). They can produce single boards, but my impression was that even for single boards they are more expensive than the Chinese ones above, so I did not actually tried them.  

Also maybe interesting to note there is [**this site**](https://pcbshopper.com/) that compares offers from multiple manufacturers. It might be worth a look.
and they both produced excellent quality PCBs at relatively reasonable prices. 

In all my projects I try to preserve the Gerber files, which is what you need to order the PCBs (*I might forget for some projects for which I did not order PCB boards*).  
*Look for a folder called Gerber in the project you are intersted in.*  
Basically the ordering is in three steps:  
	- First you upload your Gerber files, define the parameters (i.e. colors, number of layers, size, etc.)  
	- Then somebody checks your submission and if there is anything wrong with it, they'll email you to let you know.  
	- If the check passes on your Gerber files, the manufacturing starts (which takes 1-2  days, depending on which one you used)
	- Then the boards are shipped and they take around a week to get to you (if you paid for the reasonable fast shipping, otherwise it takes around a month).  

## Some images
**The boards  they arrived from JlcPcb.com**  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/AllPCBs_Front.jpg)  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/AllPCBs_Back.jpg)  

**Front of the board**, after soldering the socket and header pins  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ESPFlashingAdapter_Front.jpg)  

**Back of the board**, after soldering the socket and header pins  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ESPFlashingAdapter_Back.jpg)  
