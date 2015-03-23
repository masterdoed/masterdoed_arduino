#!/usr/bin/python
# search Arduino

import serial

PORT = '/dev/ttyACM0'
BAUD = 9600
board = serial.Serial(PORT,BAUD)
print 'HARDWARE: %s' %board.__str__()
board.close()

