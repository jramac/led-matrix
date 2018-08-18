#include <SPI.h>
#include <stdlib.h>
int pimpek[8];

byte stupac[]={B01111111,B10111111,B11011111,B11101111,B11110111,B11111011,B11111101,B11111110}; //zbrajaju se sa "&"
byte red[]={B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010,B00000001}; //zbrajaju se sa "|"
byte stupacIzlaz,redIzlaz;

void setup(){
Serial.begin(115200);
pinMode(13, OUTPUT); //clock
pinMode(11, OUTPUT); //data
pinMode(4, OUTPUT); //latch
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV2);
SPI.begin();
SPI.transfer(0);
SPI.transfer(0);
digitalWrite(4, HIGH);
digitalWrite(4, LOW);
} 
  
void loop(){
for(int g=0;g<8;g++){  //vrti se za svaki stupac
    if(Serial.available()>7){
  for(int c=0;c<8;c++){
  pimpek[c]=Serial.read();
  }
  }
 stupacIzlaz=stupac[g];
 redIzlaz=pimpek[g];
     
    digitalWrite(4,LOW);
    SPI.transfer(stupacIzlaz);
    SPI.transfer(redIzlaz);
    digitalWrite(4,HIGH);

 stupacIzlaz=B11111111;
 redIzlaz=B00000000;   
}
}
