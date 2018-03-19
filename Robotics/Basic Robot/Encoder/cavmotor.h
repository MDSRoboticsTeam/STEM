#ifndef Cavmotor_h
#define Cavmotor_h
#include "Arduino.h"
class Cavmotor
{
  public:
    Cavmotor( 
      byte dir_0, // Direction 0 pin
      byte dir_1, // Direction 1 pin
      byte enc,    // Encoder input pin
      byte power // PWM input power pin
      );

    void Cavmotor::forward(int power); // Move Forward
    void Cavmotor::reverse(int power); // Move Reverse
    void Cavmotor::brake(); // Shutoff and brake
    void Cavmotor::shutoff(); // shutoff and coast
    /*
    void pivotLeft(float deg);
    void pivotRight(float deg);
   */
  private:

    byte  _dir_0_pin;
    byte  _dir_1_pin;
    byte  _enc_pin;
    byte  _pwm_pin;

    int   _motorPower;
    float _motorSpeed;
    
    
};
#endif 
