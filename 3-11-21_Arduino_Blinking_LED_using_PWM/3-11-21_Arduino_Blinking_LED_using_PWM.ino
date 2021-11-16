/*
 * PWM meurupakan kepanjangan dari Pulse Width Modulation,
 * merupakan pin yang mana nilai dari keluaran dapat diatur dari 0 hingga 255.
 * Pin PWM ditandai dengan tanda "~".
*/


// Inisialisasi pin PWM Arduino yang akan dipakai
int lampuMerah = 9, lampuKuning = 10, lampuHijau = 11;

// Deklarasi variabel 
int nilai;

void setup() {
  Serial.begin(9600);

  // Deklarasi Input/Output dengan perulangan (for)
  for(nilai = 9; nilai <= 11; nilai++){
    pinMode(nilai, OUTPUT);  
  }
}

void loop() {
  // Perulangan untuk menyalakan LED secara berurutan dari pin 9 hingga 11
  for(int i = 9; i <= 11; i++){
    Serial.print("Volt di pin: " + String(i)); 
    delay(1000);
    for(nilai = 0; nilai <= 255; nilai++){ // Perulangan untuk mengatur PWM naik pada pin ke-i mulai dari 0 hingga 255
      analogWrite(i, nilai);
      float volt = 0.019607 * nilai;
      Serial.println("Tegangannya adalah " + String(volt) + " volt"); // Menampilkan tegangan pada pin ke-i
      delay(10);
    }
  }

  // Perulangan untuk menyalakan LED secara berurutan dari pin 11 hingga 9
  for(int i = 11; i >= 9; i--){
    Serial.print("Volt di pin: " + String(i)); 
    delay(1000);
    for(nilai = 255; nilai >= 0; nilai--){ // Perulangan untuk mengatur PWM turun pada pin ke-i mulai dari 255 hingga 0
       analogWrite(i, nilai);
       float volt = 0.019607 * nilai; 
       Serial.println("Tegangannya adalah " + String(volt) + " volt"); // Menampilkan tegangan pada pin ke-i
       delay(10); 
    }      
  }

}
