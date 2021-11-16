#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi pin Arduino yang akan dipakai
#define SS_PIN 10
#define RST_PIN 9

int buzzer = 6;
int sensorInfrared = 7;

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Deklarasi variabel
String uidString;
int sensorRead;

int count = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  SPI.begin();
  rfid.PCD_Init();

  // Inisialisasi I/O
  pinMode(buzzer, OUTPUT);
  pinMode(sensorInfrared, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Tempelkan Kartu Anda!");
}

void loop() {
  // Membaca nilai pada sensor infrared
  readSensorInfrared();
  Serial.print(uidString);
  if(rfid.PICC_IsNewCardPresent() && count == 0)
  {
    // Membaca nomor pada RFID tag
    readRFID();
    if(uidString == "2AA5B715")
    {
      count = 1;
      clearLCD(1);
      pengguna("Upin");
      delay(2000);
      clearLCD(1);
      lcd.setCursor(0, 1);
      lcd.print("Palang Buka");
      delay(1000);
      clearLCD(1);
      lcd.setCursor(0, 1);
      lcd.print("Silahkan lewat!");
      pembacaan("Terdaftar");
    }
    else if(uidString == "1ACE980")
    {
      count = 1;
      clearLCD(1);
      pengguna("Ipin");
      delay(2000);
      clearLCD(1);
      lcd.setCursor(0, 1);
      lcd.print("Palang Buka");
      delay(1000);
      clearLCD(1);
      lcd.setCursor(0, 1);
      lcd.print("Silahkan lewat!");
      pembacaan("Terdaftar");
    }
    else
    {
      clearLCD(1);
      lcd.setCursor(0, 1);
      lcd.print("Daftar Dulu Gan");
      delay(1000);
      clearLCD(1);
      pembacaan("Tidak Terdaftar");
    }
  }
  else if(rfid.PICC_ReadCardSerial() && count == 1)
  {
    clearLCD(1);
    lcd.setCursor(0, 1);
    lcd.print("Cukup TAP sekali!");
    pembacaan("Tidak Terdaftar");
  }

  if(count == 1)
  {
    if(sensorRead == 0) // Ada Objek
    {
      clearLCD(1);
      delay(1000);
      lcd.setCursor(0, 1);
      lcd.print("Palang tutup");
      delay(1000);
      pembacaan("Terdaftar");
      clearLCD(1);
      count = 0;
    }
  }
}

// Membaca nomor pada RFID tag
void readSensorInfrared() {
  sensorRead = digitalRead(sensorInfrared);
  Serial.println("Nilai sensor Read:" + String(sensorRead));
}

// Fungsi baca RFID
void readRFID() {
  rfid.PICC_ReadCardSerial();
  uidString = String(rfid.uid.uidByte[0], HEX) + "" +
              String(rfid.uid.uidByte[1], HEX) + "" +
              String(rfid.uid.uidByte[2], HEX) + "" +
              String(rfid.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}

// Fungsi memanggil pengguna
void pengguna(String nama) {
  lcd.setCursor(0, 1);
  lcd.print("Welcome " + nama);
}

// Fungsi aktifkan buzzer
void pembacaan(String nilai) {
  if(nilai == "Terdaftar")
  {
    for(int i = 0; i < 2; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }  
  }
  else if(nilai == "Tidak Terdaftar")
  {
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
  }
}

// Fungsi membersihkan LCD
void clearLCD(int posisi){
  lcd.setCursor(0, posisi);
  lcd.print("                     ");
}
