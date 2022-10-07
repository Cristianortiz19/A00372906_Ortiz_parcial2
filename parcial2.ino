int pins[7] = {4,5,6,7,8,2,3};
const int sensorPin= A0;
int btnState;
bool cooldown = true;
int sensorValue;


void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 7; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  btnState = digitalRead(pins[5]);
  Serial.println(btnState);
  
  Serial.println(sensorValue);
  if(sensorValue < 170){
    digitalWrite(pins[0], LOW);
    digitalWrite(pins[1], LOW);
    digitalWrite(pins[2], LOW);
    digitalWrite(pins[3], LOW);
    digitalWrite(pins[4], LOW);
  }
  if(sensorValue > 170 & sensorValue < 340){
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], LOW);
    digitalWrite(pins[2], LOW);
    digitalWrite(pins[3], LOW);
    digitalWrite(pins[4], LOW);
  }
  if(sensorValue > 340 & sensorValue < 510){
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], HIGH);
    digitalWrite(pins[2], LOW);
    digitalWrite(pins[3], LOW);
    digitalWrite(pins[4], LOW);
  }
  if(sensorValue > 510 & sensorValue < 680){
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], HIGH);
    digitalWrite(pins[2], HIGH);
    digitalWrite(pins[3], LOW);
    digitalWrite(pins[4], LOW);
  }
  if(sensorValue > 680){
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], HIGH);
    digitalWrite(pins[2], HIGH);
    digitalWrite(pins[3], HIGH);
    digitalWrite(pins[4], HIGH);
  }
  
  if(btnState != 0){
    cooldown = false;
    delay(5000);
    cooldown = true;
  }
  
  
  if(sensorValue < 170 && cooldown == true){
    tone(pins[6], 1500, 400);
    delay(600);
    noTone(pins[6]);
   }
  if(sensorValue > 700 && cooldown == true){
    tone(pins[6], 1000, 3000);
    delay(4000);
    noTone(pins[6]);
   }
}
