#include <IRremote.h>

int receiver = 2; //Signal Pin of IR receiver to Arduino Pin ?
int LedPin = 8; //output to pin
int LedState = LOW;
int previous = LOW;
long time = 0;

IRrecv irrecv(receiver);
decode_results results;
 
void setup(){
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  Serial.println("Visual Effects Online");
  irrecv.enableIRIn(); // Start the receiver
}
 
void loop(){
  if (irrecv.decode(&results)){ // have we received an IR signal?
    translateIR(); 
    irrecv.resume(); // receive the next value
    LedState = digitalRead(LedPin);
  }
}

void translateIR(){ // takes action based on IR code received
 switch(results.value){
  case 0xFF30CF: //Need to change to change button code
 if(LedState == LOW){
          digitalWrite(LedPin, HIGH);
          Serial.println(" Controler '1' Read  Led On");
          digitalRead(LedState);
   } else if(LedState != LOW){
          digitalWrite(LedPin, LOW);
          Serial.println(" Controler '1' Read  Led Off");
  }
  default: Serial.println(" Imput not in use");
 }
  delay(1000); // Do not get immediate repeat
}
