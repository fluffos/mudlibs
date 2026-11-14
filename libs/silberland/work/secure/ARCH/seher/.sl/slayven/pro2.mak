
/def -p99 -F -P0BCmagenta -mregexp -t'(> )*Du wandelst [0-9]* LPs in [0-9]* MPs um' hil1
/def -p99 -F -P0BCmagenta -mregexp -t'Ein magisches Portal' hil3
/def -p99 -F -ah -mregexp -t'^(> )*Die Angst ist staerker als Du' hil4 = \	/echo -aCbgyellow -aBCred ! ! !   F L U C H T   ! ! !
/def -p99 -F -aBCyellow -aCbgred -mregexp -t'^(> )*Vorsicht-Modus' hil5
/def -p99 -F -aBCyellow -aCbgred -mregexp -t'^(> )*Ok, Fluchtrichtung' hil6
/def -p99 -F -aBCmagenta -aCbgyellow -mregexp -t'^(> )*\* Extrablatt! Neuer Artikel' hil7
/def -p99 -P0BCgreen -mregexp -t'(> )*Du teilst [A-Za-z]* mit:' hil8;
/def -p99 -mregexp -F -P0Cyellow -t'( (sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' part0
/def -p99 -mregexp -F -P0Cyellow -t'^((sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' part00
/def -p99 -mregexp -F -P0Cyellow -t'(> )*([0-9]*) Muenzen' part1 = 
/def -p90 -F -P0BCyellow -mregexp -t'(Orpheus|Powered|Camel|Hagugu|Cyrax|Omega|Titania|Zaphod|Semira|Ryker|Sargola|Isabell|Gangsta|Zwark|Homer|Thor|Ray|Krigi|Aleph|Levitikus|Elvira|Tpring|Hunchback|Snowcrash|Vivienne|Fenris|Berx|Canziora|Aenarion|Gladstone|Elena|Idefix|Verdandi|Raballion|Cohen|Torte|Olmeca|Arthoas|Sheila|Zordan|Joscherl|Lamuerte|Brezel|Andi|Lysira|Knuth|Fender|Kara|Birdy|Xagul|Gridi|Nike|Adt|Dobob|Skunk|Slayven|Lostboy|Protheg|Subsonic|Vader|Ed|Aargon|Andyl|Muaddib|Bad|Asgaard|Sengir|Skunkzweiti)( |,|\.)' part7;
/def -p99 -P0BCgreen -mregexp -t'^(> )*\[Allgemein:.*\]?' eb1
/def -p99 -P0BCcyan -mregexp -t'^(> )*\[Abenteuer:.*\]' eb2
/def -p99 -P0BCmagenta -mregexp -t'^(> )*[A-Za-z -]* sagt:' eb3
/def -p99 -P0Cred -mregexp -t'^(> )*\[Moerder:.*\]?' eb4
/def -p99 -P0Cwhite -P0BCbgred -mregexp -t'^(> )*\[Tod:.*\]?' eb5
/def -p99 -P0Cbgblue -mregexp -t'^(> )*\[Seher:[A-Za-z -]*\]?' eb6
/def -p99 -P0Cyellow -mregexp -t'^(> )*\[Grats:[A-Za-z -]*\]' eb7
/def -p99 -P0Cyellow -mregexp -t'^(> )*\[Beileid:[A-Za-z -]*\]' eb8
/def -p10 -P0Cyellow -mregexp -t'^(> )*\[[A-Za-z]*:[A-Za-z -]*\]?' eb9
/def -p99 -P0BCblue -mregexp -t'^(> )*\[Erzseher:[A-Za-z -]*\]' eb10
/def -p99 -P0BCcyan -mregexp -t'(> )*[A-Za-z]* teilt Dir mit:' hil2
/def -p99 -P0BCred -mregexp -t'^(> )*\Dein Wille wird wieder schwaecher.' willenskraft
















































