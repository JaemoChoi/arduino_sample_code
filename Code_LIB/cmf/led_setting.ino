#include <Adafruit_NeoPixel.h> // Adafruit NeoPixel 라이브러리 포함
#include <SoftwareSerial.h>      // 소프트웨어 시리얼 라이브러리 포함

// --- 설정 값 (사용자 환경에 맞게 수정) ---
#define LED_PIN    5  // NeoPixel 데이터 핀 번호
#define LED_COUNT  100 // 연결된 LED의 총 개수
#define BT_RX_PIN  8  // 블루투스 모듈의 TX와 연결될 핀
#define BT_TX_PIN  7  // 블루투스 모듈의 RX와 연결될 핀

// NeoPixel 객체 생성 (GRBW 타입으로 설정)
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// 블루투스 통신을 위한 SoftwareSerial 객체 생성
SoftwareSerial BTSerial(BT_RX_PIN, BT_TX_PIN);

String receivedString = ""; // 블루투스로부터 수신한 데이터를 저장할 변수

void setup() {
  Serial.begin(9600);      // PC와의 시리얼 통신 시작 (디버깅용)
  BTSerial.begin(9600);    // 블루투스 모듈과의 통신 시작 (HC-06의 기본 속도)

  strip.begin();           // NeoPixel 라이브러리 초기화
  strip.show();            // 모든 LED를 끈 상태로 시작
  strip.setBrightness(255); // 밝기 설정 (0~255), 너무 밝으면 전력 소모가 크니 주의!
  
  Serial.println("아두이노 준비 완료. 블루투스 연결을 기다립니다...");
}

void loop() {
  // 블루투스 시리얼을 통해 데이터가 수신되었는지 확인
  while (BTSerial.available()) {
    char inChar = (char)BTSerial.read(); // 데이터를 한 글자씩 읽음
    
    // 안드로이드 앱에서 보낸 데이터의 끝을 의미하는 '\n' (줄바꿈) 문자를 받으면
    if (inChar == '\n') {
      Serial.print("수신된 데이터: ");
      Serial.println(receivedString);
      
      // 수신된 문자열을 파싱하여 LED 색상으로 변환하는 함수 호출
      parseAndSetColor(receivedString);
      
      // 다음 데이터를 받기 위해 문자열 변수를 비움
      receivedString = ""; 
    } else {
      // 줄바꿈 문자가 아니면 문자열에 계속 추가
      receivedString += inChar;
    }
  }
}

// 수신된 문자열(예: "255,0,0,0")을 파싱하여 LED 색상을 설정하는 함수
void parseAndSetColor(String data) {
  // 쉼표(,)를 기준으로 문자열을 잘라 각 색상 값을 추출
  int r = getValue(data, ',', 0).toInt();
  int g = getValue(data, ',', 1).toInt();
  int b = getValue(data, ',', 2).toInt();
  int w = getValue(data, ',', 3).toInt();

  // 디버깅을 위해 시리얼 모니터에 파싱된 값 출력
  Serial.print("R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" W: "); Serial.println(w);

  // 모든 LED의 색상을 한 번에 동일하게 설정
  for(int i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(r, g, b, w));
  }
  
  // 변경된 색상 정보를 LED에 실제로 적용
  strip.show(); 
}

// 쉼표로 구분된 문자열에서 특정 순서(index)의 값을 추출하는 함수
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
