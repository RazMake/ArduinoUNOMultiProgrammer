# Writing to the NON-Volatile memory
ESP07 has Flash memory, ATTiny85 has EEPROM. Both these kinds of memories are **non**-volatile memories, meaning the data will survive a power cycle of the device.  
This is interesting in some cases because it allows the device to continue what it was doing when it was powered off.  

## ESP07 IDE configuration
Before we go into details with the available APIs, we need to first configure Arduino IDE. In order to determine what settings can we use we would could run a sketch on the
board to get the correct values.
In order to get useful information from that sketch you would need to be able to see the 'println' statements.  
The same process can help when you are trying to debug a program, you can find details [***here***](), if you don't already know how to do it.
