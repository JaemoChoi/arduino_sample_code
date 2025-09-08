
/* DA Open Fridge Main Controller */
#include <Adafruit_NeoPixel.h>
#include "PIN_define.h"

#define PC_COMMAND Serial
#define DEZIN_COMMAND Serial2
#define BT_COMMAND Serial3

int SCENE_NO = 0;
uint8_t Phone_Command = 255;

void setup() {
  // put your setup code here, to run once:
  PC_COMMAND.begin(9600);
  DEZIN_COMMAND.begin(9600);  // communication serial
  BT_COMMAND.begin(9600);     // BT serial
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


// BT Commnad incoming
void serialEvent3() {  // Phone -> Arduino command
  SCENE_NO = Serial3.read();
  //Serial.println(SCENE_NO);  // Arduino -> Control PC // BT setiing ==> Serial.write(c);
  //Serial2.println(c);     // Arduino -> Dezin Slave Arduino
}

void serialEvent() {  // Debug PC -> Arduino
  char serial_data = Serial.read();
  SCENE_NO = serial_data - '0';
  // Serial3.println(c);  // Arduino -> BT module , BT setiing ==> Serial3.write(c);
  // Serial2.println(c);  // Arduino -> Control PC Command
  //Serial.println(SCENE_NO);
}
