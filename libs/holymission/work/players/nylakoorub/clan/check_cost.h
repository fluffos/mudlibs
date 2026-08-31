#include "/players/nylakoorub/guild/lib/defines/skills.h"

int check_cost(int sp) {
    if((int)this_player()->query_sp() < sp){
	write("You need to have at least "+
	  sp +
	  " spell points to cast.\n");
	return 1;
    }
    else
	return 0;
}
