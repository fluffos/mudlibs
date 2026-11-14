/def -p1 -mglob -F -h'PROMPT *> ' catch_prompt = /test prompt ("LP: %lebp MP: %magp > ")
/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' anzeige = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif%;/checkflucht%;
/def pre = /if ((%1 =~ "zeit") | (%1 =~ "time")) /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("$$(/time %%%H:%%%M:%%%S) > ") %;/set prelp=0%;/elseif (%1 =~ "off") /undef catch_prompt%;/def catch_prompt = %;/set prelp=0%;/elseif (%1 =~ "lp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp > ")%;/set prelp=1%;/elseif (%1 =~ "mp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp > ")%;/set prelp=1%;/elseif (%1 =~ "lpmp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp MP: %%magp > ")%;/set prelp=1%;/elseif (%1 =~ "mplp") /undef catch_prompt%;/set prelp=1%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp LP: %%lebp > ")%;/elseif (%1 =~ "string") /undef catch_prompt%;/set prelp=0%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("%-1 ")%;/else /echo %% Options for pre: time, lp, mp, lpmp, mplp, string <text>, off.%;/endif%;/DOKEY NEWLINE
/def checkflucht = /if ((%lebp<%vo) & (%lebpdiff<0)) /fl%; /endif
/def fl=/echo FLUCHT!%;
/pre lpmp
/def g2b = /g2z%; /z2b%;
/def b2g = /b2z%; /z2g%;
;/def MACROFILE = ~/tf-dir/macros.tf
;/def HILITEFILE = ~/tf-dir/hilite.tf
;/def GAGFILE = ~/tf-dir/gag.tf
;/def TRIGFILE = ~/tf-dir/trig.tf
;/def BINDFILE = ~/tf-dir/bind.tf
;/def HOOKFILE = ~/tf-dir/hook.tf
;/def WORLDFILE = ~/tf-dir/world.tf
;/def LOGFILE = tiny.log
/def ff = stecke schwert ein%; ziehe schild aus%; feuerball%; trage schild%; zuecke schwert%;
/def scha = stecke axt ein%;leg axt in beutel 3%;nimm beil 3 aus beutel%;zuecke beil%;smash%;leg beil in beutel%;nimm axt aus beutel 3%;zuecke todesaxt%;
/def tur = leg axt in beutel 3%;nimm blitzaxt 2 aus beutel 2%;zuecke blitzaxt%;turran%;leg blitzaxt in beutel 2%;nimm todesaxt aus beutel 3%;zuecke todesaxt%;
/def s1 = zieh schild aus%; zuecke beil%; smash%;zuecke mordorschwert%; zieh schild an%;
/def oo = kurz%;no%;o%;lang%;no%;
/def oo1 = kurz%;sw%;w%;lang%;sw%;
/def -t'Eine Segelyacht legt am Steg an.' by = by
/def -t'Die Segelyacht legt am*' vy = vy
/def p = ziehe schild aus%;pfeil%;ziehe schild an
/def f = ziehe schild aus%;stecke saebel ein%;feuerball%;trage schild%;zuecke saebel
/def rein = zieh umhang aus%;leg umhang in beutel 2%;nimm zauberrobe aus beutel 2%;trage robe%;
/def raus = zieh robe aus%;leg robe in beutel 2%;nimm umhang aus beutel 2%;trage umhang%;

;/def mperhohlt = /if (%maxmp=%magp) /zauberjetzt%; /endif
;/def uebeloopsave = /mperhohlt%;/repeat -00:00:10 1 /uebeloop
;/def uebeloop = /uebeloopsave
;/def uebe = /repeat -00:00:03 1 /uebeloop%;/def zauberjetzt = %*
;/def uebeaus = /def uebeloop = %;\
;               /repeat -00:00:06 1\
;                 /def uebeloop = /uebeloopsave

/def -p1 -mglob -t'*Fenris ruft: M E U B E R L *' fenr = /repeat -02 1 che






















