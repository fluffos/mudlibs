#include <cmd.h>

nomask int
in_cmd(string str) {
    mixed room;
    object old_room;
    string cmd;

    if (!CHECK) return 0;

    if (!str ||
      sscanf(str, "%s %s", room, cmd) != 2) {
	notify_fail("Usage: in <room> <cmd>\n");
	return 1;
    }

    room = (string)TP->absolute_path(room, 0);

    if (!room) {
	notify_fail("Invalid file name.\n");
	return 0;
    }

    old_room = environment(TP);
    move_object(TP, room);

    command(cmd, TP);

    if (old_room)
	move_object(TP, old_room);
    else
	write("Could not return back again.\n");
    return 1;
}
