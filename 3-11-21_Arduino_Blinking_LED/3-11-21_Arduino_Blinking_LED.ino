/*
 * Pin 13 Pada Arduino UNO merupakan pin LED_BUILTIN,
 * sehingga pada pin 13 sudah terdapat LED untuk melakukan blink.
*/

void setup() {
  pinMode(13, OUTPUT); // Deklarasi Pin 13 sebagai OUTPUT
}

void loop() {
  digitalWrite(13, HIGH); // Pin 13 bernilai HIGH
  delay(1000);
  digitalWrite(13, LOW); // Pin 13 bernilai LOW
  delay(1000);
}
