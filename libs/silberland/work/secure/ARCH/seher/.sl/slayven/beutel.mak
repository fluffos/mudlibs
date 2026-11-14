/def looton = /def -p1 -mregexp -t'^(> )*Du nimmst ([A-Z,a-z,-]*).' inbeutel1 = sb %%P2%;\
     /def -p2 -mregexp -t'^(> )*Du nimmst ([e,i,n]*) ([A-Z,a-z,-]*).' inbeutel2 = sb %%P3%;\
     /def -p3 -mregexp -t'^(> )*Du nimmst ([e,i,n]*) ([a-z]*) ([A-Z,a-z,-]*).' inbeutel5 = sb %%P4%;\
     /def -p4 -mregexp -t'^(> )*Du nimmst ein Paar ([A-Z,a-z,-]*).' inbeutel3 = sb %%P2%;\
     /def -p10 -mregexp -t'^(> )*Du nimmst [0-9]* Muenzen' inbeutel4
/def lootoff = /undef inbeutel1%;/undef inbeutel2%;/undef inbeutel3%;/undef inbeutel4%;/undef inbeutel5
/alias nb /def -p99 -1 -mregexp -t'Du nimmst' inbtemp %; nimm %1 aus beutel 3%;
/alias sb stecke %1 in beutel 3 

