void setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  TOP_BACK.setPixelColor(Pixel, TOP_BACK.Color(red, green, blue, white));
}



void setAll(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < TOP_BACK_NUM; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}

void setAll_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255 ; dim > -1 ; dim--) {
    for (int i = 0; i < TOP_BACK_NUM; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}

void TOP_BACK_LED_SET1(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < 21; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}


void TOP_BACK_LED_SET2(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 21; i < 42; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}


void TOP_BACK_LED_SET3(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 42; i < 63; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}


void TOP_BACK_LED_SET4(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 64; i < 85; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}


void TOP_BACK_LED_SET5(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 85; i < 106; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}


void TOP_BACK_LED_SET6(byte red, byte green, byte blue, byte white) {
  for (float dim = 0 ; dim < 256 ; dim++) {
    for (int i = 106; i < 127; i++) {
      setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    TOP_BACK.show();
  }
}


void TOP_BACK_TEST() {
  TOP_BACK_LED_SET1(0, 0, 0, 255);
  TOP_BACK.show();
  delay(1000);

  TOP_BACK_LED_SET2(0, 0, 0, 255);
  TOP_BACK.show();
  delay(1000);

  TOP_BACK_LED_SET3(0, 0, 0, 255);
  TOP_BACK.show();
  delay(1000);

  TOP_BACK_LED_SET4(0, 0, 0, 255);
  TOP_BACK.show();
  delay(1000);

  TOP_BACK_LED_SET5(0, 0, 0, 255);
  TOP_BACK.show();
  delay(1000);

  TOP_BACK_LED_SET6(0, 0, 0, 255);
  TOP_BACK.show();
  delay(1000);
}

void Llight_All_off()
{
  TOP_BACK_LED_SET1(0, 0, 0, 0);
  TOP_BACK_LED_SET2(0, 0, 0, 0);
  TOP_BACK_LED_SET3(0, 0, 0, 0);
  TOP_BACK_LED_SET4(0, 0, 0, 0);
  TOP_BACK_LED_SET5(0, 0, 0, 0);
  TOP_BACK_LED_SET6(0, 0, 0, 0);
  TOP_BACK.show();

}

void Light_init()
{
  analogWrite(TOP_FRONT, 0);
  analogWrite(TOP_MID, 0);
  analogWrite(DRAW_EDGE, 0);
  analogWrite(DRAW_BACK, 0);
  Llight_All_off();

}
