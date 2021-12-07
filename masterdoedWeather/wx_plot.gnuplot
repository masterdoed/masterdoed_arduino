## Title: wx_plot.gnuplot
## Author: Matthias Doetterl - arduino@doedspace.Degrees
## 
## Gnuplot file to visualize arduino weather data 

# Initialize datetime format
now=strftime("%Y-%m-%d %H:%M:%S", time(0.0))
#today=strftime("%Y-%m-%d", time(0.0))
today="2016-02-18 23:59:59"
start="2016-02-18 00:00:00"



set title "WeatherChart"
set term png
set output "today.png"
set xdata time
set timefmt '%Y-%m-%d %H:%M:%S'
set format x "%H%M"
set xtics 360 nomirror rotate by -90
#set xtics start, 86400, today
set autoscale x
#set object 1 rect from today."00:00:00",20 to today." 23:59:59",17 fc rgb "#ccffcc"
#set object 2 rect from today."00:00:00",17 to today." 23:59:59",15 fc rgb "#ffcc99"
#set object 3 rect from today."00:00:00",15 to today." 23:59:59",0 fc rgb "#ffeeff"
set grid xtics ytics front
set yrange [0:30]
set ytics 2
set xlabel "DateTime in Hour" right
set ylabel "Temperature in Celsius"
set key below
set datafile sep ','
plot "weatherReadings.txt" using 1:2 title "Temperature" with lines, "weatherReadings.txt" using 1:3 title "Humidity" with lines


# Plot first data 
#set title "WeatherChart"
#set datafile separator ","
#set terminal png size 800,600
#set output 'today.png'
#set xlabel "Time"
#set xdata time
#set timefmt "%Y-%m-%d %H:%M:%S"
#set format x "%m-%d\n%H:%M"
#set autoscale x
#set ylabel "Degrees in Celsius"
#set grid
#set yrange [0:30]
#plot "weatherReadings.txt" using 1:2 title "Temperature" with lines, "weatherReadings.txt" using 1:3 title "Humidity" with lines

