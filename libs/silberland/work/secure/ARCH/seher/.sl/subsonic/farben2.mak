;
; ---=== S I L B E R L A N D ===---
;
;     FARBMAKROS FUER TINYFUGUE
;
;     (C)1997, 1998 by SuBSoNiC
;
; Version 1.1  Terminal-Ausfuehrung

;-----------------------------------------------------------------------------------------------------------------------------

/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Allgemein:*[A-Za-z0-9.:;,*!?\'\" ]*\]' eb1
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Kultur:[A-Za-z0-9.:;,\'\" ]*\]' eb2
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Wissenschaft:[A-Za-z0-9.:;,\'\" ]*\]' eb3
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Sport:[A-Za-z0-9.:;,\'\" ]*\]' eb4
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Unfinn:[A-Za-z0-9.:;,\'\" ]*\]' eb5
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Abenteuer:[A-Za-z0-9.:;,\'\" ]*\]?' eb6
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Auktion:[A-Za-z0-9.:;,\'\" ]*\]?' eb7
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Seher:[A-Za-z0-9.:;,\'\" ]*\]?' eb8
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Erzseher:[A-Za-z0-9.:;,\'\" ]*\]?' eb9
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Elfen:[A-Za-z0-9.:;,\'\" ]*\]?' eb10 
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Hobbits:[A-Za-z0-9.:;,\'\" ]*\]?' eb11
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Menschen:[A-Za-z0-9.:;,\'\" ]*\]?' eb12
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Zwerge:[A-Za-z0-9.:;,\'\" ]*\]?' eb13
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[DruidenZirkel:[A-Za-z0-9.:;,\'\" ]*\]?' eb14
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Berserker:[A-Za-z0-9.:;,\'\" ]*\]?' eb15   
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Paladine:[A-Za-z0-9.:;,\'\" ]*\]?' eb16
/def -i -p99 -F -P0hr -mregexp -t'^(> )*\[Tod:\]' eb17
/def -i -p99 -F -P0hr -mregexp -t'^(> )*\[Info:[A-Za-z0-9.:;,\'\" ]*\]' eb18
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Moerder:[A-Za-z0-9.:;,\'\" ]*\]' eb19
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Event:[A-Za-z0-9.:;,\'\" ]*\]' eb20
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Beileid:[A-Za-z0-9.:;,\'\" ]*\]' eb21
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Grats:[A-Za-z0-9.:;,\'\" ]*\]' eb22
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[TinyFugue:[A-Za-z0-9.:;,\'\" ]*\]' eb23
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Intermud:[A-Za-z0-9.:;,\'\" ]*\]?' eb24
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[D-chat:[A-Za-z0-9.:;,\'\" ]*\]?' eb25
/def -i -p99 -F -P0r -mregexp -t'^(> )*\[Nachrichten:[A-Za-z0-9.:;,\'\" ]*\]' eb26  

/def -i -p99 -F -ahu -mregexp -t'^(> )*Die Angst ist staerker als Du' kampf1 = \       
    /echo -arB ! ! !   R E D   A L E R T   ! ! !
/def -i -p99 -F -ahu -mregexp -t'^(> )*In panischer Angst bist du nach [A-Za-z] gefluechtet.' kampf2
/def -i -p99 -F -ahu -mregexp -t'^(> )*Vorsicht-Modus' kampf3
/def -i -p99 -F -ahu -mregexp -t'^(> )*Ok, Fluchtrichtung' kampf4

/def -i -p99 -mregexp -F -P0h -t'(Freunde|Metallica|Nicole|Duncan|Neon|Sheila|Cloud|Krigi|Sengir|Nike|Looser|Rck|Adt|Ikea|Schlaubi|Lexana|Tomtom|Skunk|Protheg|Slayven|Subsonic|Vader|Andyl|Titania|Kaptain|Cohen|Elvira|Raballion|Orktoeter|Infraschall|Elwuud|Jake|Tpring|Aargon|Losser|Losserzwei|Cadrim|Lamyra|Zwark|Sila|Aleph|Booster|Elena|Zeus|Xagul|Trintrasil|Cocopops|Ford|Bonbon|Amnenion|Gauloises|Asgaard|Knuth|Tharsonius|Ambrolosch|Berzerktod|Gangsta|King|Omega|Verdegard|Scho|Dobob|Canziora)' FCom

/def -i -p99 -mregexp -F -P0h -t'^((sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' loc1
/def -i -p99 -mregexp -F -P0h -t'( (sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' loc1a
/def -i -p99 -mregexp -F -P0h -t'^(> )*Ein magisches Portal' loc2
 
/def -i -p99 -mregexp -F -P0h -t'Du lernst aus Deinem Fehler.' mag8 =
/def -i -p99 -mregexp -F -P0h -t'zu wenig Zauberpunkte' mag9 =

/def -i -p99 -mregexp -F -P0h -t'elementaren Luftpfeil' dru1 =
/def -i -p99 -mregexp -F -P0h -t'elementaren Erzpfeil' dru2 =
/def -i -p99 -mregexp -F -P0h -t'elementaren Wasserpfeil' dru3 =
/def -i -p99 -mregexp -F -P0h -t'elementaren Eispfeil' dru4 =
/def -i -p99 -mregexp -F -P0h -t'elementaren Feuerpfeil' dru5 =
/def -i -p99 -mregexp -F -P0h -t'elementaren Windstoss' dru6 =
/def -i -p99 -mregexp -F -P0h -t'elementaren Erzstrahl' dru7 =
/def -i -p99 -mregexp -F -P0h -t'elementaren Wasserstrahl' dru8 =

/def -i -p99 -mregexp -F -P0h -t'ein kleiner Feuerwusel' dru9 =
/def -i -p99 -mregexp -F -P0h -t'Panzer aus Eis, Luft, Feuer, Erz und Wasser' dru10 =
/def -i -p99 -mregexp -F -P0h -t'Deine Haende beginnen zu brennen!' dru11 =

/def -i -p99 -mregexp -F -P0h -t'loest sich in ein rauchwoelkchen auf' dru12 =
/def -i -p99 -mregexp -F -P0h -t'Das Feuer um Deinen Haenden erlischt' dru13 =
/def -i -p99 -mregexp -F -P0h -t'Elementarpanzer loest sich in die einzelnen Elemente auf' dru14 =
/def -i -p99 -mregexp -F -P0h -t'doch nichts passiert' dru15 =
/def -i -p99 -mregexp -F -P0h -t'Dein vorheriger Zauber erlischt' dru16 =
/def -i -p99 -mregexp -F -P0h -t'Du musst Dich erst wieder konzentrieren' dru17 =
/def -i -p99 -mregexp -F -P0h -t'Du bist noch mit der Spruchvorbereitung beschaeftigt' dru18 =
/def -i -p99 -mregexp -F -P0h -t'Die Ausfuehrung Deines vorbereiteten Spruchs wird verzoegert' dru19 =
/def -i -p99 -mregexp -F -P0h -t'nicht genuegend Magiepunkte' dru20 =
/def -i -p99 -mregexp -F -P0h -t'Du kannst Dich nicht auf die Muster des Zaubers konzentrieren' dru21 = 
/def -i -p99 -mregexp -F -P0h -t'Du hast nicht genug freie Haende dafuer' dru22= ;end of file
