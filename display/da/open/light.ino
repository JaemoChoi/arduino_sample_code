void LIGHT_SCENE_0() {
  analogWrite(CABI_L, 0);
  analogWrite(CABI_R, 0);
  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_1() {
  analogWrite(CABI_L, 0);
  analogWrite(CABI_R, 0);
  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_2() {
  analogWrite(CABI_L, 0);
  analogWrite(CABI_R, 0);
  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_3() {
  analogWrite(CABI_L, 0);
  analogWrite(CABI_R, 0);
  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_4() {
  for (int dim = 0; dim < 256; dim++) {
    analogWrite(CABI_L, dim);
    analogWrite(CABI_R, dim);
    delay(5);
  }
  delay(3000);
  for (int dim = 256; dim > 128; dim--) {
    analogWrite(CABI_L, dim);
    analogWrite(CABI_R, dim);
    delay(5);
  }

  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID14(0, 0, 0, 128);
  setAll_BOT23(0, 0, 0, 128);
}

void LIGHT_SCENE_5() {

  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID14(0, 0, 0, 128);
  setAll_BOT2(0, 0, 0, 128);
}

void LIGHT_SCENE_6() {

  for (int dim = 128; dim > -1; dim--) {
    analogWrite(CABI_L, dim);
    analogWrite(CABI_R, dim);
    delay(5);
  }

  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_7() {

  delay(7000);

  setAll_NITTO_LEFT(0, 0, 0, 128);
  setAll_NITTO_RIGHT(0, 0, 0, 128);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 128);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 128);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_8() {

  delay(3000);

  setAll_NITTO_LEFT(0, 0, 0, 128);
  setAll_NITTO_RIGHT(0, 0, 0, 128);
  setAll_COVER_LEFT(0, 0, 0, 128);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_CHILLER_(0, 0, 0, 128);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 128);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_9() {

  delay(3000);

  setAll_NITTO_LEFT(0, 0, 0, 128);
  setAll_NITTO_RIGHT(0, 0, 0, 128);
  setAll_COVER_LEFT(0, 0, 0, 128);
  setAll_COVER_RIGHT(0, 0, 0, 128);
  setAll_CHILLER_(0, 0, 0, 128);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 128);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}

void LIGHT_SCENE_10() {

  delay(2000);
  setAll_CHILLER_(0, 0, 0, 0);
  delay(2000);
  setAll_NITTO_LEFT(0, 0, 0, 0);
  setAll_NITTO_RIGHT(0, 0, 0, 0);
  setAll_COVER_LEFT(0, 0, 0, 0);
  setAll_COVER_RIGHT(0, 0, 0, 0);
  setAll_BASKET(0, 0, 0, 0);
  setAll_CENTER(0, 0, 0, 0);
  setAll_TOP(0, 0, 0, 0);
  setAll_MID(0, 0, 0, 0);
  setAll_BOT(0, 0, 0, 0);
}
