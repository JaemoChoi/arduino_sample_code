//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(2,1);       // 2:RX, 1:Tx

#include <WiFiNINA.h>
#include <utility/wifi_drv.h>

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  pinMode(6, OUTPUT);

  digitalWrite(6, HIGH);

  WiFiDrv::pinMode(25, OUTPUT);  //define GREEN LED
  WiFiDrv::pinMode(26, OUTPUT);  //define RED LED
  WiFiDrv::pinMode(27, OUTPUT);  //define BLUE LED

  WiFiDrv::analogWrite(25, 255);  //GREEN
  WiFiDrv::analogWrite(26, 255);  //RED
  WiFiDrv::analogWrite(27, 255);  //BLUE
}

void loop() {
  // put your main code here, to run repeatedly:


  if (Serial1.available()) {
    char c = Serial1.read();
    Serial.println(c);

    if (c == '1') {
      WiFiDrv::analogWrite(25, 255);  //GREEN
      WiFiDrv::analogWrite(26, 0);    //RED
      WiFiDrv::analogWrite(27, 0);    //BLUE
    }
    if (c == '2') {
      WiFiDrv::analogWrite(25, 0);    //GREEN
      WiFiDrv::analogWrite(26, 255);  //RED
      WiFiDrv::analogWrite(27, 0);    //BLUE
    }
    if (c == '3') {
      WiFiDrv::analogWrite(25, 0);    //GREEN
      WiFiDrv::analogWrite(26, 0);    //RED
      WiFiDrv::analogWrite(27, 255);  //BLUE
    }
  }
}
