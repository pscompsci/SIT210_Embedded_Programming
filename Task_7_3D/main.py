#!/usr/bin/python3

''' Task 7.3D - Raspberry Pi PWM

    Student ID:     219011171
    Student Name:   Peter Stacey
'''

from time import sleep
from gpiozero import DistanceSensor, PWMLED
from signal import signal, SIGTERM, SIGHUP, pause

led    = PWMLED(13)
sensor = DistanceSensor(echo=17, trigger=4)

def safe_exit():
    exit(1)

def main():
    running = True
    try:
        signal(SIGTERM, safe_exit)
        signal(SIGHUP, safe_exit)
        led.on()
        while running:
            distance= sensor.value
            print(f'Distance {distance:1.2f} m')
            duty_cycle = round(1.0 - distance,1)            
            if duty_cycle < 0:
                duty_cycle = 0.0
            led.value = duty_cycle
            sleep(0.1)
    except KeyboardInterrupt:
        pass
    finally:
        running = False
        sensor.close()

if __name__ == '__main__':
    main()
