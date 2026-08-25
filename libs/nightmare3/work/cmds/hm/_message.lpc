//	/bin/high_mortal/_message.c
//	from the Nightmare mudlib
//	movement message changing
//	created by Descartes of Borg 09 december 1992

#include <std.h>

inherit DAEMON;

int cmd_message(string str) {
    string what, msg;

    if(!str) {
	notify_fail("Which message? What is the message?\n");
	return 0;
    }
    if(sscanf(str, "%s %s", what, msg) != 2) {
	notify_fail("Correct syntax: <message [in | out] [msg]>\n");
	return 0;
    }
    if(what != "in" && what != "out") {
	notify_fail("You may only set your messages in and out.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 10) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    this_player()->add_mp(-10);
    if(what == "in") this_player()->setenv("MIN", "$N "+msg);
    else this_player()->setenv("MOUT", "$N "+msg+" $D");
    return 1;
}

void help() {
    write("Syntax: <message [in | out] [msg]>\n\n"+
	"Changes you messages when you enter and exit a room.\n"+
	"The in message makes other players see :\n"+
	"    Your_name msg. when you enter a room, whereas the out:\n"+
	"    Your_name msg direction. when you leave.\n");
}
