//	/bin/high_mortal/_decloak.c
//	from the Nightmare mudlib
//	the reverse of cloak
//	created by Descartes of Borg 02 march 1993

#include <std.h>

inherit DAEMON;

int cmd_decloak() {
    if(!this_player()->query_invis()) {
	notify_fail("You are not cloaked!\n");
	return 0;
    }
    this_player()->set_invis();
    return 1;
}

void help() {
  message("help",
    "Syntax: <decloak>\n\n"
    "This command cancels any invisibility or cloaking effect on the user.",
    this_player() );
}
