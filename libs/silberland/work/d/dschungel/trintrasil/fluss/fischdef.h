
//oooooooooooooooooooooooo FISCHRUF ooooooooooooooooooooooooooooooooooooooooooooo


#define PFEIFE AddCmd(({"rufe","pfeife","locke"}), "func_fischruf");



//-------------------------- fischruffunktion -----------------------------------


#define FLUSSFISCHRUF int func_fischruf(string str) { \
  object pfeife; \
  pfeife=present("fischpfeife", TP); \
  notify_fail("Mit was willst Du pfeifen?\n"); \
\
  if(str=="mit pfeife"||str=="mit fischpfeife"||str=="nach fisch mit pfeife"||\
     str=="pfeife"||str=="fischpfeife"||str=="fisch"||str=="nach fisch"||\
     str=="fisch mit pfeife"||str=="nach fischen mit pfeife"||\
     str=="nach fischen"||str=="fische mit pfeife"||str=="nach fischen"||\
     str=="fische"||str=="fisch an"||str=="fische an"||\
     str=="fisch mit pfeife an"||str=="fische mit pfeife an"||\
     str=="mit fischpfeife an"||str=="fisch mit fischpfeife an"||\
     str=="fische mit fischpfeife an"||str=="fisch herbei") {\
\
     	if( find_call_out("fisch")!=-1 || find_call_out("fisch1")!=-1 ) {\
\
     		write(BSL("\nJaja, die Fische werden schon kommen.\n"));\
     		return 1;\
     	}\
\
     	if(!pfeife) {\
\
     		write(BSL("\nUm mit einer Fischpfeife einen Fisch zu rufen braucht man zu " \
                "allererst einmal eine FISCHPFEIFE!")); \
                return 1;\
        }\
\
        if((pfeife) && (!present("STDFISCH", TO))) {\
\
        	write(BSL("\nDu haeltst Deinen Kopf unter Wasser und blast mit aller Kraft " \
                "in die Pfeife. Du hoerst zwar absolut nichts, glaubst aber ein " \
                "unangenehmes Vibrieren zu spueren.")); \
                say(BS("\n"+TPN+" steckt seinen Kopf ins Wasser. Kurz Daruaf spuerst Du " \
                "ein leichtes, unangenehmes Vibrieren.")); \
                call_out("fisch", 3); \
                return 1;\
        }\
\
        if((pfeife) && (present("STDFISCH", TO))) {\
\
        	write(BSL("\nWarum willst Du schon wieder Fische herbei pfeifen wo doch "\
                "noch einer hier ist.")); \
                return 1;\
        }\
        return 0;\
      }\
      return 0;\
}




//---------------------fischcallouts---------------------------------------------


#define FLUSSFISCHCALLOUTS(x)  fisch() {\
\
    tell_room(this_object(), BSL("\nDas Wasser x geraet seltsam in Bewegung."));\
\
    call_out("fisch1", 3);\
}\
\
\
\
fisch1() {\
\
    object fisch;\
\
    tell_room(this_object(), BSL("\nSprudelnd und spritzend tauchen ploetzlich einige sehr "\
    "grosse Fische auf.\n\n"));\
    fisch=CLONEOB("/d/dschungel/trintrasil/fluss/npc/stdfisch");\
    fisch->move(this_object(), M_TPORT);\
    fisch=CLONEOB("/d/dschungel/trintrasil/fluss/npc/stdfisch");\
    fisch->move(this_object(), M_TPORT);\
    fisch=CLONEOB("/d/dschungel/trintrasil/fluss/npc/stdfisch");\
    fisch->move(this_object(), M_TPORT);\
    call_out("fisch2", 2);\
}\
\
\
\
fisch2() {\
\
    tell_room(this_object(), BSL("\nDu koenntest auf den Ruecken eines der Fische klettern."));\
}

//-------------------------- auf den fisch klettern -----------------------------


#define REITEN AddCmd(({"klettere","kletter","steige","stieg"}), "func_reiten");\


#define FLUSSREITFUNC(x)   int func_reiten(string str) {\
\
    object fisch;\
    fisch=present("STDFISCH", TO);\
\
    notify_fail("Auf was willst Du klettern?\n");\
\
    if(str=="auf fisch"||str=="fisch"||str=="auf ruecken fisch"||\
       str=="auf ruecken"||str=="auf fischruecken"||str=="fischruecken")  {\
\
     if(fisch) {\
\
     	write(BSL("\nVorsichtig kletterst Du auf den Ruecken eines Fisches. Der Fisch "\
     	"scheint Dich ohne Probleme zu tragen."));\
        tell_room(this_object(), "\n");\
        this_player()->move("x", \
        M_GO,"auf den Ruecken eines Fisches und schwimmt auf den Fluss hinaus.", "klettert",\
        "klettert auf den Ruecken eines Fisches und schwimmt herein");\
        fisch->move("/d/dschungel/trintrasil/hoehle/room/kontrollraum-h", M_GO+\
        M_SILENT+ M_NO_SHOW);\
        fisch->remove();\
        return 1;\
     }\
\
\
     if(!fisch) {\
\
     	write(BSL("\nDa ist kein Fisch auf den Du klettern koenntest, den muesstest Du erst "\
     	"mit einer Fischpfeife pfeifen."));\
        return 1;\
     }\
\
     return 0;\
    }\
    return 0;\
}




