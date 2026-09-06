#include <cmd.h>

nomask int
trans_cmd(string str)
{
    object ob;

    if (!CHECK) return 0;

    if (!str) {
	notify_fail("Trans whom?\n");
	return 0;
    }

    ob = find_living(str);

    if (!ob) {
	notify_fail("No such living being found.\n");
	return 0;
    }

    tell_object(ob, "You are magically transferred somewhere.\n");
    ob->move_player("X#" + object_name(environment(TP)));

    return 1;
}
