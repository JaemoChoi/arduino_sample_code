
import serial
import subprocess
import os
import pygame
import time
import psutil  # 추가 설치 필요: pip install psutil
import ctypes  # 작업 표시줄 제어를 위한 라이브러리

# ffplay 프로세스를 관리하기 위한 변수
current_process = None
is_paused = False  # 현재 상태를 관리하는 변수 (False: 재생 중, True: 일시정지)

# 설정 파일에서 시리얼 포트와 BAUDRATE 읽기
def load_serial_config(config_file):
    config = {}
    with open(config_file, "r") as file:
        for line in file:
            key, value = line.strip().split("=")
            config[key] = value
    return config

# 작업 표시줄 숨기기
def hide_taskbar():
    ctypes.windll.user32.ShowWindow(ctypes.windll.kernel32.GetConsoleWindow(), 0)
    ctypes.windll.user32.ShowWindow(ctypes.windll.user32.FindWindowW("Shell_TrayWnd", None), 0)
    print("작업 표시줄 숨김")

# 작업 표시줄 표시
def show_taskbar():
    ctypes.windll.user32.ShowWindow(ctypes.windll.user32.FindWindowW("Shell_TrayWnd", None), 1)
    ctypes.windll.user32.ShowWindow(ctypes.windll.user32.FindWindowW("Shell_TrayWnd", None), 5)
    print("작업 표시줄 표시")


# 설정 파일 경로
CONFIG_FILE = r"C:\Humanoid_G\config.txt"

# 설정 파일에서 시리얼 포트와 BAUDRATE 읽기
serial_config = load_serial_config(CONFIG_FILE)
PORT = serial_config["PORT"]
BAUDRATE = int(serial_config["BAUDRATE"])

print(f"설정 파일에서 불러온 PORT: {PORT}, BAUDRATE: {BAUDRATE}")

# mp3 파일 경로
#AUDIO_FILE = r"d:\video\sound.mp3"  # 소리 파일 경로


# VLC 경로
FFPLAY_PATH = r"C:\Humanoid_G\ffmpeg-2025-09-22-git-c9168717bf-full_build\bin\ffplay.exe"
# 영상 파일 경로
VIDEO_MONITOR1 = {i+1: f"C:\Humanoid_G\Video\HG{i+1}.mp4" for i in range(10)}
#BLACK_MONITOR1 = r"d:\video\black1.mp4" # 1번 모니터용 검은 영상
#BLACK_MONITOR2 = r"d:\video\black2.mp4" # 2번 모니터용 검은 영상

hide_taskbar()

ffplay_processes = []
def play_with_ffplay(video_path, left, top, width, height, mute=False, rotate=0, add_black=False, loop=False):
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
    if rotate == 90:
        cmd.append("-vf")
        cmd.append("transpose=1")  # 90도 회전
    elif rotate == 180:
        cmd.append("-vf")
        cmd.append("transpose=2,transpose=2")  # 180도 회전
    elif rotate == 270:
        cmd.append("-vf")
        cmd.append("transpose=2")  # 270도 회전
    if add_black:
        cmd.append("-vf")
        cmd.append(f"color=c=black:size={width}x{height}")  # 블랙 화면 추가
    if loop:
        cmd.append("-loop")
        cmd.append("0")  # 0은 무한 반복
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

#play_with_ffplay(BLACK_MONITOR1, 0, 0, 1920, 1080)
#play_with_ffplay(BLACK_MONITOR2, 1920, 0, 1920, 1080)

# ffplay 프로세스 일시정지/재개 상태 변수
is_paused = False

def toggle_pause_resume():
    global current_process, is_paused
    if current_process and current_process.poll() is None:
        try:
            ps_proc = psutil.Process(current_process.pid)
            if is_paused:
                ps_proc.resume()  # 프로세스 재개
                print("동영상 재개")
                is_paused = False
            else:
                ps_proc.suspend()  # 프로세스 일시정지
                print("동영상 일시정지")
                is_paused = True
        except Exception as e:
            print(f"Pause/Resume 실패: {e}")
    # 동영상 재생 로직
    
try:
    while True:
        if ser.in_waiting:  # 시리얼 데이터가 수신되었는지 확인
            line = ser.readline().decode('utf-8').strip()  # 시리얼 데이터 읽기
            print(f"받은 데이터: {line}")
            if line == "99":  # Play/Pause 토글 명령
                toggle_pause_resume()
            kill_ffplay()
            #stop_audio()
            if line.lower() == "1":
                #print("▶ play 실행: 1_1.mp4 + 2_1.mp4")
                play_with_ffplay(VIDEO_MONITOR1[1], 0, 0, 2560, 1660, mute=False, rotate=0)
            elif line.lower() == "2":
                #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
                play_with_ffplay(VIDEO_MONITOR1[2], 0, 0, 2560, 1660, mute=False, rotate=0)
            elif line.lower() == "3":
                #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
                play_with_ffplay(VIDEO_MONITOR1[3], 0, 0, 2560, 1660, mute=False, rotate=0)
               
            elif line.lower() == "4":
                #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
                play_with_ffplay(VIDEO_MONITOR1[4], 0, 0, 2560, 1660, mute=False, rotate=0)
               

finally:
    # 프로그램 종료 시 작업 표시줄 다시 표시
    show_taskbar()
            
