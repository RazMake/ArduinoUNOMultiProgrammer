# Overview
This is a very simple adapter, it has no additional components and all it is doing is to adapt between castelated pads of the ESP chips to pins that can fit into a breadboard.
The only additional thing that I thought of was to make the breadboard adapter fit into the programing adapter.  
I realized that it was prety time consuming to move the chip from one adapter to the other and the pogo pins were going to eventually wear out the pads and start having bad contact.  
This would have caused intermittent issues that I did not want to have to deal with.

# BOM
This adapter needs just a few components.  
*Note: Prices are as of **Dec 2019**.*
* Header pins [**$6.39**/20 sets of male/female pairs](https://www.ebay.com/itm/20pcs-Male-Female-Header-1x40-2-54mm-40-Pin-PCB-Through-Hole-Arduino-and-Pi/223054186518)  
* Pogo Pins [**$4.77**/50pcs](https://www.ebay.com/itm/US-Stock-50pcs-P100-Q2-Dia-1-36mm-180g-Spring-Test-Probe-Pogo-Pin/371912543788?_trkparms=aid%3D1110002%26algo%3DSPLICE.SOI%26ao%3D1%26asc%3D20200122160600%26meid%3D0881a15aa9744e3085db59527660863c%26pid%3D100011%26rk%3D2%26rkt%3D12%26sd%3D401303915326%26itm%3D371912543788%26pmt%3D1%26noa%3D0%26pg%3D2047675&_trksid=p2047675.c100011.m1850)

# Manufacturing the adapter
There is no diagram for this adapter as it is trivial just connects each pad of the ESP to each pin. There still is an electrical diagram in the KiCad project, if you are curious.

## Designing the PCB
I have used [**KiCad**](https://kicad-pcb.org/download/windows/) for designing the PCB and using [**DRCNow (free version)**](https://www.numericalinnovations.com/pages/dfm-now-free-gerber-viewer) for validating them.  
Manufacturing the PCB takes about *1.5 weeks*, so it is worth '*optimizing for high latency*' here. That means:
* Go over the circuit multiple times. I also printed the circuits on paper and went over them with a pen.
* Use any verification you can before sending the design for manufacturing.
* Run the '***rule checks***' and also go over the circuit multiple times looking for errors.  

The [***KiCad project***](https://github.com/RazMake/KiCad/tree/master/Adapters/Adapters%20for%20breadboard/ESP07) containing the schematic and the PCB design of the adapters you see in the pictures (the one I have made and currently using).   
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

**Front of the board**, after soldering the pogo and header pins  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ESPBreadboardAdapter_Front.jpg)  

**Back of the board**, after soldering the pogo and header pins  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ESPBreadBoardAdapter_Back.jpg)  

**Board with ESP connected**  
![](https://github.com/RazMake/ArduinoUNOMultiProgrammer/blob/master/Photos/ESPBreadboardAdapter_WithESP.jpg)  
