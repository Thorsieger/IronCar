#include <Servo.h>

Servo traction;
Servo direct;

//init traction
const long interval = 1000;
unsigned long previousMillis = 0;

//Données
boolean messageRecu = false;
String inputString = "";

void setup(){
  Serial.begin(9600);
  
  traction.attach(11);
  direct.attach(9);

  init_traction();
}
  
void loop()
{
  if(messageRecu == true)
  {
    
    int val = inputString.toInt();

    if(val/1000==1)//Tourner
    {
      direct.write(val%1000);
    }
    else if(val/1000==2)//avancer
    {
      traction.write(val%1000);
    }
    else if(val/1000==3)//reculer
    {
      traction.write(8);
      delay(200);
      traction.write(90);
      delay(200);
      traction.write(val%3000);
    }
    
    messageRecu = false;
    inputString = "";
  }
}

void init_traction()
{
  for(int i=0;i<3;)
  {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if(i==0)      traction.write(90);
      else if(i==1) traction.write(180);
      else if(i==2) traction.write(0);
      i++;
    }
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inChar == '\n') {
      messageRecu = true;
    }
  }
}
