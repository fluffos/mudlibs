/def balrog_aufzug2kneipe = verlasse aufzug%;ultrakurz%;w%;w%;w%;w%;w%;s%;oeffne tuer%;s%;s%;s%;s%;w%;w%;w%;w%;w%;w%;w%;s%;s%;s%;s%;so%;n%;unten%;unten%;unten%;n%;n%;w%;w%;w%;lang%;n%;/echo essma was!%;
/def balrog_kneipe2aufzug = ultrakurz%;s%;o%;o%;o%;s%;s%;/sh sleep 2%;oben%;/sh sleep 2%;oben%;/sh sleep 2%;oben%;/sh sleep 2%;s%;nw%;n%;n%;n%;n%;o%;o%;o%;o%;o%;o%;o%;n%;n%;n%;oeffne tuer mit schwerer eisenschluessel%;n%;n%;o%;o%;o%;o%;lang%;o%;betrete aufzug%;
/def balrog_aufzug2him = verlasse aufzug%;o%;o%;o%;mlgor%;no%;so%;sw%;
/def balrog_him2aufzug = no%;nw%;sw%;mlgor%;w%;w%;w%;betrete aufzug%;
/def balrog_flucht = /edit -c0 balrog_aufzugraus2%;/balrog_him2aufzug%;
/def balrog_aufzug2druide = verlasse aufzug%;w%;w%;kletter durch loch%;o%;/balrog_heilen%;
/def balrog_druide2aufzug = w%;n%;o%;o%;betrete aufzug%;

/def -p900 -t"*Der Druide heilt Dich.*" balrog_heilen = gib druide 50 muenzen%;
/def -p901 -t"*Der Druide sagt: Na gut. Ist ja Dein Geld.*" balrog_heilenfertig = /edit -c100 balrog_aufzugraus2%;/balrog_druide2aufzug

/def essen = /echo essen
/def fl = /balrog_flucht
/def ret = /edit -c100 balrog_aufzugraus2%;/balrog_kneipe2aufzug%;
/def balrog_satt = /edit -c0 balrog_aufzugraus2%;/edit -c0 balrog_aufzugraus1%;/balrog_kneipe2aufzug%;

/def -p20 -t"*Ein Aufzug kommt an.*" balrog_aufzugrein = betrete aufzug
/def -p20 -t"*Der Aufzug naehert sich Ebene 1 und bleibt stehen.*" balrog_aufzugraus1 = /balrog_aufzug2kneipe%;
/def -p20 -t"*Der Aufzug naehert sich Ebene 2 und bleibt stehen.*" balrog_aufzugraus2 = /balrog_aufzug2him%;
/def -p20 -t"*Der Aufzug naehert sich Ebene 3 und bleibt stehen.*" balrog_aufzugraus3 = /balrog_aufzug2druide%;
