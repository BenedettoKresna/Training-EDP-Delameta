// Inisialisasi Pin STM32
int ledMerah = PA0, ledKuning = PA1, ledHijau = PA5;
int sensorInfrared = PA3;
int sensorLDR = PA4;
int lock = 0, count = 0;
String led;

void setup() {
  // Deklarasi Input atau Output
  Serial.begin(9600);
  
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  pinMode(sensorInfrared, INPUT);
  pinMode(sensorLDR, INPUT);

}

void loop() {
  // Membaca nilai sensor
  int bacaSensorLDR = map(analogRead(sensorLDR), 0, 4095, 255, 0);
  int bacaSensorInfrared = digitalRead(sensorInfrared);

  // Menampilkan nilai sensor
  Serial.print("Nilai LDR : " + String(bacaSensorLDR) + " ");
  Serial.println("Nilai Infrared : " + String(bacaSensorInfrared) + " ");

  // Logika
  if(bacaSensorInfrared == 0 && lock == 0){
    lock = 1;
  }
  else if(bacaSensorInfrared == 1 && lock == 1){
    if(count == 0){
      count = 1;
    }
    else{
      count = 0;
    }
    lock = 0;
  }

  if(count == 1){
    if(bacaSensorLDR >= 200){
      pembacaan(ledHijau, ledKuning, ledMerah);

    }
    else if(bacaSensorLDR >= 100 && bacaSensorLDR < 200){
      pembacaan(ledKuning, ledMerah, ledHijau);
    }
    else{
      pembacaan(ledMerah, ledHijau, ledKuning);
    }
  }
  else{
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  }
}

void pembacaan(int led1, int led2, int led3){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}
