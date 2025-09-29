void listen(int count) {
  float pos = 0;

  while (1) {
    if (BT_Serial.available()) {
      SCENE_NO = BT_Serial.read();
      EAR_strip.clear();
      EAR_strip.show();
      REAR_strip.clear();
      REAR_strip.show();
      led_flag = 1;
      return;
    }
    EAR_strip.clear();
    REAR_strip.clear();

    // 항상 groupSize개가 원형으로 이어지게
    for (int i = 0; i < groupSize; i++) {
      int idx_ear = ((int)(pos + i)) % EAR_NUM;
      int idx_rear = ((EAR_NUM - 1) - ((int)(pos + i) % EAR_NUM));

      float ratio = (float)i / (groupSize - 1);
      float brightness = pow(0.2, ratio);

      uint8_t rr = (uint8_t)(((1 - ratio) * r1 + ratio * r2) * brightness);
      uint8_t gg = (uint8_t)(((1 - ratio) * g1 + ratio * g2) * brightness);
      uint8_t bb = (uint8_t)(((1 - ratio) * b1 + ratio * b2) * brightness);
      uint8_t ww = (uint8_t)(((1 - ratio) * w1 + ratio * w2) * brightness);

      EAR_strip.setPixelColor(idx_ear, EAR_strip.Color(rr, gg, bb, ww));
      REAR_strip.setPixelColor(idx_rear, REAR_strip.Color(rr, gg, bb, ww));
    }

    EAR_strip.show();
    REAR_strip.show();
    delay(frameDelay);
    pos += speed;
    // pos가 너무 커지면 원형으로 유지
    if (pos >= EAR_NUM) pos -= EAR_NUM;
  }

  EAR_strip.clear();
  EAR_strip.show();
  REAR_strip.clear();
  REAR_strip.show();
}

void EAR_grd(int count) {
  // 시작 색상과 끝 색상 (예: 빨강 → 파랑)
  uint8_t color1[3] = { 149, 184, 240 };  // 빨강
  uint8_t color2[3] = { 255, 80, 20 };    // 파랑
  for (float bri = 0; bri < 256; bri += 4) {
    for (int i = 0; i < EAR_NUM; i++) {
      float t = (float)i / (EAR_NUM - 1);  // 0~1 사이의 값
      uint8_t r = (uint8_t)(color1[0] + (color2[0] - color1[0]) * t);
      uint8_t g = (uint8_t)(color1[1] + (color2[1] - color1[1]) * t);
      uint8_t b = (uint8_t)(color1[2] + (color2[2] - color1[2]) * t);
      EAR_strip.setPixelColor(i, EAR_strip.Color(r * (bri / 255), g * (bri / 255), b * (bri / 255)));
      REAR_strip.setPixelColor(i, REAR_strip.Color(r * (bri / 255), g * (bri / 255), b * (bri / 255)));
    }
    EAR_strip.show();
    REAR_strip.show();
  }
  //for (float bri = 255; bri >= 0; bri-=4) {
  for (int i = 0; i < EAR_NUM ; i++) {

    EAR_strip.setPixelColor(i, EAR_strip.Color(0, 0, 0));
    //EAR_strip.setPixelColor(60 - i, REAR_strip.Color(0, 0, 0));

    REAR_strip.setPixelColor(i, REAR_strip.Color(0, 0, 0));
    //REAR_strip.setPixelColor(60 - i, REAR_strip.Color(0, 0, 0));
    EAR_strip.show();
    REAR_strip.show();
    delay(10);
  }

  //}
}
