#include <cmd.h>

nomask int
update_cmd(string str) {
    object ob;

    if (!CHECK) return 0;

    if (!str) {
	notify_fail("Update what object?\n");
	return 0;
    }

    str = (string)TP->absolute_path(str,0);
    if (!str || str[0] != '/') {
	notify_fail("Invalid file name.\n");
	return 0;
    }

    ob = find_object(str);
    if (!ob) {
	notify_fail("No such object.\n");
	return 0;
    }

    /* Well, actually should check that this is not a clone of object... */
    if (interactive(ob)) {
	notify_fail("Stop fooling around.\n");
	return 0;
    }

    destruct(ob);
    write(str + " will be reloaded at next reference.\n");
    return 1;
}
