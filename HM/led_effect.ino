void listen(int count) {
  float pos = 0;

  for (int cycle = 0; cycle < count; cycle++) {
    while (pos < NUMPIXELS - groupSize) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        return;
      }
      strip.clear();

      // 6픽셀 묶음 출력
      for (int i = 0; i < groupSize; i++) {
        int idx = (int)(pos + i);
        if (idx >= 0 && idx < NUMPIXELS) {
          float ratio = (float)i / (groupSize - 1);

          uint8_t rr = (uint8_t)((1 - ratio) * r1 + ratio * r2);
          uint8_t gg = (uint8_t)((1 - ratio) * g1 + ratio * g2);
          uint8_t bb = (uint8_t)((1 - ratio) * b1 + ratio * b2);
          uint8_t ww = (uint8_t)((1 - ratio) * w1 + ratio * w2);

          strip.setPixelColor(idx, strip.Color(rr, gg, bb, ww));
        }
      }

      strip.show();
      delay(frameDelay);
      pos += speed;
    }
    pos = 0;  // 한 사이클 끝 → 다시 처음으로
  }

  // 끝나면 꺼짐
  strip.clear();
  strip.show();
}

void breathe(uint8_t r, uint8_t g, uint8_t b, uint8_t w, int cycles) {
  for (int c = 0; c < cycles; c++) {
    // 밝아짐
    for (int bri = 0; bri <= 255; bri++) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        return;
      }
      strip.clear();
      for (int i = 0; i < NUMPIXELS; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        strip.setPixelColor(i, strip.Color(rr, gg, bb, ww));
      }
      strip.show();
      delay(5);  // 속도 조절
    }

    // 어두워짐
    for (int bri = 255; bri >= 0; bri--) {
      strip.clear();
      for (int i = 0; i < NUMPIXELS; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        strip.setPixelColor(i, strip.Color(rr, gg, bb, ww));
      }
      strip.show();
      delay(5);
    }
  }

  // 끝나면 꺼짐
  strip.clear();
  strip.show();
}
