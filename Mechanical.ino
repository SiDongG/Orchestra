int enable=11;
int motor1=10;
int motor2=9;
int sensor=2;
int Power=0;
int led=12;

void setup() {
  // put your setup code here, to run once:
  pinMode (led,OUTPUT);
  pinMode (enable,OUTPUT);
  pinMode (motor1,OUTPUT);
  pinMode (motor2,OUTPUT);
  pinMode (sensor,INPUT);
}

void loop() {
  analogWrite(enable,200);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);

}
