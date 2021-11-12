// Inisialisasi Pin STM32
int ledMerah = PC13, ledKuning = PC14, ledHijau = PC15;
int buttonMerah = PA0, buttonKuning = PA1, buttonHijau = PA2;

void setup() {
  // Deklarasi Pin sebagai Masukan dan Keluaran
  Serial.begin(9600);
  
  pinMode(buttonMerah, INPUT);
  pinMode(buttonKuning, INPUT);
  pinMode(buttonHijau, INPUT);

  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT); 
}

void loop() {
  // Membaca nilai pada sensor
  int buttonReadMerah = digitalRead(buttonMerah);
  int buttonReadKuning = digitalRead(buttonKuning);
  int buttonReadHijau = digitalRead(buttonHijau);

  // Menampilkan nilai pada sensor
  Serial.print("Button 1:" + String(buttonReadMerah) + " ");
  Serial.print("Button 2:" + String(buttonReadKuning) + " ");
  Serial.println("Button 3:" + String(buttonReadHijau));
  
  // Logika
  if(buttonReadMerah == 1){
    digitalWrite(ledMerah, HIGH);
  }
  else{
    digitalWrite(ledMerah, LOW);     
  }
  
  if(buttonReadKuning == 1){
    digitalWrite(ledKuning, HIGH);
  }
  else{
    digitalWrite(ledKuning, LOW);
  }
  
  if(buttonReadHijau == 1){
    digitalWrite(ledHijau, HIGH);
  }
  else{
    digitalWrite(ledHijau, LOW);
  }
}
