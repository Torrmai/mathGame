/*ทดสอบการเขียน โปรโตเทรด บน arduino ide
 * ปล.1 คิดว่าอย่างน้อบคงมีตัวอย่างเผื่อไปโมในอนาคต
 * ปล.2 จะพยายามคอมเม้นต์มากที่สุดเท่าที่จะเป็นไปได้
 * ปล.3 PT_WAIT_UNTIL ต้องใส่นะบอกว่า timestamp อยู่ตรงไหนบ้างมิฉะนั้นมันจะไม่ออกจาก loop เลย
 */
#include <pt.h>
//declare the task that programe have
static struct pt pt1,pt2;
static int blinky(struct pt *pt)
{
  static unsigned long t = 0;
  //เริ่มต้นงาน
  PT_BEGIN(pt);
  while(1){
    t = millis();//รับเวลามาว่าเวลาเริ่มต้นคือเท่าไหร่
    PT_WAIT_UNTIL(pt,millis() -t > 500);//=delay(500);
    digitalWrite(PIN_PC0,HIGH);
    t = millis();//เวลาหลังเปิดไฟ
    PT_WAIT_UNTIL(pt,millis() -t > 500);
    digitalWrite(PIN_PC0,LOW);
  }
  PT_END(pt);
}
static int pressedToLight(struct pt *pt)
{
  static unsigned long t = 0;
  PT_BEGIN(pt);
  while(1){
    t = millis();
    PT_WAIT_UNTIL(pt,millis() - t > 20);//Debounce switch ละกเก็บ timestamp ไปเลยจะได้ออกจาก loop ได้
    int r = digitalRead(PIN_PC2);
    Serial.println(r);
    if(r == 0) digitalWrite(PIN_PC1,HIGH);
    else digitalWrite(PIN_PC1,LOW);
  }
  PT_END(pt);
}
void setup() {
  Serial.begin(9600);
  pinMode(PIN_PC0,OUTPUT);
  pinMode(PIN_PC1,OUTPUT);
  pinMode(PIN_PC2,INPUT);
  /////////////////////////////
  //บอกให้ตัวงานของเราทั้งหมดเริ่มทำงาน
  PT_INIT(&pt1);
  PT_INIT(&pt2);

}

void loop() {
  // put your main code here, to run repeatedly:
  blinky(&pt1);
  pressedToLight(&pt2);
}
