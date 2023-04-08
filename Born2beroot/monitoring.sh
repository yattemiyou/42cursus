#!/bin/bash

LVM=`vgs --noheadings | awk '{if ($3 > 0) {print "yes"} else {print "no"}}'`
NUMBER=$((36#`head -n 1 /var/log/sudo/seq`))

echo "#LVM use: ${LVM}"
echo "#Sudo : ${NUMBER} cmd"
