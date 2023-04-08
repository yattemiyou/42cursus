#!/bin/bash

NUMBER=$((36#`head -n 1 /var/log/sudo/seq`))

echo "#Sudo : ${NUMBER} cmd"
