void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonPressed = digitalRead(2);
  Serial.println(buttonPressed);
  //delay(1000);
}
