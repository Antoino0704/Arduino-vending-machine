# Arduino-vending-machine
simulates a vending machine where the LEDs represent food 

# For programmer
the loop function of the sketch checks if there are data in the monitor if you read them and if the value is 49 (10) it adds 10 to the "money" variable and then checks if any buttons have been clicked and checks the value of "money" ( according to the button, the number to compare with varies see the code to understand better) if it is true the corresponding LED lights up and in money the comparison number is subtracted if it is false the white LED will flash according to what is needed to reach that value ( 10 -> 30 2 times)

# THE LEDs

red led --> 0.20€

yellow led --> 0.30€

green led --> 0.40€

blue led --> 0.50€

white led --> indicates how long it is to reach the price of that product according to the budget (example if you have € 0.10 and you want to buy the green led (€ 0.30) the white led flashes twice) 

# THE BUTTONS

the various buttons are used to buy a certain food (therefore a LED) based on the position in which it coincides (for example the first button is used to buy the first LED and so on) both the numbering of the LEDs start from left to right

# Requirements

1 Arduino (recommend Arduino uno but you can use another model)

1 breadboard (but I used 2)

5 resistor

5 led (colors of your choice)

5 button

15 jumper (but I used 16)

# How to get started

mount the circuit following the code set-up

upload the sketch on arduino and open the serial monitor

enter 10 from the keyboard to add 0.10€ to your budget

your current budget will gradually appear in the monitor

click on the button based on the LED you want to turn on, if you have enough money, the "purchase successfully completed" screen will pop up and the corresponding LED will light up. then also the white led will flash according to how much you miss to be able to buy that product again (1 time --> 0.10€)

if you do not have enough money, the white LED flashes immediately
