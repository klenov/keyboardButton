/*
   KeyboardButton Library - Example
   https://github.com/klenov/KeyboardButton
*/

#include <KeyboardButton.h>

void setup() {
  Keyboard.begin();

  KeyboardButton::enableButton(0, KEY_UP_ARROW);
  KeyboardButton::enableButton(1, KEY_DOWN_ARROW);
  
  KeyboardButton::enableButton(3, 'a');
  KeyboardButton::enableButton(7, 'b');
}

void loop() {
  KeyboardButton::updateButtons();
}
