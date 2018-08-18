from PIL import Image
import serial
import time
import struct
import os

ser1 = serial.Serial('COM3', 115200)
time.sleep(2)

for d in range (0,50):
 drc=sorted(os.listdir('.'))
 for f in drc:
  if  f.endswith('.jpg'):
    im=Image.open(f)
    px=im.load()
    penis=0
    for x in range(0,16):
        print ('______')
        for y in range(0,8):
            if px[x,y]==(255,255,255):
                izlaz=0
            elif px[x,y]==(0,0,0):
                izlaz=1
            else:
                izlaz=0
            kurac=abs(y-7)
            penis+=(izlaz*2**kurac)
        ser1.write(struct.pack('>B', penis))
        penis=0
        time.sleep(0.003)
