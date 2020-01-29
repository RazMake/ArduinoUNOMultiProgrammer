# Backstory
I am working on a larger project that uses multiple ATTiny85 microcontrollers and ESP8266 to provide internet connectivity. At some point I realized I kept putting off this project because
I did not want to start digging up again how to program each of these devices, set up my computer with the necessary software, go through the pain of trail and error until succesfully programming each device.
I remember that the cheap FTDI adapters are finiky to get to work in windows (the drivers do not always want to work with clone chips and you have to go find an older version on some more or less shady site).

# Solution
So I had a couple of Arduino UNOs (also clones) lying in my drawer and collecting dust, and I thought it would be great if I can somehow use the Arduino to flash each of these devices.
After some reasearch on the internet, it turns out it is possible to program both of these chips (and likely others too).
So I decided to save my self some grief in the future and:
	- make it a repeatable process (flashing each chip)
	- document the computer setup, as well as some of the gotchas
So next time I try this it is going to be a little easier to get past the basics (falshing the microcontrollers) and I can focus on designing the circuit and writting the firmware for my projects.


# BOM (2019)
	. Arduno UNO
	. ATTniy85
	. ESP07
	. Capacitor 10uF
	. 1k rezistor
	. 2.2K rezistor
	. Pogo Pins
	. 8 pin socket

# Electrical circuit
Both circuits are very simple. I ended up just using wires, no PCB.
![ATTiny85 Flash Electrical Diagram]()
![ESP07/12 Flash Electrical Diagram]()

# Code
Great news! There is no *new* code needed for this project: one of the adapters runs without any code the other one needs an example sketch falshed to Arduino UNO (which comes with the IDE).

# Endresult
I have now two adapters that fit on the same Arduino UNO headers, that I can use to flash an ESP07/ESP12/ATTiny85. Luckly for flashing ESPs Arduino needs to be disabled,
so by connecting the RESET pin to the ground, I don't need to reflash the Arduino with a different sketch. Basically I just swap the adapter, change the settings in the IDE and I flash the new bits.

## ATTiny85 adapter

## ESP07/ESP12 adapter


## _Disclaimer_
_There might be better implementations for this but with what I had at my disposal the resulting two adapters are not that bad.
The circuits I have used are minimalistic, and roughly built (no PCBs), but the adapters are relatively small and relatively convenient to use
(relatively = if you are not goint to make tens of version of the same project, in which case you're probably better off buying one of those spring clamp adapters which grab the chip)._