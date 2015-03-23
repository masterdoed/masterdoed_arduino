#!/usr/bin/python

# ardu2Pi.py
####################

# Port Detection
import serial

#for com in range(0,4):
 try:
  Port = '/dev/ttyACM'+str(com)
  BAUD = 9600
  board = serial.Serial(PORT,BAUD)
  board.close()
  break
 except:
  pass

com = '0'

########
# Blinks
from Tkinter import *
import time

DEVICE = '/dev/ttyACM'+str(com)
BAUD = 9600
ser = serial.Serial(DEVICE,BAUD)

root = Tk()

def five() :
 ser.write('5')
 return

def two() :
 ser.write('2')

def seven() :
 ser.write('7')

root.title("doed - Arduino Pi Test")
Button(text='2 mal blinken', command=two, background="#33D63B", fg="#ffffff").pack()
Button(text='5 mal blinken', command=five, background="#1DE4F2", fg="#ffffff").pack()
Button(text='7 mal blinken', command=seven, background="#DC0F16", fg="#ffffff").pack() 

root.mainloop()

