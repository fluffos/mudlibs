/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use this code.
// Written by Sulam(12-15-91)
*/

#include <std.h>

inherit DAEMON;

int
cmd_snoopable() {
    return (int) this_player()->set_snoop();
}

void help() {
    write("Syntax: <snoopable>\n\n"+
	"Allows you to give out permission to low level immortals to snoop\n"+
	"you, as well as allowing you to revoke that permission.  High\n"+
	"level immortals always have the ability to override this permission.\n");
}
