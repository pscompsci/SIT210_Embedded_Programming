#ifndef SIT210_MORSE_H_
#define SIT210_MORSE_H_

#define TIME_UNIT 500                   // base time unit in milliseconds
#define SYMBOL_SPACE TIME_UNIT          // time between symbols in a letter
#define DOT_LENGTH TIME_UNIT            // time a dot lasts
#define DASH_LENGTH (3 * TIME_UNIT)     // time a dash lasts
#define LETTER_SPACE (3 * TIME_UNIT)    // time between letter in a word
#define WORD_SPACE (7 * TIME_UNIT)      // time between words

void blinkDot(int pin);
void blinkDash(int pin);
void symbolPause();
void letterPause();
void wordPause();

// Morse letters required for my name
void blinkP(int pin);
void blinkE(int pin);
void blinkT(int pin);
void blinkR(int pin);

// These additional functions would allow
// blinking my last name, in addition to
// my first name
void blinkS(int pin);
void blinkA(int pin);
void blinkC(int pin);
void blinkY(int pin);

#endif /* SIT210_MORSE_H_ */