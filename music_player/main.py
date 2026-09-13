import os
os.environ["PYGAME_HIDE_SUPPORT_PROMPT"] = "hide"
import pygame

def play_music(folder, song_name):

    file_path = os.path.join(folder, song_name) #path to an mp3 file

    if not os.path.exists(file_path): #checks if path exists
        print("File not found")
        return

    pygame.mixer.music.load(file_path) #loads the music
    pygame.mixer.music.play() #plays the music

    print(f"\nNow playing: {song_name}") #takes user input for commands
    print("Commands: [P]ause, [R]esume, [S]top")

    while True:

        command = input("> ").upper()

        if command == "P":
            pygame.mixer.music.pause()
            print("Paused")
        elif command == "R":
            pygame.mixer.music.unpause()
            print("Resumed")
        elif command == "S":
            pygame.mixer.music.stop()
            print("Stopped")
            return
        else:
            print("Invalid command")
def main():

    try:
        pygame.mixer.init() #initialize mixer
    except pygame.error as e:
        print("Audio initialization failed:", e)
        return

    folder = "music"

    if not os.path.isdir(folder): #check's if folder exists with name
        print(f"Folder '{folder}' not found")
        return

    mp3_files = [file for file in os.listdir(folder) if file.endswith(".mp3")] #creates list of mp3 file names

    if not mp3_files:
        print("No .mp3 files found")
        return

    while True:
        print("*** MP3 Player ***")
        print("My song list:")

        for index, song in enumerate(mp3_files, start = 1): #prints out each song in the list
            print(f"{index}. {song}")

        choice_input = input("\nEnter the song # to play (or 'Q' to quit): ") #takes user input for song choice

        if choice_input.upper() == "Q": #quit command
            print("Bye")
            break

        if not choice_input.isdigit(): #checks if actual number
            print("Enter a valid number")
            continue

        choice = int(choice_input)-1

        if 0<=choice <len(mp3_files): #checks if number in range
            play_music(folder, mp3_files[choice]) #goes to play file
        else:
            print("Invalid choice")
    
if __name__ == "__main__":
    main()