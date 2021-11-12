int ir = 7;

void setup() {
  Serial.begin(9600);
  pinMode(ir, INPUT);

}

void loop() {
  int bacaIR = digitalRead(ir);
  Serial.println("Nilai Sensor : " + String(bacaIR));
}
