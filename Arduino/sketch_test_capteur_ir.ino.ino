int sens1_old = 3;//perdu=0,droite=1,gauche=2,droit=3
int sens2_old = 3;


void setup(){
Serial.begin(9600);
}

void loop(){

int cap1A = color(A0);
int cap1B = color(A1);
int cap2A = color(A2);
int cap2B = color(A3);

Serial.println(cap1A);
Serial.println(cap1B);
Serial.println(cap2A);
Serial.println(cap2B);
Serial.println("________________");

int sens1,sens2;

if(cap1A == 0 && cap1B==0)sens1=3;//droit
else if(cap1A==1 && cap1B==0)sens1=1;//droite
else if(cap1A==0 && cap1B==1)sens1=2;//gauche
else sens1=0;//perdu

if(cap2A == 0 && cap2B==0)sens2=3;//droit
else if(cap2A==1 && cap2B==0)sens2=1;//droite
else if(cap2A==0 && cap2B==1)sens2=2;//gauche
else sens2=0;//perdu

if(sens1=!0)sens1_old=sens1;
if(sens2=!0)sens2_old=sens2;

if((sens1_old==3 && sens2_old==3) || (sens1_old==1 && sens2_old==2) || (sens1_old==2 && sens2_old==1))Serial.println("tout droit");
else if((sens1_old==1 && sens2_old==3) || (sens1_old==3 && sens2_old==1))Serial.println("little droite");
else if((sens1_old==2 && sens2_old==3) || (sens1_old==3 && sens2_old==2))Serial.println("little gauche");
else if(sens1_old==1 && sens2_old==1)Serial.println("full droite");
else if(sens1_old==2 && sens2_old==2)Serial.println("full gauche");

Serial.println("________________");

delay(1000);
}

int color(int pin)
{
  int cap = analogRead(pin);
  
  if(cap < 400)return 0;//white
  else if(cap > 600)return 1;//black
  else return 2;//IND
}
