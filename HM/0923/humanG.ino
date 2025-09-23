
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include "pin_def.h"


SoftwareSerial BT_Serial(8, 7);

Adafruit_NeoPixel EAR_strip(EAR_NUM, EAR_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel SHOULDER_strip(SHOULDER_NUM, SHOULDER_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel HAND_strip(HAND_NUM, HAND_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel FOOT_strip(FOOT_NUM, FOOT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel NECK_strip(NECK_NUM, NECK_PIN, NEO_GRBW + NEO_KHZ800);


// 색상 정의
// RGBW 색상 정의
uint8_t r1 = 255, g1 = 80, b1 = 20, w1 = 0;    // 첫 번째 색상
uint8_t r2 = 149, g2 = 184, b2 = 217, w2 = 0;  // 두 번째 색상

int mode = 1;
int SCENE_NO = 255;

int DIM  =  255;
int led_flag = 0;



// 효과 파라미터
int groupSize = 6;
float speed = 0.4;    // 이동 속도 (작으면 느려짐)
int frameDelay = 20;  // ms 단위 프레임 간격

// listen 효과 함수 (count번 실행 후 종료)

void setup() {
  BT_Serial.begin(9600);
  Serial.begin(9600);
  LED_init();

  // listen 효과를 3번 실행하고 끝냄
}

void loop() {
  // 아무것도 안 함
  if (SCENE_NO == 1) {
    Serial.println(SCENE_NO);
    listen(3);
    led_flag = 1;
    SCENE_NO = 255;
  }
  if (SCENE_NO == 2) {
    Serial.println(SCENE_NO);
    breathe(0, 0, 0, 100, 3);
    led_flag = 1;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 3) {
    Serial.println(SCENE_NO);
    //EAR_setAll(0, 0, 0, 100);
    SHOULDER_setAllOFF(0, 0, 0, 150, 50);
    HAND_setAllOFF(0, 0, 0, 150, 50);
    FOOT_setAllOFF(0, 0, 0, 150, 50);
    NECK_setAllOFF(0, 0, 0, 150, 50);
    SCENE_NO = 255;
  }

    if (SCENE_NO == 4) {
    Serial.println(SCENE_NO);
    //EAR_setAll(0, 0, 0, 100);
    SHOULDER_setAllOFF(0, 0, 0, 150, 20);
    HAND_setAllOFF(0, 0, 0, 150, 20);
    FOOT_setAllOFF(0, 0, 0, 150, 20);
    NECK_setAllOFF(0, 0, 0, 150, 20);
    SCENE_NO = 255;
  }

  if (BT_Serial.available()) {
    SCENE_NO = BT_Serial.read();
  }
}
