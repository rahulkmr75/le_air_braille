#include <CapacitiveSensor.h>


//pin 6 used as function generator
CapacitiveSensor   cs_1_2 = CapacitiveSensor(A1,2);
CapacitiveSensor   cs_1_3 = CapacitiveSensor(A1,3);
CapacitiveSensor   cs_6_4 = CapacitiveSensor(6,4);
CapacitiveSensor   cs_6_5 = CapacitiveSensor(6,5);

//pin 8 used as function generator
CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9);
CapacitiveSensor   cs_8_10 = CapacitiveSensor(8,10);
CapacitiveSensor   cs_0_11 = CapacitiveSensor(A2,11);
CapacitiveSensor   cs_0_12 = CapacitiveSensor(A2,12);

//for enabling 
int pinen=7;
int led=13;
int c=0;
String str="";



//threshing value
int thresh=500;
//this threshing value is for the pins connected to ldr
//also change the threshing index in the if part  
int thresh1=500;

void setup()
{
  Serial.begin(9600);

  pinMode(pinen,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{

  //signals for another round of input
  digitalWrite(led,LOW);
  
  long start=millis();
  
  //getting the respose corresponding to pin6
  long total2 =  cs_1_2.capacitiveSensor(30);
  long total3 =  cs_1_3.capacitiveSensor(30);
  long total4 =  cs_6_4.capacitiveSensor(30);
  long total5 =  cs_6_5.capacitiveSensor(30);

  //getting the response corresponding to pin8
  long total9 =  cs_8_9.capacitiveSensor(30);
  long total10 =  cs_8_10.capacitiveSensor(30);
  long total11 =  cs_0_11.capacitiveSensor(30);
  long total12 =  cs_0_12.capacitiveSensor(30);

   /*
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
   */

  //the a* will contain the value of normal 6 bits while 
  // b* will contain the shift data and other crap
  long a2=0,a3=0,a4=0,a5=0,a9=0,a10=0,b1=0,b2=0,resa=0,resb=0;





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
    if(total4>thresh || total4<0)
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
    if (resa>0 && b1==1){
      digitalWrite(led,HIGH);
      delay(800);
    }
    if (b1==1){

    /*Serial.print(resa);
     Serial.print("\t");
     Serial.print(resb);
     Serial.println();
     */
    //the block for alphabets
    if (b2==0)
    {
      switch(resa)
      {


      case 1:
        str=String(str+"a");
        break;
      case 101:
        str=String(str+"b");
        break;
      case 11:
        str=String(str+"c");
        break;
      case 1011:
        str=String(str+"d");
        break;
      case 1001:
        str=String(str+"e");
        break;
      case 111:
        str=String(str+"f");
        break;
      case 1111:
        str=String(str+"g");
        break;
      case 1101:
        str=String(str+"h");
        break;
      case 110:
        str=String(str+"i");
        break;
      case 1110:
        str=String(str+"j");
        break;
      case 10001:
        str=String(str+"k");
        break;
      case 10101:
        str=String(str+"l");
        break;
      case 10011:
        str=String(str+"m");
        break;
      case 11011:
        str=String(str+"n");
        break;
      case 11001:
        str=String(str+"o");
        break;
      case 10111:
        str=String(str+"p");
        break;
      case 11111:
        str=String(str+"q");
        break;
      case 11101:
        str=String(str+"r");
        break;
      case 10110:
        str=String(str+"s");
        break;
      case 11110:
        str=String(str+"t");
        break;
      case 110001:
        str=String(str+"u");
        break;
      case 110101:
        str=String(str+"v");
        break;
      case 101110:
        str=String(str+"w");
        break;
      case 110011:
        str=String(str+"x");
        break;
      case 111011:
        str=String(str+"y");
        break;
      case 111001:
        str=String(str+"z");
        break;
      case 11100:
        str=String(str+"!");
        break;
      case 10000:
        str=String(str+"\'");
        break;
      case 100:
        str=String(str+",");
        break;
      case 11000:
        str=String(str+"-");
        break;
      case 101100:
        str=String(str+".");
        break;
      case 110100:
        str=String(str+"?");
        break;
      case 111111:
        Serial.print(str);
        break;
      case 111100:
        str=String(str+" ");
        break;
      }//switch
      //signals input is taken
    }//(resb==0)

    //the block for numbers
    else if(b2==1)
    {

      switch(resa)
      {
      case 1:
        str=String(str+"1");
        break;
      case 101:
        str=String(str+"2");
        break;
      case 11:
        str=String(str+"3");
        break;
      case 1011:
        str=String(str+"4");
        break;
      case 1001:
        str=String(str+"5");
        break;
      case 111:
        str=String(str+"6");
        break;
      case 1111:
        str=String(str+"7");
        break;
      case 1101:
        str=String(str+"8");
        break;
      case 110:
        str=String(str+"9");
        break;
      case 1110:
        str=String(str+"0");
        break;
      }//switch


    }//else if
    }
  }//if (digitalRead(pinen)==HIGH)


}





