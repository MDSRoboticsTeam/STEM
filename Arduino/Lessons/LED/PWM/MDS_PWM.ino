/*
  Sample program to demonstrate Pulse Width Modulation (PWM)
*/


// Variables
static int ledPin = 13;   //  LED light is connected to Pin 13, also internal LED (static means it does not change, int means integer)
static int buttonPin = 7; //  Button connected to Pin 7
int onTime  = 5;          //  On and Off Delay Time in milliseconds, initialized to 5 ms, these will be changed later
int offTime = 5;          //  in the code

void setup() {
  // put your setup code here, to run once:  
  pinMode(ledPin, OUTPUT);          // This pin is an output
  pinMode(buttonPin, INPUT_PULLUP); // This pin is an input (INPUT_PULLUP is advanced feature, covered later)
  Serial.begin(19200);              // This initializes the serial port for debugging
  Serial.println("Hello Cavaliers"); // Print a string message with a new line
}

void loop() {
  // put your main code here, to run repeatedly:

  short buttonState;  // 0 = Button Pressed

  buttonState = digitalRead(buttonPin);  // Read Button and store in buttonState   
  
  //  depending on if the button is pressed, set the On And Off Time
  //  Not Pressed:  5 ms On, 5 ms Off - 50% Duty Cycle
  //  Pressed:      1 ms On, 9 ms Off - 10% Duty Cycle
  if(buttonState == 0) {  // If buttonState == 0, it is Pressed (INPUT_PULLUP above changes it from 1 to 0)
    //Serial.println(1);  //  graph to serial monitor
    onTime  = 1;            // Set LED On and Off time (im millisecs) 10% Duty Factor
    offTime = 9;
  } else {                // Otherwise it is not pressed
      //Serial.println(0); // Do this
      onTime  = 5;                  // Set LED On and Off time (im millisecs) 50% Duty Factor
      offTime = 5;                  
  }

  digitalWrite(ledPin,1);   // Turn on LED
  delay(onTime);            // Wait
  digitalWrite(ledPin,0);   // Turn off LED
  delay(offTime);           // Wait

}
