#include "/players/nylakoorub/guild/lib/defines/skills.h"

int check_level(int level) {
    if((int)this_player()->query_level() < level){
	write("You need to be at least level "+
	  level +
	  " to perform this.\n");
	return 1;
    }
    else
	return 0;
}
