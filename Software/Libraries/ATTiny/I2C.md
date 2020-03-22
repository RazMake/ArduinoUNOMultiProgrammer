# Library
I am using [**TinyWire**](https://github.com/lucullusTheOnly/TinyWire) library.  
Which is capable of handling both *master* and *slave*, as well as switching to master temporarily while working as slave normally.  

**Interesting things to note:**
- It is very important to use ***pullup resistors for both lines*** (e.g. **2** kOhm)
- The slave part receives also at the general call address **0** (boroadcast). Request for sending to master with this address are not possible in this protocol.
- The user function callbacks for slave receiving and request are called from ISRs, so they shouldn't be to long. Also I'm not sure, if it is save to use master functions inside of it.	
# [References]
- [Instructables: Using an I2C LCD with ATTiny](https://www.instructables.com/id/Using-an-I2C-LCD-on-Attiny85/)