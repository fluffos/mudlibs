/*
** FILE:    _glist.c
** PURPOSE: Returns a list of all active gangs, their leaders, and 
**          number of members.
** CREDITS:
**    2/9/2000  Cyanide created the file.
*/

#include <daemons.h>

inherit DAEMON;

int cmd_glist() {
    mapping glist, gmembers;
    int i, sz;
    string *gnames;

    glist = GANG_D->get_list_map();
    gmembers = GANG_D->get_members_map();

    gnames = keys(glist);

    sz = sizeof(glist);

    write(sprintf("%|63s\n", "-----------{ Active Gangs }-----------"));
    write(sprintf("%|28s%|20s%|15s\n", "Gang Name", "Leader",
	"Num of Members"));

    for(i = 0; i < sz; i++)
	write(sprintf("%|28s%|20s%|15d\n", cap_all_words(gnames[i]),
	    capitalize(glist[gnames[i]]), (int)gmembers[gnames[i]] ) );

    return 1;
}

/* EOF */
