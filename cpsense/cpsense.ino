#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_3 = CapacitiveSensor(4,3);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil

//for enabling
int pin7=7;
int pin13=13;

//threshing value
int thresh=300;

void setup()                    
{
   Serial.begin(9600);
   
   pinMode(pin7,INPUT);
   pinMode(pin13,OUTPUT);

}

void loop()
{
  long start=millis();
  long total1 =  cs_4_2.capacitiveSensor(30);
  long total2 =  cs_4_3.capacitiveSensor(30);
  long total3 =  cs_4_5.capacitiveSensor(30);
  long total4 =  cs_4_6.capacitiveSensor(30);
  long total5 =  cs_4_8.capacitiveSensor(30);
  
  //threshing values can be modified using the code below
  Serial.println();
  Serial.print(total1);
  Serial.print("\t");
  Serial.print(total2);
  Serial.print("\t");
  Serial.print(total3);
  Serial.print("\t");
  Serial.print(total4);
  Serial.print("\t");
  Serial.print(total5);
  Serial.print("\t");
  Serial.println();
  
  int a=0,b=0,c=0,d=0,e=0,res=0;
  
  digitalWrite(pin13,LOW);
  delay(1200);
  
  if (digitalRead(7)==HIGH)
  {
    if(total1>thresh)
    {
      a=1;
    }
    if(total2>thresh)
    {
      b=1;
    }
    if(total3>thresh)
    {
      c=1;
    }
    if(total4>thresh)
    {
      d=1;
    }
    if(total5>thresh)
    {
      e=1;
    }
    
    res=a*16+b*8+c*4+d*2+e+64;
    char t=res;
    //Serial.print(res);
     if (res>64 && res<91)
     {
       Serial.print(t);
       digitalWrite(13,HIGH);
     }
     else if(res==94)
     {
       Serial.print("  ");
       digitalWrite(13,HIGH);
     }
     else if(res==95)
     {
       Serial.print('\n');
       digitalWrite(13,HIGH);
     }
     else if(res==93)
     {
       char bs=8;
       Serial.print(bs);
       digitalWrite(13,HIGH);
     }
     
     
    
    
  }//if (digitalRead(7)==HIGH)
  
  delay(500);
  
}

