#include "Arduino.h"
#include "morse.h"

void blinkDot(int pin) {
    digitalWrite(pin, HIGH);
    delay(DOT_LENGTH);
    digitalWrite(pin, LOW);
}

void blinkDash(int pin) {
    digitalWrite(pin, HIGH);
    delay(DASH_LENGTH);
    digitalWrite(pin, LOW);
}

void symbolPause() {
    delay(SYMBOL_SPACE);
}

void letterPause() {
    delay(LETTER_SPACE);
}

void wordPause() {
    delay(WORD_SPACE);
}

void blinkP(int pin) {
    // · – – ·
    blinkDot(pin);
    symbolPause();
    blinkDash(pin);
    symbolPause();
    blinkDash(pin);
    symbolPause();
    blinkDot(pin);
}

void blinkE(int pin) {
    // ·
    blinkDot(pin);
}

void blinkT(int pin) {
    // –
    blinkDash(pin);
}

void blinkR(int pin) {
    // · – ·
    blinkDot(pin);
    symbolPause();
    blinkDash(pin);
}

/** The following code would be added to allow my last name to
 *  be blinked as well, or instead
 */

void blinkS(int pin) {
    // · · ·
    blinkDot(pin);
    symbolPause();
    blinkDot(pin);
    symbolPause();
    blinkDot(pin);
}

void blinkA(int pin) {
    // · –
    blinkDot(pin);
    symbolPause();
    blinkDash(pin);
}

void blinkC(int pin) {
    // – · – ·
    blinkDash(pin);
    symbolPause();
    blinkDot(pin);
    symbolPause();
    blinkDash(pin);
    symbolPause();
    blinkDot(pin);
}

void blinkY(int pin) {
    // – · – –
    blinkDash(pin);
    symbolPause();
    blinkDot(pin);
    symbolPause();
    blinkDash(pin);
    symbolPause();
    blinkDash(pin);
}
