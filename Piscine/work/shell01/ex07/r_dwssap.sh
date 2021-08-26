#!/bin/sh
cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | cut -d':' -f1 | rev | sort -dr | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/, /g' | tr '\n' '.'
