import subprocess
import serial
import psutil  # 추가 설치 필요: pip install psutil
import pygame  # 추가 설치 필요: pip install pygame
import ctypes  # 작업 표시줄 제어를 위한 라이브러리

# ffplay 프로세스를 관리하기 위한 변수
current_process = None
is_paused = False  # 현재 상태를 관리하는 변수 (False: 재생 중, True: 일시정지)

FFPLAY_PATH = r"C:\Humanoid_G\ffmpeg-2025-09-10-git-c1dc2e2b7c-full_build\bin\ffplay.exe"

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

# config.txt에서 시리얼 포트 정보 읽기
def load_serial_config(config_file):
    config = {}
    try:
        with open(config_file, "r") as file:
            for line in file:
                key, value = line.strip().split("=")
                config[key.strip()] = value.strip()
        print(f"설정 파일 로드 완료: {config}")
    except Exception as e:
        print(f"설정 파일 로드 실패: {e}")
    return config

def play_video_on_dual_monitor(video_path, width, height, left, top, loop=False, rotate=0):
    global current_process, is_paused

    # 기존 재생 중인 프로세스가 있으면 종료
    if current_process and current_process.poll() is None:
        print("현재 재생 중인 동영상 종료")
        current_process.terminate()
        is_paused = False  # 새로운 동영상이 재생되면 상태를 재생 중으로 초기화

    # 작업 표시줄 숨기기
    hide_taskbar()

    # 새로운 동영상 재생
    cmd = [
        FFPLAY_PATH,
        "-noborder",
        "-x", str(width),
        "-y", str(height),
        "-left", str(left),
        "-top", str(top),
    ]
    if loop:
        cmd.extend(["-loop", "0"])  # 무한 반복 옵션 추가

    # 회전 옵션 추가
    if rotate == 90:
        cmd.extend(["-vf", "transpose=1"])  # 시계 방향 90도 회전
    elif rotate == 180:
        cmd.extend(["-vf", "transpose=2,transpose=2"])  # 180도 회전
    elif rotate == 270:
        cmd.extend(["-vf", "transpose=2"])  # 반시계 방향 90도 회전

    cmd.append(video_path)

    try:
        current_process = subprocess.Popen(cmd)  # 새로운 프로세스 실행
        print(f"동영상 재생 시작: {video_path} (loop={'ON' if loop else 'OFF'}, rotate={rotate}°)")
    except Exception as e:
        print(f"동영상 재생 실패: {e}")

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

def stop_audio():
    """현재 재생 중인 오디오를 멈춤"""
    try:
        if pygame.mixer.get_init() and pygame.mixer.music.get_busy():
            pygame.mixer.music.stop()
            print("오디오 중지")
    except Exception as e:
        print(f"오디오 중지 실패: {e}")

def play_audio(audio_path):
    """MP3 파일 재생"""
    try:
        stop_audio()  # 새로운 오디오 재생 전에 기존 오디오 중지
        pygame.mixer.init()
        pygame.mixer.music.load(audio_path)
        pygame.mixer.music.play()
        print(f"오디오 재생 시작: {audio_path}")
    except Exception as e:
        print(f"오디오 재생 실패: {e}")

# 설정 파일 경로
CONFIG_FILE = r"c:\Humanoid_G\config.txt"

# 설정 파일에서 시리얼 포트와 BAUDRATE 읽기
serial_config = load_serial_config(CONFIG_FILE)
PORT = serial_config.get("PORT", "COM1")  # 기본값: COM1
BAUDRATE = int(serial_config.get("BAUDRATE", 9600))  # 기본값: 9600

# 시리얼 포트 설정
ser = serial.Serial(PORT, BAUDRATE)

# 합쳐진 동영상 파일 경로
videos = {
    "1": r"C:\Humanoid_G\video\HG1.mp4",
    "2": r"C:\Humanoid_G\video\HG2.mp4",
    "3": r"C:\Humanoid_G\video\HG3.mp4",
    "4": r"C:\Humanoid_G\video\HG4.mp4",
    "5": r"C:\Humanoid_G\video\HG5.mp4"
}

# MP3 파일 경로
audios = {
    "9": r"C:\Humanoid_G:\audio\audio1.mp3",
    "b": r"C:\Humanoid_G\audio\audio2.mp3",
    "c": r"C:\Humanoid_G\audio\audio3.mp3"
}

# 듀얼 모니터 해상도 설정 (예: 1920x1080 모니터 2개)
monitor_width = 1920  # 가로 해상도
monitor_height = 1080 * 1  # 세로 해상도
monitor_left = 0  # 첫 번째 모니터의 왼쪽 상단
monitor_top = 0  # 첫 번째 모니터의 위쪽 상단

# 시리얼 데이터 처리
try:
    print(f"Listening on {PORT} at {BAUDRATE} baud...")
    while True:
        if ser.in_waiting:  # 시리얼 데이터가 수신되었는지 확인
            data = ser.readline().decode('utf-8').strip()  # 시리얼 데이터 읽기
            print(f"받은 데이터: {data}")
            stop_audio()  # 새로운 데이터가 들어오면 항상 오디오 중지
            if data == "99":  # Pause/Resume 토글 명령
                toggle_pause_resume()
            elif data in videos:  # 받은 데이터가 동영상 키에 해당하면
                play_video_on_dual_monitor(videos[data], monitor_width, monitor_height, monitor_left, monitor_top, loop=False)
            elif data in audios:  # 받은 데이터가 오디오 키에 해당하면
                play_audio(audios[data])
            else:
                print(f"알 수 없는 데이터: {data}")
finally:
    # 프로그램 종료 시 작업 표시줄 다시 표시
    show_taskbar()
