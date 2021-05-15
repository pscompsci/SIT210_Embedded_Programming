#define LED_PIN D7

int time_unit = 250;

int dit_length = time_unit;
int dah_length = 3 * time_unit;

int symbol_delay = time_unit;
int letter_delay = 3 * time_unit;
int word_delay = 7 * time_unit;

void blink_peter();
void blink(int duration);
void blink_p();
void blink_e();
void blink_t();
void blink_r();

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    blink_peter();
    delay(word_delay);
}

void blink(int duration) {
    digitalWrite(LED_PIN, HIGH);
    delay(duration);
    digitalWrite(LED_PIN, LOW);
}

void blink_p() {
    // '.--'
    blink(dit_length);
    delay(symbol_delay);
    blink(dah_length);
    delay(symbol_delay);
    blink(dah_length);
}

void blink_e() {
    // '.'
    blink(dit_length);
}

void blink_t() {
    // '-'
    blink(dah_length);
}

void blink_r() {
    // '.-.'
    blink(dit_length);
    delay(symbol_delay);
    blink(dah_length);
    delay(symbol_delay);
    blink(dit_length);
}

void blink_peter() {
    blink_p();
    delay(letter_delay);
    blink_e();
    delay(letter_delay);
    blink_t();
    delay(letter_delay);
    blink_e();
    delay(letter_delay);
    blink_r();
    delay(letter_delay);
}