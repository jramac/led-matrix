from PIL import Image
import serial
import time
import struct
import os

import math
import pyaudio
import numpy as np

ser1 = serial.Serial('COM3', 115200)
time.sleep(2)

CHUNK=2048
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100
KARANJE = 2.5
p=pyaudio.PyAudio()
stream=p.open(format=FORMAT,channels=CHANNELS,rate=RATE,input=True,
              frames_per_buffer=CHUNK)
x=0
drc=sorted(os.listdir('.'))
while ser1.is_open:
    podatci=np.fromstring(stream.read(CHUNK),dtype=np.int16)
    sredina=(np.average(np.abs(podatci)))*KARANJE
    broj=(200*sredina/2**16)
    ljestve="8"+"="*int(broj)+"D"
    kada=int(broj)
    if kada>19:
        kada=19
    if kada<1:
        kada=1
    print("%d %s"%(kada,ljestve))    

    for f in drc:
      if f.endswith('.jpg'):
        stopalo=str(kada)
        im=Image.open(stopalo+".jpg")
        px=im.load()
        penis=0
        for x in range(0,16):
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
        
stream.stop_stream()
stream.close()
p.terminate()
