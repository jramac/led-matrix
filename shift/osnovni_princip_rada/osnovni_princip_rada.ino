#include <SPI.h>
int lib[]={1,2,4,8,16,32,64,128,255};
byte b=B11111111; // 0 pali stupac
byte c=B00000000;  // 1 pali red

byte stupac[]={B01111111,B10111111,B11011111,B11101111,B11110111,B11111011,B11111101,B11111110};
byte red[]={B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010,B00000001};


void setup(){
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
for(int i=0;i<=7;i++){
digitalWrite(4,LOW);
SPI.transfer(stupac[i]&stupac[7-i]);
SPI.transfer(red[i]|red[7-i]);
digitalWrite(4,HIGH);
delay(25);
}
}
