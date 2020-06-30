char ch=' ';
void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.println("I'm fine.'");
}

/*
预定
'f':表示前进，两灯全亮
'b':表示后退，两灯全灭
'r':表示右转，绿灯亮
'l':表示左转，红灯亮
's':表示停止，两灯全灭
*/
void loop()
{
  if(Serial.available()>0)
  {
  	ch=Serial.read();
    switch(ch)
    {
    case 'f':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      Serial.println("f");
      break;
    case 'b':
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      Serial.println("b");
      break;
    case 'r':
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      Serial.println("r");
      break;
    case 'l':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      Serial.println("l");
      break;
    case 's':
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      Serial.println("s");
      break;
    default:
      break;
    }
  }
}
