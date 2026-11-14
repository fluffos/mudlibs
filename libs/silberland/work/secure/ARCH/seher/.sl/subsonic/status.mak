;From ray@mars.zserv.tuwien.ac.at Tue Jun 24 12:50:07 MET 1997
;Received: from mars.zserv.tuwien.ac.at by stud3.tuwien.ac.at with ESMTP
;	(1.40.112.12/16.2) id AA085089407; Tue, 24 Jun 1997 12:50:07 +0200
;Return-Path: <ray@mars.zserv.tuwien.ac.at>
;Received: (from ray@localhost) by mars.zserv.tuwien.ac.at (8.7.5/8.7.3) 
;id MAA04418 for e9626223@stud3; Tue, 24 Jun 1997 12:49:07 +0200
;Date: Tue, 24 Jun 1997 12:49:07 +0200
;From: Raimund Bauer <ray@mars.zserv.tuwien.ac.at>
;Message-Id: <199706241049.MAA04418@mars.zserv.tuwien.ac.at>
;To: e9626223@stud3.tuwien.ac.at
;Status: RO
;X-Status: 

;prompt.tf  (c) Stahldorn
;benoetigte Makrofiles: keine


/def -F -h"PROMPT *> " catch_prompt = 
/set prelp=0

/def pre = \
	/if ((%1 =~ "zeit") | (%1 =~ "time")) \
	   /undef catch_prompt%;\
	   /def -F -h"PROMPT *> " catch_prompt = /test prompt ("$$(/time %%%H:%%%M:%%%S) > ") %;\
	   /set prelp=0%;\
	/elseif (%1 =~ "off") \
	   /undef catch_prompt%;\
	   /def catch_prompt = %;\
	   /set prelp=0%;\
	/elseif (%1 =~ "lp") \
	   /undef catch_prompt%;\
	   /def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp > ")%;\
	   /set prelp=1%;\
	/elseif (%1 =~ "mp") \
	   /undef catch_prompt%;\
	   /def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp > ")%;\
	   /set prelp=1%;\
	/elseif (%1 =~ "lpmp") \
	   /undef catch_prompt%;\
	   /def -F -h"PROMPT *> " catch_prompt = /test prompt ("LP: %%lebp MP: %%magp > ")%;\
	   /set prelp=1%;\
	/elseif (%1 =~ "mplp") \
	   /undef catch_prompt%;\
	   /set prelp=1%;\
	   /def -F -h"PROMPT *> " catch_prompt = /test prompt ("MP: %%magp LP: %%lebp > ")%;\
	/elseif (%1 =~ "string") \
	   /undef catch_prompt%;\
	   /set prelp=0%;\
	   /def -F -h"PROMPT *> " catch_prompt = /test prompt ("%-1 ")%;\
	/else \
	   /echo %% Options for pre: time, lp, mp, lpmp, mplp, string <text>, off.%;\
	/endif%;\
	/DOKEY NEWLINE


/def -p1000 -ag -F -mregexp -t'Du hast jetzt (.*) \((.*)\) Lebenspunkte und (.*) \((.*)\) Mag' = \
    /set lebp=%P1%; /set magp=%P3%; \
    /set maxlp=%P2%; /set maxmp=%P4%; \
    /set lebpdiff=$[%lebp - %lebpold]%; /set magpdiff=$[%magp - %magpold]%;\
    /if ( lebpdiff > 0 ) /set lebpdiff=$[strcat("+",%lebpdiff)]%; /endif%;\
    /if ( magpdiff > 0 ) /set magpdiff=$[strcat("+",%magpdiff)]%; /endif%;\
    /set lebpold=%lebp%;  /set magpold=%magp%;\
    /if (prelp) \
      /catch_prompt%;\
    /else \
      /echo -aB -w     LP  %lebp (%lebpdiff)     MP  %magp (%magpdiff)%;\
    /endif

