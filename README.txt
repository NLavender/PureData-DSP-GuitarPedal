PD Guitar Pedal
By Noah Laudolff

This patch can run on its own, but I run it on a raspberry pi for a real guitar pedal experience. 

Write some cheeky python to run the main program on startup.


I used a Teensy 3.6 to handle the knobs and an Audio Injector Sound Card for the Audio IO. 

The pins are as follows:

FUNCTION      PIN#
POTS:
Input gain    23
Delay time    22
Delay decay   21
Rev wet       20
Rev dry       19
Trem rate     18
Trem depth    17
Dist gain     16
Dist cutoff   15
Comp gain     14
Comp thresh   A22
Comp ratio    A21
High          39
Med           38
Low           37

SWITCHES
On/off        36
Delay         35
Reverb        34
Tremolo       33 
Distortion    31
Compressor    32

LIGHTS
On/off        2
delay         3
Reverb        4
Tremolo       5
Distortion    6
Compressor    7
