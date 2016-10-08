/*
    @last change: 8 Oct '16

    Zoetrope from <Meltem Sahin>
    Copyright (C) 2016  A. Arif Balik <arifbalik@outlook.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Stepper.h>

#define LED 13

#define SENSOR1 8
#define SENSOR2 9

// revolution per animation (+1 for while loop)
#define ANM1 (210 + 1)
#define ANM2 (240 + 1)

Stepper stepper_motor(200, 4, 5, 6, 7);  // steps_per_rev, ain1_pin, ain2_pin, bin1_pin, bin2_pin

void setup(){
  pinMode(LED, OUTPUT);

  /*
    There are two different Input source and both of them is PIR sensor from adafruit.
  */
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  
  Serial.begin(9600);
}

void playAnimation(byte anmType){
  byte temp = anmType;
  
  stepper_motor.setSpeed((anmType == ANM1) ? 24 : 44); //RPM value 
 
  while(--temp){
    
    digitalWrite(LED, HIGH);  
    delay(5); //high interval ms      
    digitalWrite(LED, LOW);  

   stepper_motor.step((anmType == ANM1) ? 10 : 18);
  }
}

void loop(){

  /*  When sensor detect someone than animation
   *  number 1 and 2 will automatically play for 4 times
   */
  
  short repeat_anm = 5;
  
  if(digitalRead(SENSOR1) || digitalRead(SENSOR2)){
    while(--repeat_anm){
     playAnimation(ANM1);
     playAnimation(ANM2);
    }
  } 
}

