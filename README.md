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

**b. Upload your merged code to your lab report repository and link to it here.**

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
