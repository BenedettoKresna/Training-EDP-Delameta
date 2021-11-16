//Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>

//Inisialisasi pin Arduino yang akan dipakai
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
 Serial.begin(9600); 
 // Inisialisai SPI bus
 SPI.begin(); 
 // Inisialisai MFRC522
 mfrc522.PCD_Init(); 
}

void loop() {
  // Logika untuk mengecek apakah terdpat kartu pada RFID Reader ?
  if( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  // Logika untuk membaca nomor pada RFID Tag
  if( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }
 
  // Menampilkan nomor kartu pada Serial Monitor
  Serial.print("Nomor Kartu :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content == "2AA5B715") // Nomor pada Kartu 
  {
    Serial.println("Selamat datang!!!");
    delay(2000);
  }
  else{
    Serial.println("Kartu Belum Terdaftar!");
  }
  Serial.println("Tempelkan Kartu!");
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
