#!/bin/sh

# compute arduino sensors
echo "### computing Arduino sensors ###"
echo "get Arduino Database Values"
python3 /home/doed/raspWeather/getDatabaseValues.py
echo "draw Arduino graphs"
gnuplot /home/doed/raspWeather/drawArduinoGraphs.gnuplot

