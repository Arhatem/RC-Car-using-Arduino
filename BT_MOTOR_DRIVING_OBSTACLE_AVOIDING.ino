#define M1F 53
#define M1B 51
#define M2F 49
#define M2B 47
#define M3F 52
#define M3B 50
#define M4F 48
#define M4B 46
int Trigpin = 44;
int Echopin = 45; 
long duration ; 
long distance ; 
int state =0;
void setup() {
  // put your setup code here, to run once:
pinMode (Trigpin,OUTPUT);
pinMode (Echopin ,INPUT);
pinMode(M1F,OUTPUT);
pinMode(M1B,OUTPUT);
pinMode(M2F,OUTPUT);
pinMode(M2B,OUTPUT);
pinMode(M3F,OUTPUT);
pinMode(M3B,OUTPUT);
pinMode(M4F,OUTPUT);
pinMode(M4B,OUTPUT);
Serial3.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Trigpin , LOW)
delayMicroseconds (2);


digitalWrite(Trigpin , HIGH )
delayMicroseconds (10);
digitalWrite(Trigpin , LOW )

duration = pulseIn (Echopin , HIGH);
distance = duration * 0.034/2 ; 



if (Serial3.available ()>0)  
   state = Serial3.read();
if ( distance <=5 ){
   /*------------------OBSTACLEAVOIDING---------------*/
    digitalWrite(M1F,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2F,LOW);
    digitalWrite(M2B,HIGH);
    digitalWrite(M3F,LOW);
    digitalWrite(M3B,HIGH);
    digitalWrite(M4F,HIGH);
    digitalWrite(M4B,LOW);
    state=0;
}
 
else 

/*------------------FORWARD---------------*/
{if(state== '8') {

    digitalWrite(M1F,HIGH);
    digitalWrite(M1B,LOW) ;
    digitalWrite(M2F,HIGH);
    digitalWrite(M2B,LOW);
    digitalWrite(M3F,HIGH);
    digitalWrite(M3B,LOW);
    digitalWrite(M4F,HIGH);
    digitalWrite(M4B,LOW);
    state=0;
}
/*---------------BACKWARD----------------------*/
else if (state == '2') {
    digitalWrite(M1F,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2F,LOW);
    digitalWrite(M2B,HIGH);
    digitalWrite(M3F,LOW);
    digitalWrite(M3B,HIGH);
    digitalWrite(M4F,LOW);
    digitalWrite(M4B,HIGH);
    state=0;
}
/*-----------------STOP------------------*/
else if (state == '0') {
    digitalWrite(M1F,LOW);
    digitalWrite(M1B,LOW);
    digitalWrite(M2F,LOW);
    digitalWrite(M2B,LOW);
    digitalWrite(M3F,LOW);
    digitalWrite(M3B,LOW);
    digitalWrite(M4F,LOW);
    digitalWrite(M4B,LOW);
    state=0;
}
/*----------------------RIGHT----------------*/
else if (state == '6') {
    digitalWrite(M1F,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2F,LOW);
    digitalWrite(M2B,HIGH);
    digitalWrite(M3F,LOW);
    digitalWrite(M3B,HIGH);
    digitalWrite(M4F,HIGH);
    digitalWrite(M4B,LOW);
    state=0;
}
/*----------------------LEFT--------------------*/
else if (state == '4') {
    digitalWrite(M1F,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2F,HIGH);
    digitalWrite(M2B,LOW);
    digitalWrite(M3F,HIGH);
    digitalWrite(M3B,LOW);
    digitalWrite(M4F,LOW);
    digitalWrite(M4B,HIGH);
    state=0;
}}
}
