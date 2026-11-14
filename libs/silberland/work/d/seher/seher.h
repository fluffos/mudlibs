
#include "../domains.h"

#define OBJ(x) "/d/seher/obj/"+x

#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()))
#define CLONEME(x) clone_object(x)->move(this_object())
#define CLONEOB(x) clone_object(x)
#define CLONE(x,y) clone_object(x)->move(y, M_NOCHECK)

#define TI this_interactive()
#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define CAP_TPN capitalize(this_player()->name())
#define TO this_object()
#define PO previous_object()
#define TPP TP->QueryPronoun
#define TPPP TP->QueryPossPronoun
#define TW(x) if(find_player("woody"))tell_object(find_player("woody"),x)

#define UPPER capitalize
#ifndef CAP
#define CAP capitalize
#endif
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )

