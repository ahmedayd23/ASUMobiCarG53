int led =13;
int button=0;
int val;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  val=digitalRead(button);
 if ( val==HIGH){
  digitalWrite(led,HIGH);
  delay(2000);
  }
 else  digitalWrite(led,LOW);
}
