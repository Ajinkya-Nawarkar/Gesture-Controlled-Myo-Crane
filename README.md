# Gesture-Controlled-Myo-Crane
An automated Crane prototype using Myo Armband and Myoduino

Circuit Setup
=============
1. Use a servo(3 input) powered by arduino +5V pin and with signal pin specified in code. Then last input is ground.
2. Connect a small battery to power motor, using common H-Bridge setup to allow for forward a reverse current.
   Use two outputs from Digital PWM on Arduino to choose wether forward or reverse current. 

Startup
=======
Write the successful Arduino code in, then open MyoDuino script and make sure Myo band is on and synch'ed
Then choose the COM port of the Arduino and watch the magic happen.
