// Inisialisasi pin Arduino yang digunakan
#define A1 3
#define A2 5

// Inisialisasi variabel
int incomingByte = 0;
int input = 0;

void setup() {
  // Deklarasi pin sebagai I/O
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

  Serial.println("Pilih menu :");
  Serial.print("1. Foward");
  Serial.print("2. Backward");
  Serial.print("3. Stop");
}

void loop() {
  // Logika
  if(Serial.avaliable()>0)
  {
    incomingByte = Serial.read();
    input = incomingByte - 48;

    switch(input){
      case 1:
        foward();
        break;
      case 2:
        backward();
        break;
      case 3:
        berhenti();
        break;
    }
    delay(200);
    input=0;
  }
}

// Fungsi motor maju
void foward(){
  analogWrite(A1, 255);
  analogWrite(A2, 0);
}

// Fungsi motor mundur
void backward(){
  analogWrite(A1, 0);
  analogWrite(A2, 255);
}

// Fungsi motor berhenti
void berhenti(){
  analogWrite(A1, 0);
  analogWrite(A2, 0);
}
