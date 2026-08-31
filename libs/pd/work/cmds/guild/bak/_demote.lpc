//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;
int cmd_demote(string str) {
    string pos;
    object user;
    if(!this_player()->query_guild()) return 0;
    restore_object(SAVE+this_player()->query_guild());
    if(!str) return notify_fail("Demote who?\n");
    if(!GUILD_D->check_rights(this_player()->query_name(), 
	this_player()->query_guild(), ({ "leader" }) )) 
	return notify_fail("You are not permitted to do that.\n");
    pos = GUILD_D->query_position(lower_case(str), 
      this_player()->query_guild());
    if(pos == "none") return notify_fail("They are not part of your guild.\n");
    switch(pos) {
    case "main":
	write("You cannot demote that person.\n");
	break;
    case "squire": 
	write("They are at the lowest position possible.\n");
	break;
    case "member":
	member -= ({ lower_case(str) });
	if(!squire) squire = ({});
	squire += ({ lower_case(str) });
	write("You demote "+capitalize(str)+" to Squire.\n");
	if(user = find_player(lower_case(str))) tell_object(user, "You "
	      "have been demoted to Squire.");
	write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
	  " : (demote) "+lower_case(str)+" in "+this_player()->query_guild()+
	  " (Squire)\n");
	break;
    case "council":
	council -= ({ lower_case(str) });
	member += ({ lower_case(str) });
	write("You demote "+capitalize(str)+" to Member.\n");
	if(user = find_player(lower_case(str))) tell_object(user, "You "
	      "have been demoted to Member.");
	write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
	  " : (demote) "+lower_case(str)+" in "+this_player()->query_guild()+
	  " (member)\n");
	break;
    case "leader":

	leader -= ({ lower_case(str) });
	council += ({ lower_case(str) });
	write("You demote "+capitalize(str)+" to Council.\n");
	if(user = find_player(lower_case(str))) tell_object(user, "You "
	      "have been demoted to Council.");
	write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
	  " : (demote) "+lower_case(str)+" in "+this_player()->query_guild()+
	  " (council)\n");
	break;
    }
    save_object(SAVE+this_player()->query_guild());
    return 1;
}
void help() {
    write(@TEXT
Syntax: <demote [member]>
Usage:  This will demote a member to a lower rank in your guild.
Position: leader
TEXT);
}

