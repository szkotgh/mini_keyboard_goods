#include <Keyboard.h>

bool isPressed = false;

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
    if (isPressed == true) {
      isPressed = false;
      Keyboard.releaseAll();
      digitalWrite(13, LOW);
    }
  } else {
    if (isPressed == false) {
      isPressed = true;
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      Keyboard.releaseAll();
      digitalWrite(13, HIGH);
    }
  }
  
  digitalWrite(23, HIGH);
}
