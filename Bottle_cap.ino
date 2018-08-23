// Example 48.1 - tronixstuff.com/tutorials > chapter 48 - 30 Jan 2013 
// MSGEQ7 spectrum analyser shield - basic demonstration
#include <Adafruit_NeoPixel.h>
#include "nxd.h"

#define PIN 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(70, PIN, NEO_GRB + NEO_KHZ800);
//   strip.begin() 
//   strip.show() 
//   strip.Color(R,G,B)=> 32bit 
//   strip.setPixelColor(Neo_pixle_No,Color), 

int strobe = 4; // strobe pins on digital 4
int res = 5; // reset pins on digital 5
int input_key = 2; // External Interrupt PIN
int left[7]; // store band values in these arrays
int eq_power[7]; // Spectrum Power Value 
int band;
int w = 0;


// Each Band start position
int LED_Banda = 0;
int LED_Bandb = 10;
int LED_Bandc = 20;
int LED_Bandd = 30;
int LED_Bande = 40;
int LED_Bandf = 50;
int LED_Bandg = 60;

void setup()
{
  Serial.begin(115200);
 
  pinMode(res, OUTPUT); // reset
  pinMode(strobe, OUTPUT); // strobe
  
  pinMode(input_key,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(input_key), KEY, FALLING); 
  
  pinMode(A0,INPUT); 
  digitalWrite(res,LOW); // reset 
  digitalWrite(strobe,HIGH); //pin 5 is RESET on the shield

  strip.begin();
 strip.setBrightness(127);
  strip.show(); // Initialize all pixels to 'off'
}
void readMSGEQ7(){
// Function to read 7 band equalizers
     digitalWrite(res, HIGH);
     digitalWrite(res, LOW);
     for(band=0; band <7; band++){
     digitalWrite(strobe,LOW); // strobe pin on the shield - kicks the IC up to the next band 
     delayMicroseconds(30); // 
     left[band] = analogRead(A0); // store left band reading
     eq_power[band] = map(left[band],0,1023,0,10);
     digitalWrite(strobe,HIGH); 
     } 
}

void light_EQ(){
  colorWipe_Banda(strip.Color(10,0,0),0);
  colorWipe_Bandb(strip.Color(10,0,0),0);
  colorWipe_Bandc(strip.Color(10,0,0),0);
  colorWipe_Bandd(strip.Color(10,0,0),0);
  colorWipe_Bande(strip.Color(10,0,0),0);
  colorWipe_Bandf(strip.Color(10,0,0),0);
  colorWipe_Bandg(strip.Color(10,0,0),0);
  strip.show();
  delay(50); 
}

void light_MODE(){

  colorWipe_MODE1(strip.Color(50,0,0),0);
    strip.show();
    delay(500);
    lightOff();
    
  colorWipe_MODE2(strip.Color(20,20,20),0);
    strip.show();
    delay(500);
    lightOff();

  colorWipe_MODE3(strip.Color(0,0,50),0);
    strip.show();
    delay(500);
    lightOff();

  colorWipe_MODE4(strip.Color(0,50,0),0);
    strip.show();
    delay(500);
    lightOff();
}

void sensor_in_dimming(){
  int flex_sensor_value = analogRead(A0);
  int dimming_value = map(flex_sensor_value,0,1023,0,255);
  analogWrite(5,dimming_value);
  dimming_light(strip.Color(0,dimming_value,0),0);
}

void loop(){
 
 if (w == 1) {
  readMSGEQ7();
  light_EQ();
 }
 if (w == 0) light_MODE();
   
/*
   for (band = 0; band < 7; band++){
   Serial.print(left[band]);
   Serial.println(" ");
   }

// display values of right channel on serial monitor
   for (band = 0; band < 7; band++){
   Serial.print(eq_power[band]);
   Serial.println(" ");
   }
  */ 
}

void lightOff(){
   for(uint16_t i=0; i< 70; i++) {
      strip.setPixelColor(i,0,0,0);
      delay(10);
    }
}

void dimming_light(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i< 69; i++) {
      strip.setPixelColor(i, c);
      delay(wait);
    }
    strip.show();
}

void colorWipe_MODE1(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i< 25; i++) {
      strip.setPixelColor(MODE1[i], c);
      delay(wait);
    }
}

void colorWipe_MODE2(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i< 26; i++) {
      strip.setPixelColor(MODE2[i], c);
      delay(wait);
    }
}

void colorWipe_MODE3(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i< 26; i++) {
      strip.setPixelColor(MODE3[i], c);
      delay(wait);
    }
}

void colorWipe_MODE4(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i< 28; i++) {
      strip.setPixelColor(MODE4[i], c);
      delay(wait);
    }
}




void colorWipe_Banda(uint32_t c, uint8_t wait) {
    for(uint16_t i=LED_Banda; i< LED_Banda + eq_power[0]; i++) {
      strip.setPixelColor(i, c);
      delay(wait);
    }
    for(uint16_t i = LED_Banda + eq_power[0]; i< 10; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    delay(wait);
    }
}

void colorWipe_Bandb(uint32_t c, uint8_t wait) {
  for(uint16_t i=LED_Bandb; i< LED_Bandb + eq_power[1]; i++) {
    strip.setPixelColor(i, c);
    delay(wait);
  }
   for(uint16_t i=LED_Bandb + eq_power[1]; i< 20; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    delay(wait);
  }
  
}

void colorWipe_Bandc(uint32_t c, uint8_t wait) {
  for(uint16_t i=LED_Bandc; i< LED_Bandc + eq_power[2]; i++) {
    strip.setPixelColor(i, c);
    delay(wait);
  }
    for(uint16_t i=LED_Bandc + eq_power[2]; i< 30; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    delay(wait);
  }
}

void colorWipe_Bandd(uint32_t c, uint8_t wait) {
   for(uint16_t i=LED_Bandd; i < LED_Bandd + eq_power[3]; i++) {
    strip.setPixelColor(i, c);
      delay(wait);
  }
   for(uint16_t i=LED_Bandd + eq_power[3]; i< 40; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    delay(wait);
  }
}

void colorWipe_Bande(uint32_t c, uint8_t wait) {
   for(uint16_t i=LED_Bande; i< LED_Bande + eq_power[4]; i++) {
    strip.setPixelColor(i, c);
    delay(wait);
  }
    for(uint16_t i=LED_Bande + eq_power[4]; i< 50; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    delay(wait);
  }
}

void colorWipe_Bandf(uint32_t c, uint8_t wait) {
  for(uint16_t i=LED_Bandf; i <  LED_Bandf + eq_power[5]; i++) {
    strip.setPixelColor(i, c);
    delay(wait);
  }
   for(uint16_t i=LED_Bandf + eq_power[5]; i < 60; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    delay(wait);
  }
}

void colorWipe_Bandg(uint32_t c, uint8_t wait) {
  for(uint16_t i=LED_Bandg; i< LED_Bandg + eq_power[6]; i++) {
    strip.setPixelColor(i, c);
    delay(wait);
  }
    for(uint16_t i=LED_Bandg + eq_power[6]; i< 70; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    delay(wait);
  }
}

void KEY(){
  w=1-w;
}


