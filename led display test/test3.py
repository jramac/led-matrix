from PIL import Image
import serial
import time
import struct
ser1 = serial.Serial('COM3', 115200)
time.sleep(2)
im = Image.open('test1.jpg','r')
px=im.load()
penis=0
for g in range(0,1):
 for x in range(0,8):
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
    ser1.write(struct.pack('@B', penis))
    print(penis)
    penis=0
