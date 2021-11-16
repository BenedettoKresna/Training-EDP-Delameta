// Inisialisasi pin Arduino
int button1 = 2, button2 = 3, button3 = 4;
int led1 = 5, led2 = 6, led3 = 7;

// Inisialisasi variabel
int buttonReadAkhir1 = 0,buttonReadAkhir2 = 0, buttonReadAkhir3 = 0;
int nilai1 = 0, nilai2 = 0, nilai3 = 0;

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
  // Membaca nilai pada button
  int buttonRead1 = digitalRead(button1);
  int buttonRead2 = digitalRead(button2);
  int buttonRead3 = digitalRead(button3);  

  // Logika button 1
  if(buttonRead1 == 1 && buttonReadAkhir1== 0){
    buttonReadAkhir1 = 1;
  }
  else if(buttonRead1 == 0 && buttonReadAkhir1 == 1){
    buttonReadAkhir1 = 0;
    nilai1 = nilai1 + 1;
  }
  
  if(nilai1 == 1){
    digitalWrite(led1, HIGH);
  }
  else if(nilai1 != 1){
    digitalWrite(led1, LOW);
    nilai1 = 0;
  }

  // Logika button 2
  if(buttonRead2 == 1 && buttonReadAkhir2== 0){
  buttonReadAkhir2 = 1;
  }
  else if(buttonRead2 == 0 && buttonReadAkhir2 == 1){
    buttonReadAkhir2 = 0;
    nilai2 = nilai2 + 1;
  }
  
  if(nilai2 == 1){
    digitalWrite(led2, HIGH);
  }
  else if(nilai2 != 1){
    digitalWrite(led2, LOW);
    nilai2 = 0;
  }

  // Logika button 3
  if(buttonRead3 == 1 && buttonReadAkhir3== 0){
    buttonReadAkhir3 = 1;
  }
  else if(buttonRead3 == 0 && buttonReadAkhir3 == 1){
    buttonReadAkhir3 = 0;
    nilai3 = nilai3 + 1;
  }
  
  if(nilai3 == 1){
    digitalWrite(led3, HIGH);
  }
  else if(nilai3 != 1){
    digitalWrite(led3, LOW);
    nilai3 = 0;
  }  
}
