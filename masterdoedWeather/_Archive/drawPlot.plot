now=strftime("%Y-%m-%d %H:%M:%S", time(0.0))
today=strftime("%Y-%m-%d", time(0.0))
start="2015-08-12 00:00:00"

set title "Readings 2015-08-12"
set term png size 800,600
set output "2015_08_12_OfficeTemp.png"
set xdata time
set timefmt '%Y-%m-%d %H:%M:%S'
set format x "%H:%M"
set xtics nomirror rotate by -45
set object 1 rect from "2015-08-12 00:00:00",21 to "2015-08-12 23:59:59",18 fc rgb "#ccffcc"
set grid xtics ytics front
set yrange [15:35]
set ytics 1
set xlabel "DateTime in Hour" right
set ylabel "Temperature in Celsius"
set key below
set datafile sep ','
plot '2015_08_12_temperature_office_draw.csv' u 1:3 w lines title "Temp Office"
