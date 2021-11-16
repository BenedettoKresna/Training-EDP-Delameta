// Inisialisasi pin Arduino
int button1 = 2, button2 = 3, button3 = 4;
int lampuMerah = 5, lampuKuning = 6, lampuHijau = 7;

void setup() {
  Serial.begin(9600);
  // Deklarasi I/O  
  for(int i = 2; i <= 4; i++)
  {
    pinMode(i, INPUT); 
  }
  for(int i = 5; i <= 7; i++)
  {
    pinMode(i, OUTPUT); 
  }
}

void loop() {
  // Membaca nilai button
  int buttonRead1 = digitalRead(button1);
  int buttonRead2 = digitalRead(button2); 

  // Menampilkan nilai pada Serial Monitor
  Serial.print("Button value:" + String(buttonRead1));
  Serial.print("Button value:" + String(buttonRead2));
  
  // Logika
  if(buttonRead1 == 1 && buttonRead2 == 1){
    digitalWrite(lampuMerah, HIGH);
  }
  else{
    digitalWrite(lampuMerah, LOW);
  }
}
