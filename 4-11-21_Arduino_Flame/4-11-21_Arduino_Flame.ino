// Inisialisasi pin Arduino yang dipakai
int sensorFlame = A1;
int led = 5;

void setup() {
  Serial.begin(9600);

  // Deklarasi I/O
  pinMode(sensorFlame, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // Melakukan pembacaan nilai pada sensor
  int sensorReadFlame = analogRead(sensorFlame);

  // Menampilkan nilai pada Serial Monitor
  Serial.println("Nilai pembacaan sensor : " + String(sensorReadFlame));  
  delay(1000);
}
