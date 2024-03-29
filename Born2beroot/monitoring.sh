#!/bin/bash -eu

ARCH=`uname -a`
PROC=`grep "physical id" /proc/cpuinfo | sort -u | wc -l`
VPROC=`grep processor /proc/cpuinfo | wc -l`
MEM=`free --mebi | awk '$1=="Mem:" {printf "%d/%dMB (%.2f%%)", $2-$7, $2, ($2-$7)/$2*100}'`
DISK=`df -h | awk '$6=="/" {printf "%.1f/%.1fGb (%d%%)", $3, $2, $5}'`
CPU=`top -b -n 1 | awk -F ',' 'NR==3 {print $4}' | awk '{printf "%.1f", 100.0-$1}'`
UPTIME=`uptime -s | awk -F ':' '{print $1 ":" $2}'`
LVM=`/usr/sbin/vgs --noheadings | awk '{if ($3 > 0) {print "yes"} else {print "no"}}'`

CONNECTION=`ss -t | grep ESTAB | wc -l`

USER=`who | wc -l`

DEVICE="enp0s8"
IP=`ip -4 addr show ${DEVICE} | grep inet | awk -F '[ /]' '{print $6}'`
MAC=`ip link show ${DEVICE} | grep link | awk '{print $2}'`

NUMBER=$((36#`head -n 1 /var/log/sudo/seq`))

INFO=""
INFO+="#Architecture: ${ARCH}\n"
INFO+="#CPU physical : ${PROC}\n"
INFO+="#vCPU : ${VPROC}\n"
INFO+="#Memory Usage: ${MEM}\n"
INFO+="#Disk Usage: ${DISK}\n"
INFO+="#CPU load: ${CPU}%\n"
INFO+="#Last boot: ${UPTIME}\n"
INFO+="#LVM use: ${LVM}\n"
INFO+="#Connections TCP : ${CONNECTION} ESTABLISHED\n"
INFO+="#User log: ${USER}\n"
INFO+="#Network: IP ${IP} (${MAC})\n"
INFO+="#Sudo : ${NUMBER} cmd\n"

echo -e ${INFO} | wall
