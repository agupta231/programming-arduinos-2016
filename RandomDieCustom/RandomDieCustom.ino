const int buttonPin = 8;

void setup() {
  Serial.begin(9600);
  
  for(int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(buttonPin, INPUT);
}

void loop() {
  Serial.println(digitalRead(buttonPin));
  int button_state = digitalRead(buttonPin);
  
  if(digitalRead(buttonPin) == HIGH) {
      Serial.println("In the Loop");
     for(int i = 2; i < 8; i++) {
        digitalWrite(i, LOW);
      }
        
      int value = random(1, 7);
      Serial.println(value);
  
      for(int i = 0; i < 10; i++) {
        int led = random(1, 7);
        digitalWrite(led, HIGH);
  
        delay(500);
  
        digitalWrite(led, LOW);
      }
  
      for(int i = 2; i < 8; i++) {
        digitalWrite(i, HIGH);
      }
  
      delay(1000);
//  
//      for(int i = 2; i < 8; i++) {
//        digitalWrite(i, LOW);
//      }
//  
//      for(int i = 0; i < value; i++) {
//        digitalWrite(i + 2, HIGH);
//      }
  }
  
  button_state = 0;
}
