#include <cmd.h>

nomask int
dest_cmd(string str)
{
    object ob;

    if (!CHECK) return 0;

    if (!str) {
	notify_fail("Usage: destruct <object>\n");
	return 0;
    }

    if (ob = get_object(str)) {
	string tmp;

	if (interactive(ob)) {
	    notify_fail("You must not destruct players!\n");
	    return 0;
	}

	if ((tmp = (string)ob->query_name()) || (tmp = (string)ob->short())) {
	    say(sprintf("%s is disintegrated by %s.\n", tmp,
		(string)TP->query_name()));
	} else {
	    tmp = object_name(ob);
	}

	/* Should be ob->remove(), but... */
	destruct(ob);

	this_player()->tell_me("Ok. Destructed " + tmp + ".");
	return 1;
    }

    notify_fail("No " + str + " found.\n");
}
