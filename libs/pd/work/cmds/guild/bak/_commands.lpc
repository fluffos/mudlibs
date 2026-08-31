//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;
int cmd_commands(string str) {
    string pos, pos2, out;
    if(!this_player()->query_guild()) return 0;
    pos = this_player()->query_guild_position();
    switch(pos) {
    case "main":
	out = "The following guild commands are availible for you:\n";
	out += "%^BOLD%^%^BLUE%^Induct %^RESET%^ : "
	"Inducts a player into your guild.\n";
	out += "%^BOLD%^%^BLUE%^Reject%^RESET%^  : "
	"Removes a player from your guild.\n";
	out += "%^BOLD%^%^BLUE%^Promote%^RESET%^ : "
	"Promotes a members to a higher position.\n";
	out += "%^BOLD%^%^BLUE%^Demote%^RESET%^  : "
	"Demotes a member to a lower position.\n";
	out += "%^BOLD%^%^BLUE%^Members%^RESET%^ : "
	"Shows a list of current members.\n";
	pos2 = capitalize(this_player()->query_guild_position());
	if(pos2 == "main") pos2 = "Leader";
	out += "You also have access to the Guild Treasury.\n"
	"Your position is: "+pos2;
	write(out);
	break;
    case "leader":
	out = "The following guild commands are availible for you:\n";
	out += "%^BOLD%^%^BLUE%^Induct %^RESET%^ : "
	"Inducts a player into your guild.\n";
	out += "%^BOLD%^%^BLUE%^Reject%^RESET%^  : "
	"Removes a player from your guild.\n";
	out += "%^BOLD%^%^BLUE%^Promote%^RESET%^ : "
	"Promotes a members to a higher position.\n";
	out += "%^BOLD%^%^BLUE%^Demote%^RESET%^  : "
	"Demotes a member to a lower position.\n";
	out += "%^BOLD%^%^BLUE%^Members%^RESET%^ : "
	"Shows a list of current members.\n";
	pos2 = capitalize(this_player()->query_guild_position());
	out += "You also have access to the Guild Treasury.\n"
	"Your position is: "+pos2;
	write(out);
	break;
    case "council":
	out = "The following guild commands are availible for you:\n";
	out += "%^BOLD%^%^BLUE%^Induct %^RESET%^ : "
	"Inducts a player into your guild.\n";
	out += "%^BOLD%^%^BLUE%^Reject%^RESET%^  : "
	"Removes a player from your guild.\n";
	out += "%^BOLD%^%^BLUE%^Promote%^RESET%^ : "
	"Promotes a members to a higher position.\n";
	out += "%^BOLD%^%^BLUE%^Demote%^RESET%^  : "
	"Demotes a member to a lower position.\n";
	out += "%^BOLD%^%^BLUE%^Members%^RESET%^ : "
	"Shows a list of current members.\n";
	pos2 = capitalize(this_player()->query_guild_position());
	out += "Your position is: "+pos2;
	write(out);
	break;

    case "member":
    case "squire":
	out = "The following guild commands are availible for you:\n";
	out += "%^BOLD%^%^BLUE%^Members%^RESET%^ : "
	"Shows a list of current members.\n";
	out += "Your position is: "+
	capitalize(this_player()->query_guild_position());
	write(out);
	break;
    case "none":
	if(wizardp(this_player())) {
	    out = "The following guild commands are availible for you:\n";
	    out += "%^BOLD%^%^BLUE%^Induct %^RESET%^ : "
	    "Inducts a player into your guild.\n";
	    out += "%^BOLD%^%^BLUE%^Reject%^RESET%^  : "
	    "Removes a player from your guild.\n";
	    out += "%^BOLD%^%^BLUE%^Promote%^RESET%^ : "
	    "Promotes a members to a higher position.\n";
	    out += "%^BOLD%^%^BLUE%^Demote%^RESET%^  : "
	    "Demotes a member to a lower position.\n";
	    out += "%^BOLD%^%^BLUE%^Members%^RESET%^ : "
	    "Shows a list of current members.\n";
	    if(this_player()->query_cap_name() == "Whit") 
		pos2 = "Guild Master";
	    else pos2 = "Wizard";
	    out += "You also have access to the Guild Treasury.\n"
	    "Your position is: "+pos2+"";
	    write(out);
	    break;
	}
	write("You have no position in your guild.  Please bug this.\n");
	break;
    }
    return 1;
}
void help() {
    write(@TEXT
Syntax: <commands>
Usage:  This will show you a list of guild commands availible to you.
Position: member, council, leader
TEXT);
}

