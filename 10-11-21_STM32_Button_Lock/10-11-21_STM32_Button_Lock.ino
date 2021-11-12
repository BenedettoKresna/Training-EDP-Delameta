// Inisialisasi variabel
int ledMerah = PC13, ledKuning = PC14, ledHijau = PC15; // Inisialisasi Pin pada LED
int buttonMerah = PA0, buttonKuning = PA1, buttonHijau = PA2; // Inisialisasi Pin pada Button
int kunciMerah = 0, kunciKuning = 0, kunciHijau = 0; 
int countMerah = 0, countKuning = 0, countHijau = 0;

void setup() {
  // Deklarasi Pin Input/Output
  Serial.begin(9600);

  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  pinMode(buttonMerah, INPUT);
  pinMode(buttonKuning, INPUT);
  pinMode(buttonHijau, INPUT);
}

void loop() {
  // Pembacaan button oleh digitalRead()
  int bacaButtonMerah = digitalRead(buttonMerah);
  int bacaButtonKuning = digitalRead(buttonKuning);
  int bacaButtonHijau = digitalRead(buttonHijau);

  // Menampilkan nilai pada Serial Monitor
  Serial.print("Nilai pada button merah : " + String(bacaButtonMerah) + " ");
  Serial.print("Nilai pada button kuning : " + String(bacaButtonKuning) + " ");
  Serial.println("Nilai pada button hijau : " + String(bacaButtonHijau));

  // Logika Button Merah
  if(bacaButtonMerah == 1){
    kunciMerah = 1;
  }

  if(kunciMerah == 1 && bacaButtonMerah == 0){
    if(countMerah == 0){
      digitalWrite(ledMerah, HIGH);
      countMerah = 1;
    }
    else{
      digitalWrite(ledMerah, LOW);
      countMerah = 0;
    }
    kunciMerah = 0;
  }

  // Logika Button Kuning
  if(bacaButtonKuning == 1){
    kunciKuning = 1;
  }

  if(kunciKuning == 1 && bacaButtonKuning == 0){
    if(countKuning == 0){
      digitalWrite(ledKuning, HIGH);
      countKuning = 1;
    }
    else{
      digitalWrite(ledKuning, LOW);
      countKuning = 0;
    }
    kunciKuning = 0;
  }

  // Logika Button Hijau
  if(bacaButtonHijau == 1){
    kunciHijau = 1;
  }

  if(kunciHijau == 1 && bacaButtonHijau == 0){
    if(countHijau == 0){
      digitalWrite(ledHijau, HIGH);
      countHijau = 1;
    }
    else{
      digitalWrite(ledHijau, LOW);
      countHijau = 0;
    }
    kunciHijau = 0;
  }
}
