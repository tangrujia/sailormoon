import processing.serial.*;       //processing serial library

Serial myPort;                       // The serial port
int[] serialInArray = new int[8]; // Where we'll put what we receive
int serialCount = 0;                 // A count of how many bytes we receive
int x;                               //the x coordinate
int y;                               //the y coordinate
int px = x;                          //px and py equal to x and y
int py = y;
int prx;                              //previous x/y for other loops
int pry;

int lx;                               //more x/y alternates
int ly;
int lpx;                              //more px/py alternates
int lpy;  

int button1val;                       //button values
int button2val;
int button3val;

int r1 = 0;                        //radius values
int r2 = 0;

int counter = 0;                   //counters in loops

int potval;  //I printed potval in processing first. it automatically become 0-255. I don't know why thou. but i can work with it. 
int Red; 
int Green;
int Blue;
float colorval; 

boolean firstContact = false;        // Whether we've heard from the microcontroller

void setup() {
  size(600, 400);  // Stage size
  //println(Serial.list()[1]);
  //String portName = Serial.list()[1];
  myPort = new Serial(this, "/dev/cu.usbmodem1411", 9600); //setting up communication
  x=300;
  y=300;
  background(0, 0, 0);
}

void draw() {
  
  colorval=map(potval,0,255,0,1024); //map color value from 0-255 to 0-1024
  
   if(colorval >0 && colorval<171) //WHITE 1023/6=170.5 there will be six color options
  {
    Red = 255;
    Green = 255;
    Blue = 255;
  }
  else if(colorval >171 && colorval < 342) //GREY 
  {
   Red = 96;
   Green = 96;
   Blue = 96;
  }
   else if(colorval >342 && colorval <513) //BLUE
  {
   Red = 0;
   Green = 0;
   Blue = 255;
  }
  
    else if(colorval >513 && colorval < 684) //green
  {
   Red= 0;
   Green = 255;
   Blue = 0;
  }
    else if(colorval >684 && colorval <=855) //yellow
  {
   Red = 255;
   Green = 255;
   Blue = 0;
  }
    else if(colorval >855 && colorval < 1024) //red
  {
   Red = 255;
   Green = 0;
   Blue = 0;
  }
  
  // //for testing: 
  //fill(Red,Green,Blue);
  //ellipse(575,375,15,15);
  //println(colorval); 
  
   
  if (x >= 2 && x <= 30 && y >= 2 && y <= 30) //if the object is within the area
  {
    lx=x;
    ly=y;
    lpx=px;
    lpy=py;

    if (button2val==0)  //if button 2 is pressed
    {
      
      if (counter <1)  //how may times has it been in the loop? if it is <1, increase counter untill it is >=1
      {
        prx = x;
        pry = y;  //the other previous x/y equal to x/y 
        println(counter);
        counter = counter + 1;
      }
      if (counter>=1)  //lock the circle int the position and make the size of it growing
      {
        println(counter);
        noStroke(); 
        fill(Red,Green,Blue,10);  // a circle with transparency 
        ellipse(prx*20, pry*20, r1, r2);  //the cricle grow as coutner ++
        r1=r1+5;
        r2=r2+5;
      }
    } 
    else
    {     
      r1=0;   //if the object is out if the area, do nothing 
      r2=0;
     counter=0;        
    }

    if (button1val == 0) //if the buttom1 is pressed
    {
      noStroke(); 
      fill(Red,Green,Blue); 
      ellipse(((lx+lpx)/2)*20, ((ly+lpy)/2)*20, 10, 10); //turn the x and y into variables with that formula.
      
      print(lx); //printing for bug checking
      print(" ");
      print(ly);
      print(" ");
      print(lpx);
      print(" ");
      println(lpy);
    }

    if (button3val == 0) { //if button3 is pressed 
      background(0);  //reset the background. This covers everthing up
    }
  }
}


void serialEvent(Serial myPort) { //communication setup from arduino
  // read a byte from the serial port:
  int inByte = myPort.read();
  // if this is the first byte received, and it's an A,
  // clear the serial buffer and note that you've
  // had first contact from the microcontroller.
  // Otherwise, add the incoming byte to the array:
  if (firstContact == false) {
    if (inByte == 'A') {
      myPort.clear();          // clear the serial port buffer
      firstContact = true;     // you've had first contact from the microcontroller
      myPort.write('A');       // ask for more
    }
  } else {
    // Add the latest byte from the serial port to array:
    serialInArray[serialCount] = inByte;
    serialCount++;

    // If we have 7 bytes:
    if (serialCount > 7) {   
      x = serialInArray[0];
      y = serialInArray[1];
      px = serialInArray[2];
      py = serialInArray[3];
      button1val = serialInArray[4];
      button2val = serialInArray[5];
      button3val = serialInArray[6];
      potval=serialInArray[7];
      // Send a capital A to request new sensor readings:
      myPort.write('A');
      // Reset serialCount:
      serialCount = 0;
    }
  }
}