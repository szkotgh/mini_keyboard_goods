#include <Keyboard.h>

void setup() {  
  Keyboard.begin();
  pinMode(A2, INPUT_PULLUP);
  pinMode(23, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(23, LOW);
}

void loop() {
  digitalWrite(23, LOW);
  
  if (digitalRead(A2)) {
    Keyboard.releaseAll();
    digitalWrite(13, LOW);
  } else {
    Keyboard.press(KEY_LEFT_CTRL); // Ctrl 키 누름
    Keyboard.press('v');            // 'V' 키 누름
    Keyboard.releaseAll();          // 모든 키 해제
    digitalWrite(13, HIGH);
  }
  
  digitalWrite(23, HIGH);
}
