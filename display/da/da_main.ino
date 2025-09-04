/* DA Open Fridge Main Controller */

#include <Adafruit_NeoPixel.h>
#include "PIN_define.h"

#define PC_COMMAND Serial
#define DEZIN_COMMAND Serial2
#define BT_COMMAND Serial3

uint8_t SCENE_NO = 0;
uint8_t Phone_Command = 255;

Adafruit_NeoPixel NITTO_LEFT(NITTO_LEFT_NUM, NITTO_LEFT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel FRONT_LEFT(FRONT_LEFT_NUM, FRONT_LEFT_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel NITTO_RIGHT(NITTO_RIGHT_NUM, NITTO_RIGHT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel FRONT_RIGHT(FRONT_RIGHT_NUM, FRONT_RIGHT_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel CHILLER(CHILLER_NUM, CHILLER_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel TOP_LEVEL_FRONT(TOP_LEVEL_FRONT_NUM, TOP_LEVEL_FRONT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel TOP_LEVEL_BACK(TOP_LEVEL_BACK_NUM, TOP_LEVEL_BACK_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel MIDDLE_LEVEL_FRONT(MIDDLE_LEVEL_FRONT_NUM, MIDDLE_LEVEL_FRONT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel MIDDLE_LEVEL_BACK(MIDDLE_LEVEL_BACK_NUM, MIDDLE_LEVEL_BACK_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel BOT_LEVEL_FRONT(BOT_LEVEL_FRONT_NUM, BOT_LEVEL_FRONT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel BOT_LEVEL_BACK(BOT_LEVEL_BACK_NUM, BOT_LEVEL_BACK_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel SIDE_LEFT(SIDE_LEFT_NUM, SIDE_LEFT_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel SIDE_RIGHT(SIDE_RIGHT_NUM, SIDE_RIGHT_PIN, NEO_GRBW + NEO_KHZ800);


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
      break;

    case 1:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      LIGHT_SCENE_1();
      break;

    case 2:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      LIGHT_SCENE_2();
      break;

    case 3:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      LIGHT_SCENE_3();
      break;

    case 4:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      break;

    case 5:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      break;

    case 6:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      break;

    case 7:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      break;

    case 8:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      break;

    case 9:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      break;

    case 10:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      break;

    default:
      break;
  }
}


// BT Commnad incoming
void serialEvent3() {  // Phone -> Arduino command
  SCENE_NO = Serial3.read();
  //Serial.println(c);      // Arduino -> Control PC // BT setiing ==> Serial.write(c);
  //Serial2.println(c);     // Arduino -> Dezin Slave Arduino
}

void serialEvent() {  // Debug PC -> Arduino
  uint8_t c = Serial.read();
  Serial3.println(c);  // Arduino -> BT module , BT setiing ==> Serial3.write(c);
  Serial2.println(c);  // Arduino -> Control PC Command
}
