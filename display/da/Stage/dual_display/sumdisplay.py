import subprocess

def merge_videos_with_rotation(video1, video2, output):
    cmd = [
        r"D:\coode_work\ffmpeg-2025-07-10-git-82aeee3c19-full_build\bin\ffmpeg.exe",
        "-i", video1,
        "-i", video2,
        "-filter_complex", "[0:v]transpose=2[v0];[1:v]transpose=1[v1];[v0][v1]vstack=inputs=2[v]",
        "-map", "[v]",  # 병합된 비디오 스트림 선택
        "-map", "1:a",  # 첫 번째 동영상의 오디오 스트림 선택
        "-c:v", "libx264",  # 비디오 코덱 설정
        "-c:a", "aac",  # 오디오 코덱 설정
        "-strict", "experimental",  # AAC 코덱 사용 시 필요
        output
    ]
    try:
        subprocess.run(cmd, check=True)
        print(f"동영상 병합 완료: {output}")
    except subprocess.CalledProcessError as e:
        print(f"동영상 병합 실패: {e}")

# 병합할 동영상 파일 경로
video11 = r"D:\video\DL1.mp4"  # 첫 번째 동영상
video21 = r"D:\video\DR1.mp4"  # 두 번째 동영상
output1 = r"D:\video\STAGE1.mp4"  # 병합 결과 파일

video12 = r"D:\video\DL2.mp4"  # 첫 번째 동영상
video22 = r"D:\video\DR2.mp4"  # 두 번째 동영상
output2 = r"D:\video\STAGE2.mp4"  # 병합 결과 파일

video13 = r"D:\video\DL3.mp4"  # 첫 번째 동영상
video23 = r"D:\video\DR3.mp4"  # 두 번째 동영상
output3 = r"D:\video\STAGE3.mp4"  # 병합 결과 파일

video14 = r"D:\video\DL4.mp4"  # 첫 번째 동영상
video24 = r"D:\video\DR4.mp4"  # 두 번째 동영상
output4 = r"D:\video\STAGE4.mp4"  # 병합 결과 파일

video15 = r"D:\video\DL5.mp4"  # 첫 번째 동영상
video25 = r"D:\video\DR5.mp4"  # 두 번째 동영상
output5 = r"D:\video\STAGE5.mp4"  # 병합 결과 파일

video16 = r"D:\video\DL6.mp4"  # 첫 번째 동영상
video26 = r"D:\video\DR6.mp4"  # 두 번째 동영상
output6 = r"D:\video\STAGE6.mp4"  # 병합 결과 파일

video17 = r"D:\video\DL7.mp4"  # 첫 번째 동영상
video27 = r"D:\video\DR7.mp4"  # 두 번째 동영상
output7 = r"D:\video\STAGE7.mp4"  # 병합 결과 파일

video18 = r"D:\video\DL8.mp4"  # 첫 번째 동영상
video28 = r"D:\video\DR8.mp4"  # 두 번째 동영상
output8 = r"D:\video\STAGE8.mp4"  # 병합 결과 파일

video19 = r"D:\video\DL9.mp4"  # 첫 번째 동영상
video29 = r"D:\video\DR9.mp4"  # 두 번째 동영상
output9 = r"D:\video\STAGE9.mp4"  # 병합 결과 파일

video100 = r"D:\video\DL10.mp4"  # 첫 번째 동영상
video200 = r"D:\video\DR10.mp4"  # 두 번째 동영상
output10 = r"D:\video\STAGE10.mp4"  # 병합 결과 파일

# 동영상 병합 실행
merge_videos_with_rotation(video11, video21, output1)
merge_videos_with_rotation(video12, video22, output2)
merge_videos_with_rotation(video13, video23, output3)
merge_videos_with_rotation(video14, video24, output4)
merge_videos_with_rotation(video15, video25, output5)
merge_videos_with_rotation(video16, video26, output6)
merge_videos_with_rotation(video17, video27, output7)
merge_videos_with_rotation(video18, video28, output8)
merge_videos_with_rotation(video19, video29, output9)
merge_videos_with_rotation(video100, video200, output10)
