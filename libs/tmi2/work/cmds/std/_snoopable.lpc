// This file is part of the TMI distribution mudlib.
// Please include this header if you use this code.
// Written by Buddha@TMI (8/1/92)
// Help added by Mobydick, 11-21-92. BEAT CAL!

#include <priv.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_snoopable() {
	int snoopy;
	if (this_player()->query("snoopable")) {
		this_player()->set("snoopable", 0, MASTER_ONLY);
		write("You are no longer snoopable.\n");
	} else {
		this_player()->set("snoopable", 1, MASTER_ONLY);
		write("You can now be snooped by anyone.\n");
	}
	return 1;
}

int help() {
	write ("Usage: snoopable\n\n"+
"The snoopable command turns your snoopability on and off. If you are\n"+
"snoopable, any wizard can snoop you. If you are not snoopable, only\n"+
"administrators can snoop you. It is polite to remain snoopable, and it\n"+
"is also polite not to snoop anyone without their permission.\n"+
"\nSee also: snoop.\n") ;
	return 1 ;
}
/* EOF */
