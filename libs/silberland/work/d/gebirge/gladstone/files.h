#define HOME(x) "/players/gladstone/"+x
#define ROOM(x) HOME("room/")+x
#define OBJ(x) HOME("obj/")+x
#define NPC(x) HOME("npc/")+x

#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()))
#define CLONEME(x) clone_object(x)->move(this_object())
#define PlayerAlign this_player()->QueryProp(P_ALIGN)
#define PlayerGender this_player()->QueryProp(P_GENDER)
#define XX(x) if (!is_clone(this_object())) return
#define CLONEOB(x) clone_object(x)
#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPossPronoun()

#define UPPER capitalize
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )
#define bool int
#define TRUE 1
#define FALSE 0
#define ES 0
#define SIE 2

#define PO  previous_object()
#define QP QueryProp
