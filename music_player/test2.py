import glob
import os
import simpleaudio as sa
from os import path
import soundfile
from pydub import AudioSegment
p = r"H:\My Drive\electric-baton\music_player\music"

for fp in glob.glob(p + "\\*"):
    if os.path.isfile(fp):
        with open(fp, "r") as f:
            path = os.path.basename(fp)
            print(path)
            data, sampleRate = soundfile.read(path)
            soundfile.write(path, data, sampleRate)
            wav = sa.WaveObject.from_wave_file(fp)
            play_obj = wav.play()
            play_obj.stop()
sound = AudioSegment.from_file(fp)

halfway_point = len(sound) // 2
first_half = sound[:halfway_point]

# create a new file "first_half.mp3":
first_half.export("H:\\My Drive\\electric-baton\\music_player\\music\\Sample2.wav", format="wav")
wav = sa.WaveObject.from_wave_file("H:\\My Drive\\electric-baton\\music_player\\music\\Sample2.wav")
play_obj = wav.play()
