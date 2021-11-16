#include<SPI.h>
#include<MFRC522.h>

//Inisialisasi pin Arduino yang akan dipakai
#define SS_PIN 10
#define RST_PIN 9
int buzzer = 6;

MFRC522 rfid(SS_PIN, RST_PIN);


void setup() {
  Serial.begin(9600);
  // Deklarasi pin sebagai Input/Output
  SPI.begin();
  MFRC522 PCD_Init(); 
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Logika untuk mengecek apakah terdpat kartu pada RFID Reader ?
  if( !rfid.PICC_IsNewCardPresent()){
    return;
  }
  // Logika untuk membaca nomor pada RFID Tag
  if( !rfid.PICC_ReadCardSerial()){
    return;
  }

  // Menampilkan nomor kartu pada Serial Monitor
  Serial.print("Nomor Kartu :");
  String content= "";
  byte letter;
  for(byte i = 0; i < rfid.uid.size; i++)
  {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(rfid.uid.uidByte[i], HEX);
    content.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(rfid.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Pesan : ");
  content.toUpperCase();
  if(content == "2AA5B715")
  {
    Serial.println("Selamat datang User 1!"); 
    pembacaan("Terdaftar");
  }
  else if(content == "1A0CE980")
  {
    Serial.println("Selamat datang User 2!"); 
    pembacaan("Terdaftar");
  }
  else
  {
    Serial.println("Kartu belum terdaftar!"); 
    pembacaan("Tidak Terdaftar");
  }
  Serial.println("Tempelkan Kartu!");
  delay(500);
}

void pembacaan(String nilai){
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
