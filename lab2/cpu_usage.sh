#!/bin/bash

MYPID=48390	#PID number of the browser process
echo "PID IS" $MYPID
ps -p $MYPID -o comm	#displays process name

while [ "1" == "1" ]	#trick to keep the loop running
do
   x=`date +%s`	#current time from computer
   y=`ps -p $MYPID -o %cpu | tail -n 1`
   sleep 1	#1sec pause
   echo $x $y
done
