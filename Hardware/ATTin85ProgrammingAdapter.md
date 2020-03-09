# Overview
For this adapter I used the least amount of parts I could. Some/most of the components I decided to not add are meant to improve stability, so I expect this adapter is going to fail from time to time to program the chip.  
My experience has been so far (after a few hunderd writes) that it is sufficiently stable for hobby level work. So far I don't plan making it more complex.
I only had one occurence when it failed to write the chip and, upon retrying, it succesfully flasthed the new firmware. I consider this a sufficiently small annoyance so I kept the the adapter simple.

# BOM
This adapter is very simple, it does not really have additional components.  
*Note: Prices are as of **Dec 2019**.*
* Header pins [**$6.39**/20 sets of male/female pairs](https://www.ebay.com/itm/20pcs-Male-Female-Header-1x40-2-54mm-40-Pin-PCB-Through-Hole-Arduino-and-Pi/223054186518)  
* 8 pin socket  [**$2.99**/20pcs](https://www.ebay.com/itm/20Pcs-8Pin-Dip-20-Ic-Socket-Double-In-Line-Integrated-Circuit-Solder-Type/163040422083?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D20160908105057%26meid%3D204107da225f4390aaa244fe15edeac8%26pid%3D100675%26rk%3D2%26rkt%3D15%26mehot%3Dag%26sd%3D282315166074%26itm%3D163040422083%26pmt%3D0%26noa%3D1%26pg%3D2380057&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3Af472dd74-4240-11ea-978e-74dbd180e3a4%7Cparentrq%3Aef2d7d2316f0ac3d5c8ad1b3fff6eed4%7Ciid%3A1&autorefresh=true)

# Circuit
This is the circuit diagram manually drawn because it is a bit easier to follow when you're trying to verify your connections.  
![ATTiny85 Flash Electrical Diagram](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Hardware/ATTiny85Circuit.png?raw=true)  
I have used [**KiCad**](https://kicad-pcb.org/download/windows/) for designing the PCB and using [**DRCNow (free version)**](https://www.numericalinnovations.com/pages/dfm-now-free-gerber-viewer) for validating them.  
Manufacturing the PCB takes about *1.5 weeks*, so it is worth '*optimizing for high latency*' here. That means:
* Go over the circuit multiple times. I also printed the circuits on paper and went over them with a pen.
* Use any verification you can before sending the design for manufacturing.
* Run the '***rule checks***' and also go over the circuit multiple times looking for errors.  

The [***KiCad project***](https://github.com/RazMake/KiCad/tree/master/Adapters/Adapters%20for%20programming/ATTiny85) containing the schematic and the PCB design of the adapters you see in the pictures (the one I have made and currently using).   
*Note: Once I had the PCBs, in my hand I realized to things (maybe they save you some money/effort):*
* *I had a few places where I noticed things can be improved, when trying to use the boards.*
* *I could have been a bit more efficient by putting all the boards on the same panel.  
   This way I could have ordered 5x of a little bigger pannel rather tha 5x 3 different small pannels.*  

This [**KiCad project**]() contains **all** boards with fixes to the minor issues above. I just did not order new PCBs yet so they're not really tested.

# Manufacturing
I have used both [JLCPCB](https://jlcpcb.com/quote#/?orderType=1&stencilWidth=100&stencilLength=100&stencilCounts=5&stencilLayer=2&stencilPly=1.6&steelmeshSellingPriceRecordNum=A8256537-5522-491C-965C-646F5842AEC9&purchaseNumber=)
and [PCBWay](https://www.pcbway.com/orderonline.aspx) and they both produced excellent quality PCBs at relatively reasonable prices.  
Both these sites only allow a minimum of 5 copies ordered. It takes a little over a week to receive the PCBs.  
If you want european PCBs, you could use [these](https://www.eurocircuits.com/) guys, but they're more expensive than any of the other two.
They also can make one-offs, but at least sometimes their price for one is more than for a set of 5 on the chinese sites above.
*Note: **[This](https://pcbshopper.com/)** site allows you to compare prices for multiple sources.*  
Each of the projects above (checkout [my KiCad repository](https://github.com/RazMake/KiCad) for other projects too) 
contains a folder called **Gerber** which contains the files you would need to order the PCBs from one of these sites.  
Once you receive the boards you would need to solder the headers and the socket.

# Some images
**The boards  they arrived from JlcPcb.com**  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/AllPCBs_Front.jpg)  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/AllPCBs_Back.jpg)  

**Front of the board**, after soldering the socket and header pins  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ATTinyFlashingAdapter_Front.jpg)  

**Back of the board**, after soldering the socket and header pins  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ATTinyFlashingAdapter_Back.jpg)  
