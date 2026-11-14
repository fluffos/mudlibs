#pragma strong_types
#define GEBIET "koerperflicker"
#include "../def.h"

#define CTPN capitalize(this_player()->name())
#define MAGIERNAME "clementine"
#define REGION "dschungel"

#define ME this_object()
#define BS(x) break_string(x, 78)
#define WLOG(f,x) write_file(f,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
#define TELLOTHERS say(this_player()->Name() +
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())
#define WRITELOG(x) write_file(LOG("koerperflicker.log"),ctime()+":"+x+".\n")
#define QUESTLOG "/d/dschungel/clementine/koerperflicker/log/"
#define QUESTITEM "\nkoerperflickerquest"
#define QUESTNAME "Freiheit fuer Baldi Amputant"
#define QUESTMEMO "\nQUESTMEMO"
