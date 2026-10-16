/*========================================
             IR_with_7seg

==========================================
Description:



Programmer:
  Yuzon, Maria Rebekah J.
  Manicang, Joshua G.

 Date:
  14 Oct 2026 
----------------------------------------*/
const int sensorPin = 34;
const int tensPins[7] = {13, 14, 27, 26, 25, 33, 32};
const int onesPins[7] = {23, 22, 21, 19, 18, 17, 16};

int count = 0;
int lastState = HIGH;

#include "decoder.h"

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(tensPins[i], OUTPUT);
    pinMode(onesPins[i], OUTPUT);
  }
  decoder(count);
}

void loop() {
  int state = digitalRead(sensorPin);

  if (state == LOW && lastState == HIGH) {
    count = (count + 1) % 100;
    decoder(count);
    Serial.println(count);
    delay(500);
  }

  lastState = state;
}