;From ray@mars.zserv.tuwien.ac.at Tue Jun 24 12:50:01 MET 1997
;Received: from mars.zserv.tuwien.ac.at by stud3.tuwien.ac.at with ESMTP
;	(1.40.112.12/16.2) id AA084969400; Tue, 24 Jun 1997 12:50:00 +0200
;Return-Path: <ray@mars.zserv.tuwien.ac.at>
;Received: (from ray@localhost) by mars.zserv.tuwien.ac.at (8.7.5/8.7.3) 
;id MAA04411 for e9626223@stud3; Tue, 24 Jun 1997 12:49:00 +0200
;Date: Tue, 24 Jun 1997 12:49:00 +0200
;From: Raimund Bauer <ray@mars.zserv.tuwien.ac.at>
;Message-Id: <199706241049.MAA04411@mars.zserv.tuwien.ac.at>
;To: e9626223@stud3.tuwien.ac.at
;Status: RO
;X-Status: 

/def flucht=
/def -i -p99 -F -P0BCmagenta -mregexp -t'(> )*Du wandelst [0-9]* LPs in [0-9]* MPs um' hil1
/def -i -p99 -F -P0BCgreen -mregexp -t'(> )*[A-Za-z@]* teilt Dir mit:' hil2
/def -i -p99 -F -P0BCmagenta -mregexp -t'^(> )*Ein magisches Portal*' hil3
/def -i -p99 -F -ah -mregexp -t'^(> )*Die Angst ist staerker als Du' hil4 = \
	/echo -aCbgyellow -aBCred ! ! !   F L U C H T   ! ! !%;/flucht
/def -i -p99 -F -aBCyellow -aCbgred -mregexp -t'^(> )*Vorsicht-Modus' hil5
/def -i -p99 -F -aBCyellow -aCbgred -mregexp -t'^(> )*Ok, Fluchtrichtung' hil6
/def -i -p99 -F -aBCmagenta -aCbgyellow -mregexp -t'^(> )*\* Extrablatt! Neuer Artikel' hil7
/def -i -p99 -F -P0BCgreen -mregexp -t'(> )*Du teilst [A-Za-z@]* mit:' hil8

;/def -i -p99 -F -ah -mregexp -t'(> )*[A-Za-z ]*macht einen [a-z*] Eindruck' hil2

/def -i -p99 -mregexp -F -P0Cyellow -t'( (sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' part0
/def -i -p99 -mregexp -F -P0Cyellow -t'^((sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' part00
/def -i -p99 -mregexp -F -P0Cyellow -t'(> )*([0-9]*) Muenzen' part1 = 
/def -i -p99 -mregexp -F -P0BCred -t'magischen Pfeil' part2 =
/def -i -p99 -mregexp -F -P0BCred -t'Feuerball' part3 =
/def -i -p99 -mregexp -F -P0BCred -t'Feuerbaellchen' part8 =
/def -i -p99 -mregexp -F -P0BCcyan -t'Zauberspruch ist missglueckt' part4 =
/def -i -p99 -mregexp -F -P0BCyellow -t'Elfendorf' part5 =
/def -i -p99 -mregexp -F -P0BCred -t'zu wenig Zauberpunkte' part6
/def -i -p99 -F -P0BCyellow -mregexp -t'(Ghostrider|Gauloises|Sheila|Skunk\
|Lostboy|Protheg|Negoc|Slayven|Subsonic|Vader|Ed|Aargon|Andyl|Asgaard\
|Ford|Mond|Dusty|Stahldorn|Eros|Critter|Thor|Angrox\
|Titania|Elvira|Nike|Dobob|Booster|Gildoniel|Aleph|\
Embee|EMBee|Fenris|Amnenion|Eve|Sisqui|Trintrasil|Verdegard|Xagul|Crowley|\
Verdandi|Woody|Berx|Cadrim|Xorgna)( |,|\.|s|\])' part7
;/def -i -p99 -

/def -i -p99 -F -P0BCgreen -mregexp -t'^(> )*\[Allgemein:[A-Za-z]*\]?' eb1
/def -i -p99 -F -P0BCcyan -mregexp -t'^(> )*\[Abenteuer:[A-Za-z]*\]?' eb2
/def -i -p99 -F -P0BCmagenta -mregexp -t'^(> )*[A-Za-z]* sagt:' eb3
/def -i -p99 -F -P0BCmagenta -mregexp -t'^(> )*[A-Za-z]* ruft:' eb7
/def -i -p99 -F -P0Cred -mregexp -t'^(> )*\[Moerder:[A-Za-z ]*\]' eb4
/def -i -p99 -F -P0Cred -P0BCbgyellow -mregexp -t'^(> )*\[Tod:\]' eb5
/def -i -p99 -F -P0Cyellow -mregexp -t'^(> )*\[Seher:[A-Za-z ]*\]' eb6
/def -i -p99 -F -P0Ccyan -mregexp -t'^(> )*\[DruidenZirkel:[A-Za-z]*\]?' eb10

/def -i -p99 -F -P0Cmagenta -t'ist gerade ins SilberLand \
gekommen.' eb8
/def -i -p99 -F -P0Cmagenta -t'hat gerade das SilberLand \
verlassen.' eb9

/def -i -p99 -mregexp -F -P0Ccyan -t'Luftpfeil' partd1 =
/def -i -p99 -mregexp -F -P0BCyellow -t'Erzpfeil' partd2 =
/def -i -p99 -mregexp -F -P0BCblue -t'Wasserpfeil' partd3 =
/def -i -p99 -mregexp -F -P0BCcyan -t'Eispfeil' partd4 =
/def -i -p99 -mregexp -F -P0BCred -t'Feuerpfeil' partd5 =
/def -i -p99 -mregexp -F -P0Ccyan -t'Windstoss' partd6 =
/def -i -p99 -mregexp -F -P0BCred -t'Feuerhand' partd7 =
/def -i -p99 -mregexp -F -P0BCyellow -t'Erzstrahl' partd8 =
/def -i -p99 -mregexp -F -P0BCblue -t'Wasserstrahl' partd9 =

/def -i -p99 -mregexp -F -P0Ccyan -t'Du musst Dich erst wieder konzentrieren.' partd1a =
/def -i -p99 -mregexp -F -P0Ccyan -t'Du lernst aus Deinem Fehler.' partd2a =
/def -i -p99 -F -P0Ccyan -mregexp -t'(> )*Druide [A-Za-z]* teilt euch mit:' partdt1
/def -i -p99 -F -P0Ccyan -mregexp -t'(> )*Druidin [A-Za-z]* teilt euch mit:' partdt4
/def -i -p99 -F -P0Ccyan -mregexp -t'(> )*Druidenpapa [A-Za-z]* teilt euch mit:' partdt2
/def -i -p99 -F -P0Ccyan -mregexp -t'(> )*Du teilst den Druiden mit:' partdt3
;unet.univie.ac.at/~a9321047







