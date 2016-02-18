#!/usr/bin/python
import serial
import datetime
import time

#myFile = open('weatherReadings.txt', 'w')

ser = serial.Serial('/dev/ttyUSB0', 9600)

while True:
 line = ser.read()
 now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
 print now+","+line
 #myFile.write (now+","+line)

#myFile.close()
