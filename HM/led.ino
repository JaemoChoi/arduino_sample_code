#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

#define PIN 6
#define NUMPIXELS 50

SoftwareSerial BT_Serial(8, 7);
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

// 색상 정의
// RGBW 색상 정의
uint8_t r1 = 255, g1 = 80, b1 = 20, w1 = 0;    // 첫 번째 색상
uint8_t r2 = 149, g2 = 184, b2 = 217, w2 = 0;  // 두 번째 색상

int mode = 1;
int SCENE_NO = 255;

// 효과 파라미터
int groupSize = 6;
float speed = 0.5;    // 이동 속도 (작으면 느려짐)
int frameDelay = 10;  // ms 단위 프레임 간격

// listen 효과 함수 (count번 실행 후 종료)

void setup() {
  BT_Serial.begin(9600);
  Serial.begin(9600);
  strip.begin();
  strip.show();

  // listen 효과를 3번 실행하고 끝냄
}

void loop() {
  // 아무것도 안 함
  if (SCENE_NO == 1) {
    Serial.println(SCENE_NO);
    listen(2);
    //SCENE_NO = 255;
  }
  if (SCENE_NO == 2) {
    Serial.println(SCENE_NO);
    breathe(0, 0, 0, 100, 3);
    //SCENE_NO = 255;
  }

  if (BT_Serial.available()) {
    SCENE_NO = BT_Serial.read();
  }
}

