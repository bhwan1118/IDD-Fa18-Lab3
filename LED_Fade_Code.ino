/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

//use this to track fsr changes
int force;

//hold converted force values for RGB
int mapped_force; 

 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  

}
 
void loop()
{
  
  force = analogRead(A0);
  mapped_force = force * 255 / 1000;

  if(force <= 1000){
    setColor(255-mapped_force, 0, 0);  // aqua
  }else{
    setColor(0, 0, 0);
  }
}
 
void setColor(int red, int green, int blue)
{
  /*#ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif */
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255- green);
  analogWrite(bluePin, 255 - blue);  
}
