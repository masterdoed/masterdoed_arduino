now=strftime("%Y-%m-%d %H:%M:%S", time(0.0))
today=strftime("%Y-%m-%d", time(0.0))
start="2013-01-01 00:00:00"

set title "Readings Today"
set term png
set output "/var/www/doed_blog/raspbuino/Today.png"
set xdata time
set timefmt '%Y-%m-%d %H:%M:%S'
#set xtics start, 86400, today
set format x "%H"
set xtics nomirror rotate by -90
set object 1 rect from today."00:00:00",20 to today." 23:59:59",17 fc rgb "#ccffcc"
set object 2 rect from today."00:00:00",17 to today." 23:59:59",15 fc rgb "#ffcc99"
set object 3 rect from today."00:00:00",15 to today." 23:59:59",0 fc rgb "#ffeeff"
set grid xtics ytics front
set yrange [11:21]
set ytics 1
set xlabel "DateTime in Hour" right
set ylabel "Temperature in Celsius"
set key below
set datafile sep ','
plot '/home/doed/raspWeather/CSV/wohnzimmerToday.csv' u 1:2 w lines title "Temp Wohnzimmer"

set title "Readings LastWeek"
set term png
set output "/var/www/doed_blog/raspbuino/LastWeek.png"
set xdata time
set timefmt '%Y-%m-%d %H:%M:%S'
set xtics start, 86400, today
set format x "%d.%m"
set xtics nomirror rotate by -90
set object 1 rect from start,20 to today." 23:59:59",17 fc rgb "#ccffcc"
set object 2 rect from start,17 to today." 23:59:59",15 fc rgb "#ffcc99"
set object 3 rect from start,15 to today." 23:59:59",0 fc rgb "#ffeeff"
set grid xtics ytics front
set yrange [11:21]
set ytics 1
set xlabel "DateTime in Day.Month" right
set ylabel "Temperature in Celsius"
set key below
set datafile sep ','
plot '/home/doed/raspWeather/CSV/wohnzimmerLastWeek.csv' u 1:2 w lines title "Temp Wohnzimmer"

set title "Readings Year"
set term png
set output "/var/www/doed_blog/raspbuino/Year.png"
set xdata time
set timefmt '%Y-%m-%d %H:%M:%S'
set xtics start, 2592000, today
set format x "%m/%Y"
set xtics nomirror rotate by -90
set object 1 rect from start,20 to today." 23:59:59",17 fc rgb "#ccffcc"
set object 2 rect from start,17 to today." 23:59:59",15 fc rgb "#ffcc99"
set object 3 rect from start,15 to today." 23:59:59",0 fc rgb "#ffeeff"
set grid xtics ytics front
set yrange [11:21]
set ytics 1
set xlabel "DateTime in Month/Year" right
set ylabel "Temperature in Celsius"
set key below
set datafile sep ','
plot '/home/doed/raspWeather/CSV/wohnzimmerYear.csv' u 1:2 w lines title "Temp Wohnzimmer"






