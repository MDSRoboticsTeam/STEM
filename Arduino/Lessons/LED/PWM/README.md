## [PWM Project](https://wokwi.com/arduino/projects/311353186199798336) 

https://wokwi.com/arduino/projects/311353186199798336

In this project, we want to blink the LED rapidly, and depending on if the button is pressed or not, we will
change the ratio of On and Off Times.  This will demonstrate [Pulse Width Modulation (PWM)](https://learn.sparkfun.com/tutorials/pulse-width-modulation), which is used to control
LEDs, Motors, and [Servos](https://components101.com/motors/servo-motor-basics-pinout-datasheet) used in robotics.

By changing the Serial Monitor "display" parameter in the json file (below) we can also plot the state of the button.

*"serialMonitor": { "display": **"plotter"**, "newline": "lf" }*

We also will use the Logic Analyzer to capture our signals.  After we run and stop the code,
we can  then use [PulseView](https://sigrok.org/wiki/Downloads) to analyse the timing of our design.

If you download and install [PulseView](https://sigrok.org/wiki/Downloads) on your PC, you can then load the output file via *Import Value Changed Dump File ...*

- The datafile should be in your Downloads directory with a name *wokwi-logic.vcd*
- Open PulseView and load the file via *Import Value Changed Dump File ...*
- Set Downsampling factor to **50** and select OK

Here is what the output looks like.  I've added some timing markers and labels for clarity, I've also used the 
PWM decoder that is built into PulseView.

Compare the timing values on the graph with what is in the code, and note the LED response as a function of those values.

![Timing](https://raw.githubusercontent.com/MDSRoboticsTeam/STEM/master/Arduino/img/MDS%20PWM%201.png)

Later on we will learn how to generate PWM signals with built-in Arduino functions and libraries.

### Challenge
See if you can control a [Wokwi Servo](https://docs.wokwi.com/parts/wokwi-servo) with your design.  
Hint: To delay fractional milliseconds (e.g. 1.8 ms), look at [delayMicroseconds()](https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/)

### More Information
- [Servos](https://learn.sparkfun.com/tutorials/hobby-servo-tutorial?_ga=2.84966681.1237556482.1633344074-145714027.1633344074)
- [More Servos](https://www.sparkfun.com/servos)
- [PWM](https://learn.sparkfun.com/tutorials/pulse-width-modulation)
