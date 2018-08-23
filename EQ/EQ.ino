
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(98, 8, NEO_GRB+NEO_KHZ800); // Finger Print LED 12EA

int mode0[] = {0,1,2,3,4,5,6,7,10,13,
                14,17,20,21,24,27,36,37,38,39,
                40,42,45,48,49,53,55,56,57,62,
                64,65,66,67,68,69,70,71};

int mode1[] = {0,1,2,3,4,5,6,13,
                14,28,29,30,31,32,33,34,35,38,
                41,42,45,48,56,57,58,59,60,61,
                62,63,69,70,76,78,79,80,81,82};
               
int mode2[] = {0,1,2,3,4,5,6,7,10,13,
               15,16,18,19,21,28,29,30,
               31,32,33,34,35,43,44,45,46,47,
               49,55,56,62,64,65,66,67,68,70,
               71,72,73,74,75,76,77,80,87,90};
               
int mode3[] = {0,1,2,3,4,5,6,7,10,13,
               15,16,18,19,21,28,29,30,
               31,32,33,34,35,43,44,45,46,47,
               49,55,56,62,64,65,66,67,68,70,
               71,72,73,74,75,76,78,79,85,86,
               91,92,93,94,95,96,97};

int R = 5;
int G = 5;
int B = 5;
int Led_color = 1;

int strobe = 4; // strobe pins on digital 4
int res = 5; // reset pins on digital 5
int left[7]; // store band values in these arrays
int right[7];
int eq_power[14];
int frq_band[14] = {0,13,14,27,28,41,42,55,56,69,70,83,84,97};
int band;
int MODE = 0; // Gradation_EQ
int Weight = 20;

int Input_key1 = 2;
int Input_key2 = 3;

int EQ_flag = 0;
int Light_flag = 0;
int BT_flag = 0;

int EQ_status = 1; // Gradation EQ
int Light_status = 1; // White
int BT_status = 1; // BT On

// Setup //////////////////////////////////////////////////
void setup()
{
 Serial.begin(115200);
 pinMode(7,OUTPUT); // BT Power on/off relay control
 pinMode(0,INPUT);  // BT Sound analog input
 pinMode(res, OUTPUT); // reset
 pinMode(strobe, OUTPUT); // strobe
 attachInterrupt(digitalPinToInterrupt(Input_key1), Input_key1_ISR, RISING); 
 
 digitalWrite(res,LOW); // reset low
 digitalWrite(strobe,HIGH); //pin 5 is RESET on the shield
 digitalWrite(7,LOW); // Relay Off => BT Power on

 strip.begin();
 strip.show();
 
}

void readMSGEQ7()
// Function to read 7 band equalizers
{
 digitalWrite(res, HIGH);
 delayMicroseconds(100);
 digitalWrite(res, LOW);
 delayMicroseconds(100);
 for(band=0; band <7; band++)
 {
 digitalWrite(strobe,LOW); // strobe pin on the shield - kicks the IC up to the next band 
 delayMicroseconds(100); // 
 
 left[band] = analogRead(0); // store left band reading
 if (left[band] > 800) left[band] = 600;
 if (left[band] < 30 ) left[band] = 30;
 
 eq_power[band] = map(left[band],30,700,1,7);
 
 digitalWrite(strobe,HIGH); 
 delayMicroseconds(100);
 }
  eq_power[4] = (eq_power[3]+eq_power[5])/2;
  eq_power[7] = (eq_power[0]+eq_power[1])/2;
  eq_power[8] = (eq_power[1]+eq_power[2])/2;
  eq_power[9] = (eq_power[2]+eq_power[3])/2;
  eq_power[10] = (eq_power[3]+eq_power[4])/2;
  eq_power[11] = (eq_power[4]+eq_power[5])/2;
  eq_power[12] = (eq_power[5]+eq_power[6])/2;
  eq_power[13] = (eq_power[6]+eq_power[0])/2;
}

void loop(){
  
 if (MODE == 0) { // EQ Mode
  readMSGEQ7();
  if (EQ_status == 1) Gradation_EQ();
  if (EQ_status == 2 ) Rainbow_EQ();
 }

//test code

 if (MODE == 1){ // Light Mode
  int KEY1 = digitalRead(Input_key1);
  int KEY2 = digitalRead(Input_key2);
  
  if (KEY2 == HIGH) Led_color++;
  if (Led_color == 7) Led_color = 1;
  delay(200);
  Led_select_color();
  if (Light_status == 1) Light1();
  if (Light_status == 2) Light2();
  if (Light_status == 3) Light3();
  if (Light_status == 4) strip_off();
  
//test code end

/*
 if (MODE == 1){ // Light Mode
  int KEY2 = digitalRead(Input_key2);
  
  if (KEY2 == HIGH) Led_color++;
  if (Led_color == 7) Led_color = 1;
  Led_select_color();
  if (Light_status == 1) Light1();
  if (Light_status == 2) Light2();
  if (Light_status == 3) Light3();
  if (Light_status == 4) strip_off();
 */ 
  }

 if (MODE == 2){ // BT Power Off
    BT_OFF();
   // MODE = 0 ;
    EQ_status = 1; // after BT Power off, go to Light Mode
  }
  
 if (MODE == 3) { // BT Power On
   BT_ON();
  // MODE = 1;
   Light_status = 1; // after BT Power on, go to EQ Mode
 }
 
 // display values of left channel on serial monitor
/*
 for (band = 0; band < 7; band++)
 {
 Serial.print(eq_power[band]);
 Serial.print(" ");
 }
 Serial.println();
*/
}

void Input_key1_ISR(){
  int input_key2_value = digitalRead(Input_key2);
   if (input_key2_value == HIGH) {
// test code
        MODE++;
        if (MODE == 4) MODE = 0;
        Change_Mode();
        }
      
// test code end
 
 /*
      delay(1000);
      int input_key1_value = digitalRead(Input_key1);
      int input_key2_value = digitalRead(Input_key2);
      if ((input_key1_value == HIGH) && (input_key2_value == HIGH)) {
        MODE = MODE + 1;
        if (MODE == 4) MODE = 0;
        Change_Mode();
        }
 */
  else if (EQ_flag == 1) {
     EQ_status = EQ_status + 1;
     if (EQ_status == 3) EQ_status = 1; 
    }

  else if (Light_flag == 1) {
     Light_status = Light_status + 1;
     if (Light_status == 5) Light_status = 1; 
    }

  else if (BT_flag == 1) {
     BT_status = BT_status + 1;
     if (BT_status == 3) BT_status = 1; 
    }
}

void Change_Mode(){
  
  if (MODE == 0) {
    strip_off(); // clear LED
    mode0_LED(strip.Color(20,5,5),0); // "EQ" EQ_Mode
    delay(2000);
  }
  if (MODE == 1){
    strip_off(); // clear LED
    mode1_LED(strip.Color(10,10,10),0); // "LED" Light_Mode
     delay(2000);
  }
  
  if (MODE == 2){
    strip_off(); // clear LED
    mode2_LED(strip.Color(20,0,0),0); // "BT OFF" BT_OFF_Mode
     delay(2000);
  }

  if (MODE == 3){
    strip_off(); // clearLED 
    mode3_LED(strip.Color(0,0,20),0); // "BT ON" BT_ON_Mode
    delay(2000);
  }
  
}
void Rainbow_EQ(){
 EQ_flag = 1;

// Others flag clear
 Light_flag = 0; 
 BT_flag = 0;
 
 EQ_band0(strip.Color(5,0,0),0);
 EQ_band1(strip.Color(0,5,0),0);
 EQ_band2(strip.Color(0,0,5),0);
 EQ_band3(strip.Color(5,5,0),0);
 EQ_band4(strip.Color(5,0,5),0);
 EQ_band5(strip.Color(5,5,5),0);
 EQ_band6(strip.Color(0,5,5),0);

 EQ_band7(strip.Color(7,3,0),0);
 EQ_band8(strip.Color(5,5,3),0);
 EQ_band9(strip.Color(3,0,7),0);
 EQ_band10(strip.Color(5,5,3),0);
 EQ_band11(strip.Color(5,3,5),0);
 EQ_band12(strip.Color(10,2,2),0);
 EQ_band13(strip.Color(3,7,10),0);
 strip.setBrightness(150);
 strip.show();
 delay(50);
}

void Gradation_EQ(){
  EQ_flag = 1;

  // Others flag clear
  Light_flag = 0;
  BT_flag = 0;
  
  EQ_0();
  EQ_1();
  EQ_2();
  EQ_3();
  EQ_4();
  EQ_5();
  EQ_6();
  EQ_7();
  EQ_8();
  EQ_9();
  EQ_10();
  EQ_11();
  EQ_12();
  EQ_13();
 strip.setBrightness(150);
  strip.show();
  delay(50);
}

void Led_select_color(){
 
  if (Led_color == 1) {
    R = 80;
    G = 0;
    B = 0;
  }
  if (Led_color == 2) {
    R = 10;
    G = 80;
    B = 10;
  }
  if (Led_color == 3) {
    R = 10;
    G = 10;
    B = 80;
  }
  if (Led_color == 4) {
    R = 50;
    G = 50;
    B = 50;
  }
  if (Led_color == 5) {
    R = 50;
    G = 50;
    B = 0;
  }
  if (Led_color == 6) {
    R = 0;
    G = 50;
    B = 50;
  }
 
}

void Light1(){  // LED brightness 10%
  Light_flag = 1;

  // Others flag clear
  EQ_flag = 0;
  BT_flag = 0;
  
     for(uint16_t i=0; i< 98; i++)
   {
    strip.setPixelColor(i, strip.Color(R,G,B));
      }
     
  strip.setBrightness(30);    
  strip.show();
  delay(100);
}

void Light2(){  // LED brightness 20%
  Light_flag = 1;
  EQ_flag = 0;
  BT_flag = 0;

  
     for(uint16_t i=0; i< 98; i++)
   {
    strip.setPixelColor(i, strip.Color(R,G,B));
      }
  strip.setBrightness(60);
  strip.show();
  delay(100);
}
void Light3(){  // LED brightness 30%
  Light_flag = 1;

  // Others flag clear
  EQ_flag = 0;
  BT_flag = 0;
  
     for(uint16_t i=0; i< 98; i++)
   {
    strip.setPixelColor(i, strip.Color(R,G,B));
      }
  strip.setBrightness(100);
  strip.show();
  delay(100);
}


void BT_OFF(){
  digitalWrite(7,HIGH); // relay off
  MODE = 1; // go to Light mode
}

void BT_ON(){
  digitalWrite(7,LOW); // relay on
  MODE = 0; // go to EQ mode
  }

////////////////////////////////////////////////////////// Color EQ Display
void EQ_band0(uint32_t c, uint8_t wait) {
   for(uint16_t i=frq_band[0]; i< eq_power[0]; i++)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=eq_power[0]; i< 7; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band1(uint32_t c, uint8_t wait) {
   for(uint16_t i=frq_band[1]; i> frq_band[1]-eq_power[1]; i--)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[1]-eq_power[1]; i> 6; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band2(uint32_t c, uint8_t wait) {

  for(uint16_t i=frq_band[2]; i< frq_band[2]+eq_power[2]; i++)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[2]+eq_power[2]; i< 21; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band3(uint32_t c, uint8_t wait) {


  for(uint16_t i=frq_band[3]; i> frq_band[3]-eq_power[3]; i--)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[3]-eq_power[3]; i> 20; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band4(uint32_t c, uint8_t wait) {


  for(uint16_t i=frq_band[4]; i< frq_band[4]+eq_power[4]; i++)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[4]+eq_power[4]; i< 35; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band5(uint32_t c, uint8_t wait) {

  for(uint16_t i=frq_band[5]; i> frq_band[5]-eq_power[5]; i--)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[5]-eq_power[5]; i> 34; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band6(uint32_t c, uint8_t wait) {
  for(uint16_t i=frq_band[6]; i< frq_band[6]+eq_power[6]; i++)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[6]+eq_power[6]; i< 49; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band7(uint32_t c, uint8_t wait) {

  for(uint16_t i=frq_band[7]; i> frq_band[7]-eq_power[7];i--)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[7]-eq_power[7]; i> 48; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band8(uint32_t c, uint8_t wait) {
  for(uint16_t i=frq_band[8]; i< frq_band[8]+eq_power[8]; i++)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[8]+eq_power[8]; i< 63; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band9(uint32_t c, uint8_t wait) {

  for(uint16_t i=frq_band[9]; i> frq_band[9]-eq_power[9]; i--)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[9]-eq_power[9]; i> 62; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band10(uint32_t c, uint8_t wait) {
  for(uint16_t i=frq_band[10]; i< frq_band[10]+eq_power[10]; i++)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[10]+eq_power[10]; i< 77; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band11(uint32_t c, uint8_t wait) {

  for(uint16_t i=frq_band[11]; i> frq_band[11]-eq_power[11]; i--)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[11]-eq_power[11]; i> 76; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band12(uint32_t c, uint8_t wait) {
  for(uint16_t i=frq_band[12]; i< frq_band[12]+eq_power[12]; i++)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[12]+eq_power[12]; i< 91; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_band13(uint32_t c, uint8_t wait) {

  for(uint16_t i=frq_band[13]; i> frq_band[13]-eq_power[13]; i--)
   {
    strip.setPixelColor(i, c);
      }
   for(uint16_t i=frq_band[13]-eq_power[13]; i> 90; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

/////////////////////////////////////////////////// Gradation EQ Display
void EQ_0() {
   for(uint16_t i=frq_band[0]; i< eq_power[0]; i++)
   {
    strip.setPixelColor(i,strip.Color(Weight*(eq_power[0]-i),i+1,i+1));
      }
   for(uint16_t i=eq_power[0]; i< 7; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_1() {
   for(uint16_t i=frq_band[1]; i> frq_band[1]-eq_power[1]; i--)
   {
    strip.setPixelColor(i,strip.Color(Weight*(eq_power[1]-(frq_band[1]-i)),frq_band[1]-i+1,frq_band[1]-i+1));
      }
   for(uint16_t i=frq_band[1]-eq_power[1]; i> 6; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_2() {

  for(uint16_t i=frq_band[2]; i< frq_band[2]+eq_power[2]; i++)
   {
    strip.setPixelColor(i,strip.Color(Weight*(eq_power[2]-(i-frq_band[2])),i-frq_band[2]+1,i-frq_band[2]+1));
      }
   for(uint16_t i=frq_band[2]+eq_power[2]; i< 21; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_3() {

  for(uint16_t i=frq_band[3]; i> frq_band[3]-eq_power[3]; i--)
   {
   strip.setPixelColor(i,strip.Color(Weight*(eq_power[3]-(frq_band[3]-i)),frq_band[3]-i+1,frq_band[3]-i+1));
      }
   for(uint16_t i=frq_band[3]-eq_power[3]; i> 20; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_4() {

  for(uint16_t i=frq_band[4]; i< frq_band[4]+eq_power[4]; i++)
   {
   strip.setPixelColor(i,strip.Color(Weight*(eq_power[4]-(i-frq_band[4])),i-frq_band[4]+1,i-frq_band[4]+1));
      }
   for(uint16_t i=frq_band[4]+eq_power[4]; i< 35; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_5() {
  
  for(uint16_t i=frq_band[5]; i> frq_band[5]-eq_power[5]; i--)
   {
   strip.setPixelColor(i,strip.Color(Weight*(eq_power[5]-(frq_band[5]-i)),frq_band[5]-i+1,frq_band[5]-i+1));
      }
   for(uint16_t i=frq_band[5]-eq_power[5]; i> 34; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_6() {
  for(uint16_t i=frq_band[6]; i< frq_band[6]+eq_power[6]; i++)
   {
     strip.setPixelColor(i,strip.Color(Weight*(eq_power[6]-(i-frq_band[6])),i-frq_band[6]+1,i-frq_band[6]+1));
      }
   for(uint16_t i=frq_band[6]+eq_power[6]; i< 49; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_7() {

  for(uint16_t i=frq_band[7]; i> frq_band[7]-eq_power[7];i--)
   {
    strip.setPixelColor(i,strip.Color(Weight*(eq_power[7]-(frq_band[7]-i)),frq_band[7]-i+1,frq_band[7]-i+1));
      }
   for(uint16_t i=frq_band[7]-eq_power[7]; i> 48; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_8() {
  for(uint16_t i=frq_band[8]; i< frq_band[8]+eq_power[8]; i++)
   {
    strip.setPixelColor(i,strip.Color(Weight*(eq_power[8]-(i-frq_band[8])),i-frq_band[8]+1,i-frq_band[8]+1));
      }
   for(uint16_t i=frq_band[8]+eq_power[8]; i< 63; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_9() {

  for(uint16_t i=frq_band[9]; i> frq_band[9]-eq_power[9]; i--)
   {
    strip.setPixelColor(i,strip.Color(Weight*(eq_power[9]-(frq_band[9]-i)),frq_band[9]-i+1,frq_band[9]-i+1));
      }
   for(uint16_t i=frq_band[9]-eq_power[9]; i> 62; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_10() {
  for(uint16_t i=frq_band[10]; i< frq_band[10]+eq_power[10]; i++)
   {
     strip.setPixelColor(i,strip.Color(Weight*(eq_power[10]-(i-frq_band[10])),i-frq_band[10]+1,i-frq_band[10]+1));
      }
   for(uint16_t i=frq_band[10]+eq_power[10]; i< 77; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_11() {

  for(uint16_t i=frq_band[11]; i> frq_band[11]-eq_power[11]; i--)
   {
    strip.setPixelColor(i,strip.Color(Weight*(eq_power[11]-(frq_band[11]-i)),frq_band[11]-i+1,frq_band[11]-i+1));
      }
   for(uint16_t i=frq_band[11]-eq_power[11]; i> 76; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_12() {
  for(uint16_t i=frq_band[12]; i< frq_band[12]+eq_power[12]; i++)
   {
     strip.setPixelColor(i,strip.Color(Weight*(eq_power[12]-(i-frq_band[12])),i-frq_band[12]+1,i-frq_band[12]+1));
      }
   for(uint16_t i=frq_band[12]+eq_power[12]; i< 91; i++)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

void EQ_13() {

  for(uint16_t i=frq_band[13]; i> frq_band[13]-eq_power[13]; i--)
   {
   strip.setPixelColor(i,strip.Color(Weight*(eq_power[13]-(frq_band[13]-i)),frq_band[13]-i+1,frq_band[13]-i+1));
      }
   for(uint16_t i=frq_band[13]-eq_power[13]; i> 90; i--)
   {
    strip.setPixelColor(i, strip.Color(0,0,0));
      }
}

////////////////////////////////////////////// MODE Character Display
void mode0_LED(uint32_t c, uint8_t wait) { // "EQ"
  for(uint16_t i=0; i<38; i++) {
    strip.setPixelColor(mode0[i], c);
   
   // delay(wait);
  }
   strip.show();
}

void mode1_LED(uint32_t c, uint8_t wait) { // "LED"
  for(uint16_t i=0; i<38; i++) {
    strip.setPixelColor(mode1[i], c);
   
  //  delay(wait);
  }
   strip.show();
}

void mode2_LED(uint32_t c, uint8_t wait) { // "BT ON"
  for(uint16_t i=0; i<48; i++) {
    strip.setPixelColor(mode2[i], c);
   
  //  delay(wait);
  }
   strip.show();
}

void mode3_LED(uint32_t c, uint8_t wait) { // "BT OFF"
  for(uint16_t i=0; i<55; i++) {
    strip.setPixelColor(mode3[i], c);
   
  //  delay(wait);
  }
   strip.show();
}

void strip_off(){ // LED Clear(Off)
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
 
  }
     strip.show();
}

