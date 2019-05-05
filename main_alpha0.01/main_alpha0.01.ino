/*mathGameV1
 * พยายามจะแบ่ง multitask ตัวสำคัญๆก่อน
 * เนื่องจาก lcd ยังอยู่กับอีกคนฉะนั้นจะใช้การเขียนเท่าที่จะทำได้ก่อนละกัน
 * ปล.คิดว่าน่าจะต้องเปลี่ยนอะไรไม่มากในส่วนการแสดงผลมั้ง
*/
#define SEC 1000
#include <pt.h>
static struct pt pt_inp,pt_count_down;
bool time_out =  false,preesed = false;
int digit = 0;int tmp = 0;
static int countDown(struct pt *pt)
{
  static unsigned long t = 0;
  PT_BEGIN(pt);
  while(1)
  {
    t = millis();
    PT_WAIT_UNTIL(pt,millis() - t > 1*SEC);
    tmp += 1;
    if(tmp == 10)
    {
      tmp = 0;
      time_out = true;     
    }
    else time_out = false;
  }
  PT_END(pt);
}
static int inp(struct pt *pt)
{
  //อ่านค่าที่กด switch จาก practicum board
  static unsigned long t = 0;
  PT_BEGIN(pt);
  while(1)
  {
    t = millis();
    PT_WAIT_UNTIL(pt,millis() - t > 50);
    int rd;
    if(Serial.available() > 0)
    {
      //แปลง ASCII เป็นตัวเลขปกติ
      rd = Serial.read() - 48;
      //บางทีมันมีค่าที่ stream มาต่ำกว่า 0
      if(rd  >= 0){
        // rd == 'A'
        if(rd == 17)
        {
          tmp = 0;
        }
        else{
          Serial.print(tmp);
          Serial.print(" :t-> ");
          Serial.println(rd);
        }
      }
    }
  }
  PT_END(pt);
}
void setup() {
  Serial.begin(9600);
  PT_INIT(&pt_count_down);
  PT_INIT(&pt_inp);

}
void loop() {
  countDown(&pt_count_down);
  inp(&pt_inp);
}
