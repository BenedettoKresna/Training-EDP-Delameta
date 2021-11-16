unsigned long myTime;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print("Time: ");
  myTime = millis(); // Fungsi untuk menggantikan delay

  Serial.println(myTime); // Menampilkan nilai dari variabel myTime
  delay(1000);            // Nilai ditampilkan setiap 10 detik
}
