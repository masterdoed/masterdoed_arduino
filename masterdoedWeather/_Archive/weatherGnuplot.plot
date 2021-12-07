set title "WeatherChart"
set datafile separator ","
set terminal png size 800,600
set output 'webGui/today.png'
set xlabel "Time"
set xdata time
set timefmt "%Y-%m-%d %H:%M:%S"
set format x "%m-%d\n%H:%M"
set autoscale x
set ylabel "Degrees in Celsius"
set grid
set yrange [-30:50]
plot "weatherReadings.txt" using 1:2 title "Temperature" with lines, "weatherReadings.txt" using 1:3 title "Humidity" with lines
