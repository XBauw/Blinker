#include <Blinker.h>

//klasse-implementatie

  Blinker::Blinker(unsigned int ledPin, unsigned long blinkInterval) {
    _ledPin = ledPin;
    _blinkInterval = blinkInterval;
    _nu = millis();
    _volgendeBlinkOm = _nu;
  }
  
  Blinker::~Blinker() {}


  int Blinker::begin() {
      pinMode(_ledPin, OUTPUT);

      return 0;
    }

  int Blinker::handle() {
     int retVal = false;
     _nu = millis();

        if (_nu >= _volgendeBlinkOm) {
            _volgendeBlinkOm = _nu + _blinkInterval;
            digitalWrite(_ledPin, !digitalRead(_ledPin));
            Serial.println("Blink!");
            retVal = true;
        }

        return retVal;    

    }