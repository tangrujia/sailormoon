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

I already bought it from Adafruit. Haven't arrived yet. Will need to sole the shield on the arduino. 

http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense

####Code Resources 
for making synths and implementing analog output from: http://playground.arduino.cc/Main/ArduinoSynth
These are the open source on OctoSynth I found online. I am still trying to understand it. 

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

## Final 
#include <Melody.h>

const uint8_t speaker_pin = 2;
const uint8_t note_button = A0;

Melody player(speaker_pin);

byte octav = 5;
uint8_t note = 0;
int prev_button_value = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(speaker_pin, OUTPUT);
  pinMode(note_button, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  int value = analogRead(note_button);
  
  if(value > 100)
  {
    if(value > 1000)
    {
      note = 0;
    }
    else if(value > 950)
    {
      note = 2;
    }
    else if(value > 920)
    {
      note = 4;
    }
    else if(value > 880)
    {
      note = 5;
    }
    else if(value > 850)
    {
      note = 7;
    }
    else if(value > 810)
    {
      note = 9;
    }
    else if(value > 780)
    {
      note = 11;
    }
    else if(value > 750)
    {
      if(note != 20)
      {
        octav -= 1;
        note = 20;
      }
      
      return;
    }
    else if(value > 730)
    {
      if(note != 21)
      {
        octav += 1;
        note = 21;
      }
      
      return;
    }
    else
    {
      return;
    }
    
    byte note_byte = (octav * 16) + note;
    
    Serial.print("{0x");
    Serial.print(note_byte, HEX);
    Serial.print(", 0x04},");
    Serial.println("");
    Serial.print("{0xFF, 0x64},");
    
    tone(speaker_pin, player.getNoteFrequency(note_byte));
    
    prev_button_value = value;
    
    while(value > 100)
    {
      delay(100);
      value = analogRead(note_button);
      
      if(abs(value - prev_button_value) > 20) break; // change note
    }
    
    
    noTone(speaker_pin);
    
    Serial.println("");
  }
  
  delay(100);
}

