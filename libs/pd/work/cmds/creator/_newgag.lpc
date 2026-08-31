// Made by Inferno to silence people
#include <std.h>
#include <daemons.h>
inherit DAEMON;

int ip_address(string s) {
	if(sscanf(s, "%d.%d.%d.%d") > 2) return 1;
	return 0;
}

int cmd_newgag(string str) {
    object ob;
    string ip;

    if(!str) {
	notify_fail("Gag what?\n");
	return 0;
    }
    ob = find_living(str);
    if (!ob && !ip_address(str)) {
	notify_fail("Could not find: "+str+"!");
	return 0;
    }
    if(ob) ip = query_ip_number(ob);
	else ip = str;
    if(!wizardp(this_player())) {
	notify_fail("You are not permitted to do that.\n");
	return 0;
    }
    if (GAG_D->gagged(ip)) {
	notify_fail("It is already so.");
	return 0;
    }
    if(ob)
	new("/std/obj/gag")->move(ob);
    GAG_D->add_gag(ip);
    write("Player and IP range gagged.\n");
    return 1;
}

void help() {
    write("Syntax: <gag [options] [player]>\n\nGags a player from using communication commands.  This command was modified to "
	"use a daemon to gag IPs instead of just one character and to have a gag expire on at a certain time.");
}
