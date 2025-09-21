#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 50

// GRBW 네오픽셀 지정
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

// 숨쉬기 효과 함수 (RGBW)
void breathe(uint8_t r, uint8_t g, uint8_t b, uint8_t w, int cycles) {
  for (int c = 0; c < cycles; c++) {
    // 밝아짐
    for (int bri = 0; bri <= 255; bri++) {
      strip.clear();
      for (int i = 0; i < NUMPIXELS; i++) {
        uint8_t rr = (r * bri) / 255;
        uint8_t gg = (g * bri) / 255;
        uint8_t bb = (b * bri) / 255;
        uint8_t ww = (w * bri) / 255;
        strip.setPixelColor(i, strip.Color(rr, gg, bb, ww));
      }
      strip.show();
      delay(5); // 속도 조절
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

void setup() {
  strip.begin();
  strip.show();

  // 예: 하얀색 숨쉬기 효과 3번 실행
  breathe(0, 0, 0, 255, 3);

  // 예: 보라색(R+B+W) 숨쉬기 효과 2번 실행
  // breathe(255, 0, 255, 100, 2);
}

void loop() {
  // 빈 루프
}