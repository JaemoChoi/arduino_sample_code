import serial
import subprocess
import os
import pygame
import time
import psutil  # 추가 설치 필요: pip install psutil

# 설정 파일에서 시리얼 포트와 BAUDRATE 읽기
def load_serial_config(config_file):
    config = {}
    with open(config_file, "r") as file:
        for line in file:
            key, value = line.strip().split("=")
            config[key] = value
    return config

# 설정 파일 경로
CONFIG_FILE = r"d:\video\config.txt"

# 설정 파일에서 시리얼 포트와 BAUDRATE 읽기
serial_config = load_serial_config(CONFIG_FILE)
PORT = serial_config["PORT"]
BAUDRATE = int(serial_config["BAUDRATE"])

print(f"설정 파일에서 불러온 PORT: {PORT}, BAUDRATE: {BAUDRATE}")

# mp3 파일 경로
AUDIO_FILE = r"d:\video\sound.mp3"  # 소리 파일 경로

def play_audio(AUDIO_FILE):
    # pygame 초기화
    pygame.mixer.init()
    pygame.mixer.music.load(AUDIO_FILE)
    pygame.mixer.music.play()
    print(f"소리 재생 중: {AUDIO_FILE}")

def stop_audio():
    # 현재 재생 중인 음악을 중지
    if pygame.mixer.get_init():  # mixer가 초기화된 경우에만 실행
        pygame.mixer.music.stop()
        print("소리 재생 중지")

# VLC 경로
FFPLAY_PATH = r"D:\coode_work\ffmpeg-2025-07-10-git-82aeee3c19-full_build\bin\ffplay.exe"
# 영상 파일 경로
VIDEO_MONITOR1 = {i+1: f"d:/video/DL{i+1}.mp4" for i in range(10)}
VIDEO_MONITOR2 = {i+1: f"d:/video/DR{i+1}.mp4" for i in range(10)}
BLACK_MONITOR1 = r"d:\video\black1.mp4" # 1번 모니터용 검은 영상
BLACK_MONITOR2 = r"d:\video\black2.mp4" # 2번 모니터용 검은 영상

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

def hide_taskbar():
    os.system("taskkill /f /im explorer.exe")  # 작업 표시줄 숨기기

def restore_taskbar():
    os.system("start explorer.exe")  # 작업 표시줄 복원

# ffplay 프로세스 일시정지
def pause_ffplay():
    for proc in ffplay_processes:
        try:
            ps_proc = psutil.Process(proc.pid)
            ps_proc.suspend()  # 프로세스 일시정지
            print("▶ ffplay 일시정지")
        except Exception as e:
            print(f"일시정지 실패: {e}")

# ffplay 프로세스 재개
def resume_ffplay():
    for proc in ffplay_processes:
        try:
            ps_proc = psutil.Process(proc.pid)
            ps_proc.resume()  # 프로세스 재개
            print("▶ ffplay 재개")
        except Exception as e:
            print(f"재개 실패: {e}")

# 시리얼 연결
ser = serial.Serial(PORT, BAUDRATE)
print(f"Listening on {PORT}...")

#play_with_ffplay(BLACK_MONITOR1, 0, 0, 1920, 1080)
#play_with_ffplay(BLACK_MONITOR2, 1920, 0, 1920, 1080)

# ffplay 프로세스 일시정지/재개 상태 변수
is_paused = False

def toggle_play_pause():
    global is_paused
    if is_paused:
        # 현재 일시정지 상태라면 재개
        resume_ffplay()
        is_paused = False
        print("▶ ffplay 재개")
    else:
        # 현재 재생 중이라면 일시정지
        pause_ffplay()
        is_paused = True
        print("▶ ffplay 일시정지")

    # 동영상 재생 로직
while True:
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()
        print(f"받은 데이터: {line}")
        if line == "99":  # Play/Pause 토글 명령
            toggle_play_pause()
            continue
        kill_ffplay()
        stop_audio()
        if line.lower() == "1":
            #print("▶ play 실행: 1_1.mp4 + 2_1.mp4")
            play_with_ffplay(VIDEO_MONITOR1[1], 0, 0, 1920, 1080, mute=True, rotate=270, loop=True)
            play_with_ffplay(VIDEO_MONITOR2[1], 1920, 0, 1920, 1080, mute=False, rotate=90, loop=True)
        elif line.lower() == "2":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[2], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[2], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "3":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[3], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[3], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "4":
           # print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[4], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[4], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "5":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[5], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[5], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "6":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[6], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[6], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "7":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[7], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[7], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "8":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[8], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[8], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "9":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[9], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[9], 1920, 0, 1920, 1080, mute=False, rotate=90)
        elif line.lower() == "10":
            #print("▶ play 실행: 1_2.mp4 + 2_2.mp4")
            play_with_ffplay(VIDEO_MONITOR1[10], 0, 0, 1920, 1080, mute=True, rotate=270)
            play_with_ffplay(VIDEO_MONITOR2[10], 1920, 0, 1920, 1080, mute=False, rotate=90)                            
        elif line.lower() == "3":
            #print("▶ play 실행: sound")
            play_audio(AUDIO_FILE)  # 소리 재생
        elif line.lower() == "20":
            #print("▶ play 실행: 검은 화면")
            play_with_ffplay(BLACK_MONITOR1, 0, 0, 1920, 1080)
            play_with_ffplay(BLACK_MONITOR2, 1920, 0, 1920, 1080)

