// Inisialisasi pin Arduino
int buzzer = 5;
int sensor = 4;

void setup() {
  Serial.begin(9600);
  // Deklarasi pin sebagai I/O
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);

}

void loop() {
  // Membaca nilai pada sensor
  int sensorRead = digitalRead(sensor);

  // Menampilkan nilai pada sensor
  Serial.println("Nilai sensor PIR" + String(sensorRead));

  // Logika
  if(sensorRead == 1){
    digitalWrite(buzzer, HIGH);
    Serial.println("Waspadalah! Waspadalah!");
  }
  else{
    digitalWrite(buzzer, LOW);
  }
}
