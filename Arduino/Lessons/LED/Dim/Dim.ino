/* 
  A simple sketch to illustrate Analog Ouput to set an LED
  to several different light levels
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
    Serial.print("OFF - 0\n");
    delay(500);  // wait 500 ms

    analogWrite(ledPin, 64);  //    turn on LED LOW
    Serial.print("LOW - 64 \n");
    delay(500);  // wait 500 ms
    
    analogWrite(ledPin, 128);  //    turn on LED MED LOW
    Serial.print("MED LOW - 128\n");
    delay(500); // wait 500 ms

    analogWrite(ledPin, 192);  //    turn on LED MED HIGH
    Serial.print("MED HIGH - 192\n");
    delay(500); // wait 500 ms

    analogWrite(ledPin, 255);  //    turn on LED HIGH
    Serial.print("MED HIGH - 255\n");
    delay(500); // wait 500 ms
    
    
}
