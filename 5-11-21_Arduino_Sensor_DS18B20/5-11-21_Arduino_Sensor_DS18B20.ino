#include <OneWire.h>
#include <DallasTemperature.h>

// Inisialisasi pin yang digunakan
int sensorSuhu = 2;
int buzzer = 3;

OneWire oneWire(sensorSuhu);
DallasTemperature sensor(&oneWire);

int index1 = 0;

void setup() {
  Serial.begin(9600);
  sensor.begin();

  // Deklarasi I/O
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // Membaca nilai pada sensor suhu
  sensor.requestTemperatures();
  float readSensorSuhu = sensor.getTempCByIndex(0);

  // Logika
  if(readSensorSuhu != DEVICE_DISCONNECTED_C){
    Serial.println("Suhu yang terbaca pada sensor " + String(index1) + " : " + String(readSensorSuhu));
    if(readSensorSuhu >= 31){
      digitalWrite(buzzer, HIGH);
    }
    else{
      digitalWrite(buzzer, LOW);
    }
  }
  else{
    Serial.println("Error, sensor " + String(index1) + " tidak terdeteksi!");
  }
}
