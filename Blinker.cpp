#include <Arduino.h>
#include <Blinker.h>

//klasse-implementatie

  Blinker::Blinker(unsigned int ledPin, unsigned long blinkInterval, const long startDelay) {
    _ledPin = ledPin;
    _blinkInterval = blinkInterval;
    _startDelay = startDelay;
  }
  
  Blinker::~Blinker() {}


  int Blinker::begin() {
      pinMode(_ledPin, OUTPUT);
      _volgendeBlinkOm = millis() + startDelay;

      return 0;
    }

  int Blinker::handle(void) {
     int retVal = false;
     unsigned long now = millis();

        if (now >= _volgendeBlinkOm) {
            _volgendeBlinkOm = now + _blinkInterval;
            digitalWrite(_ledPin, !digitalRead(_ledPin));
            Serial.println("Blink!");
            retVal = true;
        }

        return retVal;    

    }
