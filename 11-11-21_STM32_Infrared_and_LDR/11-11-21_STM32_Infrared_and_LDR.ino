// Initialitation STM32's Pin
int ledMerah = PC13, ledKuning = PA2, ledHijau = PC15;
int sensorInfrared = PA0;
int sensorLDR = PA1;
int lock = 0;
int count = 0;

void setup() {
  // Declaration Pin as an Input or Output
  Serial.begin(9600);
  
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  pinMode(sensorInfrared, INPUT);
  pinMode(sensorLDR, INPUT);

}

void loop() {
  // Read sensor value and then put it into new variable
  int bacaSensorInfrared = digitalRead(sensorInfrared);
  int bacaSensorLDR = map(analogRead(sensorLDR), 0, 4096, 0, 255);

  // Show  in sensor value in Serial Monitor
  Serial.print("Pembacaan sensor Infrared : " + String(bacaSensorInfrared));
  Serial.println("Pembacaan sensor LDR : " + String(bacaSensorLDR));

  // Logic
  if(bacaSensorLDR >= 200){
    analogWrite(ledKuning, 255);
  }
  else if(bacaSensorLDR <= 200 && bacaSensorLDR >= 100){
    analogWrite(ledKuning, 150);
  }
  else{
    analogWrite(ledKuning, 0);
  }

  if(bacaSensorInfrared == 0 && lock == 0){
    lock = 1;
  }
  else if(bacaSensorInfrared == 1 && lock == 1){
    if(count == 0){
      digitalWrite(ledMerah, HIGH); 
      count = 1;
    }
    else{
      digitalWrite(ledMerah, LOW);    
      count = 0;    
    }
    lock = 0;
  }
  
//  if(bacaSensorInfrared == 0){
//    digitalWrite(ledMerah, HIGH);
//  }
//  else{
//    digitalWrite(ledMerah, LOW);
//  }

}
