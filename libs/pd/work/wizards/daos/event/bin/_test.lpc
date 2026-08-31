#include <std.h>

inherit DAEMON;

int cmd_test() {
    int enc, maxenc;

    enc = this_player()->query_internal_encumbrance();
    maxenc = this_player()->query_max_internal_encumbrance() / 2;

    if (enc > maxenc) {
	write("You can't hold any more.");
	return 1;;
    }
    else {
	write("internal encumbrance = "+enc+"");
	write("max internal encumbrance = "+maxenc+"");
	return 1;
    }
}
