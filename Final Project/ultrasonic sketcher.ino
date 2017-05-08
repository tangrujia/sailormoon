int trig2 = 11; //Trig and echo pin setup for the Ultrasonic sensors
int echo2 = 10;

int trig1 = 13;
int echo1 = 12;

int trig3 = 7;
int echo3 = 6;

int trig4 = 4;
int echo4 = 3;

int button1 = 8;  //Button variable setup
int button2 = 9;
int button3 = 2;

int potpin = A2; //poteniometer
int potval;
int colorval=potval; //potval is from 0-1023

int x;       //x integer for the x coordinate
int y;       //y integer for the y coordinate
int px = x;  //sets previous x as x
int py = y;  // sets previous y as y
int inByte = 0;  //For arduino to processing serial com

void setup() {
  Serial.begin (9600);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(trig4, OUTPUT);
  pinMode(echo4, INPUT);

  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(potpin, INPUT);

  establishContact(); //establish contact with processing
}

void loop() {
  int button1val = digitalRead(button1);   //setting up buttons
  int button2val = digitalRead(button2);
  int button3val = digitalRead(button3);
  potval = analogRead(potpin); //read potentiometer value


  if (Serial.available() > 0)
  {
    inByte = Serial.read();
    long duration4, distance4; //duration and distance for the sensors
    long duration3, distance3;
    long duration2, distance2;
    long duration1, distance1;

    digitalWrite(trig2, LOW); //trigger the ultrasonic pins
    delayMicroseconds(2);
    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2, LOW);
    duration2 = pulseIn(echo2, HIGH); //record the time it takes for the sound to return
    distance2 = (duration2 / 2) / 29.1; //convert the time to distance

    digitalWrite(trig4, LOW);
    delayMicroseconds(2);
    digitalWrite(trig4, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig4, LOW);
    duration4 = pulseIn(echo4, HIGH);
    distance4 = (duration4 / 2) / 29.1;

    digitalWrite(trig3, LOW);
    delayMicroseconds(2);
    digitalWrite(trig3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig3, LOW);
    duration3 = pulseIn(echo3, HIGH);
    distance3 = (duration3 / 2) / 29.1;

    digitalWrite(trig1, LOW);
    delayMicroseconds(2);

    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig1, LOW);
    duration1 = pulseIn(echo1, HIGH);
    distance1 = (duration1 / 2) / 29.1;

//     Serial.println ("Distance1: ");
//     Serial.println (distance1);
//     Serial.print ("Distance2: ");
//     Serial.println(distance2);
//     Serial.print ("Distance3: ");
//     Serial.println(distance3);
//     Serial.print ("Distance4: ");
//     Serial.println(distance4);
//     Serial.print("Potval:");
//     Serial.println(potval); 
// print for debugging 


//divide the artboard into 7 subdivision on y axis
    if (distance1 < 30 && distance2 > 30 && distance3 > 30 && distance4 > 30) //If sensor detects in a certain area
    {
      x = distance1;   //set x to the recorded distances
      y = 4;   //set y to 4 
    }
    else if (distance1 < 30 && distance2 < 30 && distance3 > 30 && distance4 > 30)
    {
      x = ((distance1 + distance2) / 2);  //if both distance sensors are sensing value, it means the object is in the space between them. calculate the avg x value. 
      y = 6; //set y to 6
    }
    else if (distance1 > 30 && distance2 < 30 && distance3 > 30 && distance4 > 30)
    {
      x = distance2;
      y = 8;
    }
    else if (distance1 > 30 && distance2 < 30 && distance3 < 30 && distance4 > 30)
    {
      x = ((distance2 + distance3) / 2);
      y = 10;
    }
    else if (distance1 > 30 && distance2 > 30 && distance3 < 30 && distance4 > 30)
    {
      x = distance3;
      y = 12;
    }
    else if (distance1 > 30 && distance2 > 30 && distance3 < 30 && distance4 < 30)
    {
      x = ((distance3 + distance4) / 2);
      y = 14;
    }

    else if (distance1 > 30 && distance2 > 30 && distance3 > 30 && distance4 < 30)
    {
      x = distance4;
      y = 16;
    }


    //Serial.write will send a byte or a series of bytes. With an integer it only sends 1 byte.
    //Serial write everything (sends it to processing via serial)
    Serial.write(x);
    Serial.write(y);
    Serial.write(px);
    Serial.write(py);
    Serial.write(button1val);
    Serial.write(button2val);
    Serial.write(button3val);
    Serial.write(potval);
    px = x;  //Set px and py to x and y (used if lines are reimplemented)
    py = y;
    delay(50);
  }
}
void establishContact() {   //prints A until contact is established.
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}
