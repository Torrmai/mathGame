/*
Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
Visit out my new site: kosworld.tk
 */

// Pin 2-8 is connected to the 7 segments of the display.

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;
int a,b,i,j;
int timer = 500;

// the setup routine runs once when you press reset:
void setup() 
{                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  

  for(i=20;i>=0;i--)
  {
    a = i / 10;
    b = i - (a * 10);
    for(j=0;j<500;j++)
    {
      digitalWrite(D1, HIGH);   
      digitalWrite(D2, LOW);   
      if(a == 0)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, HIGH);  
      }
      else if(a == 1)
      {
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);   
      }
      else if(a == 2)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, LOW);
      }
      delay(1);
      digitalWrite(D1, HIGH);   
      digitalWrite(D2, LOW);   
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);
      
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);
      if(b == 0)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, HIGH);  
      }
      else if(b == 1)
      {
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);   
      }
      else if(b == 2)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, LOW);
      }
      else if(b == 3)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, LOW);   
      }
      else if(b == 4)
      {
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, LOW);     
      }
      else if(b == 5)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, LOW);     
      }
      else if(b == 6)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, LOW);     
      }
      else if(b == 7)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);   
      }
      else if(b == 8)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, LOW);     
      }
      else if(b == 9)
      {
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, LOW);     
      }
      delay(1);
      digitalWrite(D1, LOW);   
      digitalWrite(D2, HIGH);   
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);
    }
  }
}

// the loop routine runs over and over again forever:
void loop() 
{
  digitalWrite(D1, HIGH);   
  digitalWrite(D2, HIGH);   
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
}
