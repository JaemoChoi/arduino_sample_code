#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 50

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 색상 정의
uint32_t color1 = strip.Color(255, 0, 0);   // 빨강
uint32_t color2 = strip.Color(0, 0, 255);   // 파랑

// 효과 파라미터
int groupSize = 6;
float speed = 0.1;   // 이동 속도 (작으면 느려짐)
int frameDelay = 10; // ms 단위 프레임 간격

// listen 효과 함수 (count번 실행 후 종료)
void listen(int count) {
  float pos = 0;

  for (int cycle = 0; cycle < count; cycle++) {
    while (pos < NUMPIXELS - groupSize) {
      strip.clear();

      // 6픽셀 묶음 출력
      for (int i = 0; i < groupSize; i++) {
        int idx = (int)(pos + i);
        if (idx >= 0 && idx < NUMPIXELS) {
          float ratio = (float)i / (groupSize - 1);
          uint8_t r = (uint8_t)((1 - ratio) * ((color1 >> 16) & 0xFF) + ratio * ((color2 >> 16) & 0xFF));
          uint8_t g = (uint8_t)((1 - ratio) * ((color1 >> 8) & 0xFF) + ratio * ((color2 >> 8) & 0xFF));
          uint8_t b = (uint8_t)((1 - ratio) * ((color1) & 0xFF) + ratio * ((color2) & 0xFF));

          strip.setPixelColor(idx, strip.Color(r, g, b));
        }
      }

      strip.show();
      delay(frameDelay);
      pos += speed;
    }
    pos = 0; // 한 사이클 끝 → 다시 처음으로
  }

  // 다 끝나면 꺼줌
  strip.clear();
  strip.show();
}

void setup() {
  strip.begin();
  strip.show();

  // listen 효과를 3번 실행하고 끝냄
  listen(3);
}

void loop() {
  // 아무것도 안 함
}