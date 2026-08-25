//	/bin/user/_cls.c
//	from the Nightmare mudlib
//	Command to clear the screen for terminals with ANSI code support
//	created by Otto@Nightmare 07 march 1993


#define CLS ESC+"[H"+ESC+"[2J"

#include <std.h>

inherit DAEMON;

int cmd_cls() {
    string str;

    if((str = (string)this_player()->getenv("TERM")) != "ansi" &&
      str != "xterm" && str != "ansi-status") {
	notify_fail("You do not have ansi set.  Try <help ansi>.\n");
	return 0;
    }
    message("prompt", "%^INITTERM%^", this_player());
    return 1;
}

void help() {
    write("Syntax: <cls>\n\nClears the screen for players who have terminals\n"+
	"that support ANSI escape codes.\n");
}
