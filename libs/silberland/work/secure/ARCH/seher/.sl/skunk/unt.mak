;fpt v0.67 ixtab
;new fps -f npc [wort]+
/require tr.tf
/def -i fphelp = \
  /echo fps < -r npc [wort]+ | [wort]* >%; \
  /echo 7 : exit%; \
  /echo 8 : selektiertes Wort verwerfen und an die Queue fpnie anfuegen%; \
  /echo 9 : help%; \
  /echo 4 : vorheriges Wort %; \
  /echo 5 : selektiertes Wort verwerfen%; \
  /echo 6 : nachfolgendes Wort%; \
  /echo 1 : Inhalt von fpnie anzeigen%; \
  /echo 2 : selektiertes Wort untersuchen%; \
  /echo 3 : Inhalt von fpneu anzeigen%;\
  /echo 0 : Speichere den Inhalt von fpnie%;\
  /echo , : Lade den Inhalt von fpnie%;\
  /echo + : naechstes Verb%;\
  /echo - - : vorheriges Verb%;\
  /echo . : zuletzt unt Wort zurueckholen%;\
  /echo > : fps entfernen%;\
  /echo < : fps unterbrechen

;fpneu  Queue mit den gefundenen und noch nicht untersuchten Nomen
;fpalt  Queue mit den bereits untersuchten Nomen
;fpnie  Queue der Woerte die nie untersucht werden sollen
;fpakt  das zuletzt von fpneu entnomen Nomen
;fpverb Queue der Verben

/def -i fpinit = \
  /def -i -p10 -w${world_name} -mglob -t'*\\[*' keine_ebenen%;\
  /def -i -p10 -w${world_name} -mglob -t'*ruft:*' keine_rufe%;\
  /def -i -p10 -w${world_name} -mglob -t'*teilt dir mit*' kein_teil%;\
  /def -i -p10 -w${world_name} -mglob -t'*aus der Ferne.' keine_emotes%;\
  /def -i -p10 -w${world_name} -mglob -t'*gekommen.' kein_kommen%;\
  /def -i -p10 -w${world_name} -mglob -t'*verlassen.' kein_gehen%;\
  /def -i -mglob -w${world_name} -t'*' zeilen_lesen = /fpt %%{*}%;\
  /bind 4 = /fppre%; \
  /bind 6 = /fpnext%; \
  /bind 2 = /fpunt%; \
  /bind 5 = /fpnunt%; \
  /bind 8 = /fp2nie%; \
  /bind 7 = /fpexit%; \
  /bind 9 = /fphelp%; \
  /bind 3 = /fpshow fpneu%; \
  /bind 1 = /fpshow fpnie%; \
  /bind , = /fpload%; \
  /bind 0 = /fpsave%; \
  /bind - = /fpvpre%; \
  /bind + = /fpvnext%; \
  /bind . = /fpreuse%; \
  /bind > = /fpclear%; \
  /bind < = /fpbreak%; \
  /bind ? = /echo fpanzahl %%fpanzahl fppointer %%fppointer fpaktp %%fpaktp fpalt %%fpalt%;\
  /def -w${world_name} -h"PROMPT" = /fpinput%;\
  /if ( fpstatus!=2 ) \
    /set fpaktion=unt%;\
    /set fpaktp=1%; \
    /set fpalt=%; \
    /set fpanfang=1%;\
    /set fpanzahl=0%; \
    /set fpaverb=8%; \
    /set fplast=0%;\
    /set fpneu=%; \
    /set fppointer=1%; \
    /set fppverb=8%; \
    /set fpnpc=merlin%;\
    /set fpverb=beruehre frage@%%{fpnpc}@nach iss lausche lies rieche trinke unt%; \
  /endif%;\
  /if ( fpstatus!=2 & fpstatus!=1 ) \
    /set fpnie=ausgang ausgaenge norden sueden westen osten unten oben runter rauf suedwesten suedosten nordwesten nordosten du dir dein deine dich ferne%;\
  /endif%;\

/def -i fpstop = \
  /undef keine_ebenen%;\
  /undef keine_rufe%;\
  /undef kein_teil%;\
  /undef keine_emotes%;\
  /undef kein_kommen%;\
  /undef kein_gehen%;\
  /undef zeilen_lesen%;\
  /unbind 4%; \
  /unbind 6%; \
  /unbind 2%; \
  /unbind 8%; \
  /unbind 5%; \
  /unbind 7%; \
  /unbind 9%; \
  /unbind 3%; \
  /unbind 1%; \
  /unbind 0%; \
  /unbind ,%; \
  /unbind +%; \
  /unbind -%; \
  /unbind .%; \
  /unbind ?%; \
  /unbind >%; \
  /unbind <%; \
  /unhook PROMPT%;\
  /test kbgoto(0)%; \
  /test kbdel(kblen())

/def -i fpbreak = \
  /echo Untersuchen nun unterbrochen :-|%;\
  /set fpstatus=2%;\
  /fpstop

/def -i fpexit = \
  /echo Untersuchen nun beendet :)%;\
  /set fpstatus=1%;\
  /fpstop
  
/def -i fpclear = \
  /echo Entferne nun fp :~(%;\
  /fpstop%;\
  /undef fp2nie%;\
  /undef fpbreak%;\
  /undef fpexit%;\
  /undef fpget%;\
  /undef fphelp%;\
  /undef fpinit%;\
  /undef fpinput%;\
  /undef fpload%;\
  /undef fpnext%;\
  /undef fpnunt%;\
  /undef fppre%;\
  /undef fpput%;\
  /undef fprem%;\
  /undef fpreuse%;\
  /undef fps%;\
  /undef fpsave%;\
  /undef fpshow%;\
  /undef fpstop%;\
  /undef fpunt%;\
  /undef fpt%;\
  /undef fpvnext%;\
  /undef fpvpre%;\
  /undef fprsp%;\
  /unset fpaktion%; \
  /unset fpanfang%; \
  /unset fpaktp%; \
  /unset fpalt%; \
  /unset fpanzahl%; \
  /unset fpaverb%; \
  /unset fpfst%; \
  /unset fplword%; \
  /unset fpneu%; \
  /unset fpnie%; \
  /unset fppointer%; \
  /unset fppverb%; \
  /unset fpstatus%; \
  /unset fptrennung%; \
  /unset fpverb%; \
  /unset fpwort%;\
  /unset fpnpc%;\
  /undef fpclear

;binding functions

/def -i fpinput = \
  /set fpakt=%;\
  /if ( fppointer=fpanzahl+1 )  \
    /set fppointer=$[fppointer-1]%; \
  /endif%;\
  /if ( (fppointer>0) ) \
    /set fpakt=$(/fpget %{fppointer} %{fpneu})%; \
    /grab %{fpaktion} %{fpakt}%;\
  /else \
    /fpexit%; \
  /endif%; \

/def -i fppre = \
  /if ( fppointer>1 ) \
    /set fppointer=$[fppointer-1]%; \
  /endif%; \
  /fpinput

/def -i fpnext = \
  /if ( fppointer<fpanzahl ) \
    /set fppointer=$[fppointer+1]%; \
  /endif%; \
  /fpinput

/def -i fpvpre = \
  /if ( fppverb>1 ) \
    /set fppverb=$[fppverb-1]%; \
  /endif%; \
  /set fpaktion=$(/eval /echo $(/fprsp $(/fpget %{fppverb} %{fpverb})))%;\
  /fpinput

/def -i fpvnext = \
  /if ( fppverb<fpaverb ) \
    /set fppverb=$[fppverb+1]%; \
  /endif%; \
  /set fpaktion=$(/eval /echo $(/fprsp $(/fpget %{fppverb} %{fpverb})))%;\
  /fpinput

/def -i fpreuse = \
  /set fpanzahl=$[fpanzahl+1]%; \
  /set fpneu=$(/fpput %{fppointer} %{fplword} %{fpneu})%; \
  /fpinput

/def -i fpunt = \
  /if (fppointer>0) \
    /set fpanfang=1%; \
    /test kbgoto(0)%;\
    /let fpline=$[kbtail()]%;\
    /let fpakt2=$[substr(fpline,$[strrchr(fpline," ")+1])]%;\
    /if ( fpakt=~fpakt2 ) \
      /set fpneu=$(/fprem %{fppointer} %{fpneu})%; \
      /set fpanzahl=$[fpanzahl-1]%; \
      /set fpaktp=$[fppointer]%; \
      /set fpalt=$[strcat( %{fpalt}, " ", %{fpakt})]%;\
      /set fplword=%{fpakt}%;\
    /else \
      /set fpalt=$[strcat( %{fpalt}, " ", %{fpakt2})]%;\
      /set fplword=%{fpakt2}%;\
    /endif%;\
    /echo %fpline%; \
    %fpline%;\
  /endif  
  
/def -i fp2nie = \
  /set fpnie=$[strcat( %{fpnie}, " ", %{fpakt})]%;\
  /fpnunt

/def -i fpnunt = \
  /set fpalt=$[strcat( %{fpalt}, " ", %{fpakt})]%;\
  /set fpneu=$(/fprem %{fppointer} %{fpneu})%; \
  /set fpanzahl=$[fpanzahl-1]%; \
  /if (fppointer=$[fpanzahl+1]) \
    /set fppointer=$[fpanzahl]%;\
  /endif%;\
  /fpinput%; \

/def -i fpsave = \
  /echo fpnie gespeichert in $[{#}?{1}:'nieunt']%;\
  /sys echo %{fpnie} > $[{#}?{1}:'nieunt'] 

/def -i fpload = \
  /echo fpnie geladen aus $[{#}?{1}:'nieunt']%;\
  /set fpnie=$(/quote -decho -S '$[{#}?{1}:'nieunt'])

;stack queue array functions

; zeigt die einzelnen Woerter einer Queue numeriert an
/def -i fpshow = \
  /eval /eval /set fpdummy=%%{%{1}}%; \
  /let fpcounter=1%; \
  /let fpout=%; \
  /let fphlp=$(/fpget %{fpcounter} %{fpdummy})%; \
  /while ( {fphlp} !~ '' ) \
    /if ( (strlen(fpout)+strlen(fphlp)+3) > 79 ) \
      /echo %fpout%; \
      /let fpout=%; \
    /endif%; \
    /let fpout=$[strcat(fpout,' ',fpcounter,' ',fphlp)]%;\
    /let fpcounter=$[fpcounter+1]%; \
    /let fphlp=$(/fpget %{fpcounter} %{fpdummy})%; \
  /done%;\
  /if ( {fpout} !~ '' ) \
    /echo %fpout%; \
  /endif%; \
  /unset fpdummy

; ausgabe des i-ten wortes
/def -i fpget = \
  /eval /echo %%{$[{1}+1]}

; schreibt das Wort an die i-te Position des Queues
/def -i fpput = \
  /let argc1=%{1}%;\
  /let argc2=%{2}%;\
  /shift%;\
  /shift%;\
  /eval /echo %%{-L$[{#}-{argc1}+1]} %{argc2} %%{-$[{argc1}-1]}

; ausgabe ohne das i-te wort
/def -i fprem = \
  /let argc1=%{1}%;\
  /shift%;\
  /eval /echo %%{-L$[{#}-{argc1}+1]} %%{-%{argc1}}


; Start, das einzige Kommando welches von der Kommandozeilen aufgerufen
; werden sollte
/def -i fps = \
  /if ( ( fpstatus==2 ) & ( {#} ) ) \
    /set fpstatus=1%;\
  /endif%;\
  /fpinit%;\
  /if ( ( "-f" =~ {1} ) & ( {#} > 2 ) ) \
    /set fppverb=2%;\
    /eval /set fpnpc=%{2}%;\
    /set fpaktion=frage %{fpnpc} nach%;\
    /if ( {#}=3 ) \
      /set fpalt=%{2} %{3}%;\
      frage %{fpnpc} nach %{3}%;\
    /else \
      /set fpalt=%{2}%;\
      /set fpneu=%{-2}%; \
      /set fpanzahl=$[fpanzahl+{#}-2]%; \
      /fpinput%;\
    /endif%;\
  /elseif ( ( {1} !~ "-f" ) & ( fpstatus != 2 ) ) \
    /if ( {#}=0 ) \
      schau%;\
    /elseif ( {#}=1 ) \
      /set fpalt=%{1}%; \
      /set fpanzahl=0%; \
      unt %{1}%;\
    /else \
      /set fpneu=%{*}%; \
      /set fpanzahl=$[fpanzahl+{#}]%; \
      /fpinput%;\
    /endif%;\
  /endif  

; ersetzt @ durch <space>
; -r -v Variabel
; -e no echo
; -r repl Variabel
/def fprsp = \
  /while ( {#}>1 ) \
    /if ( {1} =~ "-e" ) /let flagecho=1%; /endif%;\
    /if ( {1} =~ "-r" ) /let flagrepl=1%; /endif%;\
    /if ( {1} =~ "-v" ) /let flagvar=1%; /endif%;\
    /shift%;\
  /done%;\
  /if ( flagvar | flagrepl ) \
    /let fpdummy=$(/eval /echo %%{%{1}})%; \
  /else%;\
    /let fpdummy=%1%;\
  /endif%;\
  /let fpind=0%;\
  /while ( (fpind:=$[strchr(fpdummy,"@")]) != -1 ) \
    /let fpdummy=$[strcat($[substr(fpdummy,0,fpind)]," ",$[substr(fpdummy,$[fpind+1])])]%;\
  /done%;\
  /if ( !flagecho ) /echo %fpdummy%; /endif%;\
  /if ( flagrepl ) /eval /set %1=%fpdummy%; /endif

; sucht die grossgeschriebenen Woerter heraus, die nicht am Satzanfang
; stehen und weder in  fpalt  noch  fpnie  enhalten sind, und reiht sie
; ab der Posisition des geraden untersuchten Wortes ein, welches bereits
; geloescht wurde, am Zeilenende durch Bindestrich getrennte Woerter wer-
; den wieder zusammengefuegt, fuehrendes ( oder nach folgende ,;!:?) wer-
; den entfernt
/def -i fpt = \
  /while ( {#}>0 ) \
    /if ( ( (ascii({1}) >= ascii('A')) & (ascii({1}) <= ascii('Z')) \
          & (fpanfang=0) ) | fptrennung | (ascii({1})=ascii('(')) ) \
       /if ( ({#}=1) & (strrchr({1},'-')+1)=strlen({1}) ) \
          /set fptrennung=1%;\
          /set fpfst=$[substr({1},0,strlen({1})-1)]%;\
       /else \
         /if (fptrennung) \
           /set fptrennung=0%; \
           /set fpwort=$[tolower(strcat(fpfst,{1}))]%;\
         /else \
           /set fpwort=$[tolower({1})]%; \
         /endif%; \
	 /let fpcutpost=$[strchr({fpwort},'.;?!,:)')]%; \
         /if ( fpcutpost != -1 ) \
           /set fpwort=$[substr(fpwort,0,fpcutpost)]%;\
         /endif%; \
	 /if ( ascii(fpwort)=ascii('(') )  \
	   /set fpwort=$[substr(fpwort,1)]%; \
	 /endif%; \
         /if (strstr($[strcat(' ',fpalt,' ',fpneu,' ',fpnie,' ')],$[strcat(' ',fpwort,' ')])=-1) \
           /set fpneu=$( /fpput %{fpaktp} %{fpwort} %{fpneu} )%; \
           /set fpanzahl=$[fpanzahl+1]%; \
	   /set fpaktp=$[fpaktp+1]%; \
         /endif%; \
      /endif%;\
    /endif%;\
    /if ( strchr(%{1},'.?!:') = -1 ) \
      /set fpanfang=0%; \
    /else \
      /set fpanfang=1%; \
    /endif%; \
    /shift%; \
  /done
