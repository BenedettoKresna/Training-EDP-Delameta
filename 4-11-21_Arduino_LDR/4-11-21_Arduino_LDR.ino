// Inisialisasi pin yang akan digunakan
int sensor = A0;
int led = 5;

void setup() {
  Serial.begin(9600);

  // Deklarasi pin sebagai I/O
  pinMode(led, OUTPUT);

}

void loop() {
  // Melakukan pembacaan nilai pada sensor
  int sensorRead = map(analogRead(sensor), 0, 1024, 0, 255);

  // Menampilkan nilai sensor pada Serial Monitor
  Serial.println("Nilai pembacaan sensor : " + String(sensorRead));

  // Logika
  if(sensorRead >= 100){
    Serial.println("Gelap Sekali Everybody!");  
    analogWrite(led, sensorRead);
  }
  else{
    Serial.println("Silau Bro!");
    analogWrite(led, sensorRead);
  }
  delay(1000);

}
