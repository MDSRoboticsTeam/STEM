/* 
  A simple sketch to illustrate Analog Ouput to set an LED
  to several different light levels.
  Uses Hardware shown in Blink.fzz
*/

const int ledPin9 = 9;   // LED output pin #1
const int ledPin6 = 6;   // LED output pin #2
const int stepDelay = 100; // delay time for each step
void setup()
{
  // Set up the pushbutton pins to be an output
  pinMode(ledPin6, OUTPUT);  // Set pin mode to output
  pinMode(ledPin9, OUTPUT);  // Set pin mode to output

  Serial.begin(19200);       // Start serial output
  Serial.print("Setup\n");  
}

void loop()
{
    
    analogWrite(ledPin9,0);  //    turn LED OFF
    analogWrite(ledPin6,255);  //    turn LED OFF 
    Serial.print(0);
    Serial.print(" ");
    Serial.println(255);
    delay(stepDelay);  // wait 500 ms

    analogWrite(ledPin9, 64);  //    turn on LED LOW
    analogWrite(ledPin6,192);  //    turn LED OFF
    Serial.print(64);
    Serial.print(" ");
    Serial.println(192);
    delay(stepDelay);  // wait 500 ms
    
    analogWrite(ledPin9, 128);  //    turn on LED MED LOW
    analogWrite(ledPin6,128);  //    turn LED OFF
    Serial.print(128);
    Serial.print(" ");
    Serial.println(128);
    delay(stepDelay); // wait 500 ms

    analogWrite(ledPin9, 192);  //    turn on LED MED HIGH
    analogWrite(ledPin6,64);  //    turn LED OFF
    Serial.print(192);
    Serial.print(" ");
    Serial.println(64);

    delay(stepDelay); // wait 500 ms

    analogWrite(ledPin9, 255);  //    turn on LED HIGH
    analogWrite(ledPin6,0);  //    turn LED OFF
    Serial.print(255);
    Serial.print(" ");
    Serial.println(0);

    delay(stepDelay); // wait 500 ms
    
    
}
