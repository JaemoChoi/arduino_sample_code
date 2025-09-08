void LIGHT_SCENE_0() {
}

void LIGHT_SCENE_1() {
}

void LIGHT_SCENE_2() {
}

void LIGHT_SCENE_3() {
}

void LIGHT_SCENE_4() {
}

void LIGHT_SCENE_5() {
}

void LIGHT_SCENE_6() {
}

void LIGHT_SCENE_7() {
}

void LIGHT_SCENE_8() {
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
