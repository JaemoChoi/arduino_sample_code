#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 50

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 색상 정의
uint32_t color1 = strip.Color(255, 0, 0);   // 빨강
uint32_t color2 = strip.Color(0, 0, 255);   // 파랑

// 효과 파라미터
int groupSize = 6;
float speed = 0.1;   // 이동 속도

void listen(int count) {
  static float pos = 0;               // 현재 위치
  static int cycleCount = 0;          // 완료한 사이클 수
  static unsigned long lastUpdate = 0;
  static int targetCycles = 0;
  static bool running = false;

  // 최초 호출 시 count로 초기화
  if (!running) {
    pos = 0;
    cycleCount = 0;
    targetCycles = count;
    running = true;
  }

  unsigned long now = millis();
  if (running && now - lastUpdate > 10) {
    lastUpdate = now;
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

    // 위치 업데이트
    pos += speed;
    if (pos >= NUMPIXELS - groupSize) {
      pos = 0;           // 다시 처음으로
      cycleCount++;      // 사이클 완료
      if (cycleCount >= targetCycles) {
        running = false; // 실행 종료
        strip.clear();
        strip.show();
      }
    }
  }
}

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  listen(5); // listen 효과를 5번만 실행
}