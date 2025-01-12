# QT Pi Remote stick
# 0.1 - first revision

import board
import digitalio
import neopixel
import usb_hid
import time
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode

# https://docs.circuitpython.org/projects/hid/en/latest/api.html

keyboard = Keyboard(usb_hid.devices)

"""
pin0 = digitalio.DigitalInOut(board.D0)
pin0.switch_to_input(pull=digitalio.Pull.UP)
"""


pin0 = digitalio.DigitalInOut(board.D0)
pin0.direction = digitalio.Direction.INPUT
pin0.pull = digitalio.Pull.UP
pin0_flank = False
pin0_keycode = Keycode.ZERO

pin1 = digitalio.DigitalInOut(board.D1)
pin1.direction = digitalio.Direction.INPUT
pin1.pull = digitalio.Pull.UP
pin1_flank = False
pin1_keycode = Keycode.ONE

pin2 = digitalio.DigitalInOut(board.D2)
pin2.direction = digitalio.Direction.INPUT
pin2.pull = digitalio.Pull.UP
pin2_flank = False
pin2_keycode = Keycode.TWO

pin3 = digitalio.DigitalInOut(board.D3)
pin3.direction = digitalio.Direction.INPUT
pin3.pull = digitalio.Pull.UP
pin3_flank = False
pin3_keycode = Keycode.THREE

pin4 = digitalio.DigitalInOut(board.D4)
pin4.direction = digitalio.Direction.INPUT
pin4.pull = digitalio.Pull.UP
pin4_flank = False
pin4_keycode = Keycode.FOUR

pin5 = digitalio.DigitalInOut(board.D5)
pin5.direction = digitalio.Direction.INPUT
pin5.pull = digitalio.Pull.UP
pin5_flank = False
pin5_keycode = Keycode.FIVE

pin6 = digitalio.DigitalInOut(board.D6)
pin6.direction = digitalio.Direction.INPUT
pin6.pull = digitalio.Pull.UP
pin6_flank = False
pin6_keycode = Keycode.SIX

pin7 = digitalio.DigitalInOut(board.D7)
pin7.direction = digitalio.Direction.INPUT
pin7.pull = digitalio.Pull.UP
pin7_flank = False
pin7_keycode = Keycode.SEVEN

pin8 = digitalio.DigitalInOut(board.D8)
pin8.direction = digitalio.Direction.INPUT
pin8.pull = digitalio.Pull.UP
pin8_flank = False
pin8_keycode = Keycode.EIGHT

pin9 = digitalio.DigitalInOut(board.D9)
pin9.direction = digitalio.Direction.INPUT
pin9.pull = digitalio.Pull.UP
pin9_flank = False
pin9_keycode = Keycode.NINE

pin10 = digitalio.DigitalInOut(board.D10)
pin10.direction = digitalio.Direction.INPUT
pin10.pull = digitalio.Pull.UP
pin10_flank = False
pin10_keycode = Keycode.EQUALS


pixel = neopixel.NeoPixel(board.NEOPIXEL, 1)

while True:
    if not pin0.value and pin0_flank:
        keyboard.press(Keycode.SHIFT, pin0_keycode)
        pin0_flank = False
    if pin0.value and not pin0_flank:
        keyboard.release(Keycode.SHIFT, pin0_keycode)
        pin0_flank = True

    if not pin1.value and pin1_flank:
        keyboard.press(Keycode.SHIFT, pin1_keycode)
        pin1_flank = False
    if pin1.value and not pin1_flank:
        keyboard.release(Keycode.SHIFT, pin1_keycode)
        pin1_flank = True

    if not pin2.value and pin2_flank:
        keyboard.press(Keycode.SHIFT, pin2_keycode)
        pin2_flank = False
    if pin2.value and not pin2_flank:
        keyboard.release(Keycode.SHIFT, pin2_keycode)
        pin2_flank = True

    if not pin3.value and pin3_flank:
        keyboard.press(Keycode.SHIFT, pin3_keycode)
        pin3_flank = False
    if pin3.value and not pin3_flank:
        keyboard.release(Keycode.SHIFT, pin3_keycode)
        pin3_flank = True

    if not pin4.value and pin4_flank:
        keyboard.press(Keycode.SHIFT, pin4_keycode)
        pin4_flank = False
    if pin4.value and not pin4_flank:
        keyboard.release(Keycode.SHIFT, pin4_keycode)
        pin4_flank = True

    if not pin5.value and pin5_flank:
        keyboard.press(Keycode.SHIFT, pin5_keycode)
        pin5_flank = False
    if pin5.value and not pin5_flank:
        keyboard.release(Keycode.SHIFT, pin5_keycode)
        pin5_flank = True

    if not pin6.value and pin6_flank:
        keyboard.press(Keycode.SHIFT, pin6_keycode)
        pin6_flank = False
    if pin6.value and not pin6_flank:
        keyboard.release(Keycode.SHIFT, pin6_keycode)
        pin6_flank = True

    if not pin7.value and pin7_flank:
        keyboard.press(Keycode.SHIFT, pin7_keycode)
        pin7_flank = False
    if pin7.value and not pin7_flank:
        keyboard.release(Keycode.SHIFT, pin7_keycode)
        pin7_flank = True

    if not pin8.value and pin8_flank:
        keyboard.press(Keycode.SHIFT, pin8_keycode)
        pin8_flank = False
    if pin8.value and not pin8_flank:
        keyboard.release(Keycode.SHIFT, pin8_keycode)
        pin8_flank = True

    if not pin9.value and pin9_flank:
        keyboard.press(Keycode.SHIFT, pin9_keycode)
        pin9_flank = False
    if pin9.value and not pin9_flank:
        keyboard.release(Keycode.SHIFT, pin9_keycode)
        pin9_flank = True

    if not pin10.value and pin10_flank:
        keyboard.press(Keycode.SHIFT, pin10_keycode)
        pin10_flank = False
    if pin10.value and not pin10_flank:
        keyboard.release(Keycode.SHIFT, pin10_keycode)
        pin10_flank = True


    #print(pin3.value)
    #time.sleep(0.5)


