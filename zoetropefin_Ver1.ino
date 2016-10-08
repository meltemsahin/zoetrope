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

/* loop count per animation (+1 for while loop)
 * There is 10 steps at 24RPM per loop cycle in Animation1
 * and 18 steps at 44RPM per loop cycle in Animation2
 */
#define ANM1 (210 + 1)
#define ANM2 (240 + 1)

Stepper stepper_motor(200, 4, 5, 6, 7);  // steps_per_rev, ain1_pin, ain2_pin, bin1_pin, bin2_pin

void setup(){
  pinMode(LED, OUTPUT);

  // There are two different Input source and both of them is PIR sensor from adafruit.
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  
}

void setFrameVisible(int delayT){
  digitalWrite(LED, HIGH);  
  delay(delayT);    
  digitalWrite(LED, LOW); 
}

void nextFrame(byte anmType){
  stepper_motor.setSpeed((anmType == ANM1) ? 24 : 44); //RPM value 
  stepper_motor.step((anmType == ANM1) ? 10 : 18);
}

void playAnimation(byte anmType){
  byte temp = anmType;
  while(--temp){
    setFrameVisible(5); 
    nextFrame(anmTpye);
  }
}

void loop(){

  /*  When sensor detect someone than animation
   *  number 1 and 2 will automatically play for 4 times
   */
  
  short repeat_anm = 4 + 1; // +1 for loop
 
    while(--repeat_anm && (digitalRead(SENSOR1) || digitalRead(SENSOR2)) ){
     playAnimation(ANM1);
     playAnimation(ANM2);
    }
    
}
