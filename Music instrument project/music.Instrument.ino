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
