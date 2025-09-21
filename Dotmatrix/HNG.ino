#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 50

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t color1 = strip.Color(255, 0, 0);   // 빨강
uint32_t color2 = strip.Color(0, 0, 255);   // 파랑

int groupSize = 6;
float pos = 0;     // 위치를 float으로 해서 부드럽게 이동
float speed = 0.1; // 이동 속도 (작을수록 느리고 부드러움)
int dir = 1;

unsigned long lastUpdate = 0;

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  unsigned long now = millis();

  // 10ms마다 업데이트
  if (now - lastUpdate > 10) {
    lastUpdate = now;
    strip.clear();

    // 6픽셀 묶음 출력
    for (int i = 0; i < groupSize; i++) {
      float ledPos = pos + i;
      int idx = (int)ledPos;
      if (idx >= 0 && idx < NUMPIXELS) {
        // 그라데이션 비율
        float ratio = (float)i / (groupSize - 1);
        uint8_t r = (uint8_t)((1 - ratio) * ((color1 >> 16) & 0xFF) + ratio * ((color2 >> 16) & 0xFF));
        uint8_t g = (uint8_t)((1 - ratio) * ((color1 >> 8) & 0xFF) + ratio * ((color2 >> 8) & 0xFF));
        uint8_t b = (uint8_t)((1 - ratio) * ((color1) & 0xFF) + ratio * ((color2) & 0xFF));

        strip.setPixelColor(idx, strip.Color(r, g, b));
      }
    }

    strip.show();

    // 위치 업데이트 (부드럽게)
    pos += dir * speed;
    if (pos <= 0 || pos >= (NUMPIXELS - groupSize)) {
      dir *= -1; // 끝에 닿으면 반대방향
    }
  }
}