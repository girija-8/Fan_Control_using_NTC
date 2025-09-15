The analog value from A0 is read and converted into resistance.

Using the thermistor equation, resistance is converted into temperature (°C).

Based on the temperature range, a PWM value is selected for the fan/LED:

0% → OFF

50% duty cycle → half speed

100% duty cycle → full speed

The temperature and fan status are printed to the Serial Monitor.
