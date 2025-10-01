
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

  pinMode(SLD1, OUTPUT);
  pinMode(SLD2, OUTPUT);
  pinMode(SLD3, OUTPUT);
  pinMode(SRD1, OUTPUT);
  pinMode(SRD2, OUTPUT);
  pinMode(SRD3, OUTPUT);

  pinMode(SLB1, OUTPUT);
  pinMode(SLB2, OUTPUT);
  pinMode(SLB3, OUTPUT);
  pinMode(SLB4, OUTPUT);

  pinMode(SRB1, OUTPUT);
  pinMode(SRB2, OUTPUT);
  pinMode(SRB3, OUTPUT);
  pinMode(SRB4, OUTPUT);

  pinMode(PDLCL, OUTPUT);
  pinMode(PDLCR, OUTPUT);

  digitalWrite(SLD1, LOW);
  digitalWrite(SLD2, LOW);
  digitalWrite(SLD3, LOW);
  digitalWrite(SRD1, LOW);
  digitalWrite(SRD2, LOW);
  digitalWrite(SRD3, LOW);

  digitalWrite(SLB1, LOW);
  digitalWrite(SLB2, LOW);
  digitalWrite(SLB3, LOW);
  digitalWrite(SLB4, LOW);
  digitalWrite(SRB1, LOW);
  digitalWrite(SRB2, LOW);
  digitalWrite(SRB3, LOW);
  digitalWrite(SRB4, LOW);

  digitalWrite(PDLCL, LOW);  // ON
  digitalWrite(PDLCR, LOW);  // ON
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (SCENE_NO) {
    case 0:
      PC_COMMAND.println(SCENE_NO);
      Back_light_all();
      SCENE_NO = 255;
      break;

    case 1:
      PC_COMMAND.println(SCENE_NO);  // Cat stand-by
      digitalWrite(PDLCL, LOW);      // ON
      digitalWrite(PDLCR, LOW);      // ON
      Back_light_all();
      SCENE_NO = 255;
      break;

    case 2:
      PC_COMMAND.println(SCENE_NO);  // Cat stand-by
      digitalWrite(PDLCL, LOW);      // ON
      digitalWrite(PDLCR, LOW);      // ON
      Back_light_all();
      SCENE_NO = 255;
      break;

    case 3:
      PC_COMMAND.println(SCENE_NO);  // Cat stand-by
      digitalWrite(PDLCL, LOW);      // ON
      digitalWrite(PDLCR, LOW);      // ON
      Back_light_all();
      SCENE_NO = 255;
      break;

    case 4:
      PC_COMMAND.println(SCENE_NO);  //Mama
      digitalWrite(PDLCL, LOW);      // ON
      digitalWrite(PDLCR, LOW);      // ON
      for (float bright = 0; bright < 256; bright++) {
        analogWrite(BLR1, bright);
        analogWrite(BLR2, bright / 8);
        analogWrite(BLR3, bright / 8);
        analogWrite(BLR4, bright / 8);
        analogWrite(BLL1, bright / 8);
        analogWrite(BLL2, bright / 8);
        analogWrite(BLL3, bright / 8);
        analogWrite(BLL4, bright);
        analogWrite(BLRT, bright);
        analogWrite(BLLT, bright / 8);
        delay(5);
      }
      SCENE_NO = 255;
      break;

    case 5:
      PC_COMMAND.println(SCENE_NO);  // Papa
      digitalWrite(PDLCL, LOW);      // ON
      digitalWrite(PDLCR, LOW);      // ON
      for (float bright = 0; bright < 256; bright++) {
        analogWrite(BLR1, bright / 8);
        analogWrite(BLR2, bright / 8);
        analogWrite(BLR3, bright / 8);
        analogWrite(BLR4, bright / 8);
        analogWrite(BLL1, bright);
        analogWrite(BLL2, bright / 8);
        analogWrite(BLL3, bright / 8);
        analogWrite(BLL4, bright / 8);
        analogWrite(BLRT, bright / 8);
        analogWrite(BLLT, bright);
        delay(5);
      }
      SCENE_NO = 255;
      break;

    case 6:
      PC_COMMAND.println(SCENE_NO);  //Kidz
      digitalWrite(PDLCL, LOW);      // ON
      digitalWrite(PDLCR, LOW);      // ON
      for (float bright = 0; bright < 256; bright++) {
        analogWrite(BLR1, bright / 8);
        analogWrite(BLR2, bright / 8);
        analogWrite(BLR3, bright / 8);
        analogWrite(BLR4, bright);
        analogWrite(BLL1, bright / 8);
        analogWrite(BLL2, bright / 8);
        analogWrite(BLL3, bright / 8);
        analogWrite(BLL4, bright / 8);
        analogWrite(BLRT, bright / 8);
        analogWrite(BLLT, bright / 8);
        delay(5);
      }
      SCENE_NO = 255;
      break;

    case 7:
      PC_COMMAND.println(SCENE_NO);
      digitalWrite(PDLCL, HIGH);  //Off
      digitalWrite(PDLCR, HIGH);  //Off
      Back_light_all();
      SCENE_NO = 255;
      break;

    case 8:
      PC_COMMAND.println(SCENE_NO);
      digitalWrite(PDLCL, LOW);  //On
      digitalWrite(PDLCR, LOW);  //On

      analogWrite(SLB1, 255);  // PDLC 2
      analogWrite(SLB2, 255);  // PDLC 6
      analogWrite(SLB3, 255);  // LEFT PDLC
      analogWrite(SLB4, 255);  // RIGHT PDLC

      analogWrite(SRB1, 255);  // PDLC 2
      analogWrite(SRB2, 255);  // PDLC 6
      analogWrite(SRB3, 255);  // LEFT PDLC
      analogWrite(SRB4, 255);  // RIGHT PDLC

      Center_dim_On();

      delay(3000);
      digitalWrite(PDLCL, HIGH);  //On
      digitalWrite(PDLCR, HIGH);  //On

      Side_dim_On();

      SCENE_NO = 255;
      break;

    case 9:
      PC_COMMAND.println(SCENE_NO);
      digitalWrite(PDLCL, LOW);  //ON
      digitalWrite(PDLCR, LOW);  //ON

      analogWrite(BLR1, 0);
      analogWrite(BLR2, 0);
      analogWrite(BLR3, 0);
      analogWrite(BLR4, 0);
      analogWrite(BLL1, 0);
      analogWrite(BLL2, 0);
      analogWrite(BLL3, 0);
      analogWrite(BLL4, 0);
      analogWrite(BLRT, 0);
      analogWrite(BLLT, 0);

      for (int bright = 0; bright < 256; bright++) {
        analogWrite(SLB1, bright);  // PDLC 2
        analogWrite(SLB2, bright);  // PDLC 6
        analogWrite(SLB3, bright);  // LEFT PDLC
        analogWrite(SLB4, bright);  // RIGHT PDLC

        analogWrite(SRB1, bright);  // PDLC 2
        analogWrite(SRB2, bright);  // PDLC 6
        analogWrite(SRB3, bright);  // LEFT PDLC
        analogWrite(SRB4, bright);  // RIGHT PDLC

        delay(5);
      }
      SCENE_NO = 255;
      break;

    case 10:
      PC_COMMAND.println(SCENE_NO);
      digitalWrite(PDLCL, LOW);  //On
      digitalWrite(PDLCR, LOW);  //On

      analogWrite(SLB1, 255);  // PDLC 2
      analogWrite(SLB2, 255);  // PDLC 6
      analogWrite(SLB3, 255);  // LEFT PDLC
      analogWrite(SLB4, 255);  // RIGHT PDLC

      analogWrite(SRB1, 255);  // PDLC 2
      analogWrite(SRB2, 255);  // PDLC 6
      analogWrite(SRB3, 255);  // LEFT PDLC
      analogWrite(SRB4, 255);  // RIGHT PDLC

      Center_dim_On();

      delay(3000);
      digitalWrite(PDLCL, HIGH);  //On
      digitalWrite(PDLCR, HIGH);  //On

      Side_dim_On();

      SCENE_NO = 255;
      break;


    case 11:
      PC_COMMAND.println(SCENE_NO);
      digitalWrite(PDLCL, LOW);  //On
      digitalWrite(PDLCR, LOW);  //On

      analogWrite(SLB1, 255);  // PDLC 2
      analogWrite(SLB2, 255);  // PDLC 6
      analogWrite(SLB3, 255);  // LEFT PDLC
      analogWrite(SLB4, 255);  // RIGHT PDLC

      analogWrite(SRB1, 255);  // PDLC 2
      analogWrite(SRB2, 255);  // PDLC 6
      analogWrite(SRB3, 255);  // LEFT PDLC
      analogWrite(SRB4, 255);  // RIGHT PDLC

      Center_dim_On();

      delay(3000);
      digitalWrite(PDLCL, HIGH);  //On
      digitalWrite(PDLCR, HIGH);  //On

      Side_dim_On();

      SCENE_NO = 255;
      break;


    case 12:
      PC_COMMAND.println(SCENE_NO);
      digitalWrite(PDLCL, LOW);  //On
      digitalWrite(PDLCR, LOW);  //On

      analogWrite(SLB1, 255);  // PDLC 2
      analogWrite(SLB2, 255);  // PDLC 6
      analogWrite(SLB3, 255);  // LEFT PDLC
      analogWrite(SLB4, 255);  // RIGHT PDLC

      analogWrite(SRB1, 255);  // PDLC 2
      analogWrite(SRB2, 255);  // PDLC 6
      analogWrite(SRB3, 255);  // LEFT PDLC
      analogWrite(SRB4, 255);  // RIGHT PDLC

      Center_dim_On();

      delay(3000);
      digitalWrite(PDLCL, HIGH);  //On
      digitalWrite(PDLCR, HIGH);  //On

      Side_dim_On();

      SCENE_NO = 255;
      break;

    case 22:
      SLD1_STATUS = 1 - SLD1_STATUS;
      if (SLD1_STATUS == 1) analogWrite(SLD1, 255);
      if (SLD1_STATUS == 0) analogWrite(SLD1, 0);
      SCENE_NO = 255;
      break;

    case 23:
      SLD2_STATUS = 1 - SLD2_STATUS;
      if (SLD2_STATUS == 1) analogWrite(SLD2, 255);
      if (SLD2_STATUS == 0) analogWrite(SLD2, 0);
      SCENE_NO = 255;
      break;

    case 24:
      SLD3_STATUS = 1 - SLD3_STATUS;
      if (SLD3_STATUS == 1) analogWrite(SLD3, 255);
      if (SLD3_STATUS == 0) analogWrite(SLD3, 0);
      SCENE_NO = 255;
      break;

    case 25:
      SRD1_STATUS = 1 - SRD1_STATUS;
      if (SRD1_STATUS == 1) analogWrite(SRD1, 255);
      if (SRD1_STATUS == 0) analogWrite(SRD1, 0);
      SCENE_NO = 255;
      break;

    case 26:
      SRD2_STATUS = 1 - SRD2_STATUS;
      if (SRD2_STATUS == 1) analogWrite(SRD2, 255);
      if (SRD2_STATUS == 0) analogWrite(SRD2, 0);
      SCENE_NO = 255;
      break;

    case 27:
      SRD3_STATUS = 1 - SRD3_STATUS;
      if (SRD3_STATUS == 1) analogWrite(SRD3, 255);
      if (SRD3_STATUS == 0) analogWrite(SRD3, 0);
      SCENE_NO = 255;
      break;

    case 30:
      SLB1_STATUS = 1 - SLB1_STATUS;
      if (SLB1_STATUS == 1) analogWrite(SLB1, 255);
      if (SLB1_STATUS == 0) analogWrite(SLB1, 0);
      SCENE_NO = 255;
      break;

    case 31:
      SLB2_STATUS = 1 - SLB2_STATUS;
      if (SLB2_STATUS == 1) analogWrite(SLB2, 255);
      if (SLB2_STATUS == 0) analogWrite(SLB2, 0);
      SCENE_NO = 255;
      break;

    case 32:
      SLB3_STATUS = 1 - SLB3_STATUS;
      if (SLB3_STATUS == 1) analogWrite(SLB3, 255);
      if (SLB3_STATUS == 0) analogWrite(SLB3, 0);
      SCENE_NO = 255;
      break;

    case 33:
      SLB4_STATUS = 1 - SLB4_STATUS;
      if (SLB4_STATUS == 1) analogWrite(SLB4, 255);
      if (SLB4_STATUS == 0) analogWrite(SLB4, 0);
      SCENE_NO = 255;
      break;

    case 34:
      SRB1_STATUS = 1 - SRB1_STATUS;
      if (SRB1_STATUS == 1) analogWrite(SRB1, 255);
      if (SRB1_STATUS == 0) analogWrite(SRB1, 0);
      SCENE_NO = 255;
      break;

    case 35:
      SRB2_STATUS = 1 - SRB2_STATUS;
      if (SRB2_STATUS == 1) analogWrite(SRB2, 255);
      if (SRB2_STATUS == 0) analogWrite(SRB2, 0);
      SCENE_NO = 255;
      break;

    case 36:
      SRB3_STATUS = 1 - SRB3_STATUS;
      if (SRB3_STATUS == 1) analogWrite(SRB3, 255);
      if (SRB3_STATUS == 0) analogWrite(SRB3, 0);
      SCENE_NO = 255;
      break;

    case 37:
      SRB4_STATUS = 1 - SRB4_STATUS;
      if (SRB4_STATUS == 1) analogWrite(SRB4, 255);
      if (SRB4_STATUS == 0) analogWrite(SRB4, 0);
      SCENE_NO = 255;
      break;

    case 38:
      PDLCL_STATUS = 1 - PDLCL_STATUS;
      if (PDLCL_STATUS == 1) digitalWrite(PDLCL, HIGH);
      if (PDLCL_STATUS == 0) digitalWrite(PDLCL, LOW);
      SCENE_NO = 255;
      break;

    case 39:
      PDLCR_STATUS = 1 - PDLCR_STATUS;
      if (PDLCR_STATUS == 1) digitalWrite(PDLCR, HIGH);
      if (PDLCR_STATUS == 0) digitalWrite(PDLCR, LOW);
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
      Back_Light_All_Off();
      SCENE_NO = 255;
      break;

    case 53:  // Normal Off
      PC_COMMAND.println(SCENE_NO);
      DEZIN_COMMAND.println(SCENE_NO);
      Back_Light_Normal_All_Off();
      SCENE_NO = 255;
      break;

    case 61:
      BLR1_STATUS = 1 - BLR1_STATUS;
      if (BLR1_STATUS == 1) analogWrite(BLR1, 255);
      if (BLR1_STATUS == 0) analogWrite(BLR1, 0);
      SCENE_NO = 255;
      break;

    case 62:
      BLR2_STATUS = 1 - BLR2_STATUS;
      if (BLR2_STATUS == 1) analogWrite(BLR2, 255);
      if (BLR2_STATUS == 0) analogWrite(BLR2, 0);
      SCENE_NO = 255;
      break;

    case 63:
      BLR3_STATUS = 1 - BLR3_STATUS;
      if (BLR3_STATUS == 1) analogWrite(BLR3, 255);
      if (BLR3_STATUS == 0) analogWrite(BLR3, 0);
      SCENE_NO = 255;
      break;

    case 64:
      BLR4_STATUS = 1 - BLR4_STATUS;
      if (BLR4_STATUS == 1) analogWrite(BLR4, 255);
      if (BLR4_STATUS == 0) analogWrite(BLR4, 0);
      SCENE_NO = 255;
      break;

    case 65:
      BLRT_STATUS = 1 - BLRT_STATUS;
      if (BLRT_STATUS == 1) analogWrite(BLRT, 255);
      if (BLRT_STATUS == 0) analogWrite(BLRT, 0);
      SCENE_NO = 255;
      break;

    case 71:
      BLL1_STATUS = 1 - BLL1_STATUS;
      if (BLL1_STATUS == 1) analogWrite(BLL1, 255);
      if (BLL1_STATUS == 0) analogWrite(BLL1, 0);
      SCENE_NO = 255;
      break;

    case 72:
      BLL2_STATUS = 1 - BLL2_STATUS;
      if (BLL2_STATUS == 1) analogWrite(BLL2, 255);
      if (BLL2_STATUS == 0) analogWrite(BLL2, 0);
      SCENE_NO = 255;
      break;

    case 73:
      BLL3_STATUS = 1 - BLL3_STATUS;
      if (BLL3_STATUS == 1) analogWrite(BLL3, 255);
      if (BLL3_STATUS == 0) analogWrite(BLL3, 0);
      SCENE_NO = 255;
      break;

    case 74:
      BLL4_STATUS = 1 - BLL4_STATUS;
      if (BLL4_STATUS == 1) analogWrite(BLL4, 255);
      if (BLL4_STATUS == 0) analogWrite(BLL4, 0);
      SCENE_NO = 255;
      break;

    case 75:
      BLLT_STATUS = 1 - BLLT_STATUS;
      if (BLLT_STATUS == 1) analogWrite(BLLT, 255);
      if (BLLT_STATUS == 0) analogWrite(BLLT, 0);
      SCENE_NO = 255;
      break;

    case 99:
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

  if (serial_data == 4) analogWrite(BLL1, 255);
  if (serial_data == 5) analogWrite(BLL2, 255);
  if (serial_data == 6) analogWrite(BLL3, 255);
  if (serial_data == 7) analogWrite(BLL4, 255);
  if (serial_data == 8) analogWrite(BLLT, 255);
  if (serial_data == 9) analogWrite(BLR1, 255);
  if (serial_data == 10) analogWrite(BLR2, 255);
  if (serial_data == 11) analogWrite(BLR3, 255);
  if (serial_data == 12) analogWrite(BLR4, 255);
  if (serial_data == 13) analogWrite(BLRT, 255);

  // Down Light
  if (serial_data == 21) digitalWrite(SLD1, HIGH);
  if (serial_data == 22) digitalWrite(SLD2, HIGH);
  if (serial_data == 23) digitalWrite(SLD3, HIGH);

  if (serial_data == 24) digitalWrite(SRD1, HIGH);
  if (serial_data == 25) digitalWrite(SRD2, HIGH);
  if (serial_data == 26) digitalWrite(SRD3, HIGH);
  // BackSide Light
  if (serial_data == 31) digitalWrite(SLB1, HIGH);
  if (serial_data == 32) digitalWrite(SLB2, HIGH);
  if (serial_data == 33) digitalWrite(SLB3, HIGH);
  if (serial_data == 34) digitalWrite(SLB4, HIGH);

  if (serial_data == 35) digitalWrite(SLB1, LOW);
  if (serial_data == 36) digitalWrite(SLB2, LOW);
  if (serial_data == 37) digitalWrite(SLB3, LOW);
  if (serial_data == 38) digitalWrite(SLB4, LOW);

  if (serial_data == 99) {
    Back_Light_Normal_All_Off();
  }

  // Down light all off
  if (serial_data == 20) {
    digitalWrite(SLD1, LOW);
    digitalWrite(SLD2, LOW);
    digitalWrite(SLD3, LOW);
    digitalWrite(SRD1, LOW);
    digitalWrite(SRD2, LOW);
    digitalWrite(SRD3, LOW);
  }

  // BackSide Light All off
  if (serial_data == 30) {
    digitalWrite(SLB1, LOW);
    digitalWrite(SLB2, LOW);
    digitalWrite(SLB3, LOW);
    digitalWrite(SLB4, LOW);
    digitalWrite(SRB1, LOW);
    digitalWrite(SRB2, LOW);
    digitalWrite(SRB3, LOW);
    digitalWrite(SRB4, LOW);
  }
}
