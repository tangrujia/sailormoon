##Homework 1 
###Research

Here are some exampeles of making music with arduino. In these projects there are all physical objects invovled. By touching the physical objects, players are able to make certain sound.

Sensors:
Force Resistance Sensor: FSRs are sensors that allow you to detect physical pressure, squeezing and weight. 

PIR Motion Sensor -Pyroelectric ("Passive") InfraRed Sensors: PIR sensors allow you to sense motion, almost always used to detect whether a human has moved in or out of the sensors range. 

Thermocouple: thermocouples have no electronics inside them, they are simply made by welding together two metal wires. 

IR Sensor: IR detectors are little microchips with a photocell that are tuned to listen to infrared light. They are almost always used for remote control detection - every TV and DVD player has one of these in the front to listen for the IR signal from the clicker.

http://www.makeuseof.com/tag/musical-projects-arduino-beginners/

https://www.efxkits.us/4-steps-arduino-music-player/

classroom.google.com/u/0/c/MTkxNDY3ODU3Nlpa

https://www.instructables.com/id/Multitouch-Music-Controller/step2/Schematic/

https://www.instructables.com/id/The-Arduino-OctoSynth/



##Homework2
### Proposal 
### Here is my musical instrument project proposal

The name of this project is Octatonic 

This is an fun and simple version of piano. Using objects as keyboard.

Each object produce a note and there are 8 notes.

##Homework3
###Prove of concept

when two conductive objects touch — in my case, the object itself and human skin — the capacitance between said objects changes. With the right sensor, I can detect when something is touching the object and convert that capacitance into sound.

####Sensor: 
Capacitance Sensor / capacitance touch shield for Arduino 

http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense

####Code Resources 
for making synths and implementing analog output from: http://playground.arduino.cc/Main/ArduinoSynth


Wavetable:

char sine256[256]  __attribute__ ((aligned(256))) = {
    0 , 3 , 6 , 9 , 12 , 15 , 18 , 21 , 24 , 27 , 30 , 33 , 36 , 39 , 42 , 45 , 
    48 , 51 , 54 , 57 , 59 , 62 , 65 , 67 , 70 , 73 , 75 , 78 , 80 , 82 , 85 , 87 , 
    89 , 91 , 94 , 96 , 98 , 100 , 102 , 103 , 105 , 107 , 108 , 110 , 112 , 113 , 114 , 116 , 
    117 , 118 , 119 , 120 , 121 , 122 , 123 , 123 , 124 , 125 , 125 , 126 , 126 , 126 , 126 , 126 , 
    127 , 126 , 126 , 126 , 126 , 126 , 125 , 125 , 124 , 123 , 123 , 122 , 121 , 120 , 119 , 118 , 
    117 , 116 , 114 , 113 , 112 , 110 , 108 , 107 , 105 , 103 , 102 , 100 , 98 , 96 , 94 , 91 , 
    89 , 87 , 85 , 82 , 80 , 78 , 75 , 73 , 70 , 67 , 65 , 62 , 59 , 57 , 54 , 51 , 
    48 , 45 , 42 , 39 , 36 , 33 , 30 , 27 , 24 , 21 , 18 , 15 , 12 , 9 , 6 , 3 , 
    0 , -3 , -6 , -9 , -12 , -15 , -18 , -21 , -24 , -27 , -30 , -33 , -36 , -39 , -42 , -45 , 
    -48 , -51 , -54 , -57 , -59 , -62 , -65 , -67 , -70 , -73 , -75 , -78 , -80 , -82 , -85 , -87 , 
    -89 , -91 , -94 , -96 , -98 , -100 , -102 , -103 , -105 , -107 , -108 , -110 , -112 , -113 , -114 , -116 , 
    -117 , -118 , -119 , -120 , -121 , -122 , -123 , -123 , -124 , -125 , -125 , -126 , -126 , -126 , -126 , -126 , 
    -127 , -126 , -126 , -126 , -126 , -126 , -125 , -125 , -124 , -123 , -123 , -122 , -121 , -120 , -119 , -118 , 
    -117 , -116 , -114 , -113 , -112 , -110 , -108 , -107 , -105 , -103 , -102 , -100 , -98 , -96 , -94 , -91 , 
    -89 , -87 , -85 , -82 , -80 , -78 , -75 , -73 , -70 , -67 , -65 , -62 , -59 , -57 , -54 , -51 , 
    -48 , -45 , -42 , -39 , -36 , -33 , -30 , -27 , -24 , -21 , -18 , -15 , -12 , -9 , -6 , -3 
    };

Timer Interrupts 

Timer Interrupts let you set some code to be run repeatedly, many times a second. You can set the speed at which the interrupt is called, and it will just get called at that speed forever. For example, in the code below, I set an interrupt so that my interrupt code (the interrupt routine) is run approximately 32000 times a second.

PWM

Pulse Width Modulation (PWM) essentially lets you generate square waves on a pin with a particular duty cycle. The frequency of these square waves can also be set, conveniently in the same units as we use for setting the speed of interrupts.


####direct digital synthesis

1.Set up PWM so that it is doing a very high frequency square wave.
2.Set an interrupt that alters the duty cycle of the square wave. If we run the interrupt function on the same timer that is driving the PWM, then cunningly, for every cycle of the square wave, the interrupt is fired to set a new value to the square wave duty cycle, and voila, we have our direct digital synthesis.

ISR(TIMER1_OVF_vect) 
    {
      // update sample position (ignore overflow, as 
      // we use the top byte to index into a 256 byte buffer
      // and the overflow means it loops through the buffer)

      //oscillator 0 update position 
      oscillators[0].phaseAccu+=oscillators[0].phaseStep;
      //oscillator 0 read wave value from the wavetable at that position
      int valOut0=curWave[oscillators[0].phaseAccu>>8]*oscillators[0].volume;

      // write oscillator value to PWM duty cycle for pin 9
      OCR1A=getByteLevel(valOut0);
    }




