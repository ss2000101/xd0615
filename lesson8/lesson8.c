// 定义一些不变量 
const int sensorPin = A0;    // 传感器连接的引脚 
const int ledPin = 9;        // led选择9号引脚 

int sensorValue = 0;         // 传感器的值 
int sensorMin = 1023;        // 最小传感器值 
int sensorMax = 0;           // 最大传感器值


void setup() {
  // 打开传感器 
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // 前5秒校准 
  while (millis() < 5000) {//判断临界条件 
    sensorValue = analogRead(sensorPin);

    // 记录传感器最大值 
    if (sensorValue > sensorMax) {//判断临界条件
      sensorMax = sensorValue;
    }

    // 记录传感器最小值 
    if (sensorValue < sensorMin) {//判断临界条件
      sensorMin = sensorValue;
    }
  }

  // 较准周期结束时发出信号 
  digitalWrite(13, LOW);//关闭传感器 
}

void loop() {
  // 读取传感器的值 
  sensorValue = analogRead(sensorPin);

  // 对传感器进行校准 
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 如果传感器的值超出了校准范围 
  sensorValue = constrain(sensorValue, 0, 255);

  // 用校准值对led褪色 
  analogWrite(ledPin, sensorValue);
}	
