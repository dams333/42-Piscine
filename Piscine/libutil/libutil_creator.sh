#!/bin/sh
gcc -c *.c
ar rc libutil.a *.o
rm -f *.o
ranlib libutil.a
