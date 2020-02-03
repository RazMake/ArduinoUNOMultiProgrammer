# Backstory
I had an ideea for a larger project that would use multiple ATTiny85 microcontrollers and an ESP8266 (to provide internet connectivity).
It was sitting in my notebook for a while unil I realized I kept putting it off because it did not feel like fun to start digging up again
how to program each of these devices, set up my computer with the necessary software, go through the pain of trail and error until succesfully programming each device.
I remember that the cheap FTDI adapters are finiky to get to work in windows (the drivers do not always want to work with clone chips and you have to go find an older
version on some more-or-less shady site).

# Solution
So I had a couple of Arduino UNOs lying in my drawer and collecting dust, and I thought it would be great if I can somehow use one of them to flash each of these devices.
After some reasearch on the internet, it turns out it is possible to program both of these chips (and likely others too).
So I decided to save my self some grief in the future and:  
    - make flashing each chip a repeatable process  
    - document the computer setup, as well as some of the gotchas I encounter  
The goal being that next time I try this it is going to be a little easier to get past the basics (falshing the microcontrollers) and I can focus on designing the circuit and writting the firmware for my projects.  

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
![ATTiny85 adapter](https://github.com/RazMake/ArduinoUNOMultiProgrammer/Photos/blob/master/Attiny85Adapter.jpg?raw=true)  

## ESP07/ESP12 adapter
This is how the adapter for ESP07 looks like, mounted on the Arduino UNO:  
![ESP 07 adapter](https://github.com/RazMake/ArduinoUNOMultiProgrammer/Photos/blob/master/Esp07Adapter.jpg?raw=true)  

## _Disclaimer_
_There might be better implementations for this but with what I had at my disposal the resulting two adapters are not that bad.
The circuits I have used are minimalistic, and roughly built (no PCBs), but the adapters are relatively small and relatively convenient to use
(relatively = if you are not goint to make tens of version of the same project, in which case you're probably better off buying one of those spring clamp adapters which grab the chip)._