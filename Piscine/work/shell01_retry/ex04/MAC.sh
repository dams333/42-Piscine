#!/bin/sh
ifconfig | grep 'ether' | awk '!($1="")' | tr -d " "
