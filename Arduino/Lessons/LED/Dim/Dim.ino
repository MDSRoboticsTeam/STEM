/* 
  A simple sketch to illustrate Analog Ouput to set an LED
  to several different light levels.
  Uses Hardware shown in Blink.fzz
*/

const int ledPin = 9;   // LED output pin

void setup()
{
  // Set up the pushbutton pins to be an output
  pinMode(ledPin, OUTPUT);  // Set pin mode to output
  Serial.begin(9600);       // Start serial output
  Serial.print("Setup\n");  
}

void loop()
{
    
    analogWrite(ledPin,0);  //    turn LED OFF
    Serial.println(0);
    Serial.println("/t");
    delay(500);  // wait 500 ms

    analogWrite(ledPin, 64);  //    turn on LED LOW
    Serial.println(64);
    Serial.println("/t");
    delay(500);  // wait 500 ms
    
    analogWrite(ledPin, 128);  //    turn on LED MED LOW
    Serial.println(128);
    Serial.println("/t");
    delay(500); // wait 500 ms

    analogWrite(ledPin, 192);  //    turn on LED MED HIGH
    Serial.println(192);
    Serial.println("/t");
    delay(500); // wait 500 ms

    analogWrite(ledPin, 255);  //    turn on LED HIGH
    Serial.println(255);
    Serial.println("/t");
    delay(500); // wait 500 ms
    
    
}
