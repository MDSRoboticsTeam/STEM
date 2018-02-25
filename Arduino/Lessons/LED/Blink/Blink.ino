/* 
  A simple sketch to illustrate Digital Ouput to blink an LED
  Blinks LED at 1 Hz rate
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
 
    digitalWrite(ledPin, HIGH);  //    turn on LED
    Serial.println(5);
    Serial.println("/t");
    delay(500);  // wait 500 ms
    
    digitalWrite(ledPin, LOW);  //    turn off LED
    Serial.println(0);
    Serial.println("/t");
    delay(500); // wait 500 ms
}
  
  




