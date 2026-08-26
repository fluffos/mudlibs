/*
** FILE:    _glist.c
** PURPOSE: Returns a list of all active gangs, their leaders, and 
**          number of members.
** CREDITS:
**    2/9/2000  Cyanide created the file.
**
** TODO
**    Include invis and hp status.
*/

#include <daemons.h>

inherit DAEMON;

int cmd_gwho() {
    object *obs = users();
    int i, sz, count = 0;
    string mygang;

    mygang = TP->query("gang");

    if (!mygang) {
	write("You're not in a gang yet.\n");
	return 1;
    }

    write("Members of "+cap_all_words(mygang)+" currently logged in.\n");
    write("------------------------------------------------------\n");

    sz = sizeof(obs);
    for(i=0; i<sz; i++) {
	if (obs[i]->query("gang")==mygang) {
	    write(((string)(++count))+". "+obs[i]->query("cap_name"));

	    write("\n");
	}
    }

    return 1;
}

string help() {
    return wrap("This command shows a list of all the members of your "+
      "gang who are logged in at the moment.");
}

/* EOF */
