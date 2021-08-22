#!/bin/bash
ls -l | awk '(NR+1)%2==0'
