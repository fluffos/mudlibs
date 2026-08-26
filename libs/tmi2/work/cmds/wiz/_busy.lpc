// A basic busy flag toggler. 
// For people who don't want to be bothered.
// Original author unknown.
// Mobydick revised it for mudlib 0.9 in October 1992.
// He added this header 11-21-92. BEAT CAL!

#include <mudlib.h>

inherit DAEMON ;

int cmd_busy() { 
	int busy;
	seteuid(geteuid(previous_object()));
	busy = (int)previous_object()->query("busy");
	if (busy) {
		write("Your busy flag is now deactivated.\n");
		previous_object()->set("busy", 0);
	} else {
		write("Your busy flag is now set.\n");
		previous_object()->set("busy", 1);
	}
	return 1;
}

int help() {
	write ("Usage: busy\n\n"+
"The busy command toggles your busy bit. If you are busy, then people who\n"+
"try to \"tell\" to you will be informed that you are busy and you will\n"+
"not receive the messages. This is handy when you are trying to edit a\n"+
"long or complex file, for example.\n") ;
	return 1 ;
}
