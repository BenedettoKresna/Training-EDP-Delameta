// Inisialisasi pin Arduino yang digunakan
int button1 = 8, button2 = 9;
int led1 = 2, led2 = 3;

void setup() {
  Serial.begin(9600);

  // Deklarasi I/O
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

}

void loop() {
  // Melakukan pembacaan nilai sensor
  int buttonRead1 = digitalRead(button1);
  int buttonRead2 = digitalRead(button2);

  // Menampilkan hasil pembacaan sensor pada Serial Monitor
  Serial.println("Nilai di button 1 :" + String(buttonRead1));
  Serial.println("Nilai di button 1 :" + String(buttonRead2));

  // Logika button 1
  if(buttonRead1 == 1){
    digitalWrite(led1, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
  }

  // Logika button 2
  if(buttonRead2 == 1){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led2, LOW);
  }

}
