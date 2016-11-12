#include <CapacitiveSensor.h>

//pin 6 used as function generator
CapacitiveSensor   cs_6_2 = CapacitiveSensor(6,2);
CapacitiveSensor   cs_6_3 = CapacitiveSensor(6,3);
CapacitiveSensor   cs_6_4 = CapacitiveSensor(6,4);
CapacitiveSensor   cs_6_5 = CapacitiveSensor(6,5);

//pin 8 used as function generator
CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9);
CapacitiveSensor   cs_8_10 = CapacitiveSensor(8,10);
CapacitiveSensor   cs_8_11 = CapacitiveSensor(8,11);
CapacitiveSensor   cs_8_12 = CapacitiveSensor(8,12);

//for enabling 
int pinen=7;
int led=13;
int c=0;

//threshing value
int thresh=160;
//this threshing value is for the pins connected to ldr
//also change the threshing index in the if part  
int thresh1=160;

void setup()
{
  Serial.begin(9600);

  pinMode(pinen,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  /*if (c==0)
   {
   Serial.println("hi this is easy type.");
   c=c+1;
   }*/
  long start=millis();
  //getting the respose corresponding to pin6
  long total2 =  cs_6_2.capacitiveSensor(30);
  long total3 =  cs_6_3.capacitiveSensor(30);
  long total4 =  cs_6_4.capacitiveSensor(30);
  long total5 =  cs_6_5.capacitiveSensor(30);

  //getting the response corresponding to pin8
  long total9 =  cs_8_9.capacitiveSensor(30);
  long total10 =  cs_8_10.capacitiveSensor(30);
  long total11 =  cs_8_11.capacitiveSensor(30);
  long total12 =  cs_8_12.capacitiveSensor(30);


  Serial.println();
  Serial.print(total2);
  Serial.print("\t");
  Serial.print(total3);
  Serial.print("\t");
  Serial.print(total4);
  Serial.print("\t");
  Serial.print(total5);
  Serial.print("\t");
  Serial.print(total9);
  Serial.print("\t");
  Serial.print(total10);
  Serial.print("\t");
  Serial.print(total11);
  Serial.print("\t");
  Serial.print(total12);
  Serial.print("\t");
  Serial.println();


  //the a* will contain the value of normal 6 bits while 
  // b* will contain the shift data and other crap
  long a2=0,a3=0,a4=0,a5=0,a9=0,a10=0,b1=0,b2=0,resa=0,resb=0;



  //signals for another round of input
  digitalWrite(pinen,LOW);
  delay(1200);

  if (digitalRead(pinen)==1)
  {
    if(total2>thresh || total2<0)
    {
      a2=1;
    }
    if(total3>thresh1 || total3<0)
    {
      a3=1;
    }
    if(total4>150 || total4<0)
    {
      a4=1;
    }
    if(total5>thresh1 || total5<0)
    {
      a5=1;
    }
    if(total9>thresh || total9<0)
    {
      a9=1;
    }
    if(total10>thresh1 || total10<0)
    {
      a10=1;
    }
    if(total11>thresh || total11<0)
    {
      b1=1;
    }
    if(total12>thresh1 || total12<0)
    {
      b2=1;
    }

    /*
    Serial.println();
     Serial.print(a2);
     Serial.print("\t");
     Serial.print(a3);
     Serial.print("\t");
     Serial.print(a4);
     Serial.print("\t");
     Serial.print(a5);
     Serial.print("\t");
     Serial.print(a9);
     Serial.print("\t");
     Serial.print(a10);
     Serial.print("\t");
     Serial.print(b1);
     Serial.print("\t");
     Serial.print(b2);
     Serial.print("\t");
     Serial.println();
     */


    //getting the two binary data
    resa=(a2)+(a3*10)+(a4*100)+(a5*1000)+(a9*10000)+(a10*100000);
    resb=b1+b2*10;

    /*Serial.print(resa);
     Serial.print("\t");
     Serial.print(resb);
     Serial.println();
     */
    //the block for alphabets
    if (resb==0)
    {
      switch(resa)
      {


      case 1:
        Serial.print('a');
        break;
      case 101:
        Serial.print('b');
        break;
      case 11:
        Serial.print('c');
        break;
      case 1011:
        Serial.print('d');
        break;
      case 1001:
        Serial.print('e');
        break;
      case 111:
        Serial.print('f');
        break;
      case 1111:
        Serial.print('g');
        break;
      case 1101:
        Serial.print('h');
        break;
      case 110:
        Serial.print('i');
        break;
      case 1110:
        Serial.print('j');
        break;
      case 10001:
        Serial.print('k');
        break;
      case 10101:
        Serial.print('l');
        break;
      case 10011:
        Serial.print('m');
        break;
      case 11011:
        Serial.print('n');
        break;
      case 11001:
        Serial.print('o');
        break;
      case 10111:
        Serial.print('p');
        break;
      case 11111:
        Serial.print('q');
        break;
      case 11101:
        Serial.print('r');
        break;
      case 10110:
        Serial.print('s');
        break;
      case 11110:
        Serial.print('t');
        break;
      case 110001:
        Serial.print('u');
        break;
      case 110101:
        Serial.print('v');
        break;
      case 101110:
        Serial.print('w');
        break;
      case 110011:
        Serial.print('x');
        break;
      case 111011:
        Serial.print('y');
        break;
      case 111001:
        Serial.print('z');
        break;
      case 11100:
        Serial.print('!');
        break;
      case 10000:
        Serial.print('\'');
        break;
      case 100:
        Serial.print(',');
        break;
      case 11000:
        Serial.print('-');
        break;
      case 101100:
        Serial.print('.');
        break;
      case 110100:
        Serial.print('?');
        break;
      }//switch
      //signals input is taken
      
    }//(resb==0)

    //the block for numbers
    else if(resb==10)
    {
      digitalWrite(led,HIGH);

      switch(resa)
      {
      case 1:
        Serial.print('1');
        break;
      case 101:
        Serial.print('2');
        break;
      case 11:
        Serial.print('3');
        break;
      case 1011:
        Serial.print('4');
        break;
      case 1001:
        Serial.print('5');
        break;
      case 111:
        Serial.print('6');
        break;
      case 1111:
        Serial.print('7');
        break;
      case 1101:
        Serial.print('8');
        break;
      case 110:
        Serial.print('9');
        break;
      case 1110:
        Serial.print('0');
        break;
      }//switch
      //signals input is taken
      digitalWrite(led,LOW);
    }//else if

  }//if (digitalRead(pinen)==HIGH)

  delay(500);

}


