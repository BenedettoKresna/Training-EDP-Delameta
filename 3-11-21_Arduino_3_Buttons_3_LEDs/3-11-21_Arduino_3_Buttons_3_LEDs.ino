// Inisialisasi pin Arduino yang akan digunakan
int button1 = 2, button2 = 3, button3 = 4;
int lampuMerah = 5, lampuKuning = 6, lampuHijau = 7;

void setup() {
  Serial.begin(9600);

  // Deklarasi pin Arduino sebagai Input/Output
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
  // Pembacaan nilai pada tiap button
  int buttonRead1 = digitalRead(button1);
  int buttonRead2 = digitalRead(button2);
  int buttonRead3 = digitalRead(button3);

  // Menampilkan nilai hasil pembacaan button pada Serial Monitor
  Serial.println("Button value:" + String(buttonRead1));
  Serial.println("Button value:" + String(buttonRead2));
  Serial.println("Button value:" + String(buttonRead3));
  
  // Logika Button 1
  if(buttonRead1 == 1){
    digitalWrite(lampuMerah, HIGH);
  }
  else{
    digitalWrite(lampuMerah, LOW);
  }
  
  // Logika Button 2  
  if(buttonRead2 == 1){
    digitalWrite(lampuKuning, HIGH);
  }
  else{
    digitalWrite(lampuKuning, LOW);
  }
  
  // Logika Button 3  
  if(buttonRead3 == 1){
    digitalWrite(lampuHijau, HIGH);
  }
  else{
    digitalWrite(lampuHijau, LOW);
  }
}
