#include <Servo.h>

Servo myservo;  
int data;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, LOW);

  myservo.attach(9,600,2300);
}

void loop() {
  while (Serial.available()) {
    data = Serial.read();

    if (data == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      myservo.write(180); 
    } else if (data == '0') {
      digitalWrite(LED_BUILTIN, LOW);
      myservo.write(0);   
    }
  }

}
