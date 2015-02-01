/*****************************************************************************
* Program description:
* This program will control the LEDs for a lamp. The lamp will contain
* 15 RGB LEDs, connected to the analog pins 2-13. Colors are controlled
* using analog rather than digital for the sake of multiple colors, rather than
* strictly being off or on. The LEDs used in this code are common anode so the 
* power being sent is the inverse of what it seems like should be sent
*****************************************************************************/
#include <EEPROM.h> // include EEPROM in order to allow reads and writes to memory

int red_1 = 13, green_1 = 12, blue_1 = 11; // assign variables for first set of LEDs
int red_2 = 10, green_2 = 9, blue_2 = 8;   // assign variables for second set of LEDs
int red_3 = 7, green_3 = 6, blue_3 = 5;    // assign variables for third set of LEDs
int red_4 = 4, green_4  = 3, blue_4 = 2;   // sssign variables for fourth set of LEDs
long delayTime = 720000L; // amount of time each color is on is set here 720000 = 12 minutes

void setup(){
  // set pins 2 through 13 to control an analog output for the individual pins on the LEDs
    pinMode(13, OUTPUT); // initialize pin 13 for output
    pinMode(12, OUTPUT); // initialize pin 12 for output
    pinMode(11, OUTPUT); // initialize pin 11 for output
    pinMode(10, OUTPUT); // initialize pin 10 for output
    pinMode(9, OUTPUT);  // initialize pin 9 for output
    pinMode(8, OUTPUT);  // initialize pin 8 for output
    pinMode(7, OUTPUT);  // initialize pin 7 for output
    pinMode(6, OUTPUT);  // initialize pin 6 for output
    pinMode(5, OUTPUT);  // initialize pin 5 for output
    pinMode(4, OUTPUT);  // initialize pin 4 for output
    pinMode(3, OUTPUT);  // initialize pin 3 for output
    pinMode(2, OUTPUT);  // initialize pin 2 for output
} // close setup
void loop(){
  
  // the following 12 lines of code prevent random colors from showing up when first turned on
  analogWrite(red_1, 255); // ensure that red is complete off
  analogWrite(red_2, 255); // ensure that red is complete off
  analogWrite(red_3, 255); // ensure that red is complete off
  analogWrite(red_4, 255); // ensure that red is complete off
  analogWrite(green_1, 255); // ensure that green is completely off
  analogWrite(green_2, 255); // ensure that green is completely off
  analogWrite(green_3, 255); // ensure that green is completely off
  analogWrite(green_4, 255); // ensure that green is completely off
  analogWrite(blue_1, 255);  // ensure that blue is completely off
  analogWrite(blue_2, 255);  // ensure that blue is completely off
  analogWrite(blue_3, 255);  // ensure that blue is completely off
  analogWrite(blue_4, 255);  // ensure that blue is completely off
  
  
  int ROM = EEPROM.read(0); // read memory address 0 to see what color was last lit
  if (ROM == 1){ // check to see if the last color was red
    red();  // start back at red
  } // close if
  else if(ROM == 2){ // check to see if the last color was green
    green(); // start back at green
  } // close if
  else if(ROM == 3){ // check to see if last color was blue
    blue(); // start back at blue
  } // close if
  else if(ROM == 4){ // check to see if last color was magenta
    magenta(); // start back at magenta
  } // close if
  else if(ROM == 5){ // check to see if last color was cyan
    cyan(); // start back at cyan
  } // close if 
  else{ // if nothing else (may be the case in first time use)
    red(); // start at red
  } // close else
} // close loop

void red(){
  int r = 250; // set red to almost off
  
  // this loop will increase the brightness of the red light so that it fades in
  // with a delay of 200ms it will take a total of 2 seconds in order for the red to go from completely off to fully on
  while(r != 0){ // keep looping until red is 0 (fully on)
    analogWrite(red_1, r); // change first set of LEDs to the 'r' value
    analogWrite(red_2, r); // change second set of LEDs to the 'r' value
    analogWrite(red_3, r); // change the third set of LEDs to the 'r' value
    analogWrite(red_4, r); // change the fourt set of LEDs to the 'r' value
    r -= 25; // make r smaller
    delay(200); // hold for 200ms
  } // close while loop
  
  analogWrite(red_1, 0); // set first set of LEDs to fully on
  analogWrite(red_2, 0); // set second set of LEDs to fully on
  analogWrite(red_3, 0); // set third set of LEDs to fully on
  analogWrite(red_4, 0); // set fourth set of LEDs to fully on
  analogWrite(green_1, 255); // ensure that green is completely off
  analogWrite(green_2, 255); // ensure that green is completely off
  analogWrite(green_3, 255); // ensure that green is completely off
  analogWrite(green_4, 255); // ensure that green is completely off
  analogWrite(blue_1, 255);  // ensure that blue is completely off
  analogWrite(blue_2, 255);  // ensure that blue is completely off
  analogWrite(blue_3, 255);  // ensure that blue is completely off
  analogWrite(blue_4, 255);  // ensure that blue is completely off
  
  EEPROM.write(0,2); // write the next color to the EEPROM for next reboot
  delay(delayTime); // remain red for the given amount of time. -2000 is because it will spend two seconds fading out

  r = 0; // ensure that r is equal to 0
  while(r != 250){ // loop through until red is 250 (almost off)
    analogWrite(red_1, r); // change first set of LEDs to current 'r' color
    analogWrite(red_2, r); // change second set of LEDs to current 'r' color
    analogWrite(red_3, r); // change third set of LEDs to current 'r' color
    analogWrite(red_4, r); // change fourth set of LEDs to current 'r' color
    r += 25; // increment 'r' by 25
    delay(200); // delay for 200ms
  } // close while loop
  
  analogWrite(red_1, 255); // turn first set of LEDs to completely off
  analogWrite(red_2, 255); // turn second set of LEDs to completely off
  analogWrite(red_3, 255); // turn third set of LEDs to completely off
  analogWrite(red_4, 255); // turn fourth set of LEDs to completely off
  delay(500); // remain off for 500ms
  
  green(); // turn on green
} // close red()

void green(){
  int g = 250; // set green to almost off
  
  while(g != 0){ // keep looping until green is 0 (fully on)
    analogWrite(green_1, g); // set first set of LEDs to current 'g'
    analogWrite(green_2, g); // set second set of LEDs to current 'g'
    analogWrite(green_3, g); // set third set of LEDs to current 'g'
    analogWrite(green_4, g); // set fourth set of LEDs to current 'g'
    g -= 25; // subtract 25 from g
    delay(200); // delay 200ms
  } // close while loop
  
  analogWrite(red_1, 255);  // turn red completely off
  analogWrite(red_2, 255);  // turn red completely off
  analogWrite(red_3, 255);  // turn red completely off
  analogWrite(red_4, 255);  // turn red completely off
  analogWrite(green_1, 0);  // turn green completely on
  analogWrite(green_2, 0);  // turn green completely on
  analogWrite(green_3, 0);  // turn green completely on
  analogWrite(green_4, 0);  // turn green completely on
  analogWrite(blue_1, 255); // turn blue completely off
  analogWrite(blue_2, 255); // turn blue completely off
  analogWrite(blue_3, 255); // turn blue completely off
  analogWrite(blue_4, 255); // turn blue completely off

  EEPROM.write(0,3); // write next color to EEPROM so it will go to the next color upon reboot
  delay(delayTime); // remain green for set amount of time - 2000ms. -2000ms is for the 2000ms fade time
  
  // begin loop to fade out green
  while(g != 250){ // loop until green is almost off
    analogWrite(green_1, g); // set first set of LEDs to current 'g'
    analogWrite(green_2, g); // set second set of LEDs to current 'g'
    analogWrite(green_3, g); // set third set of LEDs to current 'g'
    analogWrite(green_4, g); // set fourth set of LEDs to current 'g'
    g += 25; // incrememnt g by 25
    delay(200); // delay for 200ms
  } // close while loop
  
  analogWrite(green_1, 255); // turn green completely off
  analogWrite(green_2, 255); // turn green completely off
  analogWrite(green_3, 255); // turn green completely off
  analogWrite(green_4, 255); // turn green completely off
  delay(500); // remain off for 500ms
  blue(); // turn on blue
} // close green()

void blue(){ 
  int b = 250; // set b to 250 (almost off)
  while(b != 0){ // loop through until blue is completely on
    analogWrite(blue_1, b); // set first set of LEDs to current 'b'
    analogWrite(blue_2, b); // set second set of LEDs to current 'b'
    analogWrite(blue_3, b); // set third set of LEDs to current 'b'
    analogWrite(blue_4, b); // set fourth set of LEDs to current 'b'
    b -= 25; // subtract 25 from b
    delay(200); // delay for 200ms
  } // close while loop
  
  analogWrite(red_1, 255); // ensure that red is completely off
  analogWrite(red_2, 255); // ensure that red is completely off
  analogWrite(red_3, 255); // ensure that red is completely off
  analogWrite(red_4, 255); // ensure that red is completely off
  analogWrite(green_1, 255); // ensure that green is completely off
  analogWrite(green_2, 255); // ensure that green is completely off
  analogWrite(green_3, 255); // ensure that green is completely off
  analogWrite(green_4, 255); // ensure that green is completely off
  analogWrite(blue_1, 0); // turn blue completely on
  analogWrite(blue_2, 0); // turn blue completely on
  analogWrite(blue_3, 0); // turn blue completely on
  analogWrite(blue_4, 0); // turn blue completely on
    
  EEPROM.write(0,4); // write next color to EEPROM for next reboot
  delay(delayTime); // remain blue for set amount of time
  b = 0; // ensure that be is equal to 0
  
  while(b != 250){  // continue looping until b is equal to 0
    analogWrite(blue_1, b); // turn first set of LEDs to current 'b' value
    analogWrite(blue_2, b); // turn second set of LEDs to current 'b' value
    analogWrite(blue_3, b); // turn third set of LEDs to current 'b' value
    analogWrite(blue_4, b); // turn fourth set of LEDs to current 'b' value
    b += 25; // increment b by 25
    delay(200); // delay for 200ms
  } // close while loop
  
  analogWrite(blue_1, 255); // turn blue completely off
  analogWrite(blue_2, 255); // turn blue completely off
  analogWrite(blue_3, 255); // turn blue completely off
  analogWrite(blue_4, 255); // turn blue completely off
  delay(500);
  
  magenta(); // turn on magenta
}

void magenta(){
  analogWrite(red_1, 40); // turn red to 40 
  analogWrite(red_2, 40); // turn red to 40
  analogWrite(red_3, 40); // turn red to 40
  analogWrite(red_4, 40); // turn red to 40
  analogWrite(green_1, 255); // turn green completely off
  analogWrite(green_2, 255); // turn green completely off
  analogWrite(green_3, 255); // turn green completely off
  analogWrite(green_4, 255); // turn green completely off
  analogWrite(blue_1, 0); // turn blue completely on 
  analogWrite(blue_2, 0); // turn blue completely on
  analogWrite(blue_3, 0); // turn blue completely on
  analogWrite(blue_4, 0); // turn blue completely on
  
  EEPROM.write(0,5); // write the next color to memory for if it is turned off
  delay(delayTime); // remain magenta for set amount of time
 
  analogWrite(red_1, 255); // turn red off
  analogWrite(red_2, 255); // turn red off 
  analogWrite(red_3, 255); // turn red off
  analogWrite(red_4, 255); // turn red off
  analogWrite(blue_1, 255); // turn blue off
  analogWrite(blue_2, 255); // turn blue off
  analogWrite(blue_3, 255); // turn blue off
  analogWrite(blue_4, 255); // turn blue off
  delay(500);  // delay for 500ms
  cyan(); // turn on cyan
} // close magenta()

void cyan(){
  int g = 255, b = 250; // set g as fully off and b as almost off
  
  analogWrite(red_1, 255); // turn off red
  analogWrite(red_2, 255); // turn off red
  analogWrite(red_3, 255); // turn off red
  analogWrite(red_4, 255); // turn off red
  
  while((b != 0) && ( g != 125)){
    analogWrite(green_1, g); // set first set of green LEDs to current 'g'
    analogWrite(green_2, g); // set second set of green LEDs to current 'g'
    analogWrite(green_3, g); // set third set of green LEDs to current 'g'
    analogWrite(green_4, g); // set fourth set of green LEDs to current 'g'
    analogWrite(blue_1, b); // set first set of blue LEDs to current 'b'
    analogWrite(blue_2, b); // set second set of blue LEDs to current 'b'
    analogWrite(blue_3, b); // set third set of blue LEDs to current 'b'
    analogWrite(blue_4, b); // set fourth set of blue LEDs to current 'b'
    g -= 13; // subtract 13 from green
    b -= 25; // subtract 25 from blue
    delay(200); // delay for 200ms
  }
  
 
  analogWrite(green_1, 125); // turn green about half way on
  analogWrite(green_2, 125); // turn green about half way on
  analogWrite(green_3, 125); // turn green about half way on
  analogWrite(green_4, 125); // turn green about half way on
  analogWrite(blue_1, 0); // turn blue fully on
  analogWrite(blue_2, 0); // turn blue fully on
  analogWrite(blue_3, 0); // turn blue fully on
  analogWrite(blue_4, 0); // turn blue fully on
 
  EEPROM.write(0,1); // store 1 to rom to go to red on next reboot
  delay(delayTime); // remain cyan for set amount of time
  
  while((b != 250) && ( g != 255)){
    analogWrite(green_1, g); // set first set of green LEDs to current 'g'
    analogWrite(green_2, g); // set second set of green LEDs to current 'g'
    analogWrite(green_3, g); // set third set of green LEDs to current 'g'
    analogWrite(green_4, g); // set fourth set of green LEDs to current 'g'
    analogWrite(blue_1, b); // set first set of blue LEDs to current 'b'
    analogWrite(blue_2, b); // set second set of blue LEDs to current 'b'
    analogWrite(blue_3, b); // set third set of blue LEDs to current 'b'
    analogWrite(blue_4, b); // set fourth set of blue LEDs to current 'b'
    g += 13; // increment g by 13
    b += 25; // increment b by 25
    delay(200); // delay for 200ms
  }
  analogWrite(green_1, 255); // turn green fully off
  analogWrite(green_2, 255); // turn green fully off
  analogWrite(green_3, 255); // turn green fully off
  analogWrite(green_4, 255); // turn green fully off
  analogWrite(blue_1, 255); // turn blue fully off
  analogWrite(blue_2, 255); // turn blue fully off
  analogWrite(blue_3, 255); // turn blue fully off
  analogWrite(blue_4, 255); // turn blue fully off
  delay(500); // delay for 500ms
  
  
  
  red(); // go back to red
}
