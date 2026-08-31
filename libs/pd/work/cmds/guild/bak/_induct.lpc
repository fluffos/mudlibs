//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;
int cmd_induct(string str) {
    string err;
    object user;
    restore_object(SAVE+this_player()->query_guild());
    if(!squire) squire = ({});
    if(!member) member = ({});
    if(!council) council = ({});
    if(!leader) leader = ({});
    err = "";
    if(!this_player()->query_guild()) return 0;
    if(!GUILD_D->check_rights( this_player()->query_name(), 
	this_player()->query_guild(), ({ "leader", "council" }) )) 
	return notify_fail("You are not permitted to do that.\n");
    if(!str) return notify_fail("Induct who?\n");
    if(!user = find_player(str = lower_case(str))) return notify_fail("No "
	  "such user online.\n");
    if(user->query_guild()) return notify_fail("You may only induct those "
	  "without guild affiliation.\n");
    write("You induct "+user->query_cap_name()+" into your guild.\n");
    tell_object(user, "You have been inducted into "+
      this_player()->query_guild()+".");
    err += "Starting object check...   ";
    if(member_array(user->query_name(), squire) != -1) {
	err += "Name is already listed as squire.  Removing.\n";
	member -= ({ user->query_name() });
    }
    if(member_array(user->query_name(), member) != -1) {
	err += "Name is already listed as member.  Removing.\n";
	member -= ({ user->query_name() });
    }
    if(member_array(user->query_name(), council) != -1) {
	err += "Name is already listed as council.  Removing.";
	council -= ({ user->query_name() });
    }
    if(member_array(user->query_name(), leader) != -1) {
	err += "Name is already listed as leader.  Removing.";
	leader -= ({ user->query_name() });
    }
    squire += ({ user->query_name() });
    user->set_guild(this_player()->query_guild());
    user->register_channels();
    if(member_array(user->query_name(), squire) == -1) {
	err += "Checking for member array writae...  Error.\n";
	write("Writing progress:\n");
	write(err+"\nThis is an unknown error.  This report has been "
	  "documented.\n");
	tell_object(user, "Error in guild system.  Canceling initiation.");
	user->set_guild();
	write_file("/d/guilds/error", err+"\n");
	return 1;
    }
    save_object(SAVE+this_player()->query_guild());
    write_file("/d/guilds/progress.log", this_player()->query_cap_name()+
      " : (induct) "                        +user->query_cap_name()+" in "+
      this_player()->query_guild()+".\n");
    return 1;
}

void help() {
    write(@TEXT
Syntax: <induct [player]>

Usage:  This will induct a person into your guild.
Position: council, leader
TEXT);
}

