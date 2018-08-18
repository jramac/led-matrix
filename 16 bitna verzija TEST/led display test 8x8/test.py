from PIL import Image
import serial
import time
ser1 = serial.Serial('COM3', 115200)
time.sleep(2)
im = Image.open('test1.jpg','r')
px=im.load()
for x in range(0,8):
    print ('______')
    for y in range(0,8):
        if px[x,y]==(255,255,255):
            izlaz=0*10**0+x*10**1+y*10**2
            ser1.write(izlaz)
        else:
            izlaz1=1*10**0+x*10**1+y*10**2
            ser1.write(izlaz1)



