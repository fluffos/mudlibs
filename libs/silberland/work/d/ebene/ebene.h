
#ifndef __EBENE_H__
#define __EBENE_H__

#include "/d/domains.h"

//#define EBENE(x) "/d/ebene/"+x
#define MIDAS(x) "/d/ebene/Midas/"+x
#define PARK(x) "/d/ebene/Park/"+x
#define SILBERWALD(x) "/d/ebene/Silberwald/"+x

#define OBJ(x) "/d/ebene/obj/"+x
#define WOODY(x) "/players/woody/"+x

#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()));
#define CLONEME(x) clone_object(x)->move(this_object());
#define CLONEOB(x) clone_object(x)
#define CLONE(x,y) clone_object(x)->move(y);

#define LOGFILE "/players/woody/log/woody.log"
#define LOGF LOGFILE

// #define WLOG(x) write_file(LOGF,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
// #define WLOG(x) write("");
// #define FLOG(y,x) write_file(y,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));

#define AppendProp(x,y) SetProp(x,QueryProp(x)+y)

#define TI this_interactive()
#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define CAP_TPN capitalize(this_player()->name())
#define TO this_object()
#define TPP TP->QueryPronoun
#define TPPP TP->QueryPossPronoun
#define TD(x) if(find_player("debugger"))tell_object(find_player("debugger"),x)
#define TK(x) if(find_player("woody"))tell_object(find_player("woody"),x)
#define TW(x) if(find_player("woody"))tell_object(find_player("woody"),x)

#define UPPER capitalize
#ifndef CAP
#define CAP capitalize
#endif
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )

#endif /* __EBENE_H__ */
