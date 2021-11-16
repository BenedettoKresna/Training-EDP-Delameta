// Inisialisasi pin Arduino
int sensorLDR = A0;
int sensorFlame = A1;
int PIR = 6;
int buzzer = 5;
int ledMerah = 2, ledKuning = 3, ledHijau = 4;

void setup() {
  Serial.begin(9600);

  // Deklarasi pin sebgai Input/Output
  pinMode(sensorFlame, INPUT);
  pinMode(sensorLDR, INPUT);
  pinMode(PIR, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

}

void loop() {
  // Membaca nilai pada masing-masing sensor
  int sensorReadFlame = map(analogRead(sensorFlame), 1023, 23, 0, 100);
  int sensorReadLDR = map(analogRead(sensorLDR), 0, 1024, 0, 255);
  int sensorReadPIR = digitalRead(PIR);

  // Menampilkan nilai masing-masing sensor pada Serial Monitor
  Serial.println("Nilai pembacaan sensor Flame : " + String(sensorReadFlame));  
  Serial.println("Nilai pembacaan sensor LDR : " + String(sensorReadLDR)); 
  Serial.println("Nilai pembacaan sensor PIR : " + String(sensorReadPIR)); 
  delay(1000);

  // Sensor LDR pada LED
  analogWrite(ledKuning, sensorReadLDR);

  // Sensor Flame dan Serial Monitor
  if(sensorReadFlame <= 5){
    Serial.println("Kondisi terpantau aman, Gan");
//    digitalWrite(ledHijau, HIGH);
//    digitalWrite(ledMerah, LOW);
//    digitalWrite(ledKuning, LOW);    
//    kondisi(ledHijau, ledMerah, ledKuning);
  }
  else if(sensorReadFlame > 5 && sensorReadFlame <= 50){
    Serial.println("Waspadalah! Waspadalah! Kondisi terpantau siaga 2");
//    digitalWrite(ledKuning, HIGH);
//    digitalWrite(ledMerah, LOW);
//    digitalWrite(ledHijau, LOW);
//    kondisi(ledKuning, ledMerah, ledHijau);
    for(int i = 0; i <= 5; i++){
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    }    
  }
  else if(sensorReadFlame > 50){
    Serial.println("Peringatan, sensor mendeteksi adanya api, kondisi siaga 1");
//    digitalWrite(ledMerah, HIGH);
//    digitalWrite(ledKuning, LOW);
//    digitalWrite(ledHijau, LOW);    
//    kondisi(ledMerah, ledKuning, ledHijau);
    for(int i = 0; i <= 5; i++){
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }        
  }
}

//void kondisi(int led1, int led2, int led3){
//  digitalWrite(led1, HIGH);
//  digitalWrite(led2, LOW);
//  digitalWrite(led3, LOW);
//}
