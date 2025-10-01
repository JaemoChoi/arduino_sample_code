void S1_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  S1.setPixelColor(Pixel, S1.Color(red, green, blue, white));
}

void S2_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  S2.setPixelColor(Pixel, S2.Color(red, green, blue, white));
}

void S3_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  S3.setPixelColor(Pixel, S3.Color(red, green, blue, white));
}

void SCENE1_LED_set1(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim += 5) {
    for (int i = 0; i < 35; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    for (int i = 70; i < 105; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
    S1.show();
  }
}

void SCENE1_LED_set2(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim -= 10) {
    if ( dim < 10 ) dim = 0;

    red = 0;
    green = 0;
    blue = 0;
    white = 255;
    for (int i = 0; i < 35; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    for (int i = 70; i < 105; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }

    red = 255;
    green = 0;
    blue = 0;
    white = 0;

    for (int i = 105; i < 142; i++) {
      S1_setPixel(i, red * ((255 - dim) / 255), green * ((255 - dim) / 255), blue * ((255 - dim) / 255), white * ((255 - dim) / 255));
      S1_setPixel(284 - i, red * ((255 - dim) / 255), green * ((255 - dim) / 255), blue * ((255 - dim) / 255), white * ((255 - dim) / 255));
    }
    S1.show();
    S2.show();
  }
}

void SCENE1_LED_set3(byte red, byte green, byte blue, byte white) {

  for (float dim = 255; dim > -1; dim -= 10) {
    if( dim < 10 ) dim = 0;
    red = 255;
    green = 0;
    blue = 0;
    white = 0;
    for (int i = 105; i < 142; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }

    red = 0;
    green = 255;
    blue = 0;
    white = 0;
    for (int i = 35; i < 70; i++) {
      S1_setPixel(i, red * ((255 - dim) / 255), green * ((255 - dim) / 255), blue * ((255 - dim) / 255), white * ((255 - dim) / 255));
      S1_setPixel(284 - i, red * ((255 - dim) / 255), green * ((255 - dim) / 255), blue * ((255 - dim) / 255), white * ((255 - dim) / 255));
    }

    S1.show();
    S2.show();
  }
}

void S1_setAll(byte red, byte green, byte blue, byte white) {
  for (int dim = 255; dim < 256; dim++) {
    for (int i = 0; i < S_NUM; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S2_setAll(byte red, byte green, byte blue, byte white) {
  for (int dim = 255; dim < 256; dim++) {
    for (int i = 0; i < S_NUM; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S3_setAll(byte red, byte green, byte blue, byte white) {
  for (int dim = 255; dim < 256; dim++) {
    for (int i = 0; i < S_NUM; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S1_SET1(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim = dim + 2) {
    for (int i = 0; i < 35; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET2(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim += 5) {
    for (int i = 35; i < 70; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET3(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim = dim + 2) {
    for (int i = 70; i < 105; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET4(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim++) {
    for (int i = 105; i < 142; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void S2_SET1(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim = dim + 2) {
    for (int i = 0; i < 35; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET2(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim++) {
    for (int i = 35; i < 70; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET3(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim++) {
    for (int i = 70; i < 105; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET4(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim += 5) {
    for (int i = 105; i < 142; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}


////////////////////////////////////////////////////////////////////////////////////////////
void S3_SET1(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim++) {
    for (int i = 0; i < 35; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET2(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim++) {
    for (int i = 35; i < 70; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET3(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim++) {
    for (int i = 70; i < 105; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET4(byte red, byte green, byte blue, byte white) {
  for (float dim = 0; dim < 256; dim++) {
    for (int i = 105; i < 142; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}


///////////////////// off ///////////////////////////////////////

void S1_SET1_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 0; i < 35; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET2_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 35; i < 70; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET3_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 70; i < 105; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET4_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 105; i < 142; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S1_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void S2_SET1_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 0; i < 35; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET2_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 35; i < 70; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET3_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 70; i < 105; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET4_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 105; i < 142; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S2_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}


////////////////////////////////////////////////////////////////////////////////////////////
void S3_SET1_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 0; i < 35; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET2_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 35; i < 70; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET3_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 70; i < 105; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET4_OFF(byte red, byte green, byte blue, byte white) {
  for (float dim = 255; dim > -1; dim++) {
    for (int i = 105; i < 142; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
      S3_setPixel(284 - i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void SLL_ON() {
  for (int dim = 0; dim < 256; dim++) {
    analogWrite(SLL, dim);
    delay(7);
  }
}

void SLR_ON() {
  for (int dim = 0; dim < 256; dim++) {
    analogWrite(SLR, dim);
    delay(7);
  }
}

void SLALL_ON(int bright) {
  for (int dim = 0; dim < bright; dim++) {
    analogWrite(SLR, dim);
    analogWrite(SLL, dim);
    delay(7);
  }
}

void SLALL_OFF(int bright) {
  for (int dim = bright; dim >= 0; dim--) {
    analogWrite(SLR, dim);
    analogWrite(SLL, dim);
  }
}


void SLL_OFF() {
  for (int dim = 255; dim > -1; dim--) {
    analogWrite(SLL, dim);
    delay(5);
  }
}

void SLR_OFF() {
  for (int dim = 255; dim > -1; dim--) {
    analogWrite(SLR, dim);
    delay(5);
  }
}


void Llight_All_off() {
  S1_setAll(0, 0, 0, 0);
  S2_setAll(0, 0, 0, 0);
  S2_setAll(0, 0, 0, 0);
}
