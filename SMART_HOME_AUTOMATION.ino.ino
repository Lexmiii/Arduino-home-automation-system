#include <SoftwareSerial.h>

#define GAS_SENSOR A0  
#define LDR_SENSOR A1  
#define FLAME_SENSOR 2  
#define RAIN_SENSOR 3  
#define BUZZER 4  
#define GREEN_LED 5     // White LED in your hardware
#define RED_LED 6  

// Bluetooth (HC-05)
SoftwareSerial BT(10, 11); // RX = 10, TX = 11

bool buzzerMuted = false;  // flag for manual buzzer control

void setup() {  
  Serial.begin(9600);  
  BT.begin(9600);  

  pinMode(GAS_SENSOR, INPUT);  
  pinMode(LDR_SENSOR, INPUT);  
  pinMode(FLAME_SENSOR, INPUT);  
  pinMode(RAIN_SENSOR, INPUT);  

  pinMode(BUZZER, OUTPUT);  
  pinMode(GREEN_LED, OUTPUT);  
  pinMode(RED_LED, OUTPUT);  

  digitalWrite(BUZZER, LOW);  
  digitalWrite(GREEN_LED, LOW);  
  digitalWrite(RED_LED, LOW);  
}  

void loop() {  
  int gasValue = analogRead(GAS_SENSOR);  
  int ldrValue = analogRead(LDR_SENSOR);  
  int flameValue = digitalRead(FLAME_SENSOR);  
  int rainValue = digitalRead(RAIN_SENSOR);  

  // Print sensor values
  Serial.print("Gas: "); Serial.print(gasValue);  
  Serial.print(" | LDR: "); Serial.print(ldrValue);  
  Serial.print(" | Flame: "); Serial.print(flameValue);  
  Serial.print(" | Rain: "); Serial.println(rainValue);  

  bool danger = false;  

  // GAS detection  
  if (gasValue > 400) {  
    Serial.println("!! Gas Detected !!");  
    BT.println("!! Gas Detected !!");  
    danger = true;  
  }  

  // Flame detection (many flame sensors go LOW when flame is present)  
  if (flameValue == LOW) {  
    Serial.println("!! Flame Detected !!");  
    BT.println("!! Flame Detected !!");  
    danger = true;  
  }  

  // Rain detection  
  if (rainValue == LOW) {  
    Serial.println("Rain Detected!");  
    BT.println("Rain Detected!");  
  }  

  // --- ALERT OUTPUT CONTROL ---  
  if (danger && !buzzerMuted) {  
    digitalWrite(BUZZER, HIGH);  
    digitalWrite(RED_LED, HIGH);  
  } else {  
    digitalWrite(BUZZER, LOW);  
    digitalWrite(RED_LED, LOW);  
  }  

  // --- BLUETOOTH COMMAND HANDLING ---  
  if (BT.available()) {  
    char cmd = BT.read();  
    if (cmd == 'G') {  
      digitalWrite(GREEN_LED, HIGH);  
      Serial.println("Green LED ON via Bluetooth");  
    } else if (cmd == '0') {  
      digitalWrite(GREEN_LED, LOW);  
      Serial.println("Green LED OFF via Bluetooth");  
    } else if (cmd == 'B') {  
      buzzerMuted = true;  
      digitalWrite(BUZZER, LOW);  
      Serial.println("Buzzer muted manually");  
      BT.println("Buzzer muted manually");  
    }  
  }  

  delay(300);  
}