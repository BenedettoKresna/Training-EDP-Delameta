#include <LiquidCrystal_I2C.h>

// Inisialisasi Pin STM32
int pinSensorFlame = PA0;

// Inisialisasi variable
unsigned long interval = 5000;
unsigned long waktuLampau = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin();

  // Deklarasi pin Arduino sebagai Input/Output
  pinMode(pinSensorFlame, INPUT);
}

void loop() {
  // Membaca nilai sensor flame
  int bacaSensorFlame = analogRead(pinSensorFlame);
  unsigned long waktuSekarang = millis();
  // Logika dengan millis()
  if((waktuSekarang - waktuLampau) >= interval){
    cleanLCD(1);
    lcd.setCursor(0, 0);
    lcd.print("Nilai Sensor :");
    lcd.setCursor(0, 1);
    lcd.print(bacaSensorFlame);
    waktuLampau = millis();
  }
  // Menampilkan nilai sensor pada Serial Monitor
  Serial.println("Nilai Sensor : " + String(bacaSensorFlame));
}

// Fungsi untuk membersihkan layar pada baris spesifik
void cleanLCD(int row){
  lcd.setCursor(0, row);
  lcd.print("                ");
}
