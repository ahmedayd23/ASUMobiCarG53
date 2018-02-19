  int yellow = 0;
  int red = 1;
  int green = 2;
  
void setup()
{
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() 
{
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  delay (2000);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  delay (200);

  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
  delay (2000);


  
}
