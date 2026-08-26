#!/bin/sh
#
# File     :  /adm/shell/grep_mudlib.sh
# Purpose  :  a shell script to list the names of all files in the mudlib
#             that match the regular expression \.\.*\-*[0-9]*\]
#             eg foo[3..-1]
#             and outputs to the file /GREP.out
#             Run from shell by typing
#               /proj/tmi/tmi-2/adm/shell/grep_mudlib.sh &
#             Takes a few minutes to run
# 95-03-13 :  Leto wrote the find command
#             Pallando changed it to a shell script and installed it here
#             Modified, documented and installed by Pallando
#
find /proj/tmi/tmi-2 -type f -exec grep -l -e '\.\.*\-*[0-9]*\]' {} \; > /proj/tmi/tmi-2/GREP.out 2> /proj/tmi/tmi-2/GREP.err
