
int pin6=6;
int pin7=7;
int pin5=5;
int pin4=4;
int led=13;
const int trigPin = 9;
const int echoPin = 10;
char BluetoothData;
long duration;
int distance;

void forward()
{  
 digitalWrite(led,HIGH);
 digitalWrite(pin7,HIGH);
 digitalWrite(pin5,HIGH);
 digitalWrite(pin6,LOW);
 digitalWrite(pin4,LOW);
 }

void back()
{
 digitalWrite(led,HIGH);
 digitalWrite(pin7,LOW);
 digitalWrite(pin5,LOW);
 digitalWrite(pin6,HIGH);
 digitalWrite(pin4,HIGH);
  }
void right()
{
  digitalWrite(led,HIGH);
 digitalWrite(pin7,HIGH);
 digitalWrite(pin5,LOW);
 digitalWrite(pin6,LOW);
 digitalWrite(pin4,HIGH);
  }

 void left()
 {
  digitalWrite(led,HIGH);
 digitalWrite(pin7,LOW);
 digitalWrite(pin5,HIGH);
 digitalWrite(pin6,HIGH);
 digitalWrite(pin4,LOW); 
  }

void stopp()
{
 digitalWrite(led,LOW);
 digitalWrite(pin6,LOW);
 digitalWrite(pin4,LOW);
 digitalWrite(pin7,LOW);
 digitalWrite(pin5,LOW);
}
void setup() {
/*pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); */ 
pinMode(pin7,OUTPUT);
pinMode(pin6,OUTPUT);
pinMode(pin5,OUTPUT);
pinMode(pin4,OUTPUT);
pinMode(led,OUTPUT);
Serial.begin(9600); 
 

}

void loop() {
/*digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH); 
distance = (duration/2) / 29; */

  if (Serial.available())
  {
 BluetoothData=Serial.read();  
 

if(BluetoothData=='F'){
/*if (distance < 25){
 right();}
 else{*/
forward();}//}
else if(BluetoothData=='B')
back();
else if(BluetoothData=='L')
left();
else if(BluetoothData=='R')
right();
else if(BluetoothData=='S')
 stopp();
  }
}
