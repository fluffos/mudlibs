#include <cmd.h>
#include <coder_levels.h>

nomask int
echoall_cmd(string str) {
    object *u;
    int i;

    if((int)TP->query_coder_level() < LVL_WIZARD)
	return notify_fail("Coder level 75!\n"), 0;

    if (!str) {
	notify_fail("Echoall what?\n");
	return 0;
    }

    u = users();

    for (i = sizeof(u) - 1; i >= 0; i--)
    {
	if (IS_ADMIN_OB(u[i]) && u[i] != TP) {
	    tell_object(u[i], "!" +
	      capitalize((string)TP->query_real_name()) + "! ");
	}
	tell_object(u[i], str + "\n");
    }

    write("You echoall: " + str + "\n");
    return 1;
}
