#include <FreqMeasure.h>
double sum=0;
int count=0;
bool state = false;
int frequency;
int continuity =0;

void setup() {
  Serial.begin(9600);
  FreqMeasure.begin(); 
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop(){
if (FreqMeasure.available()) {
      frequency = FreqMeasure.read();
      Serial.println(frequency);
    }
}
