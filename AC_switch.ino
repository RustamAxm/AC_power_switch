static uint64_t tmr1 = 0;
String Status = "";


String SetON() {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      delay(100);
      return "ON";
  }

String SetOFF() {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      delay(100);
      return "OFF";
  }

  
void SerialParser() {
  if (Serial.available()) {
    char ch = Serial.read();
    if (ch == 'w') {
      Status = SetON();
      Serial.println(Status);
      }
    else if (ch == 's') {
      Status = SetOFF();
      Serial.println(Status);
      }
    else if (ch == 'g') {
      Serial.println(Status);
      }
    }
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Status = SetON();
  Serial.begin(115200);
  Serial.println("AC power ON send 'w'");
  Serial.println("AC power OFF send 's'");
  Serial.println("get status send 'g'");
}



void loop() {
  // put your main code here, to run repeatedly:
  
  if (millis() - tmr1 > 100) {
    SerialParser();
    tmr1 = millis();
    }
}
