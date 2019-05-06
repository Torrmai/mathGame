#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int nCols = 16;
const int nRows = 2;
int F, C, combo, score, limit, lowest, highest, range, demo, a, b, ans, GameState, IsCorrect;
int digit = 0;
int tmp = 0;
int rd_inp[14];

unsigned long lastMillis1,lastMillis2;

LiquidCrystal_I2C lcd(0x27, nCols,nRows);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Serial.begin(9600);
  score = 0;
  combo = 0;
  limit = 0;
  demo = 0;
  F = 1;
  C = 4;
  ans = 0;
}

void reset()
{
  for(int i = 0;i<5;i++)
    {rd_inp[i] = -1;
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
    if(P >= 99)
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

void loop() 
{
  if (GameState == 0)
  {
    lowest = F;
    highest = F + C;
    if (highest >= 9999)
    {
      highest = 9999;
      limit = 1;
    }
    range = (highest - lowest) + 1;
    a = random(lowest, highest);
    b = random(lowest, highest);
    lcd.print(a, DEC);
    lcd.print(" + ");
    lcd.print(b, DEC);
    lcd.setCursor(0, 1);
    lcd.print("= ");
    Serial.print(a);
    Serial.print(" + ");
    Serial.println(b);
    Serial.println("= ");
    GameState = 1;
    lastMillis1 = millis();
  }
  
  if (GameState == 1)
  {
    if (Serial.available() > 0 && ( millis() - lastMillis1 ) >= 50 && digit < 14)
    {
      lastMillis1 = millis();
      int rd;
      //แปลง ASCII เป็นตัวเลขปกติ
      rd = Serial.read() - 48;
      //บางทีมันมีค่าที่ stream มาต่ำกว่า 0
      if (rd  >= 0) 
      {
        // rd == 'A'
        if (rd == 17)
        {
          Answer();
          Serial.println(ans);
          digit = 0;//ยังไม่ได้รวมกับตอน Random ตัวเกม
          GameState = 2;
          lcd.clear();
        }
        else if(rd == 19)
        {
          lcd.clear();
          lcd.print(a, DEC);
          lcd.print(" + ");
          lcd.print(b, DEC);
          lcd.setCursor(0, 1);
          lcd.print("= ");
          reset();
          ans = 0;
          digit = 0;
        }
        else 
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
  
  if (GameState == 2)
  {
    Serial.print(ans);
    Serial.print(" = ");
    Serial.print(a);
    Serial.print(" + ");
    Serial.println(b);
    if (ans == a + b)
    {
      lcd.print("CORRECT!!");
      Serial.println("CORRECT!!");
      IsCorrect = 1;
    }
    else
    {
      lcd.print("GAME OVER");
      Serial.println("GAME OVER");
      IsCorrect = 0;
    }
    ans = 0;
    lastMillis2 = millis();
    GameState = 3;
  }
  if (GameState == 3)
  { 
    if ( (millis() - lastMillis2) >= 3000)
    {
      if (IsCorrect)
      {
        if (limit == 0)
        {
          if (F < 10)
          {
            F++;
          }
          else if (F == 10)
          {
            F += 5;
            C += 10;
          }
          else if (F < 100)
          {
            F += 5;
            C += 5;
          }
          else if (F == 100)
          {
            F += 15;
            C += 100;
          }
          else if (F < 430)
          {
            F += 15;
            C += 30;
          }
          else if (F == 430)
          {
            F += 50;
            C += 500;
          }
          else if (F < 1030)
          {
            F += 50;
            C += 100;
          }
          else if (F == 1030)
          {
            F += 100;
            C += 1200;
          }
          else
          {
            F += 100;
            C += 200;
          }
        }
      }
      else
      {
        F = 1;
        C = 4;
      }
      lcd.clear();
      GameState = 0;
    }
  }
}
