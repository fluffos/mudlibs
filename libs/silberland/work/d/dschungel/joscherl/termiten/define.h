#define HOME(x) "/players/joscherl/"+x
#define DSCHUNGEL(x) "/d/dschungel/old/"+x
#define MYDSCHUNGEL(x) DSCHUNGEL("joscherl/")+x
#define TERMITEN(x) MYDSCHUNGEL("termiten/")+x
#define ROOM(x) TERMITEN("room/")+x
#define OBJ(x) TERMITEN("obj/")+x
#define NPC(x) TERMITEN("npc/")+x
#define LOG(x) TERMITEN("log/")+x
#define CHECK(x) tell_object(find_living("joscherl"), x)
#define ABS(x) (x<0?-x:x)

#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()))
#define CLONEME(x) clone_object(x)->move(this_object())
#define CLONEPL(x) clone_object(x)->move(this_player())
#define PlayerAlign this_player()->QueryProp(P_ALIGN)
#define PlayerGender this_player()->QueryProp(P_GENDER)
#define XX(x) if (!is_clone(this_object())) return
#define CLONEOB(x) clone_object(x)
#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPossPronoun()
#define TI this_interactive()
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
