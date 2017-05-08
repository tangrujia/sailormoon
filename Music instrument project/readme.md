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
int pingPin = 11;
long duration;
long distance;
int buttomstatus=0;
int buttom=6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttom,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(pingPin, OUTPUT); 
  digitalWrite(pingPin, LOW);        // Ensure pin is low
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);       // Start ranging
  delayMicroseconds(5);              //   with 5 microsecond burst
  digitalWrite(pingPin, LOW);        // End ranging
  pinMode(pingPin, INPUT);           // Set pin to INPUT
  duration = pulseIn(pingPin, HIGH); // Read echo pulse
  distance = duration / 74 / 2;        // Convert to inches

int notes[7] = {261, 294, 329, 349, 392, 440, 494}; //Putting several notes in an array
  //          mid C  D   E   F   G   A   B

  buttomstatus = digitalRead(buttom); //defining force as FSR data

Serial.println(buttomstatus);

  if (distance < 0 || distance > 50||buttomstatus==LOW) { //if not presed and not in front

    noTone(12); //dont play music

  }

  else if (buttomstatus==HIGH) {  //if pressed

    int sound = map(distance, 0, 20, 0, 6);  //map distance to the array of notes
    tone(12, notes[sound]);  //call a certain note depending on distanc
  }

}
