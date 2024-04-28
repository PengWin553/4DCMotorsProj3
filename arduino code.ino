int btn1 = 13;
int btn2 = 8;
int btn3 = 7;
int btn4 = 6;
int btn5 = 5;
int btn6 = 4;
int nMotor1 = 12;
int pMotor1 = 11;
int nMotor2 = 10;
int pMotor2 = 9;
int btn1State;
int btn2State;
int btn3State;
int btn4State;
int btn5State;
int btn6State;
int crct1State;
int crct2State;
int crct3State;
int crct4State;
int crct5State;
int crct6State;
int onOffLED = 3;
int redLED = 2;
int blueLED = A5;
void setup(){
  pinMode(btn1,INPUT); //turns the car on / off
  pinMode(btn2,INPUT); //forward
  pinMode(btn3,INPUT); //backward
  pinMode(btn4,INPUT); //break
  pinMode(btn5,INPUT); //left
  pinMode(btn6,INPUT); //right
  Serial.begin(9600);
}
void loop(){
  btn1State = digitalRead(btn1);
  btn2State = digitalRead(btn2);
  btn3State = digitalRead(btn3);
  btn4State = digitalRead(btn4);
  btn5State = digitalRead(btn5);
  btn6State = digitalRead(btn6);
  //Tells if the car is on or off
  if(btn1State == LOW){
    if(crct1State == LOW){
      crct1State = HIGH;
      Serial.println("The car is on.");
      digitalWrite(onOffLED,HIGH); 
    }else{
      crct1State = LOW;
      Serial.println("The car is off.");
      digitalWrite(onOffLED,LOW);
      digitalWrite(nMotor1,LOW);
      digitalWrite(nMotor2,LOW);
      digitalWrite(pMotor1,LOW);
      digitalWrite(pMotor2,LOW);
      digitalWrite(redLED,0);
      digitalWrite(blueLED,0);
    }
  }
  //If the car is on, you may perform the following:
      if(crct1State == HIGH){
        //forward
        if(btn2State == LOW){
            if(crct2State == LOW){
              crct2State = HIGH;
              Serial.println("The car moves forward.");
              digitalWrite(nMotor1,LOW);
              digitalWrite(nMotor2,LOW);
              digitalWrite(pMotor1,HIGH);
              digitalWrite(pMotor2,HIGH);
              digitalWrite(redLED,0);
        digitalWrite(blueLED,0);
          }else{
            crct2State = LOW;
          }
        }
        //backward
        if(btn3State == LOW){
            if(crct3State == LOW){
              crct3State = HIGH;
              Serial.println("The car moves backward.");
              digitalWrite(nMotor1,HIGH);
              digitalWrite(nMotor2,HIGH);
              digitalWrite(pMotor1,LOW);
              digitalWrite(pMotor2,LOW);
              digitalWrite(redLED,0);
         digitalWrite(blueLED,0);
          }else{
            crct3State = LOW;
          }
        }
        //break
        if(btn4State == LOW){
          if(crct4State == LOW){
            crct4State = HIGH;
            Serial.println("The car breaks.");
            digitalWrite(nMotor1,LOW);
            digitalWrite(nMotor2,LOW);
            digitalWrite(pMotor1,LOW);
            digitalWrite(pMotor2,LOW);
            digitalWrite(redLED,0);
          digitalWrite(blueLED,0);
          }else{
            crct4State = LOW;
          }
        }
        //left
        if(btn5State == LOW){
          if(crct5State == LOW){
            crct5State = HIGH;
            Serial.println("The car turns left.");
            digitalWrite(nMotor1,LOW);
            digitalWrite(pMotor1,LOW);
            digitalWrite(nMotor2,LOW);
            digitalWrite(pMotor2,HIGH);
            digitalWrite(redLED,HIGH);
            digitalWrite(blueLED,LOW);
          }else{
            crct5State = LOW;
          }
        }
        //right
        if(btn6State == LOW){
          if(crct6State == LOW){
            crct6State = HIGH;
            Serial.println("The car turns right.");
            digitalWrite(nMotor1,LOW);
            digitalWrite(pMotor1,HIGH);
            digitalWrite(nMotor2,LOW);
            digitalWrite(pMotor2,LOW);
            digitalWrite(redLED,LOW);
            digitalWrite(blueLED,HIGH);
          }else{
            crct6State = LOW;
          }
        }
      }
    delay(100);
}