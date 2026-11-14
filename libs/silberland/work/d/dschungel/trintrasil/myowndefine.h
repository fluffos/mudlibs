

//oooooooooooooooooo allgemeine Defines ooooooooooooooooooooooooooooooooooooooooo

#define CLONEOB(x) clone_object(x)
#define ENV(x) environment(x)
#define SUID seteuid(getuid(this_object()))
#define CLONEME(x) clone_object(x)->move(this_object())
#define LOGFILE "/players/dante/log/dante.log"

#define TP this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPossPronoun()

#define CASH(x) cash=CLONEOB("/obj/money"); cash->SetProp(P_AMOUNT, x); cash->move(ME);

#define SLN set_living_name

#define UPPER capitalize
#define LOWER lower_case

#define BS( x ) break_string( x, 78 )
#define BSL( x ) break_string( x, 78, 0, 1)
#define BSA(x,y) break_string(x,78,y)       
#define BSS(x,y) break_string(x,78,y,1)

#define PO  previous_object()        
 
#define TPM this_player()->move 
#define NF notify_fail
#define AD AddDetail
#define ASD AddSpecialDetail
#define ACD AddCmd
#define ARD AddReadDetail

#define SP SetProp
#define SC SetChats
#define SAC SetAttackChats
#define AI AddInfo
#define AIDI AddInfo(DEFAULT_INFO,  
#define ASODS AddSound( DEFAULT_SOUND,
#define ASMDS   AddSmell( DEFAULT_SMELL,    
#define AIT AddItem
#define AE AddExit
#define ASE AddSpecialExit
#define CAP_TPN capitalize(this_player()->name())
#define CAP(x) capitalize(x)

//sonstige:

#define TELLSD(x,y,z) tell_room("/d/dschungel/trintrasil/sdschungel/room/x", "\n");\
                      tell_room("/d/dschungel/trintrasil/sdschungel/room/x",\
                      break_string(y,78,z));\
                      tell_room("/d/dschungel/trintrasil/sdschungel/room/x", "\n");
#define TELLENV(x,y) tell_room(environment(this_object()), "\n");\
                     tell_room(environment(this_object()),\
                     break_string(x,78,y));\
                     tell_room(environment(this_object()), "\n");
#define NIX if(environment(TP)!=TO || !TP) return 0;
#define Z write("\n\n");
#define Z1 write("\n");
#define S say("\n\n");
#define S1 say("\n");	
#define H(x) tell_room("/d/dschungel/trintrasil/hoehle/room/x", "\n\n");
#define H1(x) tell_room("/d/dschungel/trintrasil/hoehle/room/x", "\n");
#define F(x) tell_room("/d/dschungel/trintrasil/fluss/room/x", "\n\n");
#define F1(x) tell_room("/d/dschungel/trintrasil/fluss/room/x", "\n");
#define SD(x) tell_room("/d/dschungel/trintrasil/sdschungel/room/x", "\n\n");
#define SD1(x) tell_room("/d/dschungel/trintrasil/sdschungel/room/x", "\n");


//define fuer details die die wschlange abfragen

#define WSCHLANGENABFRAGE(x,y)\
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                          x    \
                	return 1;\
                }\
\
                if(moveint==0) {\
                          y     \
                	return 1;\
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
                          y     \
		return 1;\
	}      