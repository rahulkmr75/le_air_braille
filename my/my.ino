char cr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x,','y','z',' ','\n'};
int ar[]={10000,1000,100,10,1,11000,10100,10010,10001,1100,1010,1001,110,11,11100,11010,11001,10110,10101,10011,110,1011.111,11110,11011,10111,1111,11111 };
int pin2=2;
int pin3=3;
int pin4=4;
int pin5=5;
int pin6=6;

//for enabling the mechanism
int pin7=7;

int pin10=10;

//enable initialized to zero
boolean en=false;

void setup(){
  
  pinMode(8,HIGH);
  
 pinMode(pin2,INPUT);
 pinMode(pin3,INPUT);
 pinMode(pin4,INPUT);
 pinMode(pin5,INPUT);
 pinMode(pin6,INPUT);
 //enabling pin
 pinMode(pin7,INPUT);
 
 //output pin
 pinMode(pin10,OUTPUT);
 pinMode(13,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
     
 
 //nh.initNode();
 //nh.advertise(chatter);
 Serial.begin(9600);
 digitalWrite(10,HIGH);
 digitalWrite(11,LOW);
 digitalWrite(12,HIGH);
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
 
 }
 
void loop()
 {
   digitalWrite(13,LOW);
   delay(2000);
   
   //Serial.print(en);
   if (digitalRead(7)==HIGH)
   {
     en=!en;
   }//if 
   if (digitalRead(7)==HIGH)
   {
     
     int a,b,c,d,e,f;
     a=!digitalRead(pin2);
     b=!digitalRead(pin3);
     c=!digitalRead(pin4);
     d=!digitalRead(pin5);
     e=!digitalRead(pin6);
     f=a*16+b*8+c*4+d*2+e+64;
     
     char t=f;
     if (f>64 && f<90)
     {
       Serial.print(t);
       digitalWrite(13,HIGH);
     }
     else if(f==94)
     {
       Serial.print("  ");
       digitalWrite(13,HIGH);
     }
     else if(f==95)
     {
       Serial.print('\n');
       digitalWrite(13,HIGH);
     }
     else if(f==93){
       Serial.print('\b');
       digitalWrite(13,HIGH);
     }
     
   }
   delay(500);
   
 }
