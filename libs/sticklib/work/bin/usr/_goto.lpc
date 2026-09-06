#include <cmd.h>

nomask int
goto_cmd(string dest) {
    object ob;
    string a, b;

    if (!CHECK) return 0;

    if (!dest) {
	notify_fail("Usage: goto <location>\n");
	return 0;
    }

    if (ob = get_object(dest)) {
	if (living(ob) && environment(ob)) ob = environment(ob);
	this_player()->move_player("X", ob);
	return 1;
    }

    dest = (string)this_player()->absolute_path(dest);
    if (sscanf(dest, "%s/virtual/%s", a, b) == 2) {
	// Let's suppose this virtual room can be found... :-/ -+ Doomdark +-
	if (a = catch(this_player()->move_player("X", dest))) {
	    this_player()->tell_me(sprintf("Error in moving: %s", a));
	}
	return 1;
    }
    notify_fail("Can't find: " + dest + "\n");
}
