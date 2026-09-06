#include <cmd.h>

nomask int
echo_cmd(string str) {
    if (!CHECK) return 0;

    if (!str) {
	notify_fail("Echo what?\n");
	return 0;
    }

    say(str + "\n");
    write("You echo: " + str + "\n");
    return 1;
}
