#define M1F 53
#define M1B 51
#define M2F 49
#define M2B 47
#define M3F 52
#define M3B 50
#define M4F 48
#define M4B 46

#define M1EN 2
#define M2EN 3
#define M3EN 5
#define M4EN 4

int Trigpin = 44;
int Echopin = 45; 
long duration ; 
long distance ; 
int state =0;
/*---------------forward function------------------*/
void forward (){
    digitalWrite(M1F,HIGH);
    digitalWrite(M1B,LOW) ;
    digitalWrite(M2F,HIGH);
    digitalWrite(M2B,LOW);
    digitalWrite(M3F,HIGH);
    digitalWrite(M3B,LOW);
    digitalWrite(M4F,HIGH);
    digitalWrite(M4B,LOW);
    analogWrite(M1EN,255);
    analogWrite(M2EN,255);
    analogWrite(M3EN,255);
    analogWrite(M4EN,255);
    state=0;
}

/*---------------backward function------------------*/
void backward (){
    digitalWrite(M1F,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2F,LOW);
    digitalWrite(M2B,HIGH);
    digitalWrite(M3F,LOW);
    digitalWrite(M3B,HIGH);
    digitalWrite(M4F,LOW);
    digitalWrite(M4B,HIGH);
    analogWrite(M1EN,255);
    analogWrite(M2EN,255);
    analogWrite(M3EN,255);
    analogWrite(M4EN,255);
    state=0;
}
/*---------------stop function---------------------*/
void STOP (){
    digitalWrite(M1F,LOW);
    digitalWrite(M1B,LOW);
    digitalWrite(M2F,LOW);
    digitalWrite(M2B,LOW);
    digitalWrite(M3F,LOW);
    digitalWrite(M3B,LOW);
    digitalWrite(M4F,LOW);
    digitalWrite(M4B,LOW);
    analogWrite(M1EN,0);
    analogWrite(M2EN,0);
    analogWrite(M3EN,0);
    analogWrite(M4EN,0);
    state=0;
}
/*---------------left function---------------------*/
void left (){
    digitalWrite(M1F,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2F,HIGH);
    digitalWrite(M2B,LOW);
    digitalWrite(M3F,HIGH);
    digitalWrite(M3B,LOW);
    digitalWrite(M4F,LOW);
    digitalWrite(M4B,HIGH);
    analogWrite(M1EN,255);
    analogWrite(M2EN,255);
    analogWrite(M3EN,255);
    analogWrite(M4EN,255);
    state=0;
}
/*---------------right function---------------------*/
void right (){
    digitalWrite(M1F,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2F,LOW);
    digitalWrite(M2B,HIGH);
    digitalWrite(M3F,LOW);
    digitalWrite(M3B,HIGH);
    digitalWrite(M4F,HIGH);
    digitalWrite(M4B,LOW);
    analogWrite(M1EN,255);
    analogWrite(M2EN,255);
    analogWrite(M3EN,255);
    analogWrite(M4EN,255);
    state=0;
}
/*--------------------------USR---------------------*/
    void USR(){
        digitalWrite(Trigpin , LOW);
        delayMicroseconds (2);
        
        digitalWrite(Trigpin , HIGH );
        delayMicroseconds (10);
        digitalWrite(Trigpin , LOW );
        
        duration = pulseIn (Echopin , HIGH);
        distance = duration * 0.034/2 ; 
    }


/*===================================================*/
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

USR();


if (Serial3.available ()>0)  
   state = Serial3.read();
if (distance <=20){
    while(distance <=20){
         right ();
    }
  right ();
  delay(1500);
  STOP();
}

else {
    /*------------------FORWARD---------------*/
    if(state== '8') {
        forward ();
    }
    /*---------------------BACKWARD---------------*/
    else if (state == '2') {
        backward();
    }
    /*----------------------STOP------------------*/
    else if (state == '0') {
        STOP ();
    }
    /*----------------------RIGHT----------------*/
    else if (state == '6') {
        right ();
    }
    /*----------------------LEFT--------------------*/
    else if (state == '4') {
        left ();
    }
}
}
