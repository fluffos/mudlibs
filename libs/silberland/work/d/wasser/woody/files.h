
#include "/d/domains.h"

#define SILBERWALD(x) EBENE("Silberwald/"+x)
#define FISCHERDORF(x) WASSER("woody/fischerdorf/"+x)
#define PIER(x) WASSER("room/pier/"+x)
#define OBJ(x) WASSER("woody/obj/"+x)

#define TI this_interactive()
#define TP this_player()
#define TPP TP->QueryPronoun
#define TPPP TP->QueryPossPronoun
#define PL this_player()
#define TPN this_player()->name()
#define CAP_TPN capitalize(this_player()->name())
#define TO this_object()
#define PO previous_object()
#define TD(x) if(find_player("debugger"))tell_object(find_player("debugger"),x)
#define TK(x) if(find_player("woody"))tell_object(find_player("woody"),x)
#define TW(x) if(find_player("woody"))tell_object(find_player("woody"),x)

#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define TPENV environment(this_player())
#define SUID seteuid(getuid(this_object()));
#define CLONEME(x) clone_object(x)->move(this_object());
#define CLONEOB(x) clone_object(x)
#define CLONETPNOCHK(x) clone_object(x)->move(TP, M_NOCHECK);
#define CLONETP(x,ob) if ((ob=clone_object(x))->move(TP, M_GET) != 1) \
                         ob->move(TPENV, M_NOCHECK);
#define CLONE(x,y) clone_object(x)->move(y);

#define LOGFILE "/players/woody/log/woody.log"
#define LOGF LOGFILE

#define UPPER capitalize
#ifndef CAP
#define CAP capitalize
#endif
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )

