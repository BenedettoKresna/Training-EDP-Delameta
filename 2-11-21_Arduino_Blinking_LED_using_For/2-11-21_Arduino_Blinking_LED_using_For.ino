// Inisialisasi pin Arduino yang akan digunakan
int lampuMerah = 2, lampuKuning = 3, lampuHijau = 4;

// Deklarasi variabel 
int nilai;

void setup() {
  // Deklarasi Input/Output Arduino dengan perulangan (for)
  for(nilai = 2; nilai <= 4; nilai++){
    pinMode(nilai, OUTPUT);  
  }
}

void loop() {
  // Perulangan agar LED 2 hingga 4 menyala secara berurutan
  for(nilai = 2; nilai <= 4; nilai++){
    digitalWrite(nilai, HIGH);
    delay(100);
  }
  // Perulangan agar LED 4 hingga 2 mati secara berurutan
  for(nilai = 4; nilai >= 2; nilai--){
    digitalWrite(nilai, LOW);
    delay(100); 
  } 
}
