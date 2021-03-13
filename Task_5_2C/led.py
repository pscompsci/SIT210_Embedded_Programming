from gpiozero import LED
import RPi.GPIO


class ToggleLED(object):

    def toggleLED(self, led):
        self.resetLEDs()
        if led == 'red':
            self.redLED.on()
        elif led == 'green':
            self.greenLED.on()
        else:
            self.blueLED.on()

    def resetLEDs(self):
        self.redLED.off()
        self.greenLED.off()
        self.blueLED.off()

    def __init__(self):
        RPi.GPIO.setmode(RPi.GPIO.BCM)
        self.redLED = LED(11)
        self.greenLED = LED(9)
        self.blueLED = LED(10)
