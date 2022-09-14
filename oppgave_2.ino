const int sensorPin = A0;
const float baselineTemp = 21.0;
const int motorPin = 9;



void setup(){
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    pinMode(motorPin, OUTPUT);
    
  }
}
void loop(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("sensor value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", Degrees C: ");
  float temperature = (voltage - .5)*100;
  Serial.println(temperature);

  if(temperature < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(motorPin, LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if (temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(motorPin, HIGH);
  }
  delay(1);

  
  
}
