/*
 * SparkFun Ludus ProtoShield Example Code
 * SparkFun Electronics
 * Nick Poole 2015
 * 
 * This is an Arduino shield that integrates an H-Bridge Driver and 
 * breaks out all I/O ports to three-pin headers on a GND/PWR/SIG 
 * standard. This enables quick prototyping and integration of 
 * Arduino projects w/o the need of a breadboard.
 * 
 * Modified to test the Sparkfun Circular Chassis robot for Mount de Sales Academy
 * modified to test the DAGU encoder
 * 
 * Ludus is the mascot of the SparkFun Education team. 
 * It is a highly intelligent octopus.
 * 
 * Please check the License.md file for licensing information.
*/

// #include <PinChangeInt.h>
// #include <PinChangeIntConfig.h>

int pwm_a = 3;   // Channel A speed
int pwm_b = 6;   // Channel B speed
int dir_a0 = 4;  // Channel A direction 0
int dir_a1 = 5;  // Channel A direction 1
int dir_b0 = 7;  // Channel B direction 0
int dir_b1 = 8;  // Channel B direction 1
const int enc_r = 2;  // right motor encoder
const int enc_l = 9;  // right motor encoder

char inbit; // A place to store serial input


// Stuff for encoder
const byte interruptPinR = 2;  // Right motor encoder  
const byte interruptPinL = 9;  // Left motor encoder
volatile byte state = LOW;

// Count of pulses from left and right encoder
// These must be volatile since they are updated by hardware
volatile long rotaryCountR = 0; // number of encoder pulses
volatile long rotaryCountL = 0; // number of encoder pulses

void setup()
{

  Serial.begin(9600);

  // Ouputs to drive motors
  pinMode(pwm_a, OUTPUT);  // Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a0, OUTPUT);
  pinMode(dir_a1, OUTPUT);
  pinMode(dir_b0, OUTPUT);
  pinMode(dir_b1, OUTPUT); 

  // Setup for encoders
  
  // Right motor
  pinMode(enc_r, INPUT_PULLUP);     //set the pin to input w/pullup
  attachInterrupt(enc_r,isr_r,RISING); // attach a PinChange Interrupt to our pin on the rising edge
  // Left motor
  pinMode(enc_l, INPUT_PULLUP);     //set the pin to input w/pullup
  attachInterrupt(enc_l,isr_l,RISING); // attach a PinChange Interrupt to our pin on the rising edge
  
  delay(3000);
  forward(25); // turn on motors
}

void loop()
{ 
      Serial.println(rotaryCountR,rotaryCountL);
      if(rotaryCountR >= 392){
        brake();
        shutoff();
      }
      
}

void isr_r ()
{
      
   rotaryCountR++;
}  // end of isr

void isr_l ()
{
      
   rotaryCountL++;
}  // end of isr

void forward(int speed) // Move Forward
{ 

digitalWrite(dir_a0, 0);
digitalWrite(dir_a1, 1);
digitalWrite(dir_b0, 0);
digitalWrite(dir_b1, 1);

analogWrite(pwm_a, speed); 
analogWrite(pwm_b, speed); 

}

void reverse(int speed) // Move Backward 
{

digitalWrite(dir_a0, 1);
digitalWrite(dir_a1, 0);
digitalWrite(dir_b0, 1);
digitalWrite(dir_b1, 0);

analogWrite(pwm_a, speed); 
analogWrite(pwm_b, speed); 
 
}

void turnL(int speed) // Turn Left while moving forward
{ 

digitalWrite(dir_a0, 0);
digitalWrite(dir_a1, 1);
digitalWrite(dir_b0, 0);
digitalWrite(dir_b1, 1);

analogWrite(pwm_a, speed); 
analogWrite(pwm_b, speed/4); 

}

void turnR(int speed) // Turn Right while moving forward
{ 

digitalWrite(dir_a0, 0);
digitalWrite(dir_a1, 1);
digitalWrite(dir_b0, 0);
digitalWrite(dir_b1, 1);

analogWrite(pwm_a, speed/4); 
analogWrite(pwm_b, speed); 

}


void spinL(int speed) // Spin Left in place
{ 

digitalWrite(dir_a0, 0);
digitalWrite(dir_a1, 1);
digitalWrite(dir_b0, 1);
digitalWrite(dir_b1, 0);

analogWrite(pwm_a, speed/2); 
analogWrite(pwm_b, speed/2); 

}

void spinR(int speed) // Spin Right in place
{ 

digitalWrite(dir_a0, 1);
digitalWrite(dir_a1, 0);
digitalWrite(dir_b0, 0);
digitalWrite(dir_b1, 1);

analogWrite(pwm_a, speed/2); 
analogWrite(pwm_b, speed/2); 

}

void brake() // Short brake
{ 

digitalWrite(dir_a0, 1);
digitalWrite(dir_a1, 1);
digitalWrite(dir_b0, 1);
digitalWrite(dir_b1, 1);

analogWrite(pwm_a, 0); 
analogWrite(pwm_b, 0);
delay(100);

}

void shutoff() // Stop Motors w/o braking
{ 

digitalWrite(dir_a0, 0);
digitalWrite(dir_a1, 0);
digitalWrite(dir_b0, 0);
digitalWrite(dir_b1, 0);

analogWrite(pwm_a, 0); 
analogWrite(pwm_b, 0);

}

void draw() // Serial Instructions
{
  Serial.println("          DuckBot 2015          ");
  Serial.println("                                ");
  Serial.println("   -------------------------    ");
  Serial.println("   |       |       |       |    ");
  Serial.println("   |   Q   |   W   |   E   |    ");
  Serial.println("   | turnL |forward| turnR |    ");
  Serial.println("   -------------------------    ");
  Serial.println("   |       |       |       |    ");
  Serial.println("   |   A   |   S   |   D   |    ");
  Serial.println("   | spinL |reverse| spinR |    ");
  Serial.println("   -------------------------    ");
  Serial.println("   |       |       |       |    ");
  Serial.println("   |   Z   |   X   |   C   |    ");
  Serial.println("   |servo L| brake |servo R|    ");
  Serial.println("   -------------------------    ");
  Serial.println("                                ");
}








