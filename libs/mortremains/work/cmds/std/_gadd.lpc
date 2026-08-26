/*
** FILE:    _gadd.c
** PURPOSE: Adds a player to your gang.
** CREDITS:
**   10 Feb 2000   Cyanide created the file.
*/

#include <messages.h>
#include <daemons.h>
#include <gangs.h>

inherit DAEMON;

int cmd_gadd(string str) {
    object ob, *obs;
    mapping map;
    int sz, i;

    if (!str) {
	write("Add who to your gang?\n");
	return 1;
    }

    ob = present(str, environment(TP));

    if (!ob || !userp(ob)) {
	write(capitalize(str)+" is not a player in the room with you.\n");
	return 1;
    }

    if (wizardp(TP) && !wizardp(ob)) {
	write("Immortal leaders cannot have mortals in their gangs!\n");
	return 1;
    }

    if (ob->query("gang")) {
	write(ob->query("cap_name")+" is already in a gang!\n");
	return 1;
    }

    map = GANG_D->get_list_map();
    if (map[TP->query("gang")] != TP->query("name") ) {
	write("You aren't the leader of that gang!\n");
	return 1;
    }

    if (!ob->query("gangallow")) {
	write(wrap(ob->query("cap_name")+" has not indicated "+
	    subjective(ob->query("gender"))+" is allowed to be added "+
	    "to a gang."));
	return 1;
    }

    str = TP->query("gang");
    i = GANG_D->add_member( str );

    switch(i) {
    case TOO_MANY_MEMBERS :
	write("Gangs may only have "+MAX_MEMBERS+" members.\n"); break;
    case NO_SUCH_GANG :
	write("Gang daemon responded: No such gang! Tell an admin!\n");
	break;
    }

    if (i != 1) return 1;

    tell_object(ob, "You have been added to "+cap_all_words(str)+"!\n");
    tell_object(TP, ob->query("cap_name")+" has accepted your offer!\n");

    ob->set("gang", str);
    ob->delete("gangallow");

    obs = users();
    sz = sizeof(obs);

    for (i=0; i<sz; i++) {    
	if (!obs[i]->query("channels/gchat")) continue;

	if ( (string)obs[i]->query("gang") == str)
	    message(MSG_CHANNEL, iwrap("[Gangchat] "+
		ob->query("cap_name")+ " has just joined "+cap_all_words(str)+
		"!"), obs[i], ({}) );
    } 

    return 1;
}

string help() {
    return(@EndHelp
Usage: gadd <player>

This command allows the leader of a gang to invite other player to join
his gang.
EndHelp
    );
}

/* EOF */
