/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' anzeige = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif%;/checkflucht%;
/def checkflucht = /if ((%lebp<%vo) & (%lebpdiff<0)) /fl%; /endif
/def fl = /echo FLUCHT!%;
/def scha = stecke axt ein%;leg axt in beutel 3%;nimm beil 3 aus beutel%;zuecke beil%;smash%;leg beil in beutel%;nimm axt aus beutel 3%;zuecke todesaxt%;
/def tur = leg axt in beutel 3%;nimm blitzaxt aus beutel 2%;zuecke blitzaxt%;turran%;leg blitzaxt in beutel 2%;nimm todesaxt aus beutel 3%;zuecke todesaxt%;
/def k2w = ultrakurz%;w%;s%;s%;s%;s%;s%;s%;s%;s%;s%;so%;s%;sw%;s%;sw%;so%;schwimme tuempel%;lang%;tauch unter%;
/def w2k = ultrakurz%;tauch auf%;schwimme ufer%;nw%;no%;n%;no%;n%;nw%;n%;n%;n%;n%;n%;n%;n%;n%;n%;lang%;o%;
/def -p1 -mglob -t'Eine Segelyacht legt am Steg an.' by = by
/def -p1 -mglob -t'Die Segelyacht legt am*' vy = vy
/def aufzug = va%;w%;w%;kletter in loch%;o%;gib 2000 muenzen an druide%;w%;n%;o%;o%;ba%;
/def au2zw = ultrakurz%;w%;w%;w%;w%;w%;s%;oeffne manntuer mit eisenschluessel%;s%;s%;s%;s%;w%;w%;w%;w%;w%;w%;w%;s%;s%;s%;lang%;s%;
/def zw2au = ultrakurz%;n%;n%;n%;n%;o%;o%;o%;o%;o%;o%;o%;n%;n%;n%;n%;oeffne manntuer mit eisenschluessel%;n%;n%;o%;o%;o%;o%;lang%;o%;ba%;
/def b2e = ultrakurz%;no%;no%;n%;w%;w%;w%;sw%;w%;s%;sw%;w%;sw%;w%;no%;no%;n%;n%;n%;n%;n%;n%;n%;n%;n%;nw%;w%;kletter rauf%;w%;lang%;w%;
/def e2b = ultrakurz%;o%;o%;runter%;o%;so%;s%;s%;s%;s%;s%;s%;s%;s%;s%;sw%;sw%;o%;no%;o%;no%;n%;o%;no%;o%;o%;o%;s%;sw%;lang%;sw%;
/def k2sk = ultrakurz%;w%;s%;s%;s%;s%;s%;s%;s%;s%;s%;so%;s%;sw%;s%;sw%;sw%;s%;u%;u%;o%;o%;u%;u%;n%;n%;n%;o%;lang%;so%;
/def sk2k = ultrakurz%;nw%;w%;s%;s%;s%;ob%;ob%;w%;w%;ob%;ob%;n%;no%;no%;n%;no%;n%;nw%;n%;n%;n%;n%;n%;n%;n%;n%;n%;lang%;o%;
/def g2a = ultrakurz%;n%;w%;w%;w%;w%;w%;nw%;n%;nw%;w%;nw%;w%;nw%;nw%;nw%;nw%;n%;n%;n%;nw%;no%;no%;n%;o%;no%;kletter rauf%;no%;so%;o%;no%;so%;no%;so%;no%;no%;o%;o%;no%;no%;o%;so%;so%;zwaenge durch spalt%;so%;sw%;so%;no%;nw%;sw%;so%;no%;lang%;nw%;
/def a2g = ultrakurz%;so%;sw%;nw%;no%;so%;sw%;nw%;no%;nw%;zwaenge durch spalt%;nw%;nw%;w%;sw%;sw%;w%;w%;sw%;sw%;nw%;sw%;nw%;sw%;w%;nw%;sw%;kletter runter%;sw%;w%;s%;sw%;sw%;so%;s%;%;s%;s%;so%;so%;so%;so%;o%;so%;o%;so%;s%;so%;o%;o%;o%;o%;o%;lang%;s%;
/def rd2w = ultrakurz%;so%;s%;so%;so%;so%;s%;o%;so%;o%;so%;sw%;sw%;sw%;s%;oob%;ob%;sw%;w%;n%;n%;n%;w%;n%;lang%;n%;
/def w2rd = ultrakurz%;s%;s%;o%;s%;s%;s%;o%;no%;u%;wu%;n%;no%;no%;no%;nw%;w%;nw%;w%;n%;nw%;nw%;n%;w%;n%;lang%;nw%;
/def be2g = ultrakurz%;o%;o%;o%;o%;o%;o%;o%;o%;o%;oob%;nu%;n%;n%;n%;w%;w%;w%;lang%;n%;
/def g2be = ultrakurz%;s%;o%;o%;o%;s%;s%;s%;sob%;wu%;w%;w%;w%;w%;w%;w%;w%;w%;lang%;w%;
/def looton = /def -p1 -mregexp -t'^(> )*Du nimmst ([A-Z,a-z,-]*).' inbeutel1 = sb %%P2%;/def -p2 -mregexp -t'^(> )*Du nimmst ([e,i,n]*) ([A-Z,a-z,-]*).' inbeutel2 = sb %%P3%;/def -p3 -mregexp -t'^(> )*Du nimmst ([e,i,n]*) ([a-z]*) ([A-Z,a-z,-]*).' inbeutel5 = sb %%P4%;/def -p4 -mregexp -t'^(> )*Du nimmst ein Paar ([A-Z,a-z,-]*).' inbeutel3 = sb %%P2%;/def -p10 -mregexp -t'^(> )*Du nimmst [0-9]* Muenzen' inbeutel4
/def lootoff = /undef inbeutel1%;/undef inbeutel2%;/undef inbeutel3%;/undef inbeutel4%;/undef inbeutel5
/def -p1 -ag -mglob -t'Das ist Vaders Rucksack. Er wurde aus einem sehr widerstandsfaehigem, robustem' gaga1 
/def -p1 -ag -mglob -t'Material gefertig, ist aber trotzdem aeusserst leicht. Doch das ist nicht das' gaga2 
/def -p1 -ag -mglob -t'Erstaunlichste an diesem Rucksack. Viel verwunderlicher ist die Tatsache, das' gaga3 
/def -p1 -ag -mglob -t'der Rucksack sehr klein wirkt, auf jeden Fall zu klein um mehr als einige' gaga4 
/def -p1 -ag -mglob -t'Muenzen darin verstauen zu koennen. Trotzdem ist der Rucksack aber in der Lage' gaga5 
/def -p1 -ag -mglob -t'Unmengen von Sachen aufzunehmen. Wie ist und bleibt Dir ein Raetsel, denn auch' gaga6 
/def -p1 -ag -mglob -t'Vader weiss dieses Geheimniss nicht. Das kann Dir auch egal sein, denn Du' gaga7 
/def -p1 -ag -mglob -t'freust Dich sehr, so einen genialen Rucksack zu besitzen. Ausserdem Du' gaga8 
/def -p1 -ag -mglob -t'erkennst ein kleines Schild an Vaders Rucksack.' gaga9 
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p99 -P0B -P0Cmagenta -mregexp -F -t'(> )*Du wandelst [0-9]* LPs in [0-9]* MPs um' hil1 
/def -p99 -P0B -P0Cmagenta -mregexp -F -t'^(> )*Ein magisches Portal' hil3 
/def -p99 -ah -mregexp -F -t'^(> )*Die Angst ist staerker als Du' hil4 = \      /echo -aCbgyellow -aBCred ! ! !   F L U C H T   ! ! !
/def -p99 -aB -aCbgred -aCyellow -mregexp -F -t'^(> )*Vorsicht-Modus' hil5 
/def -p99 -aB -aCbgred -aCyellow -mregexp -F -t'^(> )*Ok, Fluchtrichtung' hil6 
/def -p99 -aB -aCbgyellow -aCmagenta -mregexp -F -t'^(> )*\\* Extrablatt! Neuer Artikel' hil7 
/def -p99 -P0B -P0Cgreen -mregexp -t'(> )*Du teilst [A-Za-z]* mit:' hil8; 
/def -p99 -P0Cyellow -mregexp -F -t'( (sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' part0 
/def -p99 -P0Cyellow -mregexp -F -t'^((sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' part00 
/def -p99 -P0Cyellow -mregexp -F -t'(> )*([0-9]*) Muenzen' part1 
/def -p99 -P0B -P0Cred -mregexp -F -t'magischen Pfeil' part2 
/def -p99 -P0B -P0Cred -mregexp -F -t'Feuer' part3 
/def -p99 -P0B -P0Ccyan -mregexp -F -t'Zauberspruch ist missglueckt' part4 
/def -p99 -P0B -P0Cyellow -mregexp -F -t'Elfendorf' part5 
/def -p99 -P0B -P0Cred -mregexp -F -t'zu wenig Zauberpunkte' part6 
/def -p99 -P0B -P0Cgreen -mregexp -t'^(> )*\\[Allgemein:[A-Za-z ]*\\]?' eb1 
/def -p99 -P0B -P0Ccyan -mregexp -t'^(> )*\\[Abenteuer:[A-Za-z -]*\\]?' eb2 
/def -p99 -P0B -P0Cmagenta -mregexp -t'^(> )*[A-Za-z]* sagt:' eb3 
/def -p99 -P0Cred -mregexp -t'^(> )*\\[Moerder:[A-Za-z -]*\\]?' eb4 
/def -p99 -P0B -P0Cbgred -P0Cwhite -mregexp -t'^(> )*\\[Tod:[A-Za-z -]*\\]?' eb5 
/def -p99 -P0Cbgblue -mregexp -t'^(> )*\\[Seher:[A-Za-z -]*\\]?' eb6 
/def -p99 -P0Cyellow -mregexp -t'^(> )*\\[Grats:[A-Za-z -]*\\]' eb7 
/def -p99 -P0Cyellow -mregexp -t'^(> )*\\[Beileid:[A-Za-z -]*\\]' eb8 
/def -p10 -P0Cyellow -mregexp -t'^(> )*\\[[A-Za-z]*:[A-Za-z -]*\\]?' eb9 
/def -p99 -P0B -P0Cgreen -mregexp -t'(> )*[A-Za-z]* teilt Dir mit:' hil2 
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def v2z = ultrakurz%;o%;o%;o%;so%;runter%;so%;o%;so%;so%;n%;u%;u%;lang%;u%;
/def z2v = ultrakurz%;ob%;ob%;ob%;s%;nw%;nw%;w%;nw%;rauf%;nw%;w%;w%;lang%;w%;
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def g2b = /g2z%; /z2b%;
/def b2g = /b2z%; /z2g%;
/def MACROFILE = ~/tf-dir/macros.tf
/def HILITEFILE = ~/tf-dir/hilite.tf
/def GAGFILE = ~/tf-dir/gag.tf
/def TRIGFILE = ~/tf-dir/trig.tf
/def BINDFILE = ~/tf-dir/bind.tf
/def HOOKFILE = ~/tf-dir/hook.tf
/def WORLDFILE = ~/tf-dir/world.tf
/def LOGFILE = tiny.log
/def p = 1%; 4%; 5%;
/def vsoeldner = v lederruestung%; v saebel%; v kupferschild%;
/def vsoldat = v eisenschild%; v eisenpanzer%; v lederstiefel%; v kampfschwert%;
/def z2b = ultrakurz%;ob%;ob%;ob%;s%;nw%;nwob%;w%;nwob%;rauf%;no%;o%;o%;o%;no%;o%;so%;o%;no%;o%;o%;no%;ob%;ob%;ob%;lang%;schau%;
/def b2z = ultrakurz%;u%;u%;u%;sw%;w%;w%;sw%;w%;nw%;w%;sw%;w%;w%;w%;sw%;runter%;sou%;o%;sou%;so%;n%;u%;u%;u%;lang%;schau%;
/def -b'^[[F' pf = /p
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def 2k = no%;o%;no%;
/def ff = stecke schwert ein%; ziehe schild aus%; feuerball%; pfeil%; trage kevlarschild%; zuecke mordorschwert%;
/def f = ziehe schild aus%; stecke schwert ein%; feuerball%; ziehe schild an%; zuecke mordorschwert%;
/def weg = /echo ********wege*******%;/wege%;/echo *******************%;
/def wege = /echo g2e%;/echo g2z%;/echo e2z%;/echo n2f%;/echo z2w%;/echo z2s%;/echo z2t
/def wegaus = ultrakurz
/def wegan = lang
/def z2g = /wegaus%;/zwerg_eingang2hochland%;/hochland2midas_guild%;/wegan%;schau%;
/def g2z = /wegaus%;/midas_guild2hochland%;/hochland2zwerg_eingang%;/wegan%;schau%;
/def e2g = /wegaus%;/elf_hain2hochland%;/hochland2midas_guild%;/wegan%;schau%;
/def g2e = /wegaus%;/midas_guild2hochland%;/hochland2elf_hain%;/wegan%;schau%;
/def n2f = /wegaus%;s%;w%;w%;w%;nw%;sw%;sw%;w%;sw%;sw%;s%;s%;s%;sw%;w%;w%;sw%;sw%;s%;sw%;s%;s%;s%;/wegan%;s%;
/def f2n = /wegaus%;n%;n%;n%;n%;no%;n%;no%;no%;o%;o%;no%;n%;n%;n%;no%;no%;o%;no%;no%;so%;o%;o%;o%;/wegan%;n%;
/def e2z = /wegaus%;/elf_hain2hochland%;/hochland2zwerg_eingang%;/wegan%;schau%;
/def z2e = /wegaus%;/zwerg_eingang2hochland%;/hochland2elf_hain%;/wegan%;schau%;
/def z2s = /wegaus%;/zwerg_eingang2soordhin%;/wegan%;schau
/def s2z = /wegaus%;/soordhin2zwerg_eingang%;/wegan%;schau
/def z2t = /wegaus%;/zwerg_eingang2troll%;/wegan%;schau
/def t2z = /wegaus%;/troll2zwerg_eingang%;/wegan%;schau
/def f2k = /wegaus%;/fisch2knarkh%;/wegan%;schau
/def k2f = /wegaus%;/knarkh2fisch%;/wegan%;schau
/def fisch2knarkh = n%;n%;n%;n%;o%;o%;so%;so%;s%;so%;o%;so%;o%;so%;so%;o%;
/def knarkh2fisch = w%;nw%;nw%;w%;nw%;w%;nw%;n%;nw%;nw%;w%;w%;s%;s%;s%;s%;
/def zwerg_eingang2troll = /z2w%;o%;no%;o%;o%;o%;
/def troll2zwerg_eingang = w%;w%;w%;sw%;w%;/w2z%;
/def zwerg_eingang2soordhin = ob%;ob%;ob%;s%;nw%;nwob%;w%;nwob%;rauf%;no%;nw%;n%;n%;n%;n%;w%;n%;o%;o%;kletter mit seil runter%;o%;s%;s%;o%;o%;n%;betrete kathedrale
/def soordhin2zwerg_eingang = ob%;raus%;s%;w%;w%;n%;n%;w%;kletter rauf%;w%;w%;s%;o%;s%;s%;s%;s%;so%;sw%;runter%;sou%;o%;sou%;so%;n%;u%;u%;u
/def midas_guild2hochland = n%;w%;w%;w%;w%;w%;nw%;n%;nw%;w%;nw%;w%;nw%;nw%;nw%;nw%;
/def hochland2midas_guild = so%;so%;so%;so%;o%;so%;o%;so%;s%;so%;o%;o%;o%;o%;o%;s%;
/def elf_hain2hochland = o%;n%;runter%;o%;so%;s%;s%;s%;s%;s%;sob%;sob%;s%;sob%;sw%;sw%;oob%;noob%;ou%;nou%;nu%;o%;no%;o%;ou%;o%;s%;sw%;sw%;ou%;o%;o%;o%;sob%;swob%;sw%;s%;nou%;sou%;nou%;o%;s%;s%;o%;sou%;o%;so%;o%;o%;
/def hochland2elf_hain = w%;w%;nw%;w%;nwob%;w%;n%;n%;w%;swob%;nwob%;swob%;n%;no%;nou%;nu%;w%;w%;w%;wob%;no%;no%;n%;w%;wob%;w%;sw%;w%;sob%;swob%;wob%;swu%;wu%;no%;no%;nu%;n%;nu%;nu%;n%;n%;n%;n%;n%;nw%;w%;klettere rauf%;s%;w%;
/def zwerg_eingang2hochland = ob%;ob%;ob%;s%;nw%;nwob%;w%;nwob%;sw%;sou%;s%;s%;s%;sou%;o%;o%;sou%;s%;s%;s%;
/def hochland2zwerg_eingang = n%;n%;n%;nwob%;w%;w%;nwob%;n%;n%;n%;nwob%;no%;sou%;o%;sou%;so%;n%;u%;u%;u%;
/def z2w = ultrakurz%;ob%;ob%;ob%;s%;nw%;nwob%;w%;nwob%;rauf%;no%;o%;o%;o%;no%;o%;so%;lang%;schau%;
/def w2z = ultrakurz%;nw%;w%;sw%;w%;w%;w%;sw%;runter%;sou%;o%;sou%;so%;n%;u%;u%;u%;lang%;schau%;
/def g2f = /wegaus%;n%;w%;w%;w%;w%;w%;nw%;sw%;sw%;w%;sw%;sw%;s%;s%;s%;sw%;w%;w%;sw%;sw%;s%;sw%;/wegan%;schau%;
/def f2g = /wegaus%;no%;n%;no%;no%;o%;o%;no%;n%;n%;n%;no%;no%;o%;no%;no%;so%;o%;o%;o%;o%;o%;s%;/wegan%;schau%;
/def g2w = /g2z%;/z2w%;
/def w2g = /w2z%;/z2g%;
/def k2d = s%;w%;w%;sw%;w%;sw%;so%;o%;s%;s%;s%;s%;sw%;w%;w%;w%;w%;w%;w%;
/def d2g = sw%;w%;w%;w%;w%;w%;w%;s%;
/def g2d = n%;o%;o%;o%;o%;o%;o%;no%;
/def d2k = ultrakurz%;o%;o%;o%,o%;o%;o%;no%;n%;n%;n%;n%;w%;nw%;no%;o%;no%;o%;o%;kletter durch pflanzen%;lang%;schau%;
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def sch = stecke schwert ein%;leg mordorschwert in beutel%;ziehe schild aus%;nimm beil aus beutel%;zuecke beil 2%;smash%;leg beil in beutel%;nimm mordorschwert aus beutel%;zuecke mordorschwert%;trage kevlarschild%;
/def pre = /if ((%1 =~ "zeit") | (%1 =~ "time")) /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("$$(/time %%%H:%%%M:%%%S) > ") %;/set prelp=0%;/elseif (%1 =~ "off") /undef catch_prompt%;/def catch_prompt = %;/set prelp=0%;/elseif (%1 =~ "lp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp > ")%;/set prelp=1%;/elseif (%1 =~ "mp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp > ")%;/set prelp=1%;/elseif (%1 =~ "lpmp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp MP: %%magp > ")%;/set prelp=1%;/elseif (%1 =~ "mplp") /undef catch_prompt%;/set prelp=1%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp LP: %%lebp > ")%;/elseif (%1 =~ "string") /undef catch_prompt%;/set prelp=0%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("%-1 ")%;/else /echo %% Options for pre: time, lp, mp, lpmp, mplp, string <text>, off.%;/endif%;/DOKEY NEWLINE
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif
/def 2 = stecke degen ein%;pfeil%;zuecke degen%;
/def 1 = stecke degen ein%;zieh schild aus%;feuerball%;zuecke degen%;ziehe schild an%;
/def 5 = steck schwert weg%;zieh schild aus%;stecke axt ein%;feuerball%;zuecke axt%;
/def 4 = stecke axt ein%;pfeil%;zuecke axt%;
/def s1 = zuecke beil%; smash%;zuecke axt%;
/def oo = no%;o%;no%;
/def oo1 = sw%;w%;sw%;
/def -p1 -mglob -F -h'PROMPT *> ' catch_prompt = /test prompt ("LP: %lebp MP: %magp > ")
/def t1 = zuecke blitzschwert%;turran%;zuecke axt%;
/def 6 = stecke axt weg%;stecke mithrilschwert ein%;zieh kevlarschild aus%;feuerball%;zuecke mithrilschwert%;zieh kevlarschild an%;
/def -b'\\^' fb = /5
/def b = n%;spritze bestie an%;s%;pumpe pistole%;
