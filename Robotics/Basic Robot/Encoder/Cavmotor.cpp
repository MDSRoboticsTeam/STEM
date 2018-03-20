/* Sample code
class classIrq {
  public:
    classIrq(byte irqPin) {
      anchor = this;
      sensePin = irqPin;
    }
    void begin() {
      char irqNum = digitalPinToInterrupt(sensePin);
      if (irqNum != NOT_AN_INTERRUPT) {
        EIFR = _BV(irqNum);         // cancel evt. pending interrupt
        attachInterrupt(irqNum, classIrq::marshall, CHANGE);
      }
    }
  private:
    void isr() {
      isrFlag = true;
    }
    static void marshall() {
      anchor->isr();
    }
    static classIrq* anchor;
    volatile byte isrFlag;
    byte sensePin;
};
classIrq* classIrq::anchor = NULL;

The constructor sets the private static pointer and the interrupt pin.

begin attaches the interrupt to a static member function.

The static member function only uses the static private pointer to call the private ISR.

Is this enough automatism and privacy?

If you create only one of these objects, you have a deliberate singleton.
*/

#include "Arduino.h"
#include "cavmotor.h"
Cavmotor::Cavmotor(   
      byte dir_0, // Direction 0 pin
      byte dir_1, // Direction 1 pin
      byte enc,   // Encoder input pin
      byte pwr    // PWM input pin for power
      )
{

        
        
        
        // save input params
        _dir_0_pin = dir_0;
        _dir_1_pin = dir_1;
        _enc_pin   = enc;
        _pwm_pin   = pwr;
        
        // Set control pins to be outputs
        pinMode(_pwm_pin, OUTPUT);  
        pinMode(_dir_0_pin, OUTPUT);
        pinMode(_dir_1_pin, OUTPUT);

        // Attach ISR to PinChange event
        // attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(_enc_pin), pulseISR, RISING);

        
}

void Cavmotor::pulseISR()
{

  
}
void Cavmotor::forward(int power) // Move Forward
{ 

    digitalWrite(_dir_0_pin, 0);
    digitalWrite(_dir_1_pin, 1);
    analogWrite(_pwm_pin, power); 

    _motorPower = power;

}

void Cavmotor::reverse(int power) // Move Backward 
{

    digitalWrite(_dir_0_pin, 0);
    digitalWrite(_dir_1_pin, 1);
    analogWrite(_pwm_pin, power); 

    _motorPower = power;

}

void Cavmotor::brake() // Short brake
{ 
  digitalWrite(_dir_0_pin, 1);
  digitalWrite(_dir_1_pin, 1);
  
  analogWrite(_pwm_pin, 0); 
}

void Cavmotor::shutoff() // Stop Motors w/o braking
{ 

  digitalWrite(_dir_0_pin, 0);
  digitalWrite(_dir_1_pin, 0);
  
  analogWrite(_pwm_pin, 0); 
}


