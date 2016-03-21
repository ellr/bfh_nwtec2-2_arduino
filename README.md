# bfh_nwtec2-2_arduino
 BFH-TI course NWTEC2-2: arduino projects

## project 1
Main topic: PWM and capacitors

For all tasks a  1mF capacitor and a 10kOhm resistor was used.

#### Task 1
Visualize the discharging of the capacitor. The code snippet for project 1 mesures the capacity as fast as possible and prints out the values to the serial interface.

#### Task 2 & 3
Both taks are very similar. The only difference is the clock rate for the pwm pin. In task 3 it is much slower. That make it behave diffrently.

Starting with t1 = 8, the code snippet mesures the voltage on the capacitor over a short time periode and increases afterwards t1 by 8. t1's range is from 0 to 255.
