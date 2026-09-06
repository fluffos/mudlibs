#include <cmd.h>

nomask int
emote_cmd(string str) {
    if (!CHECK) return 0;

    if (!str) {
	notify_fail("Emote what?\n");
	return 0;
    }

    say((string)TP->query_name() + " " + str + "\n");
    write("\"" + (string)TP->query_name() + " " + str + "\"\n");
    return 1;
}
