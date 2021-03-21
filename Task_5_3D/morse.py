import collections
import time
import led

TIME_UNIT = 0.3
DIT_DURATION = TIME_UNIT
DAH_DURATION = 3 * TIME_UNIT
SYMBOL_PAUSE = TIME_UNIT
LETTER_PAUSE = 3 * TIME_UNIT
WORD_PAUSE = 7 * TIME_UNIT

MORSE_ENCODING = collections.OrderedDict([
    ('A', '.-'),
    ('B', '-...'),
    ('C', '-.-.'),
    ('D', '-..'),
    ('E', '.'),
    ('F', '..-.'),
    ('G', '--.'),
    ('H', '....'),
    ('I', '..'),
    ('J', '.---'),
    ('K', '-.-'),
    ('L', '.-..'),
    ('M', '--'),
    ('N', '-.'),
    ('O', '---'),
    ('P', '.--.'),
    ('Q', '--.-'),
    ('R', '.-.'),
    ('S', '...'),
    ('T', '-'),
    ('U', '..-'),
    ('V', '...-'),
    ('W', '.--'),
    ('X', '-..-'),
    ('Y', '-.--'),
    ('Z', '--..'),
    ('0', '-----'),
    ('1', '.----'),
    ('2', '..---'),
    ('3', '...--'),
    ('4', '....-'),
    ('5', '.....'),
    ('6', '-....'),
    ('7', '--...'),
    ('8', '---..'),
    ('9', '----.'),
    (' ', ' '),
    (',', '--..--'),
    ('.', '.-.-.-'),
    ('?', '..--..'),
    (';', '-.-.-.'),
    (':', '---...'),
    ("'", '.----.'),
    ('-', '-....-'),
    ('/', '-..-.'),
    ('(', '-.--.-'),
    (')', '-.--.-'),
    ('_', '..--.-')
])

class Morse(object):

    def __init__(self, pin):
        self.led = led.Controller(pin)
        self.led.turnOff()

    def blinkMessage(self, message):
        elements = self.splitMessage(message.strip())
        for element in elements:
            self.blinkWord(element)
            time.sleep(WORD_PAUSE)

    def blinkWord(self, word):
        print(f'{word}:')
        for character in word:
            print(f'{character}: ', end='')
            encoded = self.encodeSymbol(character.strip().upper())
            if encoded == -1:
                print('Not valid morse symbol')
                continue
            print(encoded)
            for symbol in encoded:
                if symbol == '.':
                    print('dit')
                    self.blinkDit()
                else:
                    print('dah')
                    self.blinkDah()
                time.sleep(SYMBOL_PAUSE)
            time.sleep(LETTER_PAUSE)

    def blinkDit(self):
        self.blink(DIT_DURATION)

    def blinkDah(self):
        self.blink(DAH_DURATION)

    def blink(self, duration):
        self.led.turnOn()
        time.sleep(duration)
        self.led.turnOff()

    def splitMessage(self, message):
        word_sep = ' '
        return list(map(list, message.split(word_sep)))

    def encodeSymbol(self, symbol):
        if symbol in MORSE_ENCODING:
            return MORSE_ENCODING[symbol]
        else:
            return -1

