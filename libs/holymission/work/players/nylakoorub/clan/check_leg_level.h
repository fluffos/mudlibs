#include "/players/nylakoorub/guild/lib/defines/skills.h"

int check_leg_level(int leg_level) {
    if((int)this_player()->query_legend_level() < leg_level) {
	write("You need to be at least legend level "+
	  leg_level +
	  " to perform this.\n");
	return 1;
    }
    else
	return 0;
}
