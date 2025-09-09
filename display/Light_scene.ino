void LIGHT_SCENE_0() {
  analogWrite(BLLT, 0);
  analogWrite(BLL1, 0);
  analogWrite(BLL2, 0);
  analogWrite(BLL3, 0);
  analogWrite(BLL4, 0);

  analogWrite(BLRT, 0);
  analogWrite(BLR1, 0);
  analogWrite(BLR2, 0);
  analogWrite(BLR3, 0);
  analogWrite(BLR4, 0);

  SL_ALL_OFF();
}

void LIGHT_SCENE_1() {

  analogWrite(BLLT, 128);
  analogWrite(BLL1, 128);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 128);

  analogWrite(BLRT, 128);
  analogWrite(BLR1, 128);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 128);

  SL_ALL_OFF();
}

void LIGHT_SCENE_2() {

  analogWrite(BLLT, 0);
  analogWrite(BLL1, 0);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 0);

  analogWrite(BLRT, 0);
  analogWrite(BLR1, 0);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 0);

  SL_ALL_OFF();
}

void LIGHT_SCENE_3() {
  analogWrite(BLLT, 128);
  analogWrite(BLL1, 128);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 128);

  analogWrite(BLRT, 128);
  analogWrite(BLR1, 128);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 128);

  digitalWrite(SLD1, 0);
  digitalWrite(SLD2, 0);
  digitalWrite(SLD3, 1);
  digitalWrite(SLB1, 0);
  digitalWrite(SLB2, 0);
  digitalWrite(SLB3, 0);
  digitalWrite(SLB4, 1);

  digitalWrite(SRD1, 0);
  digitalWrite(SRD2, 0);
  digitalWrite(SRD3, 0);
  digitalWrite(SRB1, 1);
  digitalWrite(SRB2, 0);
  digitalWrite(SRB3, 0);
  digitalWrite(SRB4, 0);
}

void LIGHT_SCENE_4() {
  analogWrite(BLLT, 128);
  analogWrite(BLL1, 128);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 128);

  analogWrite(BLRT, 128);
  analogWrite(BLR1, 128);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 128);

  digitalWrite(SLD1, 0);
  digitalWrite(SLD2, 0);
  digitalWrite(SLD3, 0);
  digitalWrite(SLB1, 1);
  digitalWrite(SLB2, 0);
  digitalWrite(SLB3, 0);
  digitalWrite(SLB4, 0);

  digitalWrite(SRD1, 0);
  digitalWrite(SRD2, 0);
  digitalWrite(SRD3, 0);
  digitalWrite(SRB1, 0);
  digitalWrite(SRB2, 0);
  digitalWrite(SRB3, 0);
  digitalWrite(SRB4, 0);
}


void LIGHT_SCENE_5() {
  analogWrite(BLLT, 128);
  analogWrite(BLL1, 128);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 128);

  analogWrite(BLRT, 128);
  analogWrite(BLR1, 128);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 128);

  digitalWrite(SLD1, 0);
  digitalWrite(SLD2, 0);
  digitalWrite(SLD3, 0);
  digitalWrite(SLB1, 0);
  digitalWrite(SLB2, 0);
  digitalWrite(SLB3, 0);
  digitalWrite(SLB4, 0);

  digitalWrite(SRD1, 0);
  digitalWrite(SRD2, 0);
  digitalWrite(SRD3, 1);
  digitalWrite(SRB1, 0);
  digitalWrite(SRB2, 0);
  digitalWrite(SRB3, 0);
  digitalWrite(SRB4, 1);
}


void LIGHT_SCENE_6() {
  analogWrite(BLLT, 128);
  analogWrite(BLL1, 128);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 128);

  analogWrite(BLRT, 128);
  analogWrite(BLR1, 128);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 128);

  SL_ALL_OFF();
}

void LIGHT_SCENE_7() {
  analogWrite(BLLT, 128);
  analogWrite(BLL1, 128);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 128);

  analogWrite(BLRT, 128);
  analogWrite(BLR1, 128);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 128);

  SL_ALL_OFF();
}

void LIGHT_SCENE_8() {
  analogWrite(BLLT, 128);
  analogWrite(BLL1, 128);
  analogWrite(BLL2, 128);
  analogWrite(BLL3, 128);
  analogWrite(BLL4, 128);

  analogWrite(BLRT, 128);
  analogWrite(BLR1, 128);
  analogWrite(BLR2, 128);
  analogWrite(BLR3, 128);
  analogWrite(BLR4, 128);

  SL_ALL_OFF();
}

void Back_Light_test() {

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Right1, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Right1, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Right2, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Right2, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Right34, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Right34, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Right5, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Right5, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Left1, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Left1, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Left2, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Left2, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Left34, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Left34, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Left5, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Left5, bright);
    delay(3);
  }
  delay(1000);


  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_RightTop, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_RightTop, bright);
    delay(3);
  }
  delay(1000);


  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_LeftTop, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_LeftTop, bright);
    delay(3);
  }
  delay(1000);
}

void Back_Light_All_On() {

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(Back_Light_Right1, bright);
    analogWrite(Back_Light_Right2, bright);
    analogWrite(Back_Light_Right34, bright);
    analogWrite(Back_Light_Right5, bright);
    analogWrite(Back_Light_Left1, bright);
    analogWrite(Back_Light_Left2, bright);
    analogWrite(Back_Light_Left34, bright);
    analogWrite(Back_Light_Left5, bright);
    analogWrite(Back_Light_RightTop, bright);
    analogWrite(Back_Light_LeftTop, bright);
    delay(5);
  }
  Light_All_Onflag = 1;
}

void Back_Light_All_Off() {

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(Back_Light_Right1, bright);
    analogWrite(Back_Light_Right2, bright);
    analogWrite(Back_Light_Right34, bright);
    analogWrite(Back_Light_Right5, bright);
    analogWrite(Back_Light_Left1, bright);
    analogWrite(Back_Light_Left2, bright);
    analogWrite(Back_Light_Left34, bright);
    analogWrite(Back_Light_Left5, bright);
    analogWrite(Back_Light_RightTop, bright);
    analogWrite(Back_Light_LeftTop, bright);
    delay(5);
  }
}

void Light_init() {

  int bright = 0;
  analogWrite(Back_Light_Right1, bright);
  analogWrite(Back_Light_Right2, bright);
  analogWrite(Back_Light_Right34, bright);
  analogWrite(Back_Light_Right5, bright);
  analogWrite(Back_Light_Left1, bright);
  analogWrite(Back_Light_Left2, bright);
  analogWrite(Back_Light_Left34, bright);
  analogWrite(Back_Light_Left5, bright);
  analogWrite(Back_Light_RightTop, bright);
  analogWrite(Back_Light_LeftTop, bright);
}

void SL_ALL_OFF()
{
  digitalWrite(SLD1, 0);
  digitalWrite(SLD2, 0);
  digitalWrite(SLD3, 0);
  digitalWrite(SLB1, 0);
  digitalWrite(SLB2, 0);
  digitalWrite(SLB3, 0);
  digitalWrite(SLB4, 0);

  digitalWrite(SRD1, 0);
  digitalWrite(SRD2, 0);
  digitalWrite(SRD3, 0);
  digitalWrite(SRB1, 0);
  digitalWrite(SRB2, 0);
  digitalWrite(SRB3, 0);
  digitalWrite(SRB4, 0);
}

void SL_ALL_ON()
{
  digitalWrite(SLD1, 1);
  digitalWrite(SLD2, 1);
  digitalWrite(SLD3, 1);
  digitalWrite(SLB1, 1);
  digitalWrite(SLB2, 1);
  digitalWrite(SLB3, 1);
  digitalWrite(SLB4, 1);

  digitalWrite(SRD1, 1);
  digitalWrite(SRD2, 1);
  digitalWrite(SRD3, 1);
  digitalWrite(SRB1, 1);
  digitalWrite(SRB2, 1);
  digitalWrite(SRB3, 1);
  digitalWrite(SRB4, 1);
}

