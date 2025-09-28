
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include "pin_def.h"


SoftwareSerial BT_Serial(8, 7);

Adafruit_NeoPixel EAR_strip(EAR_NUM, EAR_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel REAR_strip(EAR_NUM, REAR_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel SHOULDER_strip(SHOULDER_NUM, SHOULDER_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel HAND_strip(HAND_NUM, HAND_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel FOOT_strip(FOOT_NUM, FOOT_PIN, NEO_GRBW + NEO_KHZ800);

// 색상 정의
// RGBW 색상 정의
uint8_t r2 = 255, g2 = 80, b2 = 20, w2 = 0;    // 첫 번째 색상
uint8_t r1 = 149, g1 = 184, b1 = 217, w1 = 0;  // 두 번째 색상

int mode = 1;
int SCENE_NO = 255;

int DIM  =  255;
int led_flag = 0;



// 효과 파라미터
int groupSize = 6;
float speed = 0.5;    // 이동 속도 (작으면 느려짐)
int frameDelay = 5;  // ms 단위 프레임 간격

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
    EAR_setAll(0, 0, 0, 0);
    //REAR_setAll(0, 0, 0, 0);
    SHOULDER_setAll(0, 0, 0, 0);
    HAND_setAll(0, 0, 0, 0);
    FOOT_setAll(0, 0, 0, 0);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 2) {
    Serial.println(SCENE_NO);
    All_Light_On(0, 0, 0, 130);
    delay(2000);
    All_Light_Off(0, 0, 0, 130, 30);      //dimmed off
    //breathe(0, 0, 0, 100, 3);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 3) {
    Serial.println(SCENE_NO);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 4) {            // SCENE NO 4 : Working
    Serial.println(SCENE_NO);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 5) {
    Serial.println(SCENE_NO);
    led_flag = 0;
    SCENE_NO = 255;

  }

  if (SCENE_NO == 6) {          // SCENE 5 : Communication
    Serial.println(SCENE_NO);
    listen(3);
    if (led_flag == 0) SCENE_NO = 255;
  }

  if (SCENE_NO == 7) {          // SCENE 6 : Emotion
    Serial.println(SCENE_NO);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 9) {
    //Serial.println(SCENE_NO);
    EAR_strip.clear();
    EAR_strip.show();
    SHOULDER_strip.clear();
    SHOULDER_strip.show();
    HAND_strip.clear();
    HAND_strip.show();
    FOOT_strip.clear();
    FOOT_strip.show();
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 21) {
    Serial.println(SCENE_NO);
    EAR_STATUS = 1 - EAR_STATUS;
    if (EAR_STATUS == 1) EAR_setAll(0, 0, 0, 150);
    else if (EAR_STATUS == 0) EAR_setAllOFF(0, 0, 0, 150, -1);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 22) {
    Serial.println(SCENE_NO);
    SHOULDER_STATUS = 1 - SHOULDER_STATUS;
    if (SHOULDER_STATUS == 1) SHOULDER_setAll(0, 0, 0, 150);
    else if (SHOULDER_STATUS == 0) SHOULDER_setAllOFF(0, 0, 0, 150, -1);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 23) {
    Serial.println(SCENE_NO);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 24) {
    Serial.println(SCENE_NO);
    HAND_STATUS = 1 - HAND_STATUS;
    if (HAND_STATUS == 1) HAND_setAll(0, 0, 0, 150);
    else if (HAND_STATUS == 0) HAND_setAllOFF(0, 0, 0, 150, -1);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 25) {
    Serial.println(SCENE_NO);
    FOOT_STATUS = 1 - FOOT_STATUS;
    if (FOOT_STATUS == 1) FOOT_setAll(0, 0, 0, 150);
    else if (FOOT_STATUS == 0) FOOT_setAllOFF(0, 0, 0, 150, -1);
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 26) {              // Shoulder Breathing
    Serial.println(SCENE_NO);
    breathe_Neck(0, 0, 0, 150, 2);
    if (led_flag == 0) SCENE_NO = 255;
  }

  if (SCENE_NO == 27) {              // Ear animation
    Serial.println(SCENE_NO);
    EAR_grd(1);
    listen(2);
    if (led_flag == 0) SCENE_NO = 255;
  }


  if (SCENE_NO == 41) {
    EAR_strip.setBrightness(10);
    SHOULDER_strip.setBrightness(10);
    HAND_strip.setBrightness(10);
    FOOT_strip.setBrightness(10);

    EAR_strip.show();
    SHOULDER_strip.show();
    HAND_strip.show();
    FOOT_strip.show();
    led_flag = 0;

    SCENE_NO = 255;
  }

  if (SCENE_NO == 42) {
    EAR_strip.setBrightness(30);
    SHOULDER_strip.setBrightness(30);
    HAND_strip.setBrightness(30);
    FOOT_strip.setBrightness(30);

    EAR_strip.show();
    SHOULDER_strip.show();
    HAND_strip.show();
    FOOT_strip.show();
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 43) {
    EAR_strip.setBrightness(50);
    SHOULDER_strip.setBrightness(50);
    HAND_strip.setBrightness(50);
    FOOT_strip.setBrightness(50);

    EAR_strip.show();
    SHOULDER_strip.show();
    HAND_strip.show();
    FOOT_strip.show();
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 44) {
    EAR_strip.setBrightness(90);
    SHOULDER_strip.setBrightness(90);
    HAND_strip.setBrightness(90);
    FOOT_strip.setBrightness(90);

    EAR_strip.show();
    SHOULDER_strip.show();
    HAND_strip.show();
    FOOT_strip.show();
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (SCENE_NO == 45) {
    EAR_strip.setBrightness(150);
    SHOULDER_strip.setBrightness(150);
    HAND_strip.setBrightness(150);
    FOOT_strip.setBrightness(150);

    EAR_strip.show();
    SHOULDER_strip.show();
    HAND_strip.show();
    FOOT_strip.show();
    led_flag = 0;
    SCENE_NO = 255;
  }

  if (BT_Serial.available()) {
    SCENE_NO = BT_Serial.read();
  }
}
