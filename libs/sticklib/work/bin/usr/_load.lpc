#include <cmd.h>

/* Silly command, but perhaps someone still wants it. */
nomask int
load_cmd(string str) {
    mixed ret;

    if (!CHECK) return 0;

    if (!str) {
	notify_fail("Load what?\n");
	return 0;
    }

    str = (string)TP->absolute_path(str, 0);

    if (!str || str[0] != '/') {
	notify_fail("Invalid file name.\n");
	return 0;
    }

    ret = catch(call_other(str, "???"));
    if(ret)
	write(ret+"\n");
    else
	write("Ok.\n");
    return 1;
}
