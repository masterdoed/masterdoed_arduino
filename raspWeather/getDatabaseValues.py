#!/usr/bin/python
import datetime
import postgresql
import db_conf

# open db connection

# create sql statements
readWohnzimmerToday=db.prepare ("select tempwohnzimmer_timestamp, tempwohnzimmer_temp from tempwohnzimmer where date_trunc('day', tempwohnzimmer_timestamp) = date_trunc('day', now())")
readWohnzimmerLastWeek=db.prepare ("select tempwohnzimmer_timestamp, tempwohnzimmer_temp from tempwohnzimmer where tempwohnzimmer_timestamp BETWEEN (now() - '1 week'::interval)::timestamp AND now()")
readWohnzimmerYear=db.prepare ("select tempwohnzimmer_timestamp, tempwohnzimmer_temp from tempwohnzimmer where tempwohnzimmer_timestamp BETWEEN (now() - '1 year'::interval)::timestamp AND now()")

now = datetime.datetime.now()

# open files
fWohnzimmerToday=open("/home/doed/raspWeather/CSV/wohnzimmerToday.csv", "w")
fWohnzimmerLastWeek=open("/home/doed/raspWeather/CSV/wohnzimmerLastWeek.csv", "w")
fWohnzimmerYear=open("/home/doed/raspWeather/CSV/wohnzimmerYear.csv", "w")

# read todays sensor values from database and write files
with db.xact():
 for row in readWohnzimmerToday():
  fWohnzimmerToday.write(str(row[0]))
  fWohnzimmerToday.write(",")
  fWohnzimmerToday.write(str(row[1]))
  fWohnzimmerToday.write("\n")

 for row in readWohnzimmerLastWeek():
  fWohnzimmerLastWeek.write(str(row[0]))
  fWohnzimmerLastWeek.write(",")
  fWohnzimmerLastWeek.write(str(row[1]))
  fWohnzimmerLastWeek.write("\n")

 for row in readWohnzimmerYear():
  fWohnzimmerYear.write(str(row[0]))
  fWohnzimmerYear.write(",")
  fWohnzimmerYear.write(str(row[1]))
  fWohnzimmerYear.write("\n")
 

# close files
fWohnzimmerToday.close()
fWohnzimmerLastWeek.close()
fWohnzimmerYear.close()

 
