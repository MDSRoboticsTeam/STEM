#include "Arduino.h"

class classIrq {
  public:
    classIrq(
      byte irqPin,   // Pin
      void (*Func)() // ISR
      ) 
    {
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
      isrFunc();  // Call the ISR
    }
    static void marshall() {
      anchor->isr();
    }
    static classIrq* anchor;
    volatile byte isrFlag;
    byte sensePin;
    void (*isrFunc)();
};
