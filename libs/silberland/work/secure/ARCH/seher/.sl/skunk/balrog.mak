/def auf_dru = ultrakurz%;verlasse aufzug%;w%;w%;kletter durch loch%;o%;gib \
500  muenzen an druide%; w%;n%;o%;o%;betrete aufzug%;kurz%;
/def auf_bal = ultrakurz%;verlasse \
aufzug%;o%;o%;o%;mlgor%;no%;so%;kurz%;zf%;schau%;
/def bal_auf = lf%;ultrakurz%;nw%;sw%;mlgor%;w%;w%;w%;betrete \
aufzug%;kurz%;schau%;

/def resume
/def aufzug1 = verlasse aufzug%;/resume%;

/def aufzug = /def -1 -mregexp -t'Aufzug' balt1 = betrete \
aufzug%;schau%;/def -1 \
-t'Der Aufzug naehert sich Ebene %1 und bleibt stehen.' balt2 = \
/aufzug1

;/def balm1 = /def -t'Der Aufzug naehert sich Ebene 1 und bleibt stehen.' \
;balt5 = /balm12%; \
;/def -t'Der Aufzug naehert sich Ebene 3 und bleibt stehen.' \
;balt6 = /balm13%; \
;s%;o%;o%;o%;o%;o%;o%;no%;n%;n%;oeffne tuer mit eisenschluessel%;\
;n%;n%;o%;o%;o%;o%;o%;/aufzug 2%;/def resume = /balm3%;

/def balm1 = s%;o%;o%;o%;o%;o%;o%;no%;n%;n%;oeffne tuer mit schluessel%;\
n%;n%;o%;o%;o%;o%;o%;/aufzug 2%;/def resume = /balm3%;

/def balm2 = o%;o%;o%;mlgor%;no%;so%;zuende fackel an%;sw%;

/def balm3 = /balm2%;vorsicht 100%;fluchtrichtung no%;toete balrog%;

/def balm4 = loesche fackel%;nw%;sw%;mlgor%;w%;w%;w%;

/def flucht = /balm4%;/aufzug 3%;/def resume = /balm5%;

/def balm5 = w%;w%;kletter durch loch%;o%;/balm8%;

/def bal = /balm1

/def balm7 = w%;w%;w%;w%;w%;frage tschubax nach hilfe%;gib tafel an \
tschubax%;o%;s%;s%;s%;

/def balm8 = /set i $[(%maxlp - %lebp)*15 - 100]%;/eval gib %i muenzen an \
druide%;w%;n%;o%;o%;/aufzug 2%;/def resume=/balm2%;/eval sag %i


/def balm10 = w%;w%;w%;w%;w%;w%;frage tschubax nach hilfe%;gib tafel an \
tschubax%;o%;s%;oeffne tuer mit schluessel%;s%;s%;s%;sw%;w%;w%;w%;w%;w%;\
w%;n%;

/def balm6 = w%;w%;w%;w%;w%;s%;oeffne tuer mit schluessel%;s%;s%;s%;sw%;\
w%;w%;w%;w%;w%;w%;n%;teleportiere 1%;w%;w%;w%w%;n%;o%;

/def balm11 = w%;s%;o%;o%;o%;o%;teleportiere 2%;s%;o%;o%;o%;o%;o%;o%;no%;\
n%;n%;oeffne tuer mit schluessel%;n%;n%;o%;o%;o%;o%;o%;/aufzug 2%;\

/def balm12 = verlasse aufzug%;/balm6

/def balm13 = verlasse aufzug%;/balm5

/def balresume = /balm2%;/undef balt2

/def res = /balm11%;/undef balt2%;/aufzug 2%;/def resume=/balm2%;

;/def -mregexp -t'Der Balrog stirbt mit einem entsetzlichen Aufschrei.' \
;balm9 = /undef balt5%;/undef balt6%;n%;unt nische%;loesche 
;fackel%;s%;no%;nw%;sw%;mlgor%;\ w%;w%;w%;/aufzug 1%;/def resume = /balm10

/def -mregexp -t'Der Balrog stirbt mit einem entsetzlichen Aufschrei.' \
balm9 = /undef balt5%;/undef balt6%;n%;unt nische%;loesche \
fackel%;s%;no%;nw%;sw%;mlgor%;w%;w%;w%;/aufzug 1%;/def resume = /balm10

