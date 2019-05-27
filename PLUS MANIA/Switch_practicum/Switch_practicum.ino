//define pin to make it easier to read
#define Col1 PIN_PC0
#define Col2 PIN_PC1
#define Col3 PIN_PC2
#define Col4 PIN_PC3
#define Row1 PIN_PC4
#define Row2 PIN_PC5
#define Row3 PIN_PB0
#define Row4 PIN_PB1
//make bouncing to remove some noise
const int p = 60;
int now = 0;
byte h=0,v=0;
const byte out[4] = {Col4,Col3,Col2,Col1};
const byte in[4] = {Row1,Row2,Row3,Row4};
void setup() {
  Serial.begin(9600);
  //setting up output pin
  for(byte i=0;i<4;i++)
  {
    pinMode(out[i],OUTPUT);
  }
  //setting up input pin
  for(byte i =0;i<4;i++)
  {
    pinMode(in[i],INPUT_PULLUP);
  }
}

void loop() {
  //bouncing the switch
  if(millis()-now>p)
    now = millis();
  //case for the button
switch (key())     //Switch to get which button is pressed. 
   {
        case 2:
          Serial.print(0);
          break;
        case 5:
          Serial.print(3);
          break;
        case 6:
          Serial.print(2);
          break;
        case 7:
          Serial.print(1);
          break;
        case 4:
          Serial.print("C");
          break;
        case 9:
          Serial.print(6);
          break;
        case 10:
          Serial.print(5);
          break;
        case 11:
          Serial.print(4);
          break;
        case 12:
          Serial.print("A");
          break;
        case 13:
          Serial.print(9);
          break;
        case 14:
          Serial.print(8);
          break;
        case 15:
          Serial.print(7);
          break;
        default:
          ;



   }
}
byte key()
{
 static bool no_press_flag=0;    
  for(byte x=0;x<4;x++)     
  {
     if (digitalRead(in[x])==HIGH);   
     else
     break;
     if(x==(4-1))        
     {
      no_press_flag=1;
      h=0;
      v=0;
     }
  }
  if(no_press_flag==1)  
  {
    for(byte r=0;r<4;r++)  
    digitalWrite(out[r],LOW);
    for(h=0;h<4;h++)  
    {
      if(digitalRead(in[h])==HIGH) 
      continue;
      else   
      {
          for (v=0;v<4;v++)    
          {
          digitalWrite(out[v],HIGH);   
          if(digitalRead(in[h])==HIGH)  
          {
            no_press_flag=0;               
            for(byte w=0;w<4;w++)  
            digitalWrite(out[w],LOW);
            return v*4+h;  
          }
          }
      }
    }
  }
 return 50;
}
