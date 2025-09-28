void LED_init() {

  EAR_strip.begin();
  EAR_strip.setBrightness(150);
  EAR_strip.show();

  SHOULDER_strip.begin();
  SHOULDER_strip.setBrightness(150);
  SHOULDER_strip.show();

  HAND_strip.begin();
  HAND_strip.setBrightness(150);
  HAND_strip.show();

  FOOT_strip.begin();
  FOOT_strip.setBrightness(150);
  FOOT_strip.show();


  EAR_setAll(0, 0, 0, 0);
  SHOULDER_setAll(0, 0, 0, 0);
  HAND_setAll(0, 0, 0, 0);
  FOOT_setAll(0, 0, 0, 0);


}

void breathe(uint8_t r, uint8_t g, uint8_t b, uint8_t w, int cycles) {
  //for (int c = 0; c < cycles; c++) {
  while (1) {
    if (BT_Serial.available()) {
      SCENE_NO = BT_Serial.read();
      SHOULDER_strip.clear();
      SHOULDER_strip.show();
      led_flag = 1;
      return;
    }
    // 밝아짐
    for (float bri = 0; bri <= 255; bri += 4) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        SHOULDER_strip.clear();
        SHOULDER_strip.show();
        led_flag = 1;
        return;
      }
      SHOULDER_strip.clear();

      for (int i = 0; i < SHOULDER_NUM; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        SHOULDER_strip.setPixelColor(i,  SHOULDER_strip.Color(rr, gg, bb, ww));
      }
      SHOULDER_strip.show();
      delay(8);  // 속도 조절
    }

    // 어두워짐
    for (float bri = 255; bri >= 0; bri -= 2) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        SHOULDER_strip.clear();
        SHOULDER_strip.show();

        led_flag = 1;
        return;
      }
      SHOULDER_strip.clear();

      for (int i = 0; i <  SHOULDER_NUM; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        SHOULDER_strip.setPixelColor(i,  SHOULDER_strip.Color(rr, gg, bb, ww));

      }
      SHOULDER_strip.show();
      delay(7);
    }
  }

  // 끝나면 꺼짐
  SHOULDER_strip.clear();
  SHOULDER_strip.show();
}

void EAR_grd() {
  // 시작 색상과 끝 색상 (예: 빨강 → 파랑)
  uint8_t color1[3] = {149, 184, 217};   // 빨강
  uint8_t color2[3] = {255, 80, 20};   // 파랑

  for (int i = 0; i < EAR_NUM; i++) {
    float t = (float)i / (EAR_NUM - 1); // 0~1 사이의 값
    uint8_t r = (uint8_t)(color1[0] + (color2[0] - color1[0]) * t);
    uint8_t g = (uint8_t)(color1[1] + (color2[1] - color1[1]) * t);
    uint8_t b = (uint8_t)(color1[2] + (color2[2] - color1[2]) * t);
    EAR_strip.setPixelColor(i, EAR_strip.Color(r, g, b));
  }
  EAR_strip.show();
  delay(50);
}

void EAR_listen(int16_t count) {

  //for (int16_t s = 0; s < count ; s++) {

  while (1) {
    if (BT_Serial.available()) {
      SCENE_NO = BT_Serial.read();
      EAR_strip.clear();
      EAR_strip.show();
      led_flag = 1;
      return;
    }
    for (int i = 0; i < EAR_NUM; i++) {
      // 각 LED마다 시간차를 주기 위해 위치 기반 오프셋 추가
      float phase = offset + (float)i / EAR_NUM;

      // 0~1 범위에서 반복 (사인파로 자연스럽게)
      float t = (sin(phase * 2 * PI) + 1) / 2;

      // 색 보간
      uint8_t r = (1 - t) * startColor[0] + t * endColor[0];
      uint8_t g = (1 - t) * startColor[1] + t * endColor[1];
      uint8_t b = (1 - t) * startColor[2] + t * endColor[2];

      EAR_strip.setPixelColor(i, EAR_strip.Color(r * 0.3, g * 0.3, b * 0.3, 0));
    }
    EAR_strip.show();

    // 물결 진행
    offset += SPEED;
    if (offset > 1) offset -= 1; // 값이 너무 커지지 않게

  }
}
