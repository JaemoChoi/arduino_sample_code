void LED_init() {

  EAR_strip.begin();
  EAR_strip.setBrightness(150);
  EAR_strip.show();
  REAR_strip.begin();
  REAR_strip.setBrightness(150);
  REAR_strip.show();

  SHOULDER_strip.begin();
  SHOULDER_strip.setBrightness(150);
  SHOULDER_strip.show();

  HAND_strip.begin();
  HAND_strip.setBrightness(150);
  HAND_strip.show();

  FOOT_strip.begin();
  FOOT_strip.setBrightness(150);
  FOOT_strip.show();

  /*
    EAR_setAll(0, 0, 0, 100);
    SHOULDER_setAll(0, 0, 0, 100);
    HAND_setAll(0, 0, 0, 100);
    FOOT_setAll(0, 0, 0, 100);
  */
}

void ALLOFF() {

  for (int i = 0; i < EAR_NUM; i++) {
    EAR_setPixel(i, 0, 0, 0, 0);
    REAR_setPixel(i, 0, 0, 0, 0);
  }

  for (int i = 0; i < SHOULDER_NUM; i++) {
    SHOULDER_setPixel(i, 0, 0, 0, 0);
  }

  for (int i = 0; i < HAND_NUM; i++) {
    HAND_setPixel(i, 0, 0, 0, 0);
  }

  for (int i = 0; i < FOOT_NUM; i++) {
    FOOT_setPixel(i, 0, 0, 0, 0);
  }

  EAR_strip.show();
  REAR_strip.show();
  SHOULDER_strip.show();
  HAND_strip.show();
  FOOT_strip.show();
}

/*
void listen() {
  float pos = 0;

  //for (int cycle = 0; cycle < count; cycle++) {
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
    while (pos < EAR_NUM - groupSize) {
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

      // 6픽셀 묶음 출력 (EAR_strip: 왼→오, REAR_strip: 오→왼)
      for (int i = 0; i < groupSize; i++) {
        int idx_rear = (int)(pos + i);
        int idx_ear = (int)((EAR_NUM - 1) - (pos + i));
        float ratio = (float)i / (groupSize - 1);

        // 밝기: 앞쪽은 1.0, 뒤쪽은 pow(0.2, ratio)로 훨씬 더 어둡게
        float brightness = 1;//pow(0.1, 1.0 - ratio); // 0.2는 뒤쪽 어둠 정도, 더 낮추면 더 어두움

        uint8_t rr = (uint8_t)(((1 - ratio) * r1 + ratio * r2) * brightness);
        uint8_t gg = (uint8_t)(((1 - ratio) * g1 + ratio * g2) * brightness);
        uint8_t bb = (uint8_t)(((1 - ratio) * b1 + ratio * b2) * brightness);
        uint8_t ww = (uint8_t)(((1 - ratio) * w1 + ratio * w2) * brightness);

        if (idx_ear >= 0 && idx_ear < EAR_NUM) {
          EAR_strip.setPixelColor(idx_ear, EAR_strip.Color(rr, gg, bb, ww));
        }
        if (idx_rear >= 0 && idx_rear < EAR_NUM) {
          REAR_strip.setPixelColor(idx_rear, REAR_strip.Color(rr, gg, bb, ww));
        }
      }

      EAR_strip.show();
      REAR_strip.show();
      delay(frameDelay);
      pos += speed;
    }
    pos = 0;  // 한 사이클 끝 → 다시 처음으로
  }

  // 끝나면 꺼짐
  EAR_strip.clear();
  EAR_strip.show();
  REAR_strip.clear();
  REAR_strip.show();
}
*/

void breathe_EAR(uint8_t r, uint8_t g, uint8_t b, uint8_t w, int cycles) {
  for (int c = 0; c < cycles; c++) {
    // 밝아짐

    if (c == 0) {
      for (int bri = 0; bri <= 255; bri += 2) {
        if (BT_Serial.available()) {
          SCENE_NO = BT_Serial.read();
          return;
        }
        EAR_strip.clear();
        REAR_strip.clear();

        for (int i = 0; i < EAR_NUM; i++) {
          uint8_t rr = (r * bri) / 255;
          uint8_t gg = (g * bri) / 255;
          uint8_t bb = (b * bri) / 255;
          uint8_t ww = (w * bri) / 255;
          EAR_strip.setPixelColor(i, EAR_strip.Color(rr, gg, bb, ww));
          REAR_strip.setPixelColor(i, REAR_strip.Color(rr, gg, bb, ww));
        }
        EAR_strip.show();
        REAR_strip.show();
        delay(2);  // 속도 조절
      }
    } else if (c != 0) {
      for (int bri = 30; bri <= 255; bri += 2) {
        if (BT_Serial.available()) {
          SCENE_NO = BT_Serial.read();
          return;
        }
        EAR_strip.clear();
        REAR_strip.clear();

        for (int i = 0; i < EAR_NUM; i++) {
          uint8_t rr = (r * bri) / 255;
          uint8_t gg = (g * bri) / 255;
          uint8_t bb = (b * bri) / 255;
          uint8_t ww = (w * bri) / 255;
          EAR_strip.setPixelColor(i, EAR_strip.Color(rr, gg, bb, ww));
          REAR_strip.setPixelColor(i, REAR_strip.Color(rr, gg, bb, ww));
        }
        EAR_strip.show();
        REAR_strip.show();
        delay(2);  // 속도 조절
      }
    }
    // 어두워짐
    for (int bri = 255; bri >= 30; bri--) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        return;
      }
      EAR_strip.clear();
      REAR_strip.clear();
      for (int i = 0; i < EAR_NUM; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        EAR_strip.setPixelColor(i, EAR_strip.Color(rr, gg, bb, ww));
        REAR_strip.setPixelColor(i, EAR_strip.Color(rr, gg, bb, ww));
      }
      EAR_strip.show();
      REAR_strip.show();
      delay(5);
    }
  }

  // 끝나면 꺼짐
  EAR_strip.clear();
  EAR_strip.show();

  REAR_strip.clear();
  REAR_strip.show();
}

void breathe_Neck(uint8_t r, uint8_t g, uint8_t b, uint8_t w, int cycles) {
  //for (int c = 0; c < cycles; c++) {
  // 밝아짐
  while (1) {
    /*
    if (BT_Serial.available()) {
      SCENE_NO = BT_Serial.read();
      SHOULDER_strip.clear();
      SHOULDER_strip.show();
      led_flag = 1;
      return;
    }
    */
    
    preTime = millis();
    for (float bri = 0; bri <= 255; bri += 2) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        SHOULDER_strip.clear();
        SHOULDER_strip.show();
        led_flag = 1;
        return;
      }
      //SHOULDER_strip.clear();
      for (int i = 0; i < SHOULDER_NUM; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        SHOULDER_strip.setPixelColor(i, SHOULDER_strip.Color(rr, gg, bb, ww));
      }
      SHOULDER_strip.show();
      delay(10);  // 속도 조절
    }
     inTime = millis();
     Serial.print("Rising Time : ");
     Serial.println(inTime - preTime);


    // 어두워짐
    preTime = millis();
    for (float bri = 255; bri >= 0; bri -= 3) {
      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        SHOULDER_strip.clear();
        SHOULDER_strip.show();
        led_flag = 1;
        return;
      }

      // SHOULDER_strip.clear();

      for (int i = 0; i < SHOULDER_NUM; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        SHOULDER_strip.setPixelColor(i, SHOULDER_strip.Color(rr, gg, bb, ww));
      }
      SHOULDER_strip.show();
      delay(10);
    }
     inTime = millis();
     Serial.print(" Falling time :");
     Serial.println(inTime - preTime);
  }
}

/*
void EAR_grd(int count) {
  // 시작 색상과 끝 색상 (예: 빨강 → 파랑)
  uint8_t color1[3] = { 149, 184, 217 };  // 빨강
  uint8_t color2[3] = { 255, 80, 20 };    // 파랑
  for (float bri = 0; bri < 256; bri+=4) {
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
  for (float bri = 255; bri >= 0; bri-=4) {
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
}
*/

void listen() {
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

      int idx_rear = ((int)(pos + i)) % EAR_NUM;
      int idx_ear = ((EAR_NUM - 1) - ((int)(pos + i) % EAR_NUM));

      float ratio = (float)i / (groupSize - 1);
      float brightness = pow(0.2, ratio);

      uint8_t rr = (uint8_t)(((1 - ratio) * r1 + ratio * r2) * brightness);
      uint8_t gg = (uint8_t)(((1 - ratio) * g1 + ratio * g2) * brightness);
      uint8_t bb = (uint8_t)(((1 - ratio) * b1 + ratio * b2) * brightness);
      uint8_t ww = (uint8_t)(((1 - ratio) * w1 + ratio * w2) * brightness);

      EAR_strip.setPixelColor(idx_ear, EAR_strip.Color(rr, gg, bb, ww));
      REAR_strip.setPixelColor(idx_rear, REAR_strip.Color(rr, gg, bb, ww));

      if (BT_Serial.available()) {
        SCENE_NO = BT_Serial.read();
        EAR_strip.clear();
        EAR_strip.show();
        REAR_strip.clear();
        REAR_strip.show();
        led_flag = 1;
        return;
      }
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
  for (int i = 0; i < EAR_NUM; i++) {

    EAR_strip.setPixelColor(i, EAR_strip.Color(0, 0, 0));
    //EAR_strip.setPixelColor(60 - i, REAR_strip.Color(0, 0, 0));

    REAR_strip.setPixelColor(60-i, REAR_strip.Color(0, 0, 0));
    //REAR_strip.setPixelColor(60 - i, REAR_strip.Color(0, 0, 0));
    EAR_strip.show();
    REAR_strip.show();
    delay(10);
  }

  //}
}
