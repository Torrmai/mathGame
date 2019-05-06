#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int nCols = 16;
const int nRows = 2;
LiquidCrystal_I2C lcd(0x27, nCols, nRows);

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

int F, C, Time, Score, bonus, limit, lowest, highest, demo, x, y, ans, HOLD, digit, tmp, a, b, c, d;

int rd_inp[12];

int GameState, MenuState, LoadingState, PrepareState, OverState, ClearState;
unsigned long MenuTimeStamp, LoadingTimeStamp, AnswerTimeStamp, PrepareTimeStamp, OverTimeStamp, ClearTimeStamp;
unsigned long lastMillisDisplay, CountdownTimeStamp;

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
  lcd.begin();
  Serial.begin(9600);
  Score = 0;
  Time = 0;
  bonus = 5;
  limit = 0;
  demo = 0;
  F = 1;
  C = 4;
  ans = 0;
  digit = 0;
  tmp = 0;
  //Let the program random the first number before re-random again
  //Becuase the first number from random() always be a fixed number
  lowest = F;
  highest = F + C;
  x = random(lowest, highest);
  y = random(lowest, highest);
  MenuState = 0;
  lcd.print("   PLUS MANIA   ");
  MenuTimeStamp = millis();
  lastMillisDisplay = millis();
}

void reset()
{
  for (int i = 0; i < 5; i++)
  { rd_inp[i] = -1;
    Serial.print("reset->  ");
    Serial.println(rd_inp[i]);
  }
}

void Answer()
{
  int tmp = digit - 1;
  for (int i = 0; i < digit; i++)
  {
    int P = pow(10, tmp - i);
    if (P >= 99)
    {
      P++;
    }
    ans += rd_inp[i] * P;
    Serial.print("rd_inp[i] i->");
    Serial.print(i);
    Serial.print(" : value = ");
    Serial.print(rd_inp[i] * P);
    Serial.print(" : rd_inp[i] = ");
    Serial.print(rd_inp[i]);
    Serial.print(" : P = ");
    Serial.print(P);
    Serial.print(" : ans = ");
    Serial.println(ans);
  }
  reset();
}

void SevenSegmentDisplay(int port, int x)
{
  if (port == 1)
  {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  }
  else if (port == 2)
  {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  }
  else if (port == 3)
  {
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
  }
  else if (port == 4)
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

void loop()
{
  a = Time / 10;
  b = Time - (a * 10);
  c = Score / 10;
  d = Score - (c * 10);
  if ((millis() - lastMillisDisplay) % 4 == 0)
  {
    SevenSegmentDisplay(1, a);
    SevenSegmentDisplay(1, -1);
  }
  if ((millis() - lastMillisDisplay) % 4 == 1)
  {
    SevenSegmentDisplay(2, b);
    SevenSegmentDisplay(2, -1);
  }
  if ((millis() - lastMillisDisplay) % 4 == 2)
  {
    SevenSegmentDisplay(3, c);
    SevenSegmentDisplay(3, -1);
  }
  if ((millis() - lastMillisDisplay) % 4 == 3)
  {
    SevenSegmentDisplay(4, d);
    SevenSegmentDisplay(4, -1);
  }

  //Menu screen
  if (GameState == 0)
  {
    if (Serial.available() > 0)
    {
      HOLD = 1;
      GameState = 1;
      LoadingState = 0;
      Time = 10;
      lcd.clear();
      lcd.print("GET READY...");
      lcd.setCursor(0, 1);
      LoadingTimeStamp = millis();
    }
    else if (millis() - MenuTimeStamp >= 800)
    {
      MenuTimeStamp = millis();
      lcd.clear();
      if (MenuState == 0)
      {
        lcd.print("  +PLUS MANIA+  ");
        lcd.setCursor(0, 1);
        lcd.print("Press any button");
        MenuState = 1;
      }
      else if (MenuState == 1)
      {
        lcd.print(" ++PLUS MANIA++ ");
        MenuState = 2;
      }
      else if (MenuState == 2)
      {
        lcd.print("+++PLUS MANIA+++");
        lcd.setCursor(0, 1);
        lcd.print("Press any button");
        MenuState = 3;
      }
      else if (MenuState == 3)
      {
        lcd.print("   PLUS MANIA   ");
        MenuState = 0;
      }
    }
  }

  //Loading screen
  if (GameState == 1)
  {
    if ((millis() - LoadingTimeStamp) >= 1000)
    {
      LoadingTimeStamp = millis();
      if (LoadingState == 0)
      {
        LoadingState = 1;
        lcd.print("3");
      }
      else if (LoadingState == 1)
      {
        LoadingState = 2;
        lcd.print("  2");
      }
      else if (LoadingState == 2)
      {
        LoadingState = 3;
        lcd.print("  1");
      }
      else if (LoadingState == 3)
      {
        LoadingState = 4;
        lcd.print("  GO!!");
      }
      else if (LoadingState == 4)
      {
        GameState = 2;
        lcd.clear();
      }
    }
  }

  //Generate question
  if (GameState == 2)
  {
    lowest = F;
    highest = F + C;
    if (highest >= 9999)
    {
      highest = 9999;
      limit = 1;
    }
    x = random(lowest, highest);
    y = random(lowest, highest);
    lcd.print(x, DEC);
    lcd.print(" + ");
    lcd.print(y, DEC);
    lcd.setCursor(0, 1);
    lcd.print("= ");
    Serial.print(x);
    Serial.print(" + ");
    Serial.println(y);
    Serial.println("= ");
    GameState = 3;
    AnswerTimeStamp = millis();
    CountdownTimeStamp = millis();
    lastMillisDisplay = millis();
  }

  //Input anwser
  if (GameState == 3)
  {
    if(millis() - CountdownTimeStamp >= 1000)
    {
      CountdownTimeStamp = millis();
      Time--;
    }
    if(Time == 0)
    {
      lcd.clear();
      lcd.print("   TIME OUT!!");
      Serial.println("TIME OUT!!");
      OverTimeStamp = millis();
      OverState = 0;
      GameState = 6;
    }
    else if (Serial.available() > 0 && (millis() - AnswerTimeStamp) >= 100)
    {
      AnswerTimeStamp = millis();
      int rd;
      //แปลง ASCII เป็นตัวเลขปกติ
      rd = Serial.read() - 48;
      if (HOLD == 1)
      {
        rd = -1;
        HOLD = 0;
      }
      //บางทีมันมีค่าที่ stream มาต่ำกว่า 0
      if (rd  >= 0)
      {
        // rd == 'A'
        if (rd == 17 && digit > 0)
        {
          Answer();
          Serial.println(ans);
          digit = 0;//ยังไม่ได้รวมกับตอน Random ตัวเกม
          GameState = 4;
          lcd.clear();
        }
        else if (rd == 19)
        {
          lcd.clear();
          lcd.print(x, DEC);
          lcd.print(" + ");
          lcd.print(y, DEC);
          lcd.setCursor(0, 1);
          lcd.print("= ");
          reset();
          ans = 0;
          digit = 0;
        }
        else if ((rd != 12 && rd != 14 && rd != 17 && rd != 18 && rd != 20) && digit < 10)
        {
          lcd.print(rd);
          Serial.print(tmp);
          Serial.print(" :t-> ");
          Serial.println(rd);
          rd_inp[digit] = rd;
          digit++;
          Serial.println(digit);
        }
      }
    }
  }

  //Check the answer
  if (GameState == 4)
  {
    Serial.print(ans);
    Serial.print(" = ");
    Serial.print(x);
    Serial.print(" + ");
    Serial.println(y);
    if (ans == x + y)
    {
      Score++;
      Time += bonus;
      if(Time > 20)
      {
        Time = 20;
      }
      if (Score == 99)
      {
        lcd.print("  GAME CLEAR!!");
        Serial.println("GAME CLEAR!!");
        ClearTimeStamp = millis();
        ClearState = 0;
        GameState = 7;
      }
      else
      {
        lcd.print("   CORRECT!!");
        Serial.println("CORRECT!!");
        PrepareTimeStamp = millis();
        PrepareState = 0;
        GameState = 5;
      }
    }
    else
    {
      lcd.print("   WRONG!!");
      Serial.println("WRONG!!");
      OverTimeStamp = millis();
      OverState = 0;
      GameState = 6;
    }
    ans = 0;
    lastMillisDisplay = millis();
  }

  //Prepare for next question
  if (GameState == 5)
  {
    if (PrepareState == 0 && (millis() - PrepareTimeStamp) >= 2000)
    {
      if (limit == 0)
      {
        if (F < 10)
        {
          F++;
          lcd.clear();
          GameState = 2;
        }
        else if (F == 10)
        {
          F += 5;
          C += 10;
          bonus = 6;
          PrepareState = 1;
          PrepareTimeStamp = millis();
          lcd.setCursor(0, 1);
          lcd.print("Power up!!");
        }
        else if (F < 100)
        {
          F += 5;
          C += 5;
          lcd.clear();
          GameState = 2;
        }
        else if (F == 100)
        {
          F += 15;
          C += 100;
          bonus = 7;
          PrepareState = 1;
          PrepareTimeStamp = millis();
          lcd.setCursor(0, 1);
          lcd.print("Power up!!");
        }
        else if (F < 430)
        {
          F += 15;
          C += 30;
          lcd.clear();
          GameState = 2;
        }
        else if (F == 430)
        {
          F += 50;
          C += 500;
          lcd.clear();
          GameState = 2;
        }
        else if (F < 1030)
        {
          F += 50;
          C += 100;
          lcd.clear();
          GameState = 2;
        }
        else if (F == 1030)
        {
          F += 100;
          C += 1200;
          bonus = 8;
          PrepareState = 1;
          PrepareTimeStamp = millis();
          lcd.setCursor(0, 1);
          lcd.print("Power up!!");
        }
        else
        {
          F += 100;
          C += 200;
          lcd.clear();
          GameState = 2;
        }
      }
    }
    else if(PrepareState == 1 && (millis() - PrepareTimeStamp) >= 3000)
    {
      lcd.clear();
      GameState = 2;
    }
  }

  //Game over screen
  if (GameState == 6)
  {
    if (OverState == 0 && (millis() - OverTimeStamp) >= 3000)
    {
      OverTimeStamp = millis();
      lcd.clear();
      lcd.print("   GAME  OVER   ");
      lcd.setCursor(0, 1);
      OverState = 1;
    }
    if (OverState == 1  && (millis() - OverTimeStamp) >= 2000)
    {
      OverTimeStamp = millis();
      lcd.print("Total Score = ");
      lcd.print(Score);
      OverState = 2;
    }
    if (OverState == 2  && (millis() - OverTimeStamp) >= 5000)
    {
      lcd.clear();
      MenuState = 0;
      MenuTimeStamp = millis();
      lastMillisDisplay = millis();
      lcd.print("   PLUS MANIA   ");
      Time = 0;
      Score = 0;
      bonus = 5;
      GameState = 0;
    }
  }

  //Game clear screen
  if (GameState == 7)
  {
    if (ClearState == 0 && (millis() - ClearTimeStamp) >= 3000)
    {
      ClearTimeStamp = millis();
      lcd.clear();
      lcd.print("CONGRATULATIONS");
      lcd.setCursor(0, 1);
      ClearState = 1;
    }
    if (ClearState == 1 && (millis() - ClearTimeStamp) >= 2000)
    {
      ClearTimeStamp = millis();
      lcd.print("Total Score = ");
      lcd.print(Score);
      ClearState = 2;
    }
    if (ClearState == 2 && (millis() - ClearTimeStamp) >= 5000)
    {
      lcd.clear();
      MenuState = 0;
      MenuTimeStamp = millis();
      lastMillisDisplay = millis();
      lcd.print("   PLUS MANIA   ");
      Time = 0;
      Score = 0;
      bonus = 5;
      GameState = 0;
    }
  }
}
