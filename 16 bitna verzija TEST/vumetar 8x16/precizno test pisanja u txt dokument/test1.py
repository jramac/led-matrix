from PIL import Image

import serial
import time
import struct
import os

import math
import pyaudio
import numpy as np

# _______________________________POCETAK ISPISIVANJA U TXT
file = open("podatci","w") 
br=0
for d in range (0,1):
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
        #ser1.write(struct.pack('>B', penis))
        kutija=str(penis)
        file.write(kutija+"\n") 
        penis=0
        br+=1
br/=16
br=int(br)
br=str(br)     #pretvaranje u string 
file.close()   #zatvaranje tako da mogu otvoriti opet i dodati jedan redak(zato sto uvijek pise od prvog retka prema dolje"
file = open("podatci","r") 
a=file.read()   #spremanje sadrzaj dokumenta u varijablu
file.close()
file = open("podatci","w")
file.write(br+"\n"+a) #dodavanje prvog retka i nakon toga sadrzaj prvog dokumenta zato sto se sadrzaj dokumenta overwrite-a nakon ponovnog pisanja u isti
file.close()
#______________________________KRAJ ISPISIVANJA U TXT

#______________________________VUMETAR DIO KODA - POCETAK

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
    if kada>43:
        kada=43
    print("%d %s"%(kada,ljestve)) 

    
