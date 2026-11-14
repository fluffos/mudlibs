/def pre = /if ((%1 =~ "zeit") | (%1 =~ "time")) /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("$$(/time %%%H:%%%M:%%%S) > ") %;/set prelp=0%;/elseif (%1 =~ "off") /undef catch_prompt%;/def catch_prompt = %;/set prelp=0%;/elseif
 (%1 =~ "lp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp > ")%;/set prelp=1%;/elseif (%1 =~ "mp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp > ")%;/set prelp=1%;/elseif (%
1 =~ "lpmp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp MP: %%magp > ")%;/set prelp=1%;/elseif (%1 =~ "mplp") /undef catch_prompt%;/set prelp=1%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp LP: 
%%lebp > ")%;/elseif (%1 =~ "string") /undef catch_prompt%;/set prelp=0%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("%-1 ")%;/else /echo %% Options for pre: time, lp, mp, lpmp, mplp, string <text>, off.%;/endif%;/DOKEY NEWLINE
/def -Fp1000 -ag -mregexp -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 
) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magp
diff)%;/endif
/def -Fp1 -mglob -h'PROMPT *> ' catch_prompt = /test prompt ("LP: %lebp MP: %magp > ")
/def -b'^[[5~' f = 1%;2%;3%;8%;9%;
/def -p1 -mglob -t'{*} kommt an.' scnorr1 = bitte $[tolower(%1)] / um an Schueling fuer Alkohol oder Drogen
/def -p1 -mglob -t'{*} kommt an.' schnorr1 = bitte $[tolower(%1)] /um an Schueling fuer Alkohol oder Drogen
/def -p1 -mglob -t'Elvira kommt die welt vor glueck umarmend herein.' aaa = sd
/def -p1 -mglob -t'{*} gibt Dir * Muenzen.' danke1 = danke $[tolower(%1)] /fuer die Spende


