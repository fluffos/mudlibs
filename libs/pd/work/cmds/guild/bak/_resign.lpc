//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;
int cmd_resign() {
    if(!this_player()->query_guild()) return 0;
    restore_object(SAVE+this_player()->query_guild());
    if(this_player()->query_guild_position() == "main") {
	write("You are not allowed to resign.\n");
	return 1;
    }
    squire -= ({ this_player()->query_name() });
    member -= ({ this_player()->query_name() });
    council -= ({ this_player()->query_name() });
    leader -= ({ this_player()->query_name() });
    write("You resign from your guild.\n");
    save_object(SAVE+this_player()->query_guild());
    write_file("/d/guilds/progress.log", 
      this_player()->query_cap_name()+" : (resign) "+
      this_player()->query_guild()+"\n");
    this_player()->set_guild();
    return 1;
}
void help() {
    write(@TEXT
Syntax: <resign>
Usage:  This will remove you from your guild.
Position: member, council, leader
TEXT);
}

