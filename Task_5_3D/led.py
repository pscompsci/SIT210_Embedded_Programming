from gpiozero import LED
import RPi.GPIO

class Controller(object):

    def __init__(self, pin):
        RPi.GPIO.setmode(RPi.GPIO.BCM)
        self.LED = LED(pin)

    def turnOff(self):
        self.LED.off()

    def turnOn(self):
        self.LED.on()
