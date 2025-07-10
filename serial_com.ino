void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("play1");  // 1초마다 "play1" 전송
  delay(1000);
}