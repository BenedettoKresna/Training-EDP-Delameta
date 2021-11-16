#include<SPI.h>
#include<MFRC522.h>

// Inisialisasi Pin Arduino
#define SS_PIN 10
#define RST_PIN 9
int buzzer = 6;

// Mendeklarasikan Pin RFID & variabel
MFRC522 rfid(SS_PIN, RST_PIN); 
String uidString;

void setup() {
  Serial.begin(9600);
  
  // Inisialisasi SPI dan PCD_Init 
  SPI.begin();
  rfid.PCD_Init(); 
  
  // Deklarasi Input atau Output
  pinMode(buzzer, OUTPUT);
  Serial.print("Tempelkan kartu!");
}

void loop() {
  // Logika RFID
  if(rfid.PICC_IsNewCardPresent())
  {
    readRFID();
    Serial.println("Tag UID :" + uidString);
    if(uidString == "2AA5B715")
    {
      Serial.println("Selamat datang User 1!"); 
      pembacaan("Terdaftar");      
    }
    else if(uidString == "1ACE980")
    {
      Serial.println("Selamat datang User 2!"); 
      pembacaan("Terdaftar");
    }
    else
    {
      Serial.println("Kartu belum terdaftar!"); 
      pembacaan("Tidak Terdaftar");
    }    
  }
}

// Fungsi Pembacaan RFID
void readRFID() {
  rfid.PICC_ReadCardSerial();
  uidString = String(rfid.uid.uidByte[0], HEX) + "" +
              String(rfid.uid.uidByte[1], HEX) + "" +
              String(rfid.uid.uidByte[2], HEX) + "" +
              String(rfid.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}

// Fungsi Buzzer
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
