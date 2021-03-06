//testing generate problem
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int nCols = 16;
const int nRows = 2;
int F,C,combo,score,limit,lowest,highest,range,demo,a,b,c;

//Setting up the lcd 
int tmp;
LiquidCrystal_I2C lcd(0x27, nCols,nRows);
void setup() 
{
  lcd.begin();
  Serial.begin(9600);
  score = 0;
  combo = 0;
  limit = 0;
  demo = 0;
  F = 1;
  C = 4;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  lowest = F;
  highest = F + C;
  if(highest >= 9999)
  {
    highest = 9999;
    limit = 1;
  }
  range = (highest - lowest) + 1;
  a = random(lowest,highest);
  b = random(lowest,highest);
  lcd.print(a,DEC);
  lcd.print(" + ");
  lcd.print(b,DEC);
  lcd.setCursor(0, 1);
  lcd.print("= ");
  Serial.print(a);
  Serial.print(" + ");
  Serial.println(b);
  Serial.println("= ");
  if(true)
  {
    if(limit == 0)
    {
      if(combo == 0)
      {/*
        combo = 1;
      }
      else
      {*/
        combo = 0;
        if(F < 10)
        {
          F++;
        }
        else if(F == 10)
        {
          F+=5;
          C+=10;
        }
        else if(F < 100)
        {
          F+=5;
          C+=5;
        }
        else if(F == 100)
        {
          F+=15;
          C+=100;
        }
        else if(F < 430)
        {
          F+=15;
          C+=30;
        }
        else if(F == 430)
        {
          F+=50;
          C+=500;
        }
        else if(F < 1030)
        {
          F+=50;
          C+=100;
        }
        else if(F == 1030)
        {
          F+=100;
          C+=1200;
        }
        else
        {
          F+=100;
          C+=200;
        }
      }
    }
  }
  delay(1000);
  lcd.clear();
}


//09 02 07  10 11 03
//06 05 --  04 08 12 

//03 11 10 07 02 09
//12 08 04 -- 05 06
