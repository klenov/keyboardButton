/*
   KeyboardButton Library
   https://github.com/klenov/KeyboardButton
*/

#include <Arduino.h>
#include <Keyboard.h>

#define BUTTON_MINIMAL_DELAY 10

typedef void (*interruptCallback) ();

class KeyboardButton {

  public:
    KeyboardButton(const int);

    enum class IntPin { PIN_0=0, PIN_1, PIN_2, PIN_3, PIN_7=7 };

    static const unsigned long minimal_delay = BUTTON_MINIMAL_DELAY;

    static void enableButton(int, uint8_t);
    static void updateButtons();

    bool pressed_flag;
    bool enabled_flag;

    void enablePullup();
    void enableInterrupt();
    void enable();

    void setKey(uint8_t);
    void setCallback(interruptCallback);

    void interruptFunc();
    int interruptNumber();

    void update();

  private:
    const int pin;

    volatile bool press_detected;

    unsigned long last_updated_at;

    uint8_t keyboard_key;

    interruptCallback callback;

    bool minimalDelayPassed() {
      return millis() - last_updated_at > KeyboardButton::minimal_delay;
    }
    
    bool buttonReleased() {
      return digitalRead(pin) == HIGH;
    }

};


