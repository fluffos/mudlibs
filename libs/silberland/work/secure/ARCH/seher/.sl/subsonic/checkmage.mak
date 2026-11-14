/def checkmage=/edit -c100 alter1%;\
               finger %1%;\
               /edit -c0 alter1%;\
               /repeat -0:0:2 1 /edit -c100 alter2%%;\
                         finger %1%%;\
                         /if (sec1<sec2) \
                              /repeat -0:0:2 1 /echo %1 ist da!%%; /endif%%;


/def -c0 -p10 -mregexp -t'^Alter: [0-9]+d [0-9]+:[0-9]+:([0-9]+)' alter1 =/set sec1 %P1%;
/def -c0 -p10 -mregexp -t'^Alter: [0-9]+d [0-9]+:[0-9]+:([0-9]+)' alter2 =/set sec2 %P1%;
