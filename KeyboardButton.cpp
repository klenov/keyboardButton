/*
   KeyboardButton Library
   https://github.com/klenov/KeyboardButton
*/

#include "KeyboardButton.h"

 /*! * default Constructor */
KeyboardButton::KeyboardButton(const int _pin)
  : pin(_pin),
    keyboard_key(0),
    press_detected(false),
    pressed_flag(false),
    enabled_flag(false),
    last_updated_at(0) {}

void KeyboardButton::enablePullup() {
  pinMode(pin, INPUT_PULLUP);
}

void KeyboardButton::enableInterrupt() {
  attachInterrupt(interruptNumber(), callback, FALLING);
}

void KeyboardButton::enable() {
  enablePullup();
  enableInterrupt();
  enabled_flag = true;
}

void KeyboardButton::setKey(uint8_t key) {
  keyboard_key = key;
}

void KeyboardButton::setCallback(interruptCallback _callback) {
  callback = _callback;
}

void KeyboardButton::interruptFunc() {
  press_detected = true;
}

int KeyboardButton::interruptNumber() {
  return digitalPinToInterrupt(pin);
}

void KeyboardButton::update() {
  if( !minimalDelayPassed() )
    return;

  if(press_detected) {
    Keyboard.press(keyboard_key);
    press_detected = false;
    pressed_flag = true;

    last_updated_at = millis();
  }

  if(pressed_flag && buttonReleased()) {
    Keyboard.release(keyboard_key);
    pressed_flag = false;

    last_updated_at = millis();
  }
}

KeyboardButton button_0 ( 0 );
KeyboardButton button_1 ( 1 );
KeyboardButton button_2 ( 2 );
KeyboardButton button_3 ( 3 );
KeyboardButton button_7 ( 7 );

void KeyboardButton::enableButton(int pin, uint8_t key) {
  IntPin pin_number = (IntPin) pin;

  switch(pin_number){

  case IntPin::PIN_0  :
    button_0.setKey(key);
    button_0.setCallback( []() { button_0.interruptFunc(); } );
    button_0.enable();
    break;

  case IntPin::PIN_1  :
    button_1.setKey(key);
    button_1.setCallback( []() { button_1.interruptFunc(); } );
    button_1.enable();
    break;

  case IntPin::PIN_2  :
    button_2.setKey(key);
    button_2.setCallback( []() { button_2.interruptFunc(); } );
    button_2.enable();
    break;

  case IntPin::PIN_3  :
    button_3.setKey(key);
    button_3.setCallback( []() { button_3.interruptFunc(); } );
    button_3.enable();
    break;

  case IntPin::PIN_7  :
    button_7.setKey(key);
    button_7.setCallback( []() { button_7.interruptFunc(); } );
    button_7.enable();
    break;

  }
}

void KeyboardButton::updateButtons() {
  if( button_0.enabled_flag )
    button_0.update();

  if( button_1.enabled_flag )
    button_1.update();

  if( button_2.enabled_flag )
    button_2.update();

  if( button_3.enabled_flag )
    button_3.update();

  if( button_7.enabled_flag )
    button_7.update();
}
