//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;
int cmd_reject(string str) {
    object user;
    if(!this_player()->query_guild()) return 0;
    restore_object(SAVE+this_player()->query_guild());
    if(!str) return notify_fail("Reject who?\n");
    if(!GUILD_D->check_rights(this_player()->query_name(), 
	this_player()->query_guild(), ({ "leader", "council" }) )) 
	return notify_fail("You are not permitted to do that.\n");
    if(!user = find_player(lower_case(str))) {
	if(!user_exists(lower_case(str))) {
            squire -= ({ lower_case(str) });
	    member -= ({ lower_case(str) });
	    council -= ({ lower_case(str) });
	    leader -= ({ lower_case(str) });
	    write("That name has been removed from your rosters.\n");
	    save_object(SAVE+this_player()->query_guild());
	    return 1;
	}
	write("No such player online.\n");
	return 1;
    }
    if(user->query_guild() != this_player()->query_guild()) return 
	notify_fail("You may only reject those that are in your guild.\n");
    if(this_player()->query_position() == "council") {
	if(user->query_guild_position() == "council" || 
	  this_player()->query_position() == "leader") return 
	    notify_fail("You may only reject those with a lower position than "
	      "yours.\n");
	write("You reject "+user->query_cap_name()+" from your guild.\n");
	tell_object(user, "You have been rejected from your guild.\n");
        squire -= ({ user->query_name() });
	member -= ({ user->query_name() });
	council -= ({ user->query_name() });
	leader -= ({ user->query_name() });
	user->set_guild();
	save_object(SAVE+this_player()->query_guild());
	write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
	  " : (reject) "+user->query_cap_name()+" from "+
	  this_player()->query_guild()+".\n");
	return 1;
    }
    if(member_array(user->query_name(), MAIN) != -1) return 
	notify_fail("You may not remove the owner of the guild.\n");
    write("You reject "+user->query_cap_name()+" from your guild.\n");
    tell_object(user, "You have been rejected from your guild.\n");
    squire -= ({ user->query_name() });
    member -= ({ user->query_name() });
    council -= ({ user->query_name() });
    leader -= ({ user->query_name() });
    user->set_guild();
    save_object(SAVE+this_player()->query_guild());
    write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
      " : (reject) "+user->query_cap_name()+" from "+
      this_player()->query_guild()+".\n");
    return 1;
}
void help() {
    write(@TEXT
Syntax: <reject [member]>
Usage:  This will remove a member from your guild.
Position: council, leader
TEXT);
}

