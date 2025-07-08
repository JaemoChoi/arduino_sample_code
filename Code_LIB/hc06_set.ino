void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println(" AT Command:");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial2.available()) {
    char c = Serial2.read();
    Serial.write(c);
  }
  if (Serial.available()) {
    char c = Serial.read();
    Serial2.write(c);
  }
}
