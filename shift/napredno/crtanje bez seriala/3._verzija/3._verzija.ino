#include <SPI.h>
byte pimpek[]={120,204,198,99,99,198,204,120};

byte stupac[]={B01111111,B10111111,B11011111,B11101111,B11110111,B11111011,B11111101,B11111110}; //zbrajaju se sa "&"
byte red[]={B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010,B00000001}; //zbrajaju se sa "|"
byte stupacIzlaz,redIzlaz;
float vrijednosti[8];

float zbroj;
float prosjek;


void setup(){
Serial.begin(9600);
pinMode(13, OUTPUT); //clock
pinMode(11, OUTPUT); //data
pinMode(4, OUTPUT); //latch
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV8);
SPI.begin();
SPI.transfer(0);
SPI.transfer(0);
digitalWrite(4, HIGH);
digitalWrite(4, LOW);
} 
  
void loop(){
for(int g=0;g<8;g++){  //vrti se za svaki stupac
  
 stupacIzlaz=stupac[g];
 redIzlaz=pimpek[g];
     
    digitalWrite(4,LOW);
    SPI.transfer(stupacIzlaz);
    SPI.transfer(redIzlaz);
    digitalWrite(4,HIGH);
    delay(1);
    
}
}


