
/* DA Open Fridge Main Controller */
#include <Adafruit_NeoPixel.h>
#include "PIN_define.h"

#define PC_COMMAND Serial
#define DEZIN_COMMAND Serial2
#define BT_COMMAND Serial3

#define S1_PIN A1
#define S2_PIN A2
#define S3_PIN A3
#define S_NUM 284

int SCENE_NO = 0;
uint8_t Phone_Command = 255;

Adafruit_NeoPixel S1(S_NUM, S1_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel S2(S_NUM, S2_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel S3(S_NUM, S3_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  PC_COMMAND.begin(9600);
  DEZIN_COMMAND.begin(9600);  // communication serial
  BT_COMMAND.begin(9600);     // BT serial

  // Light All Off
  analogWrite(SLL, 0);
  analogWrite(SLR, 0);
  analogWrite(BPL, 0);

  S1.begin();
  S1.show();
  S2.begin();
  S2.show();
  S3.begin();
  S3.show();
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

    case 9:
      PC_COMMAND.println(SCENE_NO);
      
      SCENE_NO = 255;
      break;

    case 10:
      PC_COMMAND.println(SCENE_NO);
      
      SCENE_NO = 255;
      break;

    case 21:
      S11_STATUS = 1 - S11_STATUS;
      if (S11_STATUS == 1) S1_SET1(0, 0, 0, 200);
      if (S11_STATUS == 0) S1_SET1(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 22:
      S12_STATUS = 1 - S12_STATUS;
      if (S12_STATUS == 1) S1_SET2(0, 0, 0, 200);
      if (S12_STATUS == 0) S1_SET2(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 23:
      S13_STATUS = 1 - S13_STATUS;
      if (S13_STATUS == 1) S1_SET3(0, 0, 0, 200);
      if (S13_STATUS == 0) S1_SET3(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 24:
      S14_STATUS = 1 - S14_STATUS;
      if (S14_STATUS == 1) S1_SET4(0, 0, 0, 200);
      if (S14_STATUS == 0) S1_SET4(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 25:
      S21_STATUS = 1 - S21_STATUS;
      if (S21_STATUS == 1) S2_SET1(0, 0, 0, 200);
      if (S21_STATUS == 0) S2_SET1(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 26:
      S22_STATUS = 1 - S22_STATUS;
      if (S22_STATUS == 1) S2_SET2(0, 0, 0, 200);
      if (S22_STATUS == 0) S2_SET2(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 27:
      S23_STATUS = 1 - S23_STATUS;
      if (S23_STATUS == 1) S2_SET3(0, 0, 0, 200);
      if (S23_STATUS == 0) S2_SET3(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 28:
      S24_STATUS = 1 - S24_STATUS;
      if (S24_STATUS == 1) S2_SET4(0, 0, 0, 200);
      if (S24_STATUS == 0) S2_SET4(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 29:
      S31_STATUS = 1 - S31_STATUS;
      if (S31_STATUS == 1) S3_SET1(0, 0, 0, 200);
      if (S31_STATUS == 0) S3_SET1(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 30:
      S32_STATUS = 1 - S32_STATUS;
      if (S32_STATUS == 1) S3_SET2(0, 0, 0, 200);
      if (S32_STATUS == 0) S3_SET2(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 31:
      S33_STATUS = 1 - S33_STATUS;
      if (S33_STATUS == 1) S3_SET3(0, 0, 0, 200);
      if (S33_STATUS == 0) S3_SET3(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 32:
      S34_STATUS = 1 - S34_STATUS;
      if (S34_STATUS == 1) S3_SET4(0, 0, 0, 200);
      if (S34_STATUS == 0) S3_SET4(0, 0, 0, 0);
      SCENE_NO = 255;
      break;

    case 40:
      SLL_STATUS = 1 - SLL_STATUS;
      if (SLL_STATUS == 1) SLL_ON();
      if (SLL_STATUS == 0) SLL_OFF();
      SCENE_NO = 255;
      break;

    case 41:
      SLR_STATUS = 1 - SLR_STATUS;
      if (SLR_STATUS == 1) SLR_ON();
      if (SLR_STATUS == 0) SLR_OFF();
      SCENE_NO = 255;
      break;

    case 50:
      // Send to Dezin Command
      DEZIN_COMMAND.write(80);  // Door Left Open
      SCENE_NO = 255;
      break;

    case 51:
      // Send to Dezin Command
      DEZIN_COMMAND.write(81);  // Door Right Open
      SCENE_NO = 255;
      break;

    case 52:
      // Send to Dezin Command
      DEZIN_COMMAND.write(82);  // Door All Open
      SCENE_NO = 255;
      break;

    case 53:
      // Send to Dezin Command
      DEZIN_COMMAND.write(83);  // DRAWER Position 0
      SCENE_NO = 255;
      break;

    case 54:
      // Send to Dezin Command
      DEZIN_COMMAND.write(83);  // DRAWER Position 2
      SCENE_NO = 255;
      break;

    case 55:
      // Send to Dezin Command
      DEZIN_COMMAND.write(83);  // Sliding L
      SCENE_NO = 255;
      break;

    case 56:
      // Send to Dezin Command
      DEZIN_COMMAND.write(83);  // Sliding R
      SCENE_NO = 255;
      break;

    case 57:
      // Send to Dezin Command
      DEZIN_COMMAND.write(83);  // Chiller
      SCENE_NO = 255;
      break;


    case 60:
      // DRAWER Positon 1 => 145
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 61:
      // DRAWER Positon 1 => 155
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 62:
      // DRAWER Positon 1 => 165
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 63:
      // DRAWER Positon 1 => 175
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 64:
      // DRAWER Positon 1 => 185
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 65:
      // DRAWER Positon 1 => 195
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 66:
      // DRAWER Positon 1 => 205
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 67:
      // DRAWER Positon 1 => 215
      DEZIN_COMMAND.write(84);
      SCENE_NO = 255;
      break;

    case 68:
      // DRAWER Positon 1 => 225
      DEZIN_COMMAND.write(84);
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
}
