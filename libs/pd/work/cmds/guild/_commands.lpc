//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;
int cmd_commands(string str) {
    string pos, pos2, out;
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
	notify_fail(GUILD_D->query_lock_reason());

    if(!this_player()->query_guild()) return 0;

    pos = GUILD_D->query_actual_position(this_player()->query_name());

    switch(pos) {
    case "master":
    case "main":
	out = "Guild System v"+GUILD_VERSION+"\n";
	out += "The following guild commands are availible for you:\n";
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
	out += "%^BOLD%^%^BLUE%^Change%^RESET%^  : Changed "
	"configuration of your guild.\n";
	out += "%^BOLD%^%^BLUE%^Newsadd%^RESET%^ : This will "
	"edit the news when a member logs in.\n";
	out += "%^BOLD%^%^BLUE%^Changes%^RESET%^ : "
	"Shows log of guild roster changes.\n";

	pos2=this_player()->query_guild_position();
	if(pos2 == "main") pos2 = "Leader";
	out += "Treasury Access: Yes\n"
	"Your position is: "+pos2;
	write(out);
	break;
    case "leader":
	out = "Guild System v"+GUILD_VERSION+"\n";
	out += "The following guild commands are availible for you:\n";
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
	out += "%^BOLD%^%^BLUE%^Changes%^RESET%^ : "
	"Shows log of guild roster changes.\n";

	pos2=this_player()->query_guild_position();
	out += "Treasury Access: Yes\n";
	"Your position is: "+pos2;
	write(out);
	break;
    case "council":
	out = "Guild System v"+GUILD_VERSION+"\n";
	out += "The following guild commands are availible for you:\n";
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
	out += "Treasury Access: No\n";
	pos2=this_player()->query_guild_position();
	out += "Your position is: "+pos2;
	write(out);
	break;

    case "member":
    case "squire":
	out = "Guild System v"+GUILD_VERSION+"\n";
	out += "The following guild commands are availible for you:\n";
	out += "%^BOLD%^%^BLUE%^Members%^RESET%^ : "
	"Shows a list of current members.\n";
	out += "Treasury Access: No\n";
	out += "Your position is: "+
	capitalize(this_player()->query_guild_position());
	write(out);
	break;
    case "none":
	write("You have no position in your guild.  Please bug this.\n");
	break;
    default:
	out = "Unknown position to query commands.  Position="+pos;
	write(out+"\n");
	break;
    }
    return 1;
}
void help() {
    write(@TEXT
Syntax: <commands>
Usage:  This will show you a list of guild commands availible to you.
Position: squire, member, council, leader
TEXT);
}

