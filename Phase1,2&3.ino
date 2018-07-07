
#include<Servo.h>
Servo SM;
#define r1 7
#define r2 6
#define l1 5
#define l2 4
#define ENA 13
#define ENB 2
#define L 10
#define C 9
#define R 8
#define trigpin 12
#define echo 3
int distance;
char BluetoothData;
int Lstate =0;
int Rstate =0;
int Cstate =0;
float revcm;
char revm;
float data2;
float data3;
float angle;
float datacorected=0;
const byte interruptPin = 21;
void Stop(void)
{
 digitalWrite(r1,LOW);
 digitalWrite(r2,LOW);
 digitalWrite(l1,LOW);
 digitalWrite(l2,LOW);
  
  }
    void forwoad(void)
{
 digitalWrite(r1,HIGH);
 digitalWrite(r2,LOW);
 digitalWrite(l1,HIGH);
 digitalWrite(l2,LOW);
  }

void rightwoad(void)
{ digitalWrite(r1,HIGH);
 digitalWrite(r2,LOW);
 digitalWrite(l2,HIGH);
 digitalWrite(l1,LOW); 
  }
void leftwoad(void) {
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
}

void backwoad(void) {
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
}

int findDistance() {
  int duration;
  int distance;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echo, HIGH); 
  distance = (duration/2) / 29; 
  Serial.print (distance);
  return distance;
  
  }

void avoid() {
 distance=findDistance();
  if(distance > 25) 
    forwoad();
  else{
    delay(60);
 distance=findDistance();
    if (distance > 25) 
      forwoad();
      else {
      Stop();
      SM.write(40);
      delay(500);
    distance=findDistance();
      if (distance>25){
        SM.write(90);
        delay(1000);
        rightwoad();
        delay(500);
        Stop();
       }
      else{
        SM.write(130);
        delay(1000);
       distance=findDistance();
        if (distance>25){
          SM.write(90);
          delay(1000);
          leftwoad();
          delay(500);
          Stop();
        }
        else{
          SM.write(90);
          delay(1000);
          Stop();
          
        }
      }
    }
  }
 }


void counter(void);








void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin),counter, RISING);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(L,INPUT);
  pinMode(C,INPUT);
  pinMode(R,INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  SM.attach(11);
  SM.write(90);
  delay(1000);
  Serial.begin(9600);  
}
void loop() {
  if (Serial.available())
  { 
 BluetoothData=Serial.read();
 
 if (BluetoothData=='W')
{  analogWrite(ENA, 250);
  analogWrite(ENB, 220);
 do{
 Lstate=digitalRead(L);
 Rstate=digitalRead(R);
 Cstate=digitalRead(C);
 if (Cstate==LOW)
 {
  forwoad();
 }
 else if (Rstate==LOW)
 {
  rightwoad();
 }
 else if (Lstate==LOW)
 {
  leftwoad(); 
 }
 }while (BluetoothData!='w');
 }
 
 else if(BluetoothData=='f')
    {
      analogWrite(ENA, 250);
      analogWrite(ENB, 220);
      forwoad();

    }
  else if(BluetoothData=='b')
   { 
   analogWrite(ENA, 250);
  analogWrite(ENB, 220);
   backwoad();
   }
  else if(BluetoothData=='l')
   { 
    analogWrite(ENA, 250);
    analogWrite(ENB, 220);
    leftwoad();
   }
  else if(BluetoothData=='r')
   { 
    analogWrite(ENA, 250);
    analogWrite(ENB, 220); 
    rightwoad();
   }
  else if(BluetoothData=='s')
    Stop();
  
  else if(BluetoothData=='c')
  {
  analogWrite(ENA,250);
  analogWrite(ENB,90);
  forwoad();
  delay_s(12); 
  Stop();
  forwoad();
  analogWrite(ENA,250);
  analogWrite(ENB,100);
   delay_s(2);
  analogWrite(ENA,80);
  analogWrite(ENB,250);
   delay_s(6);
  analogWrite(ENA,250);
  analogWrite(ENB,80);
   delay_s(4);
 analogWrite(ENA,250);
  analogWrite(ENB,225);
  forwoad();
  delay_s(1);              
  leftwoad();
  delay(400);         
  forwoad();
  delay_s(1);              
  leftwoad();
  delay(400);
  forwoad();
  delay_s(2);              
  leftwoad();
  delay(400);
  forwoad();
  delay_s(1);              
  leftwoad();
  delay(400);
  forwoad();
  delay_s(2);                
    }
  else if(BluetoothData=='d')
  {
    
      while(BluetoothData=='d')
    { 
      if(Serial.available())
       BluetoothData=Serial.read();     
      data2=BluetoothData;   
      
   }
    BluetoothData=BluetoothData-'0';
     
   while(data2==(BluetoothData+'0'))
   {
      if(Serial.available())
       data2=Serial.read();   
       data3=data2;
    }
     data2=data2-'0';       
  while(data3==(data2+'0'))
   {
    if(Serial.available())
       data3=Serial.read();   
 
    }
     
   data3=data3-'0';
    datacorected=.925*(BluetoothData+(data2/10)+(data3/100))-.03;
   revm=0;
   revcm=0;
   while(1)
   { Serial.print("aaaaa");
     Serial.print(datacorected);
     Serial.print("aaaa");
     Serial.print("   ");
     Serial.print(revm);
     Serial.print(revcm);
     Serial.print("   ");
if((revm+(revcm/100))>=datacorected)
{  Stop();
    break;
}

else
forwoad();
}
    
  
    }

 else if(BluetoothData=='a')
 {

  while(BluetoothData=='a')
    { 
      if(Serial.available())
       BluetoothData=Serial.read();     
      data2=BluetoothData;   
      
   }
    BluetoothData=BluetoothData-'0';
    
   while(data2==(BluetoothData+'0'))
   {
      if(Serial.available())
       data2=Serial.read();   
       data3=data2;
    }
     data2=data2-'0';       
  while(data3==(data2+'0'))
   {
    if(Serial.available())
       data3=Serial.read();   
 
    }
     
   data3=data3-'0';
angle=(((BluetoothData*100)+(data2*10)+(data3))*(.69/360));
  revm=0; 
  revcm=0;
  while(1)
  {Serial.print("aaaaaa");
     Serial.print(datacorected);
     Serial.print("aaaaaa");
     Serial.print("   ");
     Serial.print(revm);
     Serial.print(revcm);
     Serial.print("   ");
    if((revm+(revcm/100))>=angle)
{  Stop();
    break;
}
else
rightwoad();
     
    }
  }
  }
}


  
void counter()
{
  revcm++;
if(revcm==100)
{ revm++;
  revcm=0;
  }
  
}
void delay_s(char m)
{
  for(char i=0;i<=m;i++)
       delay(500);
  
}

