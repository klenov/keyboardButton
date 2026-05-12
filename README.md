# keyboardButton

This library will work only on 32u4-based boards (Arduino Leonardo or Micro, SparkFun Pro Micro, Adafruit Feather, etc.) and only on pins with external interrupt support.

On Micro, Leonardo and other 32u4-based boards there are 5 external interrupts available on pins **0**, **1**, **2**, **3**, **7**.

## Example
```Arduino
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
```
## Useful links
* [Arduino Keyboard Modifiers and Special Keys](https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/keyboardModifiers/)
* [SparkFun Pro Micro Hookup Guide: HID Mouse and Keyboard](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/example-2-hid-mouse-and-keyboard)

## Tested with
* Pro Micro
