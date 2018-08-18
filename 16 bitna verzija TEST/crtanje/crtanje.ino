#include <SPI.h>
#include <stdlib.h>
int pimpek[16];
//int pimpek[]={40,40,255,40,47,32,200,40,38,40,255,40,255,40,104,40};
byte kara,manje;
byte stupac[]={127,191,223,239,247,251,253,254,127,191,223,239,247,251,253,254}; //zbrajaju se sa "&"

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
SPI.transfer(0);
digitalWrite(4, HIGH);
digitalWrite(4, LOW);
} 
  
void loop(){
  

  if(Serial.available()>15){
  for(int c=0;c<16;c++){
  pimpek[c]=Serial.read();
  }
  }


for(int g=0;g<16;g++){  //vrti se za svaki stupac
    stupacIzlaz=stupac[g];
    redIzlaz=pimpek[g];
  if(g>=8){  
    digitalWrite(4,LOW);    
    SPI.transfer(stupacIzlaz);
    SPI.transfer(B11111111);    
    SPI.transfer(redIzlaz);
    digitalWrite(4,HIGH);       
 }

  if(g<=7){
    digitalWrite(4,LOW);
    SPI.transfer(B11111111);    
    SPI.transfer(stupacIzlaz);
    SPI.transfer(redIzlaz);
    digitalWrite(4,HIGH);
 }


    
}

}
