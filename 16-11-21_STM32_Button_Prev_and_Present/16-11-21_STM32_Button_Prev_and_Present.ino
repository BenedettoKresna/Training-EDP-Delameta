// Inisialisasi pin STM32
int pinButton = PC13;

// Inisialisasi variabel
int buttonLampau = 0;
int count = 0;

void setup() {
  Serial.begin(9600);

  // Deklarasi pin sebagai Input/Output
  pinMode(pinButton, INPUT);

}

void loop() {
  // Membaca nilai pada button
  int buttonSekarang = digitalRead(pinButton);

  // Logika
  if(buttonSekarang == 1 && buttonLampau == 0){
    if(count == 0){
      Serial.println("LED HIGH");
      count = 1;
    }
    else{
      Serial.println("LED LOW");
      count = 0;
    }

  }
  buttonLampau = buttonSekarang;
//  Serial.println("Hitungan ke :" + String(count));

}
