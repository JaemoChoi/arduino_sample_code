#include <Adafruit_NeoPixel.h>

#define PIN 6        // 네오픽셀 데이터핀
#define NUMPIXELS 50 // 픽셀 개수

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t color1 = strip.Color(255, 0, 0);   // 빨강
uint32_t color2 = strip.Color(0, 0, 255);   // 파랑
int groupSize = 6;

int pos = 0;
int dir = 1; // 1 = 앞으로, -1 = 뒤로
int delayTime = 50;

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  strip.clear();

  // 6픽셀 묶음 그라데이션 출력
  for (int i = 0; i < groupSize; i++) {
    int ledIndex = pos + i;
    if (ledIndex >= 0 && ledIndex < NUMPIXELS) {
      // i 위치에 따른 색 보간
      float ratio = (float)i / (groupSize - 1);
      uint8_t r = (uint8_t)((1 - ratio) * ((color1 >> 16) & 0xFF) + ratio * ((color2 >> 16) & 0xFF));
      uint8_t g = (uint8_t)((1 - ratio) * ((color1 >> 8) & 0xFF) + ratio * ((color2 >> 8) & 0xFF));
      uint8_t b = (uint8_t)((1 - ratio) * ((color1) & 0xFF) + ratio * ((color2) & 0xFF));

      strip.setPixelColor(ledIndex, strip.Color(r, g, b));
    }
  }

  strip.show();
  delay(delayTime);

  // 위치 업데이트
  pos += dir;
  if (pos <= 0 || pos >= NUMPIXELS - groupSize) {
    dir *= -1; // 방향 반전
  }
}