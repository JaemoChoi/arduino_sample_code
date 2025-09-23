void EAR_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  EAR_strip.setPixelColor(Pixel, EAR_strip.Color(red, green, blue, white));
}

void SHOULDER_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  SHOULDER_strip.setPixelColor(Pixel, SHOULDER_strip.Color(red, green, blue, white));
}


void HAND_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  HAND_strip.setPixelColor(Pixel, HAND_strip.Color(red, green, blue, white));
}


void FOOT_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  FOOT_strip.setPixelColor(Pixel, FOOT_strip.Color(red, green, blue, white));
}


void NECK_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  NECK_strip.setPixelColor(Pixel, NECK_strip.Color(red, green, blue, white));
}



void EAR_setAll(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < EAR_NUM; i++) {
      EAR_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    EAR_strip.show();
  }
}

void SHOULDER_setAll(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < SHOULDER_NUM; i++) {
      SHOULDER_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    SHOULDER_strip.show();
  }
}

void HAND_setAll(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < HAND_NUM; i++) {
      HAND_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    HAND_strip.show();
  }
}

void FOOT_setAll(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < FOOT_NUM; i++) {
      FOOT_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    FOOT_strip.show();
  }
}

void NECK_setAll(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < NECK_NUM; i++) {
      NECK_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    NECK_strip.show();
  }
}


void EAR_setAllOFF(byte red, byte green, byte blue, byte white, byte dimmed) {
  for (float dim = 255 ; dim > dimmed ; dim--) {
    for (int i = 0; i < EAR_NUM; i++) {
      EAR_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    EAR_strip.show();
  }
}

void SHOULDER_setAllOFF(byte red, byte green, byte blue, byte white, byte dimmed) {
  for (float dim = 255 ; dim > dimmed ; dim--) {
    for (int i = 0; i < SHOULDER_NUM; i++) {
      SHOULDER_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    SHOULDER_strip.show();
  }
}


void HAND_setAllOFF(byte red, byte green, byte blue, byte white, byte dimmed) {
  for (float dim = 255 ; dim > dimmed ; dim--) {
    for (int i = 0; i < HAND_NUM; i++) {
      HAND_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    HAND_strip.show();
  }
}


void FOOT_setAllOFF(byte red, byte green, byte blue, byte white, byte dimmed) {
  for (float dim = 255 ; dim > dimmed ; dim--) {
    for (int i = 0; i < FOOT_NUM; i++) {
      FOOT_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    FOOT_strip.show();
  }
}


void NECK_setAllOFF(byte red, byte green, byte blue, byte white, byte dimmed) {
  for (float dim = 255 ; dim > dimmed ; dim--) {
    for (int i = 0; i < NECK_NUM; i++) {
      NECK_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    NECK_strip.show();
  }
}



