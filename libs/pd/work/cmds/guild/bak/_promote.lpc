//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;
int cmd_promote(string str) {
    string pos;
    object user;
    if(!this_player()->query_guild()) return 0;
    restore_object(SAVE+this_player()->query_guild());
    if(!str) return notify_fail("Promote who?\n");
    if(!GUILD_D->check_rights(this_player()->query_name(), 
	this_player()->query_guild(), ({ "leader" }) )) 
	return notify_fail("You are not permitted to do that.\n");
    pos = GUILD_D->query_position(lower_case(str), 
      this_player()->query_guild());
    if(pos == "none") return notify_fail("They are not part of your guild.\n");
    switch(pos) {
    case "main": 
	write("They are at the highest position possible.\n");
	break;
    case "leader":
	write("They are at the highest position possible.\n");
	break;
    case "council":
	council -= ({ lower_case(str) });
	leader += ({ lower_case(str) });
	write("You promote "+capitalize(str)+" to Leader.\n");
	if(user = find_player(lower_case(str))) tell_object(user, "You "
	      "have been promoted to Leader.");
	write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
	  " : (promote) "+lower_case(str)+" in "+this_player()->query_guild()+
	  " (leader)\n");
	break;
    case "member":
	member -= ({ lower_case(str) });
	council += ({ lower_case(str) });
	write("You promote "+capitalize(str)+" to Council.\n");
	if(user = find_player(lower_case(str))) tell_object(user, "You "
	      "have been promoted to Council.");
	write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
	  " : (promote) "+lower_case(str)+" in "+this_player()->query_guild()+
	  " (council)\n");
	break;
    case "squire":
	member += ({ lower_case(str) });
	squire -= ({ lower_case(str) });
	write("You promote "+capitalize(str)+" to Member.\n");
	if(user = find_player(lower_case(str))) tell_object(user, "You "
	      "have been promoted to Member.");
	write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
	  " : (promote) "+lower_case(str)+" in "+this_player()->query_guild()+
	  " (member)\n");
	break;
    }
    save_object(SAVE+this_player()->query_guild());
    return 1;
}
void help() {
    write(@TEXT
Syntax: <promote [member]>
Usage:  This will promote a member to a higher rank in your guild.
Position: leader
TEXT);
}

