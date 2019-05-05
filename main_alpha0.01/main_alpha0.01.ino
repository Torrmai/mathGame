/*mathGameV1
 * พยายามจะแบ่ง multitask ตัวสำคัญๆก่อน
 * เนื่องจาก lcd ยังอยู่กับอีกคนฉะนั้นจะใช้การเขียนเท่าที่จะทำได้ก่อนละกัน
 * ปล.คิดว่าน่าจะต้องเปลี่ยนอะไรไม่มากในส่วนการแสดงผลมั้ง
*/
#define SEC 1000 // millis second sometime is hard to read so let define it thousand millis sec =  1 sec to make life more easier 
#include <pt.h>
static struct pt pt_inp,pt_count_down;
bool time_out =  false,preesed = false;
int digit = 0;int tmp = 0;int rd_inp = 0;
int pw(int a,int b)
{
  int rtn = 1;
  for(int i=0;i<b;i++)
  {
    rtn *= a;
  }
  return rtn;
}
static int countDown(struct pt *pt)
{
  static unsigned long t = 0;
  PT_BEGIN(pt);
  while(1)
  {
    t = millis();
    PT_WAIT_UNTIL(pt,millis() - t > 1*SEC);
    tmp += 1;
    if(tmp == 10)//อยากให้TIMEOUTเป็นกี่วิก็เปลี่ยนตรงนี้นะฮะ
    {
      Serial.println("TIME OUT!!!!");
      tmp = 0;
      rd_inp =  0;
      digit = 0;
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
          tmp = 0;//reset time to 0 when answer
          rd_inp = 0;//ยังไม่ได้รวมกับตอน Random ตัวเกม
          digit = 0;//ยังไม่ได้รวมกับตอน Random ตัวเกม
        }
        else{
          Serial.print(tmp);
          Serial.print(" :t-> ");
          rd_inp += rd*pw(10,digit);
          Serial.println(rd_inp);
          digit++;
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
