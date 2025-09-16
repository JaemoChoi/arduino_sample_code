
/* DA Open Fridge Main Controller */
#include <Adafruit_NeoPixel.h>
#include "PIN_define.h"

#define PC_COMMAND Serial
#define DEZIN_COMMAND Serial2
#define BT_COMMAND Serial3

#define TOP_BACK_NUM 126
#define TOP_BACK_PIN A1

int SCENE_NO = 0;
uint8_t Phone_Command = 255;

Adafruit_NeoPixel TOP_BACK(TOP_BACK_NUM, TOP_BACK_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  PC_COMMAND.begin(9600);
  DEZIN_COMMAND.begin(9600);  // communication serial
  BT_COMMAND.begin(9600);     // BT serial

  pinMode(TOP_FRONT, OUTPUT);
  pinMode(TOP_MID, OUTPUT);
  pinMode(DRAW_EDGE, OUTPUT);
  pinMode(DRAW_BACK, OUTPUT);
  pinMode(PDLC, OUTPUT);

  digitalWrite(TOP_FRONT, LOW);
  digitalWrite(TOP_MID, LOW);
  digitalWrite(DRAW_EDGE, LOW);
  digitalWrite(DRAW_BACK, LOW);
  digitalWrite(PDLC, HIGH);  // PDLC OFF

  TOP_BACK.begin();
  TOP_BACK.show();  // Initialize all pixels to 'off'
  Light_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (SCENE_NO) {
    case 0:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      //LIGHT_SCENE_0();
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
      //LIGHT_SCENE_4();
      SCENE_NO = 255;
      break;

    case 5:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      //LIGHT_SCENE_5();
      SCENE_NO = 255;
      break;

    case 6:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      //LIGHT_SCENE_6();
      SCENE_NO = 255;
      break;

    case 7:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      //LIGHT_SCENE_7();
      SCENE_NO = 255;
      break;

    case 8:
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      //LIGHT_SCENE_8();
      SCENE_NO = 255;
      break;

    case 21:
      TOP_FRONT_STATUS = 1 - TOP_FRONT_STATUS;
      if (TOP_FRONT_STATUS == 1) digitalWrite(TOP_FRONT, 1);
      if (TOP_FRONT_STATUS == 0) digitalWrite(TOP_FRONT, 0);
      SCENE_NO = 255;
      break;

    case 22:
      TOP_MID_STATUS = 1 - TOP_MID_STATUS;
      if (TOP_MID_STATUS == 1) digitalWrite(TOP_MID, 1);
      if (TOP_MID_STATUS == 0) digitalWrite(TOP_MID, 0);
      SCENE_NO = 255;
      break;

    case 23:
      DRAW_EDGE_STATUS = 1 - DRAW_EDGE_STATUS;
      if (DRAW_EDGE_STATUS == 1) digitalWrite(DRAW_EDGE, 1);
      if (DRAW_EDGE_STATUS == 0) digitalWrite(DRAW_EDGE, 0);
      SCENE_NO = 255;
      break;

    case 24:
      DRAW_BACK_STATUS = 1 - DRAW_BACK_STATUS;
      if (DRAW_BACK_STATUS == 1) digitalWrite(DRAW_BACK, 1);
      if (DRAW_BACK_STATUS == 0) digitalWrite(DRAW_BACK, 0);
      SCENE_NO = 255;
      break;

    case 25:
      TOP_BACK1_STATUS = 1 - TOP_BACK1_STATUS;
      if (TOP_BACK1_STATUS == 1) TOP_BACK_LED_SET1(0, 0, 0, 150);
      if (TOP_BACK1_STATUS == 0) TOP_BACK_LED_SET1(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 26:
      TOP_BACK2_STATUS = 1 - TOP_BACK2_STATUS;
      if (TOP_BACK2_STATUS == 1) TOP_BACK_LED_SET2(0, 0, 0, 150);
      if (TOP_BACK2_STATUS == 0) TOP_BACK_LED_SET2(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 27:
      TOP_BACK3_STATUS = 1 - TOP_BACK3_STATUS;
      if (TOP_BACK3_STATUS == 1) TOP_BACK_LED_SET3(0, 0, 0, 150);
      if (TOP_BACK3_STATUS == 0) TOP_BACK_LED_SET3(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 28:
      TOP_BACK4_STATUS = 1 - TOP_BACK4_STATUS;
      if (TOP_BACK4_STATUS == 1) TOP_BACK_LED_SET4(0, 0, 0, 150);
      if (TOP_BACK4_STATUS == 0) TOP_BACK_LED_SET4(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 29:
      TOP_BACK5_STATUS = 1 - TOP_BACK5_STATUS;
      if (TOP_BACK5_STATUS == 1) TOP_BACK_LED_SET5(0, 0, 0, 150);
      if (TOP_BACK5_STATUS == 0) TOP_BACK_LED_SET5(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 30:
      TOP_BACK6_STATUS = 1 - TOP_BACK6_STATUS;
      if (TOP_BACK6_STATUS == 1) TOP_BACK_LED_SET6(0, 0, 0, 150);
      if (TOP_BACK6_STATUS == 0) TOP_BACK_LED_SET6(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 31:
      TOP_BACK_STATUS = 1 - TOP_BACK_STATUS;
      if (TOP_BACK_STATUS == 1) setAll(0, 0, 0, 150);
      if (TOP_BACK_STATUS == 0) setAll(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 40:
      PDLC_STATUS = 1 - PDLC_STATUS;
      if (PDLC_STATUS == 1) digitalWrite(PDLC, HIGH);
      if (PDLC_STATUS == 0) digitalWrite(PDLC, LOW);
      SCENE_NO = 255;
      break;

    case 50:
      // Send to Dezin Command
      Serial2.write(80);  // close
      SCENE_NO = 255;
      break;

    case 51:
      // Send to Dezin Command
      Serial2.write(81);  // Open
      SCENE_NO = 255;
      break;

    case 52:
      // Send to Dezin Command
      Serial2.write(82);  // ice
      SCENE_NO = 255;
      break;

    case 99:
      // Pause
      PC_COMMAND.println(SCENE_NO);
      SCENE_NO = 255;
      break;

    default:
      SCENE_NO = 255;
      break;
  }
}


// BT Commnad incoming
void serialEvent3() {  // Phone -> Arduino command
  SCENE_NO = Serial3.read();
  //Serial.println(SCENE_NO);  // Arduino -> Control PC // BT setiing ==> Serial.write(c);
  //Serial2.println(c);     // Arduino -> Dezin Slave Arduino
}

void serialEvent() {  // Debug PC -> Arduino
  int16_t serial_data = Serial.parseInt();
  //char serial_data = Serial.read();
  // SCENE_NO = serial_data - '0';
  // Serial3.println(c);  // Arduino -> BT module , BT setiing ==> Serial3.write(c);
  // Serial2.println(c);  // Arduino -> Control PC Command
  //Serial.println(SCENE_NO);

  if (serial_data == 4) digitalWrite(PDLC, HIGH);
  if (serial_data == 5) digitalWrite(PDLC, LOW);
  if (serial_data == 6) analogWrite(DRAW_BACK, 255);
  if (serial_data == 7) analogWrite(DRAW_BACK, 0);
  //if (serial_data == 8) TOP_BACK_TEST();
}
