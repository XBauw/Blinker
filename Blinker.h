#ifndef BLINKER_H
    #define BLINKER_H
    
    //klassedefinitie
    class Blinker {
    private:
        unsigned long _volgendeBlinkOm;
        unsigned long _nu;
        unsigned long _blinkInterval;
        unsigned int _ledPin; 
    public:
        //constructor
        Blinker(unsigned int ledPin, unsigned long blinkInterval);
        //destructor
        ~Blinker();


        int begin();
        int handle();
    };
#endif

