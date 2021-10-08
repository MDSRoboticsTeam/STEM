// A line with '//' at the beginning is a comment line (for human use only)

/*
   Multiple comment lines
   everything between /* and * / is a comment (note that there should be no space after the second '*') 

*/

//  IMPORTANT:  All lines of code should end with a ';'

// Variables
static int ledPin = 9;    //  LED light is connected to Pin 9 (static means it does not change, int means integer)
static int buttonPin = 7; //  Button connected to Pin 7
int delayTime = 500;          //  Delay Time in milliseconds, initialized to 500

void setup() {
  // put your setup code here, to run once:  
  pinMode(ledPin, OUTPUT);          // This pin is an output
  pinMode(buttonPin, INPUT_PULLUP); // This pin is an input (INPUT_PULLUP is advanced feature, covered later)
  Serial.begin(19200);              // This initialized the serial port for debugging
  Serial.println("Hello Cavaliers"); // Print a string message with a new line
}

void loop() {
  // put your main code here, to run repeatedly:
  short i;  // i is a short (small int) variable we use to count
  short buttonState;  // 1 = Button Pressed

  buttonState = digitalRead(buttonPin);  // Read Button and store in buttonState   

  if(buttonState == 0) {  // If buttonState == 0, it is Pressed (INPUT_PULLUP above changes it from 1 to 0)
    Serial.println("Button Pressed");  //  Do this 
    delayTime = 500;                  // Delay 1/2 second when we turn on LED
  } else {                // Otherwise
    Serial.println("Button Released"); // Do this
    delayTime = 1000;                   // Delay 1/2 second (500 ms) when we turn on LED
  }

  digitalWrite(ledPin,1);   // Turn on LED
  delay(delayTime);         // Wait
  digitalWrite(ledPin,0);   // Turn off LED
  delay(delayTime);         // Wait

}
