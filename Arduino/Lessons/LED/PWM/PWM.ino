/* 
  A  sketch to illustrate use Digital Ouput to blink an LED
  at varying duty factors
  Also demonstrates a simple function
  Uses Hardware shown in Blink.fzz
*/

const int ledPin = 9;   // LED output pin

void setup()
{
  // Set up the pushbutton pins to be an output
  pinMode(ledPin, OUTPUT);  // Set pin mode to output
  Serial.begin(19200);       // Start serial output
  Serial.print("Setup\n");  
}

void loop()
{
 
      BlinkLED(ledPin,500,500);
      delay(5000);
      BlinkLED(ledPin,50,50);
      delay(5000);
      BlinkLED(ledPin,5,5);
      delay(5000);
      BlinkLED(ledPin,200,800);
      delay(5000);
      BlinkLED(ledPin,20,80);
      delay(5000);
      BlinkLED(ledPin,2,8);
      delay(5000);

}

/* Function to turn LED on and off
 *  Inputs:
 *    ledPin; Digital Ouput pin
 *    ontime: Time in ms to turn LED on 
 *    offtime: Time in ms to turn LED off
 *  Returns:
 *    void
 *  Special notes:  
 *    plots to serial port
 *  Example:
 *    Blink LED at 1 Hz and 50% Duty factor
 *    BlinkLED(500,500);
 */
 
void BlinkLED(short DOpin, short ontime, short offtime)
{

    digitalWrite(DOpin, HIGH);  //    turn on LED
    Serial.println(ontime);
    Serial.println("/t");
    delay(ontime);  // wait 500 ms
    
    digitalWrite(DOpin, LOW);  //    turn off LED
    Serial.println(offtime);
    Serial.println("/t");
    delay(offtime); // wait 500 ms  
}


  
