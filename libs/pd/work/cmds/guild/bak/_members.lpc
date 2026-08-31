//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
string *member, *council, *leader, *squire;

string *filter(string *pos);

int cmd_members() {
    string *leaderfil, *councilfil, *memberfil, *squirefil;
    if(!this_player()->query_guild()) return 0;
    if(!file_exists("/d/guilds/save/"+this_player()->query_guild()+".o")) 
	return notify_fail("Your guild no longer exists.\n");
    restore_object(SAVE+this_player()->query_guild());
    memberfil = filter(member);
    leaderfil = filter(leader);
    councilfil = filter(council);
    squirefil = filter(squire);

    write(center("Guild Statistics for "+this_player()->query_guild()));
    write("\n\n%^BLUE%^%^BOLD%^Leaders: %^RESET%^\n");
    write(format_page(leaderfil, 2)+"\n");
    write("%^RED%^%^BOLD%^Councilors: %^RESET%^\n");
    write(format_page(councilfil, 2)+"\n");
    write("%^BOLD%^Members: %^RESET%^\n");
    write(format_page(memberfil)+"\n");
    write("%^BOLD%^%^GREEN%^Squires: %^RESET%^\n");
    write(format_page(squirefil)+"\n");
    write("");
    return 1;
}
void help() {
    write(@TEXT
Syntax: <members>
Usage:  This will show you the list of people currently in your guild.
Position: member, council, leader
TEXT);
}

string align(int x, string what) {
    int y;
    string out;
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
	out = what[0..x-1] + " ";
	return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}

string *filter(string *pos) {
    int i;
    string *out;
    i = sizeof(pos);
    out = ({});
    while(i--) {
	if(find_player(pos[i]) && interactive(find_player(pos[i]))) {
	    if(find_player(pos[i])->query_cap_name() == "A shadow")  
		out += ({ align(15, pos[i])+" (Offline)" });
	    else        out += ({ align(15, pos[i])+" (Online) " });
	}
	else out += ({ align(15, pos[i])+" (Offline)" });
    }
    return out;
}

