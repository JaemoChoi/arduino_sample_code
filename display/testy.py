import serial
import subprocess
import threading

# 🔌 아두이노 시리얼 포트 설정 (COM49 → 본인 PC에 맞게 수정)
ser = serial.Serial("COM49", 9600, timeout=1)

# 🎬 ffplay 실행 함수
def play_video(cmd):
    subprocess.run(cmd)

# 🎬 모니터1 (좌측, 1920x1080 해상도)
cmd1 = [
    "ffplay", "-noborder",
    "-x", "1920", "-y", "1080",
    "-left", "0", "-top", "0",
    "-autoexit",
    "video_a.mp4"
]

# 🎬 모니터2 (우측, 1920x1080 해상도)
cmd2 = [
    "ffplay", "-noborder",
    "-x", "1920", "-y", "1080",
    "-left", "1920", "-top", "0",
    "-autoexit",
    "video_b.mp4"
]

print("시리얼 데이터 대기중... (예: 'play1')")

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode().strip()
        print("받은 데이터:", data)

        if data.lower() == "play1":  # 아두이노에서 "play1" 보냈을 때
            t1 = threading.Thread(target=play_video, args=(cmd1,))
            t2 = threading.Thread(target=play_video, args=(cmd2,))
            t1.start()
            t2.start()