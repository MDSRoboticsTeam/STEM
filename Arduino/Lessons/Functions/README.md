## [Functions](https://wokwi.com/arduino/projects/311893245894328896) 

In the [PWM Project](https://wokwi.com/arduino/projects/311353186199798336) the LED was made
to be bright or dim depending on whether a button was pushed.  As we add more code to add additional
features, it will be harder to follow and debug our code.  

We can mitigate this problem by breaking up our code into **functions** that provide several
main advantages:

- The code is easier to follow and debug.
- The code can easier to be devleoped, test, and debug by teams rather than individuals.
- The code can be reused, reducing errors and the size of the code.  Changes to the functions (added capabilities or bugfixes) will be available wherever the function is used.


In mds-functions.ino, notice how our main **loop()** has been reduced in complexity from this

```C++
  // put your main code here, to run repeatedly:

  short buttonState;  // 0 = Button Pressed

  buttonState = digitalRead(buttonPin);  // Read Button and store in buttonState   
  
  //  depending on if the button is pressed, set the On And Off Time
  //  Not Pressed:  5 ms On, 5 ms Off - 50% Duty Cycle
  //  Pressed:      1 ms On, 9 ms Off - 10% Duty Cycle
  if(buttonState == 0) {  // If buttonState == 0, it is Pressed (INPUT_PULLUP above changes it from 1 to 0)
    Serial.println(1);  //  graph to serial monitor
    onTime  = 1;            // Set LED On and Off time (im millisecs) 10% Duty Factor
    offTime = 9;
  } else {                // Otherwise it is not pressed
      Serial.println(0); // Do this
      onTime  = 5;                  // Set LED On and Off time (im millisecs) 50% Duty Factor
      offTime = 5;                  
  }

  digitalWrite(ledPin,1);   // Turn on LED
  delay(onTime);            // Wait
  digitalWrite(ledPin,0);   // Turn off LED
  delay(offTime);           // Wait

```
To the following ...

```C++
void loop() {
  // put your main code here, to run repeatedly:

  setPWMDutyCycle();  // read button and set Duty Cycle
  toggleLED();        // toggle LED on/off 
}
```

The functionality of *setPWMDutyCycle()* and *toggleLED()* are now **encapsulated** in their respective functions and can be used anywhere in the program.
