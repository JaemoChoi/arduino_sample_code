void S1_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  S1.setPixelColor(Pixel, S1.Color(red, green, blue, white));
}

void S2_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  S2.setPixelColor(Pixel, S2.Color(red, green, blue, white));
}

void S3_setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  S3.setPixelColor(Pixel, S3.Color(red, green, blue, white));
}




void S1_setAll(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < S_NUM; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S2_setAll(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < S_NUM; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S3_setAll(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < S_NUM; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S1_SET1(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < 35; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET2(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 35; i < 70; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET3(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 70; i < 105; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

void S1_SET4(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 105; i < 142; i++) {
      S1_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S1.show();
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void S2_SET1(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < 35; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET2(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 35; i < 70; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET3(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 70; i < 105; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}

void S2_SET4(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 105; i < 142; i++) {
      S2_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S2.show();
  }
}


////////////////////////////////////////////////////////////////////////////////////////////
void S3_SET1(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 0; i < 35; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET2(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 35; i < 70; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET3(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 70; i < 105; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void S3_SET4(byte red, byte green, byte blue, byte white) {
  for (int dim = 0 ; dim < 256 ; dim++) {
    for (int i = 105; i < 142; i++) {
      S3_setPixel(i, red * (dim / 255), green * (dim / 255), blue * (dim / 255), white * (dim / 255));
    }
    S3.show();
  }
}

void SLL_ON(){
  for (int dim = 0 ; dim < 256 ; dim++){
    analogWrite(SLL,dim);
    delay(5);
  }
}

void SLR_ON(){
  for (int dim = 0 ; dim < 256 ; dim++){
    analogWrite(SLR,dim);
    delay(5);
  }
}

void SLL_OFF(){
  for (int dim = 255 ; dim > -1 ; dim--){
    analogWrite(SLL,dim);
    delay(5);
  }
}

void SLR_OFF(){
  for (int dim = 255 ; dim > -1 ; dim--){
    analogWrite(SLR,dim);
    delay(5);
  }
}


void Llight_All_off()
{
  S1_setAll(0, 0, 0, 0);
  S2_setAll(0, 0, 0, 0);
  S2_setAll(0, 0, 0, 0);

}

