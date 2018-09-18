//This is code to write force PR if you apply enough force

//** Ran out of time...logic is as follows. Get the sensor value from A0 and then write it only if that value exceeds exceeds PR.
//** You would read that value from the board to set PR

#include <EEPROM.h>
int addr = 0; 
int bytemax = 1024;
int address = 0;
byte value;

int PR;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  value = EEPROM.read(address);
  //Then some way to convert the byte value to an int for PR, but for now will put this dummy
  PR = value;
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  //Serial.println(sensorValue);

  int val = sensorValue/4;

  //write value only if val registered was greater than PR
  if(val > PR){
    EEPROM.write(addr, val);
  }
  
  addr = addr + 1;
  delay(1000);        // delay in between reads for stability
}
