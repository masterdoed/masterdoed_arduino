#!/usr/bin/python
import serial
import datetime
import time

ser = serial.Serial('/dev/ttyUSB0', 9600)
file = open("temperature_office.csv", 'a', 0)

while True:
 line = ser.readline()
 now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
 file.write(now+","+line)

file.close()
