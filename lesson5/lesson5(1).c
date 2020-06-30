#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S1 8
#define S2 9
#define S3 10
#define S4 11
#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(LT,OUTPUT);
  pinMode(BT,OUTPUT);
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  Serial.begin(9600);

}
byte input=0;
void loop()
{
   if(Serial.available()>0)
  {
  	input=Serial.read();
    input=input-'0';
    digitalWrite(S4,LOW);
    digitalWrite(2,input&0x1);
    digitalWrite(3,(input>>1)&0x1);
    digitalWrite(4,(input>>2)&0x1);
    digitalWrite(5,(input>>3)&0x1);
    digitalWrite(S4,HIGH);
  	delay(5);
  }
}
