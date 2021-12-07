#!/usr/bin/python
import serial
import datetime
import postgresql
import ConfigParser

# parse config file
confParser = ConfigParser.RawConfigParser()
confParser.read('config.ini')

print confParser.get('database', 'server')

# create serial
ser = serial.Serial('/dev/ttyACM0', 9600)

# create sql statements
insertWohnzimmer = db.prepare ("INSERT INTO tempwohnzimmer(tempwohnzimmer_timestamp, tempwohnzimmer_temp, tempwohnzimmer_comment) VALUES ($1, $2, $3)")

while True:
 line = str(ser.readline())
 line = line.rstrip('\r\n\'')
 line = line.replace('b\'','')
 print(line)
 now = datetime.datetime.now()
 
 # insert in db
 lineSplit = line.split(' ')
 with db.xact():
  insertWohnzimmer(now,float(lineSplit[0]),lineSplit[1])
 




