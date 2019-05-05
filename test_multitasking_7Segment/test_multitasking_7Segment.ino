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

int a,b,c,d,Time,Score,IsCorrect;
unsigned long lastMillisTime,lastMillisScore,lastMillisDisplay;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  Time = 20;
  Score = 0;
  IsCorrect = 0;
  lastMillisTime = millis();
  lastMillisScore = millis();
  lastMillisDisplay = millis();
}

void SevenSegmentDisplay(int port,int x)
{
  if(port == 1)
  {
    digitalWrite(D1, HIGH);   
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  }
  else if(port == 2)
  {
    digitalWrite(D1, LOW);   
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  }
  else if(port == 3)
  {
    digitalWrite(D1, LOW);   
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
  }
  else if(port == 4)
  {
    digitalWrite(D1, LOW);   
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
  }
  if (x == 0)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
  }
  else if (x == 1)
  {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (x == 2)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
  }
  else if (x == 3)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
  }
  else if (x == 4)
  {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if (x == 5)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if (x == 6)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if (x == 7)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (x == 8)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if (x == 9)
  {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if (x == -1)
  {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IsCorrect == 1)
  {
    Time += 5;
    lastMillisDisplay = millis();
    lastMillisTime = millis();
  }
  IsCorrect = 0;
  a = Time / 10;
  b = Time - (a * 10);
  c = Score / 10;
  d = Score - (c * 10);
  if((millis() - lastMillisDisplay) % 4 == 0)
  {
    SevenSegmentDisplay(1,a);
    SevenSegmentDisplay(1,-1);
  }
  if((millis() - lastMillisDisplay) % 4 == 1)
  {
    SevenSegmentDisplay(2,b);
    SevenSegmentDisplay(2,-1);
  }
  if((millis() - lastMillisDisplay) % 4 == 2)
  {
    SevenSegmentDisplay(3,c);
    SevenSegmentDisplay(3,-1);
  }
  if((millis() - lastMillisDisplay) % 4 == 3)
  {
    SevenSegmentDisplay(4,d);
    SevenSegmentDisplay(4,-1);
  }
  if((millis() - lastMillisScore) >= 6500)
  {
    if(Score < 99)
    {
      Score++;
    }
    IsCorrect = 1;
    lastMillisScore = millis();
  }
  if((millis() - lastMillisTime) >= 1000 && IsCorrect == 0)
  {
    if(Time > 0)
    {
      Time--;
    }
    lastMillisTime = millis();
  }
}
