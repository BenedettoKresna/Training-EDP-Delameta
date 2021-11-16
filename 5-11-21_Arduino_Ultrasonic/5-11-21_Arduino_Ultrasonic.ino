#include <NewPing.h>

// Inisialisasi pin yang akan digunakan
int trig = 5;
int echo = 4;

// Inisialisasi variabel
int batas = 400;

NewPing cm(trig, echo, batas);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Melakukan pembacaan nilai pada sensor
  int readJarak = cm.ping_cm();

  // Menampilkan hasil pembacaan pada sensor
  Serial.println("Berapa tinggi badanmu? " + String(readJarak) + " cm");
  delay(1000);
}
