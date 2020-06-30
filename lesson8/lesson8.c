// ����һЩ������ 
const int sensorPin = A0;    // ���������ӵ����� 
const int ledPin = 9;        // ledѡ��9������ 

int sensorValue = 0;         // ��������ֵ 
int sensorMin = 1023;        // ��С������ֵ 
int sensorMax = 0;           // ��󴫸���ֵ


void setup() {
  // �򿪴����� 
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // ǰ5��У׼ 
  while (millis() < 5000) {//�ж��ٽ����� 
    sensorValue = analogRead(sensorPin);

    // ��¼���������ֵ 
    if (sensorValue > sensorMax) {//�ж��ٽ�����
      sensorMax = sensorValue;
    }

    // ��¼��������Сֵ 
    if (sensorValue < sensorMin) {//�ж��ٽ�����
      sensorMin = sensorValue;
    }
  }

  // ��׼���ڽ���ʱ�����ź� 
  digitalWrite(13, LOW);//�رմ����� 
}

void loop() {
  // ��ȡ��������ֵ 
  sensorValue = analogRead(sensorPin);

  // �Դ���������У׼ 
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // �����������ֵ������У׼��Χ 
  sensorValue = constrain(sensorValue, 0, 255);

  // ��У׼ֵ��led��ɫ 
  analogWrite(ledPin, sensorValue);
}	
