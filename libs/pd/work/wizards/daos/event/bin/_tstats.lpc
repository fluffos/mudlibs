#include <std.h>
#include <security.h>

inherit DAEMON;

mapping players;

int cmd_tstats(string str) {
    string *users;
    int i;

    if(!players) players = ([]);

    if(!str) {
	users = keys(players);
	i = sizeof(users);
	while(i--) {
	    write ( capitalize(users[i] + " : " + players[users[i]] + "") );
	}
    }

    else {
	if(!find_player(str)) 
	    return notify_fail("player not found\n");
	else if(!players[str]) 
	    players[str] = 1;
	else
	    players[str]++;
	write("+1 ("+str+")\n");
    }
    seteuid(UID_CRESAVE);
    save_object("/wizards/daos/save/trivia");
    seteuid(geteuid());
    return 1;
}
