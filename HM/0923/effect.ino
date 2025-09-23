void LED_init() {

  EAR_strip.begin();
  EAR_strip.show();

  SHOULDER_strip.begin();
  SHOULDER_strip.show();

  HAND_strip.begin();
  HAND_strip.show();

  FOOT_strip.begin();
  FOOT_strip.show();

  NECK_strip.begin();
  NECK_strip.show();

  SHOULDER_setAll(0, 0, 0, 100);
  HAND_setAll(0, 0, 0, 100);
  FOOT_setAll(0, 0, 0, 100);
  NECK_setAll(0, 0, 0, 100);

}

void listen(int count) {
  float pos = 0;

  for (int cycle = 0; cycle < count; cycle++) {
    while (pos < EAR_NUM - groupSize) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        return;
      }
      EAR_strip.clear();

      // 6픽셀 묶음 출력
      for (int i = 0; i < groupSize; i++) {
        int idx = (int)(pos + i);
        if (idx >= 0 && idx < EAR_NUM) {
          float ratio = (float)i / (groupSize - 1);

          uint8_t rr = (uint8_t)((1 - ratio) * r1 + ratio * r2);
          uint8_t gg = (uint8_t)((1 - ratio) * g1 + ratio * g2);
          uint8_t bb = (uint8_t)((1 - ratio) * b1 + ratio * b2);
          uint8_t ww = (uint8_t)((1 - ratio) * w1 + ratio * w2);

          EAR_strip.setPixelColor(idx, EAR_strip.Color(rr, gg, bb, ww));
        }
      }

      EAR_strip.show();
      delay(frameDelay);
      pos += speed;
    }
    pos = 0;  // 한 사이클 끝 → 다시 처음으로
  }

  // 끝나면 꺼짐
  EAR_strip.clear();
  EAR_strip.show();
}

void breathe(uint8_t r, uint8_t g, uint8_t b, uint8_t w, int cycles) {
  for (int c = 0; c < cycles; c++) {
    // 밝아짐
    for (int bri = 0; bri <= 255; bri++) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        return;
      }
      EAR_strip.clear();
      for (int i = 0; i < EAR_NUM; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        EAR_strip.setPixelColor(i, EAR_strip.Color(rr, gg, bb, ww));
      }
      EAR_strip.show();
      delay(5);  // 속도 조절
    }

    // 어두워짐
    for (int bri = 255; bri >= 0; bri--) {
      EAR_strip.clear();
      for (int i = 0; i < EAR_NUM; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        EAR_strip.setPixelColor(i, EAR_strip.Color(rr, gg, bb, ww));
      }
      EAR_strip.show();
      delay(5);
    }
  }

  // 끝나면 꺼짐
  EAR_strip.clear();
  EAR_strip.show();
}
