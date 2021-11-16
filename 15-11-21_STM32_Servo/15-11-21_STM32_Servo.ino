#include <Servo.h>

// Inisialisasi pin STM32
int servoPin = 10;

Servo servo1;

void setup() {
  Serial.begin(9600);
  // Deklarasi servo
  servo1.attach(servoPin);

  Serial.println("Pilih salah satu :");
  Serial.println("1. Putar 45 derajat");
  Serial.println("2. Putar 90 derajat");
  Serial.println("3. Putar 180 derajat");
}

void loop() {
  // Logika
  if(Serial.available() > 0){
    int nomor = Serial.read();
    nomor = nomor - 48; // ASCII
    switch(nomor) {
      case 1:
        putar(45);
        break;
      case 2:
        putar(90);
        break;
      case 3:
        putar(180);   
        break;           
    }
    nomor = 0;
  }
}

void putar(int derajat){
  servo1.write(0);
  delay(1000);
  servo1.write(derajat);
  delay(1000);
  servo1.write(0);
  delay(1000);
}
