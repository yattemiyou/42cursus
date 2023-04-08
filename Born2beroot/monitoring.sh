#!/bin/bash

CPU=`top -b -n 1 | awk -F ',' 'NR==3 {print $4}' | awk '{printf "%.1f", 100.0-$1}'`
UPTIME=`uptime -s | awk -F ':' '{print $1 ":" $2}'`
LVM=`vgs --noheadings | awk '{if ($3 > 0) {print "yes"} else {print "no"}}'`

CONNECTION=`ss -t | grep ESTAB | wc -l`

USER=`who | wc -l`

DEVICE="enp0s8"
IP=`ip -4 addr show ${DEVICE} | grep inet | awk -F '[ /]' '{print $6}'`
MAC=`ip link show ${DEVICE} | grep link | awk '{print $2}'`

NUMBER=$((36#`head -n 1 /var/log/sudo/seq`))

echo "#CPU load: ${CPU}%"
echo "#Last boot: ${UPTIME}"
echo "#LVM use: ${LVM}"
echo "#Connections TCP : ${CONNECTION} ESTABLISHED"
echo "#User log: ${USER}"
echo "#Network: IP ${IP} (${MAC})"
echo "#Sudo : ${NUMBER} cmd"
