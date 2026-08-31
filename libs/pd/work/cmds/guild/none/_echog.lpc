//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>

int cmd_echog(string str) {
    int i;

    if(!str) return notify_fail("Syntax: <echog [string]>\n");
    if(!GUILD_D->valid_master(this_player()->query_name())) return
	notify_fail("You are not allowed to use a Guild Master command.\n");
    i=sizeof(VALID_GUILDS);
    while(i--) {
	CHAT_D->do_raw_chat(VALID_GUILDS[i], this_player()->query_cap_name()+
	  " <"+VALID_GUILDS[i]+"> "+str);
    }
    return 1;
}

void help() {
    write(@TEXT
Syntax: <echog [string]>
Usage:  This will display [string] to all the guilds 
online though the chat daemon.
TEXT);
}

