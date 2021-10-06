
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




