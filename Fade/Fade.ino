/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

int led1 = 9;
int led2 = 10;
int led3 = 11;
int brightness = 0;   
int fadeAmount = 5;
int counter = 0;

bool led2Run = HIGH;
bool led3Run = LOW;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  analogWrite(led1, brightness);
  digitalWrite(led2, led2Run);
  digitalWrite(led3, led3Run);

  // change the brightness for next time through the loop:
  counter += 1;
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  if(counter % 30 == 0) {
    if(led2Run == HIGH) {
      led2Run = LOW;
    }
    else {
      led2Run = HIGH;
    }
  }

  if(counter % 25 == 0) {
    if(led3Run == HIGH) {
        led3Run = LOW;
      }
      else {
        led3Run = HIGH;
      }
  }

  Serial.println(counter);
  
  delay(30);
}
