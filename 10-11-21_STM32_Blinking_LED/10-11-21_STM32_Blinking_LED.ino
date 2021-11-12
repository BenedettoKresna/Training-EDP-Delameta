// Define STM32's Pin
#define ledMerah PC13
#define ledKuning PC14
#define ledHijau PC15

int pin[] = {PC13, PC14, PC15};

void setup() {
  // Declaration Pin as I/O
  for(int i = 0; i <= 2; i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i <= 2; i++){
    digitalWrite(pin[i], HIGH);
    delay(1000);
    digitalWrite(pin[i], LOW);
    delay(1000);    
  }
  
//  digitalWrite(ledMerah, HIGH);
//  delay(2000);
//  digitalWrite(ledMerah, LOW);
//  delay(2000);
//  digitalWrite(ledKuning, HIGH);
//  delay(1000);
//  digitalWrite(ledKuning, LOW);
//  delay(1000);
//  digitalWrite(ledHijau, HIGH);
//  delay(1000);
//  digitalWrite(ledHijau, LOW);
//  delay(1000);  
}
