// Inisialisasi pin Arduino yang akan digunakan
int sensorFlame = A1;
int buzzer = 5;
int ledMerah = 2, ledKuning = 3, ledHijau = 4;

void setup() {
  Serial.begin(9600);

  // Deklarasi I/O
  pinMode(sensorFlame, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

}

void loop() {
  // Melakukan pembacaan nilai pada sensor
  int sensorReadFlame = map(analogRead(sensorFlame), 1023, 23, 0, 100);
//  Serial.println("Nilai pembacaan sensor : " + String(sensorReadFlame));  
  delay(1000);

  // Logika
  if(sensorReadFlame <= 5){
    Serial.println("Kondisi terpantau aman, Gan");
//    digitalWrite(ledHijau, HIGH);
//    digitalWrite(ledMerah, LOW);
//    digitalWrite(ledKuning, LOW);    
    kondisi(ledHijau, ledMerah, ledKuning);
  }
  else if(sensorReadFlame > 5 && sensorReadFlame <= 50){
    Serial.println("Waspadalah! Waspadalah! Kondisi terpantau siaga 2");
//    digitalWrite(ledKuning, HIGH);
//    digitalWrite(ledMerah, LOW);
//    digitalWrite(ledHijau, LOW);
    kondisi(ledKuning, ledMerah, ledHijau);
    for(int i = 0; i <= 5; i++){
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
    }    
  }
  else if(sensorReadFlame > 50){
    Serial.println("Peringatan, sensor mendeteksi adanya api, kondisi siaga 1");
//    digitalWrite(ledMerah, HIGH);
//    digitalWrite(ledKuning, LOW);
//    digitalWrite(ledHijau, LOW);    
    kondisi(ledMerah, ledKuning, ledHijau);
    for(int i = 0; i <= 5; i++){
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }        
  }
}

// Fungsi untuk menyalakan LED
void kondisi(int led1, int led2, int led3){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}
