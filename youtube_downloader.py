import yt_dlp
import os

def main():
    print("=== YouTube Downloader ===")
    url = input("Enter YouTube URL or Playlist URL: ").strip()

    print("\nChoose download format:")
    print("1 - Best Video + Audio (MP4)")
    print("2 - Audio only (MP3)")
    print("3 - Video only (MP4)")
    choice = input("Enter choice (1/2/3): ").strip()

    # Ask if user wants a specific range
    playlist_range = input("\nEnter video range from playlist (e.g., 7-16), or press Enter to download all: ").strip()
    playlist_items = playlist_range if playlist_range else None

    # Ask for custom download directory
    custom_dir = input("\nEnter folder path to save downloads, or press Enter to use default: ").strip()

    # Default base folders
    default_videos_folder = os.path.join(os.path.expanduser("~"), "Videos")
    default_music_folder = os.path.join(os.path.expanduser("~"), "Music")

    # Use custom directory if provided, else default
    if custom_dir:
        videos_folder = os.path.join(custom_dir, "Videos")
        music_folder = os.path.join(custom_dir, "Music")
    else:
        videos_folder = default_videos_folder
        music_folder = default_music_folder

    # Output templates
    video_outtmpl = os.path.join(videos_folder, '%(playlist_title)s', '%(title)s.%(ext)s')
    audio_outtmpl = os.path.join(music_folder, '%(playlist_title)s', '%(title)s.%(ext)s')

    # yt-dlp options
    ydl_opts = {}

    if playlist_items:
        ydl_opts['playlist_items'] = playlist_items

    if choice == '1':
        ydl_opts.update({
            'format': 'bestvideo+bestaudio',
            'merge_output_format': 'mp4',
            'outtmpl': video_outtmpl,
        })
    elif choice == '2':
        ydl_opts.update({
            'format': 'bestaudio/best',
            'postprocessors': [{
                'key': 'FFmpegExtractAudio',
                'preferredcodec': 'mp3',
                'preferredquality': '192',
            }],
            'outtmpl': audio_outtmpl,
        })
    elif choice == '3':
        ydl_opts.update({
            'format': 'bestvideo',
            'outtmpl': video_outtmpl,
        })
    else:
        print("Invalid choice, exiting.")
        return

    print("\nDownloading... Please wait.\n")
    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([url])

    print("\nDownload completed!")

if __name__ == "__main__":
    main()

