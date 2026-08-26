#include <rogues.h>
#include <mudlib.h>
#include "checkob.h"

#define SS "/d/class/warrior/Sharpshooter/"

inherit DAEMON;

int cmd_shelp(string str) {
// This line checks to see if the eyelink is equipped.
    if (!checkob(TP)) return 1;

    if (!str) str = "index";

    if (this_player()->more(SS+"help/"+str) != 1) {
	write("Type thelp index.\n");
	return 1;
    }
    return 1;
}
