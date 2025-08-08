import serial
import subprocess
import os
import time

# 시리얼 포트와 속도
PORT = 'COM6'  # 포트 이름은 실제 장치에 맞게 변경
BAUDRATE = 9600

# FFPLAY 경로
FFPLAY_PATH = r"D:\Util\ffmpeg-2025-08-04-git-9a32b86307-full_build\bin\ffplay.exe"
# 영상 파일 경로
VIDEO_MONITOR1_1 = r"D:\Videos\video_shorts_02.mp4"  # 1번 모니터 영상
VIDEO_MONITOR1_2 = r"D:\Videos\video_shorts_03.mp4"  # 2번 모니터 영상
VIDEO_MONITOR2_1 = r"D:\Videos\video_shorts_04.mp4"  # 1번 모니터 영상
VIDEO_MONITOR2_2 = r"D:\Videos\video_shorts_05.mp4"  # 2번 모니터 영상
VIDEO_MONITOR1_3 = r"D:\Videos\video_shorts_06.mp4"  # 1번 모니터 영상
VIDEO_MONITOR2_3 = r"D:\Videos\video_shorts_07.mp4"  # 2번 모니터 영상
#BLACK_MONITOR1 = r"d:\video\black1.mp4" # 1번 모니터용 검은 영상
#BLACK_MONITOR2 = r"d:\video\black2.mp4" # 2번 모니터용 검은 영상

ffplay_processes = []

def play_with_ffplay1(video_path, left, top, width, height, mute=False):
    cmd = [
        FFPLAY_PATH,
        video_path,
        "-noborder",
        "-fs",
        "-x", str(width),
        "-y", str(height),
        "-left", str(left),
        "-top", str(top),
        "-vf","transpose=2" # CCW 90도 회전
    ]
    if mute:
        cmd.append("-an")
    proc = subprocess.Popen(cmd)
    ffplay_processes.append(proc)

def play_with_ffplay2(video_path, left, top, width, height, mute=False):
    cmd = [
        FFPLAY_PATH,
        video_path,
        "-noborder",
        "-fs",
        "-x", str(width),
        "-y", str(height),
        "-left", str(left),
        "-top", str(top),
        "-vf","transpose=1" # CW 90도 회전
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
#play_with_ffplay(BLACK_MONITOR1, 0, 0, 1920, 1800)
#play_with_ffplay(BLACK_MONITOR2, 2880, 0, 3440, 1440)

while True:
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()
        print(f"받은 데이터: {line}")
        kill_ffplay()
        if line.lower() == "1":
            #print("▶ play 실행: 1_1.mp4 + 2_1.mp4")
            play_with_ffplay1(VIDEO_MONITOR1_1,    0, 0, 1920, 1080, mute = True)
            play_with_ffplay2(VIDEO_MONITOR2_1, 1920, 0, 2560, 1440, mute = False)
           
        elif line.lower() == "2":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay1(VIDEO_MONITOR1_2,    0, 0, 1920, 1080, mute = True)
            play_with_ffplay2(VIDEO_MONITOR2_2, 1920, 0, 2560, 1440, mute = False)
            
        elif line.lower() == "3":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay1(VIDEO_MONITOR1_3,    0, 0, 1920, 1080, mute = True)
            play_with_ffplay2(VIDEO_MONITOR2_3, 1920, 0, 2560, 1440, mute = False)
