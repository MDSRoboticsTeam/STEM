
# LED Current limiting

LEDs (Light Emitting Diodes) are inexpensive (usually less than $0.10), small, reliable, and energy efficient.  However, unlike incandecent bulbs, they require that the current through them is limited.  If this is not done, they will quickly be destroyed.

In order to do this, we need some basic information regarding the LED.  Below is a link to a spcification (spec) sheet for a common LED along with an image with the more useful parameters higlighted.  We will use these parameters to determine how to limit the current through the LED.  Ideally, you should use the spec sheet for the LED part that you are using, but LEDs in general have similar characteristics that are used to determine current limiting circuity.

[LED Spec Sheet](./COM-09590-YSL-R531R3D-D2.pdf)

![Specs](./img/LED%20Characteristics.PNG)

### LED Parameters

* Forward Current - This is the current that will result in device damage if the maximum is continuously exceeded.
* Peak Fwd current - This is the current that will result in device damage if the maximum exceeded for short periods.
* Suggested using current - A manufacturer suggested current value to allow maximum brightness and still operate safely.  

Note that these parameters are in milliamps, or 1 mA == 0.001 Amps.

For this example, we will use the suggested value (16-18 mA), picking 16 mA to increase reliability but still have a reasonable brightness.

* Forward voltage - This is the voltage drop across the LED at the forward current listed

This voltage varies between individual LEDs, and a range is given in the spec.  It also vaies depending on the color of the LED. We will use 2.0 volts in this example.


### Calculating the resistance needed to limit Forward Current

Vcc: Supply voltage 5 V

Vf: Forward Voltage Drop 2 V

Isu:  Suggested current 16 ma

R = (Vcc - Vf) / Isu

R = (5 - 2) / 0.016

R = 3 / .016 = 187.5 Ohms

If we consult a [table of industry standard resistor values](https://eepower.com/resistor-guide/resistor-standards-and-codes/resistor-values/), we find that 220 Ohms is the closest standard value for 10% tolerance resistors.  As tolerances get tighter the proce goes up, and this value is not critical, so we will us a 10% 220 Ohm resistor.  We increase the value over the theoretical 187.5 because this will reduce rather than increase the current, which could damage the LED, especially if the resistance variance due to tolerance lowers the value.

If we subsitute our 220 Ohm resistor into the baove equation

  R = (Vcc - Vf) / Isu

First solving for Isu  

  Isu = (Vcc - Vf) / R 

Substituting our values gives
  
  Isu = 3 V / 220 Ohm  or an **Isu = 13.6 mA**

## Detailed Explanation

Referenceing the circuit diagram below, we will show in detail how to determine the value of the current limiting resistor.  

First, some simple concepts:

- The current **I** that flows through each element (Battery, Resistor, LED) is the same for each element since there are no branches in the circuit.
- The sum of the voltages around the circuit is zero (0) - *Kirchoff's Voltage Law (KVL)*
- When summing, use the sign (+/-) first reached.
- The voltage across a circuit element is the Current (I) multiplied by the Resistance (R). **Ohm's Law** For voltage sources such as batteries, we use the voltage of the battery.

### KVL Loop

First we sum te voltages using KVL, beginning at the lower lect point in the circuit and continuing back to that point.  Remember that the sum is zero, and we use the sign first found when entering each element.

Asseen in the diagram, we have the following voltages:

- Vb: Battery Voltage
- Vr: Resistor Voltage 
- Vf: Diode Voltage

-Vb + Vr + Vf = 0  Note that Vb is negative since we entered through the '-'side of the battery.

![Specs](./img/LEDCurLimitSchem.png)


