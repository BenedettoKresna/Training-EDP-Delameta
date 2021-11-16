#include<SPI.h>
#include<MFRC522.h>

String uidString;

// Inisialisasi pin Arduino yang digunakan
#define SS_PIN 10
#define RST_PIN 9
int buzzer = 6;
int sensor = 7;

// Inisialisasi variabel
int kondisi = 0;
int kunci = 0;

// Mendeklarasikan Pin RFID
MFRC522 rfid(SS_PIN, RST_PIN); 

void setup() {
  Serial.begin(9600);
  // Inisialisasi SPI dan PCD_Init 
  SPI.begin();
  rfid.PCD_Init(); 
  // Deklarasi I/O
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.print("Tempelkan kartu!");
}

void loop() {
  int sensorRead = digitalRead(sensor);
  // Serial.println(sensorRead);
  if(rfid.PICC_IsNewCardPresent() && kunci == 0)
  {
    readRFID();
    Serial.println("Tag UID : " + uidString);
    if(uidString == "2AA5B715")
    {
      Serial.println("Selamat datang User 1!"); 
      Serial.println("Palang Terbuka");
      pembacaan("Terdaftar");
      kunci = 1;

    }
    else if(uidString == "1ACE980")
    {
      Serial.println("Selamat datang User 2!"); 
      Serial.println("Palang Terbuka");
      kunci = 1;    
    }
    else
    {
      Serial.println("Kartu belum terdaftar!"); 
      pembacaan("Tidak Terdaftar");
      kunci = 0;
    }    
  }

  if(kunci == 1){
    palang(sensorRead);
  }
}

void readRFID() {
  rfid.PICC_ReadCardSerial();
  uidString = String(rfid.uid.uidByte[0], HEX) + "" +
              String(rfid.uid.uidByte[1], HEX) + "" +
              String(rfid.uid.uidByte[2], HEX) + "" +
              String(rfid.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}

// Fungsi untuk menyalakan/mematikan buzzer
void pembacaan(String nilai) {
  if(nilai == "Terdaftar")
  {
    for(int i = 0; i < 2; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    }  
  }
  else if(nilai == "Tidak Terdaftar")
  {
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
  }
}

// Fungsi untuk menaikkan/menurunkan palang
void palang(int nilaiSensor){
   if(nilaiSensor == 0){
    Serial.println("Palang Tertutup");
    pembacaan("Terdaftar");
    kunci = 0; 
  } 
}
