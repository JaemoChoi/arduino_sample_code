void LED_initialize() {

  NITTO_LEFT.begin();
  NITTO_LEFT.show();
  NITTO_LEFT.setBrightness(100);
  NITTO_RIGHT.begin();
  NITTO_RIGHT.show();
  NITTO_RIGHT.setBrightness(100);
  FRONT_LEFT.begin();
  FRONT_LEFT.show();
  FRONT_LEFT.setBrightness(100);
  FRONT_RIGHT.begin();
  FRONT_RIGHT.show();
  FRONT_RIGHT.setBrightness(100);
  CHILLER.begin();
  CHILLER.show();
  CHILLER.setBrightness(100);
  TOP_LEVEL_FRONT.begin();
  TOP_LEVEL_FRONT.show();
  TOP_LEVEL_FRONT.setBrightness(100);
  TOP_LEVEL_BACK.begin();
  TOP_LEVEL_BACK.show();
  TOP_LEVEL_BACK.setBrightness(100);
  MIDDLE_LEVEL_FRONT.begin();
  MIDDLE_LEVEL_FRONT.show();
  MIDDLE_LEVEL_FRONT.setBrightness(100);
  MIDDLE_LEVEL_BACK.begin();
  MIDDLE_LEVEL_BACK.show();
  MIDDLE_LEVEL_BACK.setBrightness(100);
  BOT_LEVEL_FRONT.begin();
  BOT_LEVEL_FRONT.show();
  BOT_LEVEL_FRONT.setBrightness(100);
  BOT_LEVEL_BACK.begin();
  BOT_LEVEL_BACK.show();
  BOT_LEVEL_BACK.setBrightness(100);
  SIDE_LEFT.begin();
  SIDE_LEFT.show();
  SIDE_LEFT.setBrightness(100);
  SIDE_RIGHT.begin();
  SIDE_RIGHT.show();
  SIDE_RIGHT.setBrightness(100);
}

void setAll_NITTO_LEFT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NITTO_LEFT_NUM; i++) {
    NITTO_LEFT.setPixelColor(i, NITTO_LEFT.Color(red, green, blue, white));
  } 
  NITTO_LEFT.show();
}

void setAll_NITTO_RIGHT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NITTO_RIGHT_NUM; i++) {
    NITTO_RIGHT.setPixelColor(i, NITTO_RIGHT.Color(red, green, blue, white));
  }
  NITTO_RIGHT.show();
}

void setAll_FRONT_LEFT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < FRONT_LEFT_NUM; i++) {
    FRONT_LEFT.setPixelColor(i, FRONT_LEFT.Color(red, green, blue, white));
  }
  FRONT_LEFT.show();
}

void setAll_FRONT_RIGHT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < FRONT_RIGHT_NUM; i++) {
    FRONT_RIGHT.setPixelColor(i, FRONT_RIGHT.Color(red, green, blue, white));
  }
  FRONT_RIGHT.show();
}

void setAll_CHILLER(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < CHILLER_NUM; i++) {
    CHILLER.setPixelColor(i, CHILLER.Color(red, green, blue, white));
  }
  CHILLER.show();
}

void setAll_TOP_LEVEL_FRONT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < TOP_LEVEL_FRONT_NUM; i++) {
    TOP_LEVEL_FRONT.setPixelColor(i, TOP_LEVEL_FRONT.Color(red, green, blue, white));
  }
  TOP_LEVEL_FRONT.show();
}

void setAll_TOP_LEVEL_BACK(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < TOP_LEVEL_BACK_NUM; i++) {
    TOP_LEVEL_BACK.setPixelColor(i, TOP_LEVEL_BACK.Color(red, green, blue, white));
  }
  TOP_LEVEL_BACK.show();
}

void setAll_MIDDLE_LEVEL_FRONT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < MIDDLE_LEVEL_FRONT_NUM; i++) {
    MIDDLE_LEVEL_FRONT.setPixelColor(i, MIDDLE_LEVEL_FRONT.Color(red, green, blue, white));
  }
  MIDDLE_LEVEL_FRONT.show();
}

void setAll_MIDDLE_LEVEL_BACK(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < MIDDLE_LEVEL_BACK_NUM; i++) {
    MIDDLE_LEVEL_BACK.setPixelColor(i, MIDDLE_LEVEL_BACK.Color(red, green, blue, white));
  }
  MIDDLE_LEVEL_BACK.show();
}

void setAll_BOT_LEVEL_FRONT(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BOT_LEVEL_FRONT_NUM; i++) {
    BOT_LEVEL_FRONT.setPixelColor(i, BOT_LEVEL_FRONT.Color(red, green, blue, white));
  }
  BOT_LEVEL_FRONT.show();
}

void setAll_BOT_LEVEL_BACK(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BOT_LEVEL_BACK_NUM; i++) {
    BOT_LEVEL_BACK.setPixelColor(i, BOT_LEVEL_BACK.Color(red, green, blue, white));
  }
  BOT_LEVEL_BACK.show();
}
