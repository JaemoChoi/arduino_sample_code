/* DA Open Fridge Main Controller */

#include <Adafruit_NeoPixel.h>
#include "PIN_define.h"

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
  Serial.begin(9600);
  Serial2.begin(9600);  // communication serial
  Serial3.begin(9600);  // BT serial

  LED_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:

}


// BT Commnad incoming
void serialEvent3() {
  uint8_t c = Serial3.read();
  Serial.println(c);
  Serial2.println(c);
}
