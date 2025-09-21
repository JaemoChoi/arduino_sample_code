#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 50

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 숨쉬기 효과 함수
void breathe(uint32_t color, int cycles) {
  uint8_t baseR = (color >> 16) & 0xFF;
  uint8_t baseG = (color >> 8) & 0xFF;
  uint8_t baseB = (color) & 0xFF;

  for (int c = 0; c < cycles; c++) {
    // 밝아짐
    for (int b = 0; b <= 255; b++) {
      strip.clear();
      for (int i = 0; i < NUMPIXELS; i++) {
        uint8_t r = (baseR * b) / 255;
        uint8_t g = (baseG * b) / 255;
        uint8_t bl = (baseB * b) / 255;
        strip.setPixelColor(i, strip.Color(r, g, bl));
      }
      strip.show();
      delay(5); // 속도 조절 (커질수록 느려짐)
    }
    // 어두워짐
    for (int b = 255; b >= 0; b--) {
      strip.clear();
      for (int i = 0; i < NUMPIXELS; i++) {
        uint8_t r = (baseR * b) / 255;
        uint8_t g = (baseG * b) / 255;
        uint8_t bl = (baseB * b) / 255;
        strip.setPixelColor(i, strip.Color(r, g, bl));
      }
      strip.show();
      delay(5);
    }
  }

  // 다 끝나면 꺼짐
  strip.clear();
  strip.show();
}

void setup() {
  strip.begin();
  strip.show();

  // 예: 파란색 숨쉬기 효과 3번 실행
  breathe(strip.Color(0, 0, 255), 3);
}

void loop() {
  // 아무것도 안 함
}