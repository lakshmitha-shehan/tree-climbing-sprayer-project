// 6-Motor Tree Climber + Pump 
// Control via Bluetooth App (U, D, S, P, O)

int motorForward = 2; // All IN1 & IN3 pins
int motorBackward = 3; // All IN2 & IN4 pins
int pumpPin = 4;      // Relay Signal pin

char command;

void setup() {
  Serial.begin(9600); 
  pinMode(motorForward, OUTPUT);
  pinMode(motorBackward, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  
  stopAll(); // Start in safe mode
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    
    if (command == 'U') {
      // Move all 6 motors forward
      digitalWrite(motorForward, HIGH);
      digitalWrite(motorBackward, LOW);
    } 
    else if (command == 'D') {
      // Move all 6 motors backward
      digitalWrite(motorForward, LOW);
      digitalWrite(motorBackward, HIGH);
    } 
    else if (command == 'S') {
      stopAll();
    } 
    else if (command == 'O') {
      digitalWrite(pumpPin, HIGH); // Pump ON
    } 
    else if (command == 'P') {
      digitalWrite(pumpPin, LOW);  // Pump OFF
    }
  }
}

void stopAll() {
  digitalWrite(motorForward, LOW);
  digitalWrite(motorBackward, LOW);
}