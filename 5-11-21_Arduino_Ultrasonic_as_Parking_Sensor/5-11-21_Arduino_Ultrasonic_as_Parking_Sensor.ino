#include <NewPing.h>

// Inisialisasi pin Arduino
int trig = 5;
int echo = 4;
int buzzer = 3;
int ledMerah = 8, ledKuning = 9, ledHijau = 10;
int batas = 400; 

NewPing cm(trig, echo, batas);

void setup() {
  Serial.begin(9600);

  // Deklarasi I/O
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Membaca jarak pada dengan sensor ultrasonik
  int readJarak = cm.ping_cm();

  // Logika
  if(readJarak <= 20){
    Serial.println("Berhenti Gan, jarak mobil hanya " + String(readJarak) + " dari tembok");
    kondisi(HIGH, LOW, LOW);
//    digitalWrite(ledMerah, HIGH);
//    digitalWrite(ledKuning, LOW);
//    digitalWrite(ledHijau, LOW);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
  else if(readJarak > 20 &&  readJarak <= 70){
    Serial.println("Peringatan! tetap jaga jarak aman!");
    kondisi(LOW, HIGH, LOW);
//    digitalWrite(ledKuning, HIGH);
//    digitalWrite(ledMerah, LOW);
//    digitalWrite(ledHijau, LOW);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);    
  }
  else if(readJarak > 70){
    Serial.println("Mobil pada jarak aman, silahkan mundur perlahan!");
    kondisi(LOW, LOW, HIGH);
//    digitalWrite(ledHijau, HIGH);
//    digitalWrite(ledMerah, LOW);
//    digitalWrite(ledKuning, LOW);  
  }
}

void kondisi(int nilai1, int nilai2, int nilai3){
    digitalWrite(ledMerah, nilai1);
    digitalWrite(ledKuning, nilai2);
    digitalWrite(ledHijau, nilai3); 
}
