#define WEAPON "/d/dschungel/dante/stein/weapon/"
#define ARMOUR "/d/dschungel/dante/stein/armour/"
#define ROOM "/d/dschungel/dante/stein/room/"
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
#define LOGFILE "/players/dusty/log/dusty.log"

#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPossPronoun()
#define TK(x) if(find_player("angrox"))tell_object(find_player("angrox"),x)

#define UPPER capitalize
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )
#define bool int
#define TRUE 1
#define FALSE 0
#define ES 0
#define SIE 2
#define QUEST_STATS    present("jojoquest", TP);
#define NO_QUEST_STATS   "Du hast diese Quest nicht von Anfang angespielt!\n"

#define ER 1
 
#define ID "userid" 
 
 
