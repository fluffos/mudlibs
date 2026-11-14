/def -p1000 -ag -mregexp -F -t'Du hast jetzt (.*) \\((.*)\\) Lebenspunkte und (.*) \\((.*)\\) Mag' getlpundmp = /set lebp=%P1%; /set magp=%P3%; /set maxlp=%P2%; /set maxmp=%P4%; /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;/if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;/if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;/set lebpold=%lebp%;  /set magpold=%magp%;/if (prelp) /catch_prompt%;/else /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;/endif%;/checkflucht%;
/def pre = /if ((%1 =~ "zeit") | (%1 =~ "time")) /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("$$(/time %%%H:%%%M:%%%S) > ") %;/set prelp=0%;/elseif (%1 =~ "off") /undef catch_prompt%;/def catch_prompt = %;/set prelp=0%;/elseif (%1 =~ "lp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp > ")%;/set prelp=1%;/elseif (%1 =~ "mp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp > ")%;/set prelp=1%;/elseif (%1 =~ "lpmp") /undef catch_prompt%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp MP: %%magp > ")%;/set prelp=1%;/elseif (%1 =~ "mplp") /undef catch_prompt%;/set prelp=1%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp LP: %%lebp > ")%;/elseif (%1 =~ "string") /undef catch_prompt%;/set prelp=0%;/def -F -h"PROMPT *> " catch_prompt = /test prompt ("%-1 ")%;/else /echo %% Options for pre: time, lp, mp, lpmp, mplp, string <text>, off.%;/endif%;/DOKEY NEWLINE
/def -p1 -mglob -F -h'PROMPT *> ' catch_prompt = /test prompt ("LP: %lebp MP: %magp > ")


/def mperhohlt = /if (%maxmp=%magp) /zauberjetzt%; /endif
/def uebeloopsave = /mperhohlt%;/repeat -00:00:05 1 /uebeloop
/def uebeloop = /uebeloopsave
/def uebe = /repeat -00:00:03 1 /uebeloop%;/def zauberjetzt = %*
/def uebeaus = /def uebeloop = %;\
               /repeat -00:00:06 1\
                 /def uebeloop = /uebeloopsave



/def at = \
    /let delay=$[{1} - $(/time %%H:%%M:%%S)]%;\
    /repeat -$[(delay >= 0) ? delay : (delay + 24:00)] 1 %-1

/set vorsicht 1
/def checkflucht = /if ((%lebp<%vorsicht) & (%lebpdiff<0)) /flucht%; / /echo !!!!!!!!!!!!!!!!    FLUCHT   !!!!!!!!!!!!!!!!%; /endif
/def flucht = /echo FLUCHTRICHTUNG NICHT GESETZT!!      (mit /flr xxx setzten!!)
/def vors = /set vorsicht %{1}%;/echo vorsicht ist jetzt %vorsicht
/def flr = /def flucht = %{1}%%;%{2}%%;%{3}%%;%{4}%%;%{5}%%;%{6}%%;%{7}%%;%{8}%%;%{9}%%;%{10}%%;

/def begruess = fknuddel /herzlich
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
/def z2b = ultrakurz%;ob%;ob%;ob%;s%;nw%;nwob%;w%;nwob%;rauf%;no%;o%;o%;o%;no%;o%;so%;o%;no%;o%;o%;no%;ob%;ob%;ob%;lang%;schau%;
/def b2z = ultrakurz%;u%;u%;u%;sw%;w%;w%;sw%;w%;nw%;w%;sw%;w%;w%;w%;sw%;runter%;sou%;o%;sou%;so%;n%;u%;u%;u%;lang%;schau%;
/def 2k = no%;o%;no%;
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
/def oo = no%;o%;no%;
/def oo1 = sw%;w%;sw%;
/def v2z = ultrakurz%;o%;o%;o%;so%;runter%;so%;o%;so%;so%;n%;u%;u%;lang%;u%;
/def z2v = ultrakurz%;ob%;ob%;ob%;s%;nw%;nw%;w%;nw%;rauf%;nw%;w%;w%;lang%;w%;
/def elf_hain2kreuzung = o%;n%;runter%;o%;so%;s%;s%;s%;s%;s%;sob%;sob%;s%;sob%;sw%;sw%;oob%;noob%;ou%;nou%;nu%;o%;no%;o%;ou%;o%;
/def midas_guild2kreuzung = n%;w%;w%;w%;w%;w%;nw%;n%;nw%;w%;nw%;w%;nw%;nw%;nw%;nw%;w%;w%;nw%;w%;nwob%;w%;n%;n%;w%;swob%;nwob%;swob%;n%;no%;nou%;nu%;w%;w%;w%;wob%;no%;no%;n%;
/def kreuzung2midas_guild = s%;sw%;sw%;ou%;o%;o%;o%;sob%;swob%;sw%;s%;nou%;sou%;nou%;o%;s%;s%;o%;sou%;o%;so%;o%;o%;so%;so%;so%;so%;o%;so%;o%;so%;s%;so%;o%;o%;o%;o%;o%;s%;
/def kreuzung2elf_hain = w%;wob%;w%;sw%;w%;sob%;swob%;wob%;swu%;wu%;no%;no%;nu%;n%;nu%;nu%;n%;n%;n%;n%;n%;nw%;w%;klettere rauf%;s%;w%;
/def kreuzung2druidenzirkel = no%;zwaenge durch durchlass%;nw%;
/def druidenzirkel2kreuzung = so%;so%;sw%;
/def e2dz = /wegaus%;/elf_hain2kreuzung%;/kreuzung2druidenzirkel%;/wegan%;schau%;
/def dz2e = /wegaus%;/druidenzirkel2kreuzung%;/kreuzung2elf_hain%;/wegan%;schau%;
/def g2dz = /wegaus%;/midas_guild2kreuzung%;/kreuzung2druidenzirkel%;/wegan%;schau%;
/def dz2g = /wegaus%;/druidenzirkel2kreuzung%;/kreuzung2midas_guild%;/wegan%;schau%;
/def r2z = ultrakurz%;o%;o%;o%;so%;runter%;so%;o%;so%;so%;n%;u%;u%;lang%;u%;
/def z2r = ultrakurz%;ob%;ob%;ob%;s%;nw%;nw%;w%;nw%;rauf%;nw%;w%;w%;lang%;w%;
/def g2o = /wegaus%;n%;o%;o%;o%;o%;o%;o%;no%;n%;n%;n%;o%;o%;o%;o%;o%;o%;no%;n%;n%;n%;n%;w%;nw%;/wegan%;schau%;
/def o2g = /wegaus%;so%;o%;s%;s%;s%;s%;sw%;w%;w%;w%;w%;w%;w%;s%;s%;s%;sw%;w%;w%;w%;w%;w%;w%;s%;/wegan%;schau%;


/def ske = /def -p10 -1 -t'*Karavelle*' ein = betrete karavelle
/def sta = /def -p10 -n1 -t'*legt am Hafen von Tijara an*' aus = verlasse schiff
/def sma = /def -p10 -n1 -t'*legt an der Pier von Midas an*' aus = verlasse schiff


/def verfolg = /def -mregexp \
   -t'["> "]*$[strcat(toupper(substr(%1,0,1)),substr(%1,1))] \
   .* nach ([A-Z][a-z]*).' \
   gehnach = $$[tolower(%%P1)]%;\
   /def sverfolg = /undef gehnach