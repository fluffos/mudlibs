/def pf = steck schwert weg%;pfeil%;zueck schwert%;
/def fb = steck schwert weg%;feuerball%;zueck schwert%;

/def -p20 -mregexp  -t"^  Du" autospell = /spell
/def spell = /fb
/def newspell = /def spell = %{1}

/def -p100 -F -mregexp -t'^Es gibt [a-z]* sichtbare(|n) Ausga(e|)ng(e|): ' autoturein = /autorein
/def autorein = lausche%;rieche
/def rein = /def autorein = %*

/load sl.mak
/pre lpmp
