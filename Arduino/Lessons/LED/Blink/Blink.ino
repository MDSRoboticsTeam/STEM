const int ledPin = 9;   // pushbutton pin

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.print("Setup\n");
}

void loop()
{
 
    digitalWrite(ledPin, HIGH);  //    turn on LED
    Serial.print("ON\n");
    delay(500);
    
    digitalWrite(ledPin, LOW);  //    turn off LED
    Serial.print("OFF\n");
    delay(500);

    analogWrite(ledPin,128);
    delay(500);
}
  
  




