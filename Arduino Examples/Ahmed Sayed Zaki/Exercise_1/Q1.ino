int Led=3;
void setup() {
  pinMode(Led, OUTPUT);
  digitalWrite(Led, LOW);
}

void loop() {
  digitalWrite(Led, HIGH);
  delay(500);
  digitalWrite(Led, LOW);
  delay(1500);
}
