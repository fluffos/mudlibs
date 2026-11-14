
#pragma strong_types

#define GEBIET "weinberg"
#include "../def.h"
#include <moredef.h>
#define WRITELOG(x) write_file(LOG("weinberg.log"),ctime()+":"+x+".\n")
#define CTPN capitalize(this_player()->name())
#define ME this_object()
#define BS(x) break_string(x, 78)
#define WLOG(f,x) write_file(f,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));



