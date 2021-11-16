#include <SPI.h>
#include <MFRC522.h>

String uidString;

int SDA_rfid = PB7;
int RST_rfid = PA10;

MFRC522 rfid(SDA_rfid, RST_rfid);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.print("Tempelkan Kartu");
}

void loop() {
  if(rfid.PICC_IsNewCardPresent()){
    read_rfid();
    Serial.println("Nomor RFID Anda :" + uidString);
    if(uidString == "2AA5B715"){
      Serial.println("Selamat Datang!");
    }
    else{
      Serial.println("Kartu Belum Terdaftar");
    }
  }
}
void read_rfid() {
  rfid.PICC_ReadCardSerial();
  uidString = String(rfid.uid.uidByte[0], HEX) + "" +
              String(rfid.uid.uidByte[1], HEX) + "" +
              String(rfid.uid.uidByte[2], HEX) + "" +
              String(rfid.uid.uidByte[3], HEX);
  uidString.toUpperCase();
}
