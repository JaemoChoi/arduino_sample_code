import vlc
import serial
import subprocess
import os
import time

# 시리얼 포트와 속도
PORT = 'COM49'  # 포트 이름은 실제 장치에 맞게 변경
BAUDRATE = 9600

# VLC 경로
VLC_PATH = r"C:\Program Files\VideoLAN\VLC\vlc.exe"
FFPLAY_PATH = r"D:\coode_work\ffmpeg-2025-07-10-git-82aeee3c19-full_build\bin\ffplay.exe"
# 영상 파일 경로
VIDEO_MONITOR1_1 = r"d:\video\1_1.mp4"  # 1번 모니터 영상
VIDEO_MONITOR1_2 = r"d:\video\1_2.mp4"  # 2번 모니터 영상
VIDEO_MONITOR2_1 = r"d:\video\2_1.mp4"  # 1번 모니터 영상
VIDEO_MONITOR2_2 = r"d:\video\2_2.mp4"  # 2번 모니터 영상
BLACK_MONITOR1 = r"d:\video\black1.mp4" # 1번 모니터용 검은 영상
BLACK_MONITOR2 = r"d:\video\black2.mp4" # 2번 모니터용 검은 영상

def play_on_monitor(video_path, x, y, width, height):
    cmd = [
        VLC_PATH,
        video_path,
        "--video-x", str(x),
        "--video-y", str(y),
        "--width", str(width),
        "--height", str(height),
        "--no-video-deco",
        "--no-embedded-video",
       # "--fullscreen",
         "--qt-start-minimized"  # VLC 제어창 최소화
       # "--play-and-exit"
    ]
   
    subprocess.Popen(cmd)

ffplay_processes = []

def play_with_ffplay(video_path, left, top, width, height, mute=False):
    cmd = [
        FFPLAY_PATH,
        video_path,
        "-noborder",
        "-fs",
        "-x", str(width),
        "-y", str(height),
        "-left", str(left),
        "-top", str(top)
    ]
    if mute:
        cmd.append("-an")
    proc = subprocess.Popen(cmd)
    ffplay_processes.append(proc)

def kill_ffplay():
    # 실행 중인 ffplay 프로세스 직접 종료
    global ffplay_processes
    for proc in ffplay_processes:
        try:
            proc.terminate()
        except Exception:
            pass
    ffplay_processes = []

# 시리얼 연결
ser = serial.Serial(PORT, BAUDRATE)
print(f"Listening on {PORT}...")

# 블랙 초기화면 실행
play_with_ffplay(BLACK_MONITOR1, 0, 0, 2880, 1800)
play_with_ffplay(BLACK_MONITOR2, 2880, 0, 3440, 1440)

while True:
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()
        print(f"받은 데이터: {line}")
        kill_ffplay()
        if line.lower() == "1":
            print("▶ play 실행: 1_1.mp4 + 2_1.mp4")
            play_with_ffplay(VIDEO_MONITOR1_1, 0, 0, 2880, 1800,mute=True)
            play_with_ffplay(VIDEO_MONITOR2_1, 2880, 0, 3440, 1440, mute=False)
        elif line.lower() == "2":
            print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1_2, 0, 0, 2880, 1800, mute=True)
            play_with_ffplay(VIDEO_MONITOR2_2, 2880, 0, 3440, 1440, mute=False)
