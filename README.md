# Data Logger (and using cool sensors!)

*A lab report by Ben Hwang.*

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

It has 10 bits of resolution which makes sense with the value above since 2^10 is 1024.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

I think this is just adding resistors in parallel...not sure.

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

The values range from 0-1000

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

It appears to be a linear relationship. As force increases the voltage values increase until it hits a limit of 1000. Similarly as you stop applying force the values drop to 0.

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

[Code](https://github.com/bhwan1118/IDD-Fa18-Lab3/blob/master/LED_Fade_Code.ino)

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

Flex Sensor : Range of resistances = 25,000 Ohms to 100,000 ohms
Softpot : min is 10k?
Photocell : min 5-10 k up to 200 K ohms


**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

It's roughly linear?

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[Code (to modify)](https://github.com/bhwan1118/IDD-Fa18-Lab3/blob/master/LED_Display_Accel.ino)

### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

When there is nothing in proximity to the sensor the value of Proximity is roughly 2200 and Ambient is 110. When I touch the sensor the value goes all the way up to 65,000 in proximity and ambient drops to around 7. As I move my finger closer it seems that the voltage change increases exponentially up to the upper bound listed.

**b. Upload your merged code to your lab report repository and link to it here.**

[Merged Code](https://github.com/bhwan1118/IDD-Fa18-Lab3/blob/master/Merged_Prox_Accel.ino)

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

It does matter that the order of actions makes sense. For example, if you had a sequence write -> clear -> read, you would never be able to read what you wrote to the board.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

You don't want to continuously write, clear, or read data from the board. Data should be written once and then read/cleared once. I suspect that continuously writing to a board would be cumbersome and even potentially lead to errors.

**c. How many byte-sized data samples can you store on the Atmega328?**

The Atmega328 contains 1024 bytes, thus 1024 byte data samples.

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

For the analog pins, the values of the readings are already converted to a range from 0-1024 so this wouldn't be a problem? For I2C you would have to make sure that you scale the full range of readings to a 0-1024 scale. For example, if you had a I2C range of 0-10,000 you and you were registering a value of 5,000 you could scale it by (5000*1000)/10000 = 500 which is within the range of the arduino

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

It appears that a way to accomplish this is to directly specify multiple machine addresses for where to store each piece of the data so that you can store something bigger than a single byte.

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

[Ambient Sensor EEPROM code: Main ](https://github.com/bhwan1118/IDD-Fa18-Lab3/blob/master/ModifiedSwitchState.ino)

[Ambient Sensor EEPROM code: Write ](https://github.com/bhwan1118/IDD-Fa18-Lab3/blob/master/state2.ino)

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

![image](https://github.com/bhwan1118/IDD-Fa18-Lab3/blob/master/State%20Diagram.jpg)

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
