// This #include statement was automatically added by the Particle IDE.
#include "morse.h"

// ---------------------------
// Blink my name in Morse Code
// ---------------------------


int led1 = D7;

void blinkPETER(int pin) {
    blinkP(pin);
    letterPause();
    blinkE(pin);
    letterPause();
    blinkT(pin);
    letterPause();
    blinkE(pin);
    letterPause();
    blinkR(pin);
}

// This would be the approach to blinking my last name
void blinkSTACEY(int pin) {
    blinkS(pin);
    letterPause();
    blinkT(pin);
    letterPause();
    blinkA(pin);
    letterPause();
    blinkC(pin);
    letterPause();
    blinkE(pin);
    letterPause();
    blinkY(pin);
}

void setup() {
  pinMode(led1, OUTPUT);
}

void loop() {
  blinkPETER(led1);
  wordPause();
  
  // The following additions to loop() would blink my lastname
  // blinkSTACEY(led1);
  // wordPause();
}

