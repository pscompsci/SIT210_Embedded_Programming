import morse
import StringIO
import sys
import time

def test_dit(morse):
    start = time.time()
    morse.blinkDit()
    end = time.time()
    elapsed = end - start
    assert(0.1 < elapsed < 0.5, "Should be approx 300 milliseconds")
    

def test_dah(morse):
    start = time.time()
    morse.blinkDah()
    end = time.time()
    elapsed = end - start
    assert(0.7 < elapsed < 1.1, "Should be approx 900 milliseconds")


def test_blinkWord_OK(morse):
    capturedOutput = StringIO.StringIO()
    sys.stdout = capturedOutput
    morse.blinkWord('E')
    sys.stdout = sys.__stdout__
    assert(capturedOutput == "['E']: .\ndit\n",
           "Incorrect wordoutput: " + capturedOutput)


def test_blinkWord_NotOK(morse):
    capturedOutput = StringIO.StringIO()
    sys.stdout = capturedOutput
    morse.blinkWord('~')
    sys.stdout = sys.__stdout__
    assert(capturedOutput == 'Not a valid morse symbol',
           "Incorrect wordoutput: " + capturedOutput)


def test_blinkMessage(morse):
    capturedOutput = StringIO.StringIO()
    sys.stdout = capturedOutput
    morse.blinkMessage('TEST')
    sys.stdout = sys.__stdout__
    expected = "['T', 'E', 'S', 'T']:\ndah\ndit\ndit\ndit\ndit\ndah\n"
    assert(capturedOutput == expected,
           "Incorrect message output: " + capturedOutput)


def test_splitMessage(morse):
    elements = morse.splitMessage('Hello World')
    expected = ['Hello', 'World']
    assert(elements == expected, "Incorrect split")


def test_encodeSymbol_OK(morse):
    encoded = morse.encodeSymbol('H')
    expected = '....'
    assert(encoded == expected, 'Incorrect encoding')


def test_encodeSymbol_NotOK(morse):
    encoded = morse.encodeSymbol('~')
    expected = -1
    assert(encoded == expected, 'Incorrect encoding')


if __name__ == '__main__':
    morse = morse.Morse(10)
    test_splitMessage(morse)
    test_encodeSymbol_OK(morse)
    test_encodeSymbol_NotOK(morse)
    test_dit(morse)
    test_dah(morse)
    test_blinkWord_OK(morse)
    test_blinkWord_NotOK(morse)
    test_blinkMessage(morse)