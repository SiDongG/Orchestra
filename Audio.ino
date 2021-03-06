#include <Servo.h>
int led=2;
int sensor=8;
int speaker=3;

int octive=4;

int durations[]={2,1,2,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,5,1};
int C=16.3516*(2^octive);
int D=18.35405*(2^octive);
int E=20.60172*(2^octive);
int F=21.82676*(2^octive);
int G=24.49971*(2^octive);
int A=27.5*(2^octive);
int B=30.86771*(2^octive);
int high_C=32.70320*(2^octive);
int rest=0;
int notes[]={C,rest,C,rest,C,rest,D,rest,E,rest,E,rest,D,rest,E,rest,F,rest,G,rest,high_C,rest,high_C,rest,high_C,rest,G,rest,G,rest,G,rest,E,rest,E,rest,E,rest,C,rest,C,rest,C,rest,G,rest,F,rest,E,rest,D,rest,C,rest};
int s=100;

int conductorMode = 12;  //Switch 
int playerMode = 13;
int playerState;
int conductorState;

const int AA=4; //LSB
const int BB=5;
const int CC=6;
const int DD=7; //MSB
//octave buttons
int oct_up = A3;
int upstate;
int oct_down = A4;
int downstate;
int select = A5;
int selectState;

int angle=0;
bool value=0;

Servo servo;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(speaker,OUTPUT);
  pinMode(select,INPUT);
  pinMode(oct_up,INPUT);
  pinMode(oct_down,INPUT);
  pinMode(conductorMode, INPUT);
  pinMode(playerMode, INPUT);
  pinMode(AA, OUTPUT); //LSB
  pinMode(BB, OUTPUT);
  pinMode(CC, OUTPUT);
  pinMode(DD, OUTPUT); //MSB
  servo.attach(A1);
  servo.write(angle);
  Serial.begin(9600);
}

void conductorsetup() {
  digitalWrite(led,HIGH);
  selectState=digitalRead(select);
  Serial.println(1);
  if (selectState==LOW) {
    Serial.println(56);
    play();
  }
}

void playersetup() {
  /////Do audio analysis and set tempo and octave...
  play();
}

void loop() {
  int  a = octive%2;
  int b = (octive/2)%2;
  int c = (octive/4)%2;
  int d = (octive/8)%2;
  (a==0) ? digitalWrite(AA, LOW): digitalWrite(AA, HIGH);
  (b==0) ? digitalWrite(BB, LOW): digitalWrite(BB, HIGH);
  (c==0) ? digitalWrite(CC, LOW): digitalWrite(CC, HIGH);
  (d==0) ? digitalWrite(DD, LOW): digitalWrite(DD, HIGH);
  upstate=digitalRead(oct_up);
  downstate=digitalRead(oct_down);
  if (upstate==LOW) {
    octive++;
    delay(500);
  }
  if (downstate==LOW) {
    octive--;
    delay(500);
  }
  playerState=digitalRead(playerMode);
  conductorState=digitalRead(conductorMode);
  if(playerState == 1) {
    playersetup();
  } 
  else{
    conductorsetup();
  }
  
  }

void play() {
  tone(speaker,A,durations[2]*100);
  for (int i=0; notes[i]!=-1;i++){
    //move the motor in here somewhere as well
    //for testing 
    int duration=s*durations[i];
    tone(speaker,notes[i],duration*0.95);
    Serial.println(2);
    delay(duration);
    if (i==52){
        break;
      }
  }
  }
