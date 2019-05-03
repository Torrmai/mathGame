//test lcd whether it works or not
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//The maximum character of this lcd for used latter are below here
const int nCols = 16;
const int nRows = 2;
//Setting up the lcd 
LiquidCrystal_I2C lcd(0x27, nCols,nRows);


void setup()
{
// initialize the LCD
lcd.begin();
     
}
void loop()
{
  for(int i = 0;i<9;i++)
  {
    lcd.setCursor(i, 0);
    lcd.print(i+1);
    delay(1000);
    lcd.blink();
    delay(1000);
  }
  lcd.clear();
}
