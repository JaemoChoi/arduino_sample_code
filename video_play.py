import serial
import subprocess
import os

# 아두이노 연결된 포트 (예: COM3 또는 /dev/ttyUSB0)
PORT = 'COM3'
BAUDRATE = 9600

# 동영상 파일 경로
VIDEOS = {
    "play1": r"C:\videos\movie1.mp4",
    "play2": r"C:\videos\movie2.mp4",
}

# 시리얼 포트 열기
ser = serial.Serial(PORT, BAUDRATE)
print(f"Listening on {PORT}...")

while True:
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()
        print(f"받은 데이터: {line}")

        if line in VIDEOS:
            video_path = VIDEOS[line]
            print(f"재생: {video_path}")
            try:
                # VLC 대신 기본 플레이어로 실행
                os.startfile(video_path)  # Windows only
                # 또는 subprocess 방식
                # subprocess.Popen(['cmd', '/c', 'start', '', video_path])
            except Exception as e:
                print(f"에러: {e}")