// File: _bury.c
// Date: July 23rd, 1997.
// Purpose: To get rid of them smelly things known as corpses.
// Original Initative: Nightmask
// Fixed by Cyanide

#include <mudlib.h>
inherit DAEMON;

int cmd_eat(string str) {
    object corpse;

    if (!str) {
	write("Eat what?\n");
	return 1;
    }

    if (!environment(TP)) {
	write("You can't eat in the void!\n");
	return 1;
    }

    corpse = present("dead body", environment(TP));

    if (str == "corpse" && (corpse)) {
	if (!corpse) {
	    write("There's no corpse here!\n");
	    return 1;
	}

	write("You eat the corpse, EWWW!\n");
	say(TPN+" eats a freshly killed corpse, blah.\n");

	if (!userp(TP))
	    TP->receive_healing(2 * (int)corpse->query("level"));

	corpse->remove();
	return 1;
    }
    return 0;
}

string help() {
    return @ENDHELP
Usage: eat corpse

This command allows you to eat a corpse.
Yum!

ENDHELP
    ;
}
