#define HOME(x) "/players/dante/"+x
#define XX(x) if (!is_clone(this_object())) return   
#define CLONEOB(x) clone_object(x)
#define OBJ(x) ("/players/dante")+x
#define NPC(x) ("/players/dante")+x
#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()))
#define CLONEME(x) clone_object(x)->move(this_object())
#define LOGFILE "/players/dante/log/dante.log"

#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPossPronoun()
#define TK(x) if(find_player("dante"))tell_object(find_player("dante"),x)


//fuer krake tantalus


#define KNO if(present("KTENT", environment(TP))) {write("Der Tentakel haelt Dich fest!\n"); return 1;}
            
           



#define CDN create_default_npc
#define SLN set_living_name


#define UPPER capitalize
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )
#define bool int
#define TRUE 1
#define FALSE 0
#define ES 0
#define SIE 2
#define ER 1

#define PO  previous_object()        
#define QP QueryProp 
 
#define TPM this_player()->move 
#define NF notify_fail
#define AD AddDetail
#define ASD AddSpecialDetail
#define ACD AddCmd
#define ARD AddReadDetail
#define BSA(x,y) break_string(x,78,y)       
#define SP SetProp
#define SC SetChats
#define SAC SetAttackChats
#define AI AddInfo
#define AIDI AddInfo(DEFAULT_INFO,  //beispiel AIDI({blabla}));
#define ASODS AddSound( DEFAULT_SOUND,
#define ASMDS   AddSmell( DEFAULT_SMELL,    
#define AIT AddItem
#define AE AddExit
#define ASE AddSpecialExit
#define CAP_TPN capitalize(this_player()->name())
#define CAP(x) capitalize(x)
