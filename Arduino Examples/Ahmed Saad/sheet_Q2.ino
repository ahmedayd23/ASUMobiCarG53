int led=4;
int led1=5;
int led2=6;
int led3=7;
void setup() {
  pinMode(led,OUTPUT); 
   pinMode(led1,OUTPUT); 
    pinMode(led2,OUTPUT);
      pinMode(led3,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
 digitalWrite(led,HIGH);
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite (led3,LOW);
    delay(1000);
    digitalWrite(led,LOW);
  digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);
    digitalWrite (led3,LOW);
    delay(1000);
    digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
    digitalWrite (led3,LOW);
    delay(1000);
    digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite (led3,HIGH);
    delay(1000);
     digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite (led3,LOW);
    delay(1000);
     digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite (led3,HIGH);
    delay(1000);
     digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
    digitalWrite (led3,LOW);
    delay(1000);
     digitalWrite(led,LOW);
  digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW); 
    digitalWrite (led3,LOW);
    delay(1000);
     digitalWrite(led,HIGH);
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite (led3,LOW);
    delay(1000);
     
  // put your main code here, to run repeatedly:

}
