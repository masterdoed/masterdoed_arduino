#!/bin/sh

killall python

gnuplot /var/www/html/doed_arduino/weatherGnuplot.plot

python /var/www/html/doed_arduino/readSerial.py &



