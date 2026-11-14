; ---=== S I L B E R L A N D ===---
;
;    KAMPFMAKROS FUER TINYFUGUE
;
;       (C)1997 by SuBSoNiC
;
; Version 0.5        PC-Ausfuehrung
;
;-----------------------------------------------------------------------------------------------------------------------------
; VOREINSTELLUNG FUER WAFFE UND SCHILD
; !!! Muss auf die jeweils getragene Waffe eingestellt werden !!!
; !!! Default: Waffe=Schwert; Schild=Schild. !!!
; 
/def waffeweg = steck schwert ein%;
/def waffeher = zueck schwert%;
;
/def schildaus = zieh schild aus%;
/def schildan = zieh schild an%;
;
;-----------------------------------------------------------------------------------------------------------------------------
; KAMPFMAKROS FUER ABENTEURER
; /a Ausweichen
; /s Schnell
; /b Blitz
; /p Pfeil
; /f Feuerball
;
/def a = ausweichen%;
/def s = schnell%;
/def b = blitz%;
/def p = waffeweg%; pfeil%; waffeher%;
/def f = waffeweg%; schildaus%; feuerball%; schildan%; waffeher%;
;
;-----------------------------------------------------------------------------------------------------------------------------
; KAMPFMAKROS FUER DRUIDEN (ELEMENT FEUER)
; 
