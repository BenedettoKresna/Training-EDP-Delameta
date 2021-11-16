// Inisialisasi pin Arduino yang akan digunakan
int lampuMerah = 2, lampuKuning = 3, lampuHijau = 4;

void setup() {
  // Deklarasi pin Arduino sebagai Output (keluaran)
  pinMode(lampuMerah, OUTPUT);
  pinMode(lampuKuning, OUTPUT);
  pinMode(lampuHijau, OUTPUT);
}

void loop() {
  // LED merah menyala, selain itu mati
  digitalWrite(lampuMerah, HIGH);
  digitalWrite(lampuHijau, LOW);
  delay(5000);
  // LED kuning menyala, selain itu mati
  digitalWrite(lampuMerah, LOW);
  digitalWrite(lampuKuning, HIGH);
  delay(1000);
  // LED hijau menyala, selain itu mati
  digitalWrite(lampuKuning, LOW);
  digitalWrite(lampuHijau, HIGH);
  delay(3000);
}
