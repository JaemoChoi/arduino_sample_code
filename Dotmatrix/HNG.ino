#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 50

// GRBW 네오픽셀 지정
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

// 효과 파라미터
int groupSize = 6;
float speed = 0.1;   // 이동 속도
int frameDelay = 10; // ms 단위 프레임 간격

// mode 변수: 0=대기, 1=listen 실행
int mode = 1;

// RGBW 색상 정의
uint8_t r1 = 255, g1 = 0, b1 = 0, w1 = 0;   // 첫 번째 색상
uint8_t r2 = 0, g2 = 0, b2 = 255, w2 = 0;   // 두 번째 색상

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
    pos = 0; // 한 사이클 끝 → 다시 처음으로
  }

  // 끝나면 꺼짐
  strip.clear();
  strip.show();

  // 실행 끝났으니 mode=0
  mode = 0;
}

void setup() {
  strip.begin();
  strip.show();

  mode = 1; // listen 실행 요청
}

void loop() {
  if (mode == 1) {
    listen(3); // 3번 실행 후 mode=0으로 변경
  }
}