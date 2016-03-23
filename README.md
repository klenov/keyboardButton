# keyboardButton

This library will work only on 32u4-based boards (Arduino Leonardo or Micro, SparkFun Pro Micro, Adafruit Feather etc) and only on pins with external interrupt support. 

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
* [Arduino Keyboard Modifiers](https://www.arduino.cc/en/Reference/KeyboardModifiers)
* [SparkFun tutorial: Turn your ProMicro into a USB Keyboard/Mouse](https://www.sparkfun.com/tutorials/337)

## Tested with
* Pro Micro
