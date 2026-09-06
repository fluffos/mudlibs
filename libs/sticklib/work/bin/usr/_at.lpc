#include <cmd.h>

nomask int
at_cmd(string str) {
    string n;
    object old_room,room,who;
    string cmd;

    if (!CHECK) return 0;

    if (!str ||
      sscanf(str, "%s %s", n, cmd) != 2) {
	notify_fail("Usage: at <who> <cmd>\n");
	return 0;
    }

    n = lower_case(n);
    who = find_player(n);
    if (!who) who = find_living(n);

    if (!who) {
	notify_fail("Can't find " + capitalize(n) + ".\n");
	return 0;
    }

    room = environment(who);

    if (!room) {
	notify_fail(capitalize(n) + " doesn't have an environment!\n");
	return 0;
    }

    old_room = environment(TP);
    move_object(TP, room);

    TP->force_us(cmd);

    if (old_room) move_object(TP, old_room);
    else write("Couldn't return back again.\n");

    return 1;
}
