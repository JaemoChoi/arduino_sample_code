#include <Adafruit_NeoPixel.h>

#define EAR_PIN 6   // Left Side EAR control Pin No
#define REAR_PIN 2  // Right Side EAR control Pin No

#define EAR_NUM 60  // EAR LED Numbers


Adafruit_NeoPixel EAR_strip(EAR_NUM, EAR_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel REAR_strip(EAR_NUM, REAR_PIN, NEO_GRBW + NEO_KHZ800);

uint8_t r1 = 255, g1 = 80, b1 = 20, w1 = 0;    // 1st Color
uint8_t r2 = 149, g2 = 184, b2 = 255, w2 = 0;  // 2nd Color

// Effect Parameter
int groupSize = 6;
float speed = 0.5;   // moving speed (small -> Slow)
int frameDelay = 5;  // speed delay
float pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // initial Neopixel LED strip
  EAR_strip.begin();
  EAR_strip.setBrightness(150);
  EAR_strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:

  listen();
}

void listen() {

  EAR_strip.clear();
  REAR_strip.clear();

  for (int i = 0; i < groupSize; i++) {

    int idx_rear = ((int)(pos + i)) % EAR_NUM;
    int idx_ear = ((EAR_NUM - 1) - ((int)(pos + i) % EAR_NUM));

    float ratio = (float)i / (groupSize - 1);
    float brightness = pow(0.2, ratio);

    uint8_t rr = (uint8_t)(((1 - ratio) * r1 + ratio * r2) * brightness);
    uint8_t gg = (uint8_t)(((1 - ratio) * g1 + ratio * g2) * brightness);
    uint8_t bb = (uint8_t)(((1 - ratio) * b1 + ratio * b2) * brightness);
    uint8_t ww = (uint8_t)(((1 - ratio) * w1 + ratio * w2) * brightness);

    EAR_strip.setPixelColor(idx_ear, EAR_strip.Color(rr, gg, bb, ww));
    REAR_strip.setPixelColor(idx_rear, REAR_strip.Color(rr, gg, bb, ww));
  }

  EAR_strip.show();
  REAR_strip.show();
  delay(frameDelay);
  pos += speed;
  // Position initial.
  if (pos >= EAR_NUM) pos -= EAR_NUM;

  EAR_strip.clear();
  EAR_strip.show();
  REAR_strip.clear();
  REAR_strip.show();
}
