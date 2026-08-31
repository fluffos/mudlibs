//	/bin/user/_ansi.c
//      -- seeker

#include <std.h>

inherit DAEMON;

int cmd_ansi(string str) {


    if (!str || str=="") 
    { 
	message("info", "Ansi what?", this_player());
	return 1;
    }
    if (str!="on" && str!="off") 
    {
	message("info", "Ansi what?", this_player());
	return 1;
    }

    if (str=="on") {
	this_player()->setenv("TERM", "ansi");
	this_player()->reset_terminal();
    }
    else 
    {
	this_player()->setenv("TERM", "unknown");
	this_player()->reset_terminal();
    }
    message("info", "Ansi is now "+str+".", this_player());    
    return 1;
}

void help() {
    write("Syntax: <ansi [on|off]>\nTurns ansi on or off.\n");
}
