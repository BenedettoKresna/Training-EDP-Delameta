// Inisialisasi pin yang akan dipakai
int lampuMerah = 5, lampuKuning= 6, lampuHijau = 7;
int button = 2;
int sensor = 8;

// Inisialisasi variabel
int tambahan = 0;
int buttonReadAkhir = 0;


void setup() {
  Serial.begin(9600);

  // Deklarasi I/O menggunakan perulangan for
  for(int i = 2; i <= 4; i++)
  {
    pinMode(i, INPUT); 
  }
  for(int i = 5; i <= 7; i++)
  {
    pinMode(i, OUTPUT); 
  }
  pinMode(sensor, INPUT);
  Serial.println("Selamat datang di Ruko Puri Botanical");
  digitalWrite(lampuMerah, HIGH);
}

void loop() {
  // Membaca nilai pada sensor
  int buttonRead = digitalRead(button);
  int sensorRead = digitalRead(sensor);
// Serial.println("Button value:" + String(buttonRead));
  
  // Logika 
  if(buttonRead == 1 && tambahan == 0){
    digitalWrite(lampuMerah, LOW);
    Serial.println("Pintu palang dibuka");
    digitalWrite(lampuKuning, HIGH);
    delay(2000);
    digitalWrite(lampuKuning, LOW);
    digitalWrite(lampuHijau, HIGH);
    tambahan = 1;
  }
  else if(sensorRead == 0 && tambahan == 1){
    digitalWrite(lampuHijau, LOW);
    digitalWrite(lampuMerah, HIGH);
    Serial.println("Pintu palang ditutup");
    tambahan = 0;
  }
}
