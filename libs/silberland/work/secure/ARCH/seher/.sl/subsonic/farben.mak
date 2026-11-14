;
; ---=== S I L B E R L A N D ===---
;
;     FARBMAKROS FUER TINYFUGUE
;
;        (C)1997 by SuBSoNiC
;
; Version 1.0        PC-Ausfuehrung
;
;-----------------------------------------------------------------------------------------------------------------------------
; CHAT-EBENEN:
; Kennzeichnung wie folgt:
; Gruen: Allgemein, Kultur, Wissenschaft, Sport, Unsinn, Nachrichten
; Cyan: Abenteuer, Druiden, Berserker, Paladine, Auktion
; Gelb: Seher, Erzseher, Elfen, Hobbits, Menschen, Zwerge
; Rot: Tod, Moerder, Info
; Magenta: Grats, Beileid
; Weiss: TinyFugue, D-Chat, InterMud
/def -i -p99 -F -P0Cbggreen -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Allgemein:*[A-Za-z0-9.:;,*!?\'\" ]*\]' eb1
/def -i -p99 -F -P0Cbggreen -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Kultur:[A-Za-z ]*\]' eb2
/def -i -p99 -F -P0Cbggreen -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Wissenschaft:[A-Za-z ]*\]' eb3
/def -i -p99 -F -P0Cbggreen -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Sport:[A-Za-z ]*\]' eb4
/def -i -p99 -F -P0Cbggreen -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Unfinn:[A-Za-z ]*\]' eb5
/def -i -p99 -F -P0Cbggreen -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Nachrichten:[A-Za-z ]*\]' eb6  
/def -i -p99 -F -P0Cbgcyan -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Abenteuer:[A-Za-z ]*\]?' eb7
/def -i -p99 -F -P0Cbgcyan -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[DruidenZirkel:[A-Za-z ]*\]?' eb8
/def -i -p99 -F -P0Cbgcyan -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Berserker:[A-Za-z ]*\]?' eb9   
/def -i -p99 -F -P0Cbgcyan -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Paladine:[A-Za-z ]*\]?' eb10
/def -i -p99 -F -P0Cbgcyan -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Auktion:[A-Za-z ]*\]?' eb11
/def -i -p99 -F -P0Cbgyellow -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Seher:[A-Za-z ]*\]?' eb12
/def -i -p99 -F -P0Cbgyellow -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Erzseher:[A-Za-z ]*\]?' eb13
/def -i -p99 -F -P0Cbgyellow -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Elfen:[A-Za-z ]*\]?' eb14
/def -i -p99 -F -P0Cbgyellow -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Hobbits:[A-Za-z ]*\]?' eb15
/def -i -p99 -F -P0Cbgyellow -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Menschen:[A-Za-z ]*\]?' eb16
/def -i -p99 -F -P0Cbgyellow -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Zwerge:[A-Za-z ]*\]?' eb17
/def -i -p99 -F -P0Cbgred -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Tod:\]' eb18
/def -i -p99 -F -P0Cbgred -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Info:[A-Za-z ]*\]' eb19
/def -i -p99 -F -P0Cbgred -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Moerder:[A-Za-z ]*\]' eb20
/def -i -p99 -F -P0Cbgred -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Event:[A-Za-z ]*\]' eb21
/def -i -p99 -F -P0Cbgmagenta -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Beileid:[A-Za-z ]*\]' eb22
/def -i -p99 -F -P0Cbgmagenta -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Grats:[A-Za-z ]*\]' eb23
/def -i -p99 -F -P0Cbgwhite -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[TinyFugue:[A-Za-z]*\]*' eb24
/def -i -p99 -F -P0Cbgwhite -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[Intermud:[A-Za-z]*\]?' eb25
/def -i -p99 -F -P0Cbgwhite -P0Cblack -aCbgblue -aCwhite -mregexp -t'^(> )*\[D-chat:[A-Za-z]*\]?' eb26
;-----------------------------------------------------------------------------------------------------------------------------
; KAMPF: Rot
/def -i -p99 -F -ah -mregexp -t'^(> )*Die Angst ist staerker als Du' kampf1 = \
        /echo -aCbgred -aBCred ! ! !   R E D   A L E R T   ! ! !
/def -i -p99 -F -abCred -mregexp -t'^(> )*In panischer Angst bist du nach [A-Za-z] gefluechtet.' kampf2
/def -i -p99 -F -aBCred -mregexp -t'^(> )*Vorsicht-Modus' kampf3
/def -i -p99 -F -aBCred -mregexp -t'^(> )*Prinz Eisenherz-Modus' kampf4
/def -i -p99 -F -aBCred -mregexp -t'^(> )*Ok, Fluchtrichtung' kampf5
;-----------------------------------------------------------------------------------------------------------------------------
; KOMMUNIKATION: Gruen
/def -i -p99 -F -P0BCgreen -mregexp -t'(> )*[A-Za-z]* teilt Dir mit:' Com1
/def -i -p99 -F -P0BCgreen -mregexp -t'(> )*Du teilst [A-Za-z]* mit:' Com2
/def -i -p99 -F -P0BCgreen -mregexp -t'^(> )*[A-Za-z]* sagt:' Com3
/def -i -p99 -F -P0BCgreen -mregexp -t'^(> )*Du sagst:' Com4
/def -i -p99 -F -P0BCgreen -mregexp -t'^(> )*[A-Za-z]* ruft:' Com5
/def -i -p99 -F -P0BCgreen -mregexp -t'^(> )*Du rufst:' Com6
/def -i -p99 -F -P0BCgreen -mregexp -t'^(> )*[A-Za-z]* fragt:' Com7
/def -i -p99 -F -P0BCgreen -mregexp -t'^(> )*Du fragst:' Com8
;-----------------------------------------------------------------------------------------------------------------------------
; SPEZIELLE KOMMUNIKATION: Gruen
/def -i -p99 -F -P0BCyellow -mregexp -t'(> )*Druide [A-Za-z]* teilt Dir mit:' SCom1
/def -i -p99 -F -P0BCyellow -mregexp -t'(> )*Du teilst den Druiden mit:' SCom2
/def -i -p99 -mregexp -F -P0BCyellow -t'(Dich) aus der Ferne' SCom3 =
/def -i -p99 -mregexp -F -P0BCyellow -t'(Du) knuddel(s)t' SCom4 =
/def -i -p99 -mregexp -F -P0BCyellow -t'(Du) umarm(s)t' SCom5 =
/def -i -p99 -mregexp -F -P0BCyellow -t'(Du) kitzel(s)t' SCom6 
/def -i -p99 -mregexp -F -P0BCyellow -t'(Du) gratulier(s)t' SCom7 =
/def -i -p99 -mregexp -F -P0BCyellow -t'(Du) tritt(st)' SCom8 =
/def -i -p99 -mregexp -F -P0BCyellow -t'(Du) grinst' SCom9 =

/def -i -p99 -mregexp -F -P0BCwhite -t'(Freunde|Neon|Sheila|Cloud|Krigi|Sengir|Nike|Looser|Rck|Adt|Ikea|Schlaubi|Lexana|Tomtom|Skunk|Protheg|Slayven|Subsonic|Vader|Andyl|Titania|Kaptain|Cohen|Elvira|Raballion|Orktoeter|Infraschall|Elwuud|Jake|Tpring|Aargon|Losser|Losserzwei|Cadrim|Lamyra|Zwark|Sila|Aleph|Booster|Elena|Zeus|Xagul|Trintrasil|Cocopops|Ford|Bonbon|Amnenion|Gauloises|Asgaard|Knuth|Tharsonius|Ambrolosch|Kronangtod|Gangsta|Nicole|Duncan|Omega|Dobob|Verdegard|Canziora|Scho|Metallica|King)' FCom =

;-----------------------------------------------------------------------------------------------------------------------------
; RICHTUNGEN & ORTE: Cyan
/def -i -p99 -mregexp -F -P0BCcyan -t'^((sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' loc1
/def -i -p99 -mregexp -F -P0BCcyan -t'( (sued|west|nord|ost)+(ob|unt)?en)| rauf| runter| raus| oben| unten' loc1a
/def -i -p99 -mregexp -F -P0BCcyan -t'^(> )*Ein magisches Portal' loc2
;-----------------------------------------------------------------------------------------------------------------------------
; MAGIE: Rot/Magenta
; Abenteuerer:
/def -i -p99 -mregexp -F -P0BCred -t'kleines Feuerbaellchen' mag1 =
/def -i -p99 -mregexp -F -P0BCred -t'Feuerball' mag2 =
/def -i -p99 -mregexp -F -P0BCred -t'grossen Feuerball' mag3 =
/def -i -p99 -mregexp -F -P0BCred -t'gewaltig grossen Feuerball' mag4 =
/def -i -p99 -mregexp -F -P0BCred -t'magischen Pfeil' mag5 =
/def -i -p99 -mregexp -F -P0BCred -t'in Deckung' mag6 =
/def -i -p99 -mregexp -F -P0BCred -t'deutlich schneller' mag7 = 
/def -i -p99 -mregexp -F -P0BCmagenta -t'Zauberspruch ist missglueckt' mag8 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'zu wenig Zauberpunkte' mag9 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Du lernst aus Deinem Fehler.' mag10 =

; Druiden:
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Luftpfeil' dru1 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Erzpfeil' dru2 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Wasserpfeil' dru3 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Eispfeil' dru4 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Feuerpfeil' dru5 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Windstoss' dru6 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Erzstrahl' dru7 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Wasserstrahl' dru8 =
/def -i -p99 -mregexp -F -P0BCred -t'elementaren Eisball' dru9 =

/def -i -p99 -mregexp -F -P0BCred -t'ein kleiner Feuerwusel' dru10 =
/def -i -p99 -mregexp -F -P0BCred -t'Panzer aus Eis, Luft, Feuer, Erz und Wasser' dru11 =
/def -i -p99 -mregexp -F -P0BCred -t'Deine Haende beginnen zu brennen!' dru12 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'loest sich in ein rauchwoelkchen auf' dru13 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Das Feuer um Deinen Haenden erlischt' dru14 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Elementarpanzer loest sich in die einzelnen Elemente auf' dru15=
/def -i -p99 -mregexp -F -P0BCmagenta -t'doch nichts passiert' dru16 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Dein vorheriger Zauber erlischt' dru17 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Du musst Dich erst wieder konzentrieren' dru18 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Du bist noch mit der Spruchvorbereitung beschaeftigt' dru19 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Die Ausfuehrung Deines vorbereiteten Spruchs wird verzoegert' dru20 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'nicht genuegend Magiepunkte' dru21 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'Du kannst Dich nicht auf die Muster des Zaubers konzentrieren' dru22 = 
/def -i -p99 -mregexp -F -P0BCmagenta -t'Du hast nicht genug freie Haende dafuer' dru23 =

; Magische Gegenstaende:
/def -i -p99 -mregexp -F -P0BCred -t'magische Aura huellt Dich ein' item1 =
/def -i -p99 -mregexp -F -P0BCred -t'magischen Farben Deines Umhangs leuchten' item2 =
/def -i -p99 -mregexp -F -P0BCred -t'(> )*Du wandelst [0-9]* LPs in [0-9]* MPs um' item3 =
/def -i -p99 -mregexp -F -P0BCmagenta -t'jeder magische Gegenstand' item4 =
;-----------------------------------------------------------------------------------------------------------------------------
; MUENZEN: Gelb
/def -i -p99 -mregexp -F -P0BCyellow -t'(> )*([0-9]*) Muenzen' geld =
;-----------------------------------------------------------------------------------------------------------------------------
; ZEITUNG: Weiss
/def -i -p99 -F -aBCbgwhite -aBCblack -mregexp -t'^(> )*\*F Extrablatt! Neuer Artikel' news
;------------------------------------------------------------------------------------------------------------------------------
;end of file




















