
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

  analogWrite(BLLT, 255);
  analogWrite(BLL1, 255);
  analogWrite(BLL2, 255);
  analogWrite(BLL3, 255);
  analogWrite(BLL4, 255);

  analogWrite(BLRT, 255);
  analogWrite(BLR1, 255);
  analogWrite(BLR2, 255);
  analogWrite(BLR3, 255);
  analogWrite(BLR4, 255);

  analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 0); // RIGHT PDLC
}

void LIGHT_SCENE_2() {

  analogWrite(BLLT, 255);
  analogWrite(BLL1, 255);
  analogWrite(BLL2, 255);
  analogWrite(BLL3, 255);
  analogWrite(BLL4, 255);

  analogWrite(BLRT, 255);
  analogWrite(BLR1, 255);
  analogWrite(BLR2, 255);
  analogWrite(BLR3, 255);
  analogWrite(BLR4, 255);

  analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 0); // RIGHT PDLC
}

void LIGHT_SCENE_3() {
  analogWrite(BLLT, 255);
  analogWrite(BLL1, 255);
  analogWrite(BLL2, 16);
  analogWrite(BLL3, 16);
  analogWrite(BLL4, 16);

  analogWrite(BLRT, 16);
  analogWrite(BLR1, 16);
  analogWrite(BLR2, 16);
  analogWrite(BLR3, 16);
  analogWrite(BLR4, 16);

  /*
    digitalWrite(SLD1, 1);
    digitalWrite(SLD2, 1);
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
  */
  analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 0); // RIGHT PDLC
}

void LIGHT_SCENE_4() {
  analogWrite(BLLT, 16);
  analogWrite(BLL1, 16);
  analogWrite(BLL2, 16);
  analogWrite(BLL3, 16);
  analogWrite(BLL4, 255);

  analogWrite(BLRT, 255);
  analogWrite(BLR1, 255);
  analogWrite(BLR2, 16);
  analogWrite(BLR3, 16);
  analogWrite(BLR4, 16);
  /*
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
  */
 analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 0); // RIGHT PDLC
}


void LIGHT_SCENE_5() {
  analogWrite(BLLT, 255);
  analogWrite(BLL1, 255);
  analogWrite(BLL2, 255);
  analogWrite(BLL3, 255);
  analogWrite(BLL4, 255);

  analogWrite(BLRT, 255);
  analogWrite(BLR1, 255);
  analogWrite(BLR2, 255);
  analogWrite(BLR3, 255);
  analogWrite(BLR4, 255);
  /*
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
  */
 analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 0); // RIGHT PDLC
}


void LIGHT_SCENE_6() {
 analogWrite(BLLT, 0);
  analogWrite(BLL1, 0);
  analogWrite(BLL2, 255);
  analogWrite(BLL3, 255);
  analogWrite(BLL4, 0);

  analogWrite(BLRT, 0);
  analogWrite(BLR1, 0);
  analogWrite(BLR2, 255);
  analogWrite(BLR3, 255);
  analogWrite(BLR4, 0);

  analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 0); // RIGHT PDLC
}

void LIGHT_SCENE_7() {
  analogWrite(BLLT, 16);
  analogWrite(BLL1, 16);
  analogWrite(BLL2, 16);
  analogWrite(BLL3, 16);
  analogWrite(BLL4, 16);

  analogWrite(BLRT, 16);
  analogWrite(BLR1, 16);
  analogWrite(BLR2, 16);
  analogWrite(BLR3, 16);
  analogWrite(BLR4, 255);

  analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 0); // RIGHT PDLC
  digitalWrite(SRB1, HIGH);
  digitalWrite(SRB2, HIGH);
  digitalWrite(SRB3, HIGH);
}

void LIGHT_SCENE_8() {
  analogWrite(BLLT, 255);
  analogWrite(BLL1, 255);
  analogWrite(BLL2, 255);
  analogWrite(BLL3, 255);
  analogWrite(BLL4, 255);

  analogWrite(BLRT, 255);
  analogWrite(BLR1, 255);
  analogWrite(BLR2, 255);
  analogWrite(BLR3, 255);
  analogWrite(BLR4, 255);

  analogWrite(SLB1, 255); // PDLC 2
  analogWrite(SLB2, 255); // PDLC 6
  analogWrite(SLB3, 0); // PDLC 2
  analogWrite(SLB4, 0); // PDLC 6

  //SL_ALL_OFF();
}

void LIGHT_SCENE_9() {
  analogWrite(BLLT, 64);
  analogWrite(BLL1, 64);
  analogWrite(BLL2, 255);
  analogWrite(BLL3, 255);
  analogWrite(BLL4, 64);

  analogWrite(BLRT, 64);
  analogWrite(BLR1, 64);
  analogWrite(BLR2, 255);
  analogWrite(BLR3, 255);
  analogWrite(BLR4, 64);

  analogWrite(SLB1, 0); // PDLC 2
  analogWrite(SLB2, 0); // PDLC 6
  analogWrite(SLB3, 0); // LEFT PDLC
  analogWrite(SLB4, 255); // RIGHT PDLC

  //SL_ALL_OFF();
}

void Back_Light_test() {

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLR1, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLR1, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLR2, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLR2, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLR3, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLR3, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLR4, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLR4, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLRT, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLRT, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLL1, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLL1, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLL2, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLL2, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLL3, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLL3, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLL4, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLL4, bright);
    delay(3);
  }
  delay(1000);

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLLT, bright);
    delay(5);
  }

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLLT, bright);
    delay(3);
  }
  delay(1000);
}

void Back_Light_All_On() {

  for (int bright = 0; bright < 256; bright++) {
    analogWrite(BLR1, bright);
    analogWrite(BLR2, bright);
    analogWrite(BLR3, bright);
    analogWrite(BLR4, bright);
    analogWrite(BLL1, bright);
    analogWrite(BLL2, bright);
    analogWrite(BLL3, bright);
    analogWrite(BLL4, bright);
    analogWrite(BLRT, bright);
    analogWrite(BLLT, bright);
    delay(5);
  }
  //Light_All_Onflag = 1;
}

void Back_Light_All_Off() {

  for (int bright = 255; bright > -1; bright--) {
    analogWrite(BLR1, bright);
    analogWrite(BLR2, bright);
    analogWrite(BLR3, bright);
    analogWrite(BLR4, bright);
    analogWrite(BLL1, bright);
    analogWrite(BLL2, bright);
    analogWrite(BLL3, bright);
    analogWrite(BLL4, bright);
    analogWrite(BLRT, bright);
    analogWrite(BLLT, bright);
    delay(5);
  }
}

void Back_Light_Normal_All_Off() {

  int bright = 0;
  analogWrite(BLR1, bright);
  analogWrite(BLR2, bright);
  analogWrite(BLR3, bright);
  analogWrite(BLR4, bright);
  analogWrite(BLL1, bright);
  analogWrite(BLL2, bright);
  analogWrite(BLL3, bright);
  analogWrite(BLL4, bright);
  analogWrite(BLRT, bright);
  analogWrite(BLLT, bright);

}

void Light_init() {

  int bright = 0;
  analogWrite(BLR1, bright);
  analogWrite(BLR2, bright);
  analogWrite(BLR3, bright);
  analogWrite(BLR4, bright);
  analogWrite(BLL1, bright);
  analogWrite(BLL2, bright);
  analogWrite(BLL3, bright);
  analogWrite(BLL4, bright);
  analogWrite(BLRT, bright);
  analogWrite(BLLT, bright);
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
