#define HOME(x) "/d/wasser/angrox/insel/"+x
#define CLONEME(x) clone_object(x)->move(ME)
#define XX(x) if (!is_clone(this_object())) return   
#define CLONEOB(x) clone_object(x)
#define OBJ(x) HOME("obj/")+x
#define NPC(x) HOME("npc/")+x
#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()));
#define CAP_TPN capitalize(this_player()->name())
#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPossPronoun()
#define TK(x) if(find_player("angrox"))tell_object(find_player("angrox"),x)

#define PlayerAlign this_player()->QueryProp(P_ALIGN)
#define PlayerGender this_player()->QueryProp(P_GENDER)
#define CAP(x) capitalize(x)
#define UPPER capitalize
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )
#define ROOM(x) HOME("room/")+x
#define INSEL(x) HOME("room/")+x

#define LOGFILE "angrox/alrik.log"
