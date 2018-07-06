# define photointerrupter_l 9
# define photointerrupter_r 10
# define IN1 2
# define IN2 3
# define IN3 4
# define IN4 7
# define ENA 5
# define ENB 6
# define width_car 11.57


void forward(int dist);    //distance in cm
void turn(int angle);     //angle in degrees
void drive_rect(int length , int width);    //length and width in cm

void setup()
{
  pinMode(photointerrupter_l,INPUT);
  pinMode(photointerrupter_r,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}
void loop
{
  drive_rect();
}
void forward(int dist)
{
  bool flag=digitalRead(photointerrupter_l);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  for (int i=0;i<dist;)
  {
    if(digitalRead(photointerrupter_l)&&!flag)
    {
      i++;
      flag=1;
    }
    if(!digitalRead(photointerrupter_l))
    {
      flag=0;
    }
  }
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  
}
void turn(int angle)
{
  float dist=(float)angle*3.1415926535*width_car/360.0;
  bool flag=digitalRead(photointerrupter_l);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  for (int i=0;i<dist;)
  {
    if(digitalRead(photointerrupter_l)&&!flag)
    {
      i++;
      flag=1;
    }
    if(!digitalRead(photointerrupter_l))
    {
      flag=0;
    }
  }
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  
}
void drive_rect(int length , int width)
{
  forward(length);
  turn(90);
  forward(width);
  turn(90);
  forward(length);
  turn(90);
  forward(width);
  turn(90);
}
