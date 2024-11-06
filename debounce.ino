#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

const int interruptPin = 2;
const int ledPin = 13;
int ledState = 1;
int ledflag = 0;
int exitflag = 0;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleLED, LOW);

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Color Number : ");
  Serial.println(ledState);

  if (ledState == 1) {
    fadeIncolorWipe(255, 0, 0, 5);
    if (exitflag == 1) exitflag = 0;
    else fadeOutcolorWipe(255, 0, 0, 5);
  }

  if (ledState == 2) {
    fadeIncolorWipe(0, 255, 0, 5); // Green
    if (exitflag == 1) exitflag = 0;
    else fadeOutcolorWipe(0, 255, 0, 5); // Green
  }

  if (ledState == 3) {
    fadeIncolorWipe(0, 0, 255, 5); // Blue
    if (exitflag == 1) exitflag = 0;
    else fadeOutcolorWipe(0, 0, 255, 5); // Blue
  }

}


// Debounce Key Interrupt Input //
void toggleLED() {
  unsigned long currentTime = millis();

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    ledState ++;
    if (ledState > 3) ledState = 1;
    ledflag = 1;
    // digitalWrite(ledPin, ledState);
    lastDebounceTime = currentTime;
  }
}


void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    if (ledflag == 1) {
      ledflag = 0;
      break;
    }
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void fadeIncolorWipe(uint8_t R, uint8_t G, uint8_t B, int wait) {


  for (int s = 1 ; s < 256 ; s++) {
    if (ledflag == 1) {
      exitflag = 1;
      ledflag = 0;
      break;
    }
    for (int i = 0; i < strip.numPixels(); i++) {

      strip.setPixelColor(i, strip.Color(R , G , B ));

    }
    strip.setBrightness(s);
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}


void fadeOutcolorWipe(uint8_t R, uint8_t G, uint8_t B, int wait) {


  for (int s = 255 ; s > 0 ; s--) {
    if (ledflag == 1) {
      exitflag = 1;
      ledflag = 0;
      break;
    }
    for (int i = 0; i < strip.numPixels(); i++) {

      strip.setPixelColor(i, strip.Color(R , G , B ));

    }
    strip.setBrightness(s);
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }

}
