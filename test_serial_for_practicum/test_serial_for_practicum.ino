//test counting number
void setup() {
  Serial.begin(9600);
}
int i = 0;
void loop() {
  Serial.print(i%10);
  delay(2000);
  i++;
} 
