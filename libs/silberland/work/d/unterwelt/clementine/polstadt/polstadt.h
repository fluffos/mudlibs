
#pragma strong_types
#define GEBIET "polstadt"
#include "../def.h" 

#define WRITELOG(x) write_file(LOG("polstadt.log"),ctime()+":"+x+".\n")
#define CTPN capitalize(this_player()->name())
#define WLOG(f,x) write_file(f,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));



