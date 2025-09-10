/* DA Open Fridge Main Controller */

#include <Adafruit_NeoPixel.h>
#include "PIN_define.h"

#define NITTO_LEFT_PIN      1
#define NITTO_LEFT_NUM      1

#define COVER_LEFT_PIN      1
#define COVER_LEFT_NUM      1

#define NITTO_RIGHT_PIN     1
#define NITTO_RIGHT_NUM     1

#define COVER_RIGHT_PIN     1
#define COVER_RIGHT_NUM     1

#define CHILLER_PIN         1
#define CHILLER_NUM         1

#define BASKET_PIN          1
#define BASKET_NUM          1

#define CENTER_PIN          1
#define CENTER_NUM          1

#define TOP_PIN 1
#define TOP_NUM 1

#define MID_PIN 1
#define MID_NUM 1

#define BOT_PIN 1
#define BOT_NUM 1 

#define CABI_L    4
#define CABI_R    5

#define PC_COMMAND Serial
#define DEZIN_COMMAND Serial2
#define BT_COMMAND Serial3


Adafruit_NeoPixel NITTO_LEFT(NITTO_LEFT_NUM, NITTO_LEFT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel COVER_LEFT(COVER_LEFT_NUM, COVER_LEFT_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel NITTO_RIGHT(NITTO_RIGHT_NUM, NITTO_RIGHT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel COVER_RIGHT(COVER_RIGHT_NUM, COVER_RIGHT_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel CHILLER(CHILLER_NUM, CHILLER_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel BASKET(BASKET_NUM, BASKET_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel CENTER(CENTER_NUM, CENTER_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel TOP(TOP_NUM, TOP_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel MID(MID_NUM, MID_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel BOT(BOT_NUM, BOT_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  PC_COMMAND.begin(9600);
  DEZIN_COMMAND.begin(9600);  // communication serial
  BT_COMMAND.begin(9600);     // BT serial

  LED_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (SCENE_NO) {
    case 0:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      LIGHT_SCENE_0();
      SCENE_NO = 255;
      break;

    case 1:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      LIGHT_SCENE_1();
      SCENE_NO = 255;
      break;

    case 2:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      LIGHT_SCENE_2();
      SCENE_NO = 255;
      break;

    case 3:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      LIGHT_SCENE_3();
      SCENE_NO = 255;
      break;

    case 4:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    case 5:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    case 6:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    case 7:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    case 8:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    case 9:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;


    case 50:  // Sequencial On
      PC_COMMAND.println(SCENE_NO);
      //DEZIN_COMMAND.println(SCENE_NO);
      Back_Light_test();
      SCENE_NO = 255;
      break;

    case 51:  // Normal on
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      Back_Light_All_On();
      SCENE_NO = 255;
      break;

    case 52:  // Sequencial Off
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    case 53:  // Normal Off
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    case 99:  // Initial
      PC_COMMAND.println(SCENE_NO);
      //DEZIN_COMMAND.println(SCENE_NO);
      Light_init();
      SCENE_NO = 255;
      break;

    default:
      SCENE_NO = 255;
      break;
  }
}


void serialEvent3() {  // Phone -> Arduino command
  SCENE_NO = Serial3.read();
  DEZIN_COMMAND.println(SCENE_NO);  // Arduino -> Dezin Slave Arduino
  Serial.println(SCENE_NO);         // Arduino -> Control PC // BT setiing ==> Serial.write(c);
}

void serialEvent() {  // Debug PC -> Arduino
  char serial_data = Serial.read();
  SCENE_NO = serial_data - '0';
  // Serial3.println(c);  // Arduino -> BT module , BT setiing ==> Serial3.write(c);
  // Serial2.println(c);  // Arduino -> Control PC Command
  //Serial.println(SCENE_NO);
}

void LED_initialize() {

  NITTO_LEFT.begin();
  NITTO_LEFT.show();
  NITTO_LEFT.setBrightness(100);
 
  NITTO_RIGHT.begin();
  NITTO_RIGHT.show();
  NITTO_RIGHT.setBrightness(100);
 
  COVER_LEFT.begin();
  COVER_LEFT.show();
  COVER_LEFT.setBrightness(100);

  COVER_RIGHT.begin();
  COVER_RIGHT.show();
  COVER_RIGHT.setBrightness(100);
 
  CHILLER.begin();
  CHILLER.show();
  CHILLER.setBrightness(100);
 
  BASKET.begin();
  BASKET.show();
  BASKET.setBrightness(100);
 
  CENTER.begin();
  CENTER.show();
  CENTER.setBrightness(100);

  TOP.begin();
  TOP.show();
  MID.setBrightness(100);

  MID.begin();
  MID.show();
  MID.setBrightness(100);

  BOT.begin();
  BOT.show();
  BOT.setBrightness(100);
}

void setAll_NITTO_LEFT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NITTO_LEFT_NUM; i++) {
    NITTO_LEFT.setPixelColor(i, NITTO_LEFT.Color(red, green, blue, white));
  }
  NITTO_LEFT.show();
}

void setAll_NITTO_RIGHT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NITTO_RIGHT_NUM; i++) {
    NITTO_RIGHT.setPixelColor(i, NITTO_RIGHT.Color(red, green, blue, white));
  }
  NITTO_RIGHT.show();
}

void setAll_COVER_LEFT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < COVER_LEFT_NUM; i++) {
    COVER_LEFT.setPixelColor(i, COVER_LEFT.Color(red, green, blue, white));
  }
  COVER_LEFT.show();
}

void setAll_COVER_RIGHT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < COVER_RIGHT_NUM; i++) {
    COVER_RIGHT.setPixelColor(i, COVER_RIGHT.Color(red, green, blue, white));
  }
  COVER_RIGHT.show();
}

void setAll_CHILLER(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < CHILLER_NUM; i++) {
    CHILLER.setPixelColor(i, CHILLER.Color(red, green, blue, white));
  }
  CHILLER.show();
}

void setAll_BASKET(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BASKET_NUM; i++) {
    BASKET.setPixelColor(i, BASKET.Color(red, green, blue, white));
  }
  BASKET.show();
}

void setAll_CENTER(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < CENTER_NUM; i++) {
    CENTER.setPixelColor(i, CENTER.Color(red, green, blue, white));
  }
  CENTER.show();
}

void setAll_TOP(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < TOP_NUM; i++) {
    TOP.setPixelColor(i, TOP.Color(red, green, blue, white));
  }
  TOP.show();
}

void setAll_MID(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < MID_NUM; i++) {
    MID.setPixelColor(i, MID.Color(red, green, blue, white));
  }
  MID.show();
}

void setAll_MID14(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < MID_NUM/4; i++) {
    MID.setPixelColor(i, MID.Color(red, green, blue, white));
    MID.setPixelColor(75+i, MID.Color(red, green, blue, white));
  }
  MID.show();
}

void setAll_BOT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BOT_NUM; i++) {
    BOT.setPixelColor(i, BOT.Color(red, green, blue, white));
  }
  BOT.show();
}

void setAll_BOT23(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BOT_NUM/2; i++) {
    BOT.setPixelColor(25+i, BOT.Color(red, green, blue, white));
  }
  BOT.show();
}

void setAll_BOT2(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BOT_NUM/4; i++) {
    BOT.setPixelColor(25+i, BOT.Color(red, green, blue, white));
  }
  BOT.show();
}
