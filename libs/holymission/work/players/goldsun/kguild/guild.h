/*  common funcs/commands  */
/* #include "/players/whisky/genesis/sys/filter_live.h"*/
#include "/players/whisky/genesis/sys/break_string.h" 
#define BS(x) break_string(x+"\n",65); 
#define TP this_player()
#define CP(x) capitalize(x)
#define OPN CP(TP->query_name())
#define PATH "/players/goldsun"
#define TO this_object()

