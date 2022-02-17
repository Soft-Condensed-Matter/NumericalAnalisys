set terminal pngcairo enhanced font " ,18"
#Output file name
set output 'FreeFall.png'

#x axis label-name
set xlabel 'time t' font " ,16"
set xrange[0:20]
set xtics 2

#y axis label-name
set ylabel 'velocity v(t)' font " ,16"
set yrange[0:60]
set xtics 5

#Position of box with data information
set key left

#Make the graph
plot 'Results.dat' title 'Analytical' with linespoints linewidth 3 pointsize 3,\
'Results.dat' using 1:3 title 'Numerical' with linespoints linewidth 3 pointsize 3

