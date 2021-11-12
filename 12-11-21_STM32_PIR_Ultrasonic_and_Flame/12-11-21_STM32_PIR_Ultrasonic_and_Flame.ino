#include <NewPing.h>

// Initialitation STM32's Pin
int ledMerah = PC13, ledKuning = PC14, ledHijau = PC15;
int sensorFlame = PA0;
int sensorPIR = PA1;
int trig = PA4, echo = PB4, distance = 200; // Trig should be at Analog or PWM Pin
int lock = 0;
int count = 0;
int pembeda = 0;

// Make new object from Class NewPing
NewPing sensorUltrasonik(trig, echo, distance);

void setup() {
  // Declaration Pin as an I/O
  Serial.begin(9600);
  
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  pinMode(sensorFlame, INPUT);
  pinMode(sensorPIR, INPUT);
  digitalWrite(ledMerah, HIGH);
}


void loop() {
  // Read Sensor value using analogRead() or digitalRead() and then put it into new variable
  int bacaSensorFlame = map(analogRead(sensorFlame), 0, 4095, 255, 0);
  int bacaSensorPIR = map(digitalRead(sensorPIR), 0, 1, 1, 0);
  int bacaSensorUltrasonik = sensorUltrasonik.ping_cm();

  // Show Sensor value in Serial Monitor
  Serial.print("Nilai Sensor Flame : " + String(bacaSensorFlame) + " ");
  Serial.print("Nilai Sensor PIR : " + String(bacaSensorPIR) + " ");
  Serial.print("Nilai Sensor Ultrasonik : " + String(bacaSensorUltrasonik) + " ");
  Serial.print("Nilai PEMBEDA : " + String(pembeda) + " ");
  Serial.println("Nilai COUNT : " + String(count));

  // Logic
  if(bacaSensorPIR == 1 && lock == 0 && pembeda != 2){
    lock = 1;
  }
  else if(bacaSensorPIR == 0 && lock == 1 && pembeda != 2){
    if(count == 0){
      pembeda = 1;
      count = 1;
    }
    else{
      count = 0;
      pembeda = 0;
    }
    lock = 0;
  }
  
  if(bacaSensorFlame > 0 && lock == 0 && pembeda != 1){
    lock = 2;
  }
  else if(bacaSensorFlame == 0 && lock == 2 && pembeda != 1){
    if(count == 0){
      count = 1;
      pembeda = 2;
    }
    else{
      count = 0;
      pembeda = 0;
    }
    lock = 0;
  }
  
  if(count == 1){
    if(bacaSensorUltrasonik > 50){
      pembacaan(1, 0, 0);
      delay(1000);
      pembacaan(0, 1, 0);
      delay(1000);
      pembacaan(0, 0, 1);
      delay(1000);
      pembacaan(0, 1, 0);
      delay(1000);
    }
    else if(bacaSensorUltrasonik >= 25 && bacaSensorUltrasonik <= 50){
      pembacaan(1, 1, 1);
      delay(1000);
      pembacaan(0, 0, 0);
      delay(1000);    
    }
    else if(bacaSensorUltrasonik < 25){
      pembacaan(1, 1, 1);
      delay(100);
      pembacaan(0, 0, 0);
      delay(100);        
    }
  }
  else{
    pembacaan(0, 0, 0);
  }
}

void pembacaan(int led1, int led2, int led3){
  digitalWrite(ledMerah, led1);
  digitalWrite(ledKuning, led2);
  digitalWrite(ledHijau, led3);
}
