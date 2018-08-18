#include <SPI.h>
int lib[]={1,2,4,8,16,32,64,128};
int mapp=0;

int val=0;
int ledNum=8;
char abeceda[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
             's','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','!','"','#','$','%','&','(',')','*','+',',','-','.','/',
             '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','À','Á','Â','Ã','Ä','Å','Æ','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï','Ð','Ñ','Ò','Ó','Ô','Õ','Ö','×','Ø','Ù','Ú','Û','Ü','Ý','Þ','ß',
             'à','á','â','ã','ä','å','æ','ç','è','é','ê','ë','ì','í','î','ï','ð','ñ','ò','ó','ô','õ','ö','÷','ø','ù','ú','û','ü','ý','þ','ÿ','Œ','œ','Š','š','Ÿ','ƒ','–','—','‘','’','‚','“','”','„','†','‡',
             '•','…','‰','€','™'};
int kalibracija[]={26,52,78,104,130,168};    // 168
int f=0;
void setup(){
  pinMode(13, OUTPUT);//clock
  pinMode(11, OUTPUT);//data
  pinMode(4, OUTPUT);//latch
  
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV8);
SPI.begin();
  SPI.transfer(255);
  SPI.transfer(0);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 Serial.begin(115200);
}   


void loop(){
    if(Serial.available()>0)
    {
    val=Serial.read();
    }

    for(int a=0;a<167;a++)
    {
      if(val==abeceda[a])
    {
      mapp=map(a,0,kalibracija[f]+10,0,ledNum);
    }
  
for(int i=0;i<ledNum;i++){
if(mapp>i)
{
digitalWrite(4,LOW);
SPI.transfer(lib[i]);
digitalWrite(4,HIGH);
}
else
{
digitalWrite(4,LOW);
SPI.transfer(0);
digitalWrite(4,HIGH);
}
}
}
}
 



