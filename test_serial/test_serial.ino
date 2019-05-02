//for Arduino UNO board(display unit)
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int nCols = 16;
const int nRows = 2;
//Setting up the lcd 
int tmp;
LiquidCrystal_I2C lcd(0x27, nCols,nRows);
void setup() {
  lcd.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    lcd.clear(); //clear error when don't connect properly
    tmp = Serial.read();
    lcd.write(tmp);
    delay(2000);//have to delay == Practicum
    lcd.clear();
  }
  else{
    lcd.print("Connetion!!");//for error exception in lcd
    while(Serial.available() == 0)
    {}
  }
}
