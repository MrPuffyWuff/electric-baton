import glob
import os

p = r"H:\My Drive\electric-baton\music_player\music"

for fp in glob.glob(p + "\\*"):
    if os.path.isfile(fp):
        with open(fp, "r") as f:
            print(os.path.basename(fp))
            print(f.read())