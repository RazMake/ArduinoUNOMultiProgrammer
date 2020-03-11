# Overview
For this adapter I used the least amount of parts I could. Some/most of the components I decided to not add are meant to improve stability, so I expect this adapter is going to fail from time to time to program the chip.  
My experience has been so far (after a few hunderd writes) that it is sufficiently stable for hobby level work. So far I don't plan making it more complex.
I only had one occurence when it failed to write the chip and, upon retrying, it succesfully flasthed the new firmware. I consider this a sufficiently small annoyance so I kept the the adapter simple.

# BOM
This adapter is very simple, it does not really have additional components.  
*Note: Prices are as of **Dec 2019**.*
* Arduino UNO [**$2.99**/1 pcs](https://www.banggood.com/Geekcreit-UNO-R3-ATmega328P-Development-Board-For-No-Cable-p-964163.html?rmmds=search&cur_warehouse=CN).
* Header pins [**$6.39**/20 sets of male/female pairs](https://www.ebay.com/itm/20pcs-Male-Female-Header-1x40-2-54mm-40-Pin-PCB-Through-Hole-Arduino-and-Pi/223054186518)  
* 8 pin socket  [**$2.99**/20 pcs](https://www.ebay.com/itm/20Pcs-8Pin-Dip-20-Ic-Socket-Double-In-Line-Integrated-Circuit-Solder-Type/163040422083?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D20160908105057%26meid%3D204107da225f4390aaa244fe15edeac8%26pid%3D100675%26rk%3D2%26rkt%3D15%26mehot%3Dag%26sd%3D282315166074%26itm%3D163040422083%26pmt%3D0%26noa%3D1%26pg%3D2380057&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3Af472dd74-4240-11ea-978e-74dbd180e3a4%7Cparentrq%3Aef2d7d2316f0ac3d5c8ad1b3fff6eed4%7Ciid%3A1&autorefresh=true)

# Manufacturing the adapter
This is the circuit diagram manually drawn because it is a bit easier to follow when you're trying to verify your connections.  
![ATTiny85 Flash Electrical Diagram](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Hardware/ATTiny85Circuit.png?raw=true)  

## Designing the PCB
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
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ATTinyFlashingAdapter_Front.jpg)  

**Back of the board**, after soldering the socket and header pins  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ATTinyFlashingAdapter_Back.jpg)  
