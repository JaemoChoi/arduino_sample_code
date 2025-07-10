import processing.serial.*;
import java.io.*;

Serial myPort;
String incomingData = "";

void setup() {
  size(400, 100);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);  // 포트 인덱스 확인 필요
  myPort.bufferUntil('\n');
}

void serialEvent(Serial p) {
  incomingData = p.readStringUntil('\n');
  if (incomingData != null) {
    incomingData = trim(incomingData);
    println("받은 데이터: " + incomingData);
    
    if (incomingData.equals("play1")) {
      playVideo("C:/videos/movie1.mp4");
    } else if (incomingData.equals("play2")) {
      playVideo("C:/videos/movie2.mp4");
    }
  }
}

void playVideo(String path) {
  try {
    // VLC 실행 (경로 수정 필요)
    String vlcPath = "C:/Program Files/VideoLAN/VLC/vlc.exe";
    Process p = Runtime.getRuntime().exec("\"" + vlcPath + "\" \"" + path + "\"");
  } catch (IOException e) {
    println("에러: " + e.getMessage());
  }
}