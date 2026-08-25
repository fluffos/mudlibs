/* goto.c
 * Externalized by Baldrick june '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

    position = 1;
}

protected int cmd(string str, object me) {
    object dest;
    string *names, nick;

    if (!str) {
        notify_fail("Teleport like where?\n");
	return 0;
    }
    if(!me->query_thane())
	me->set_invis(0);
    nick = (string)me->expand_nickname(str);
    dest = find_living(nick);
    if (dest) {
	if(dest = environment(dest)) {
	    if (dest == environment()) {
		notify_fail("You look around and realise you are already there.\n");
		return 0;
	    }
	    me->move_player("X", dest);
	    return 1;
	} else {
	    notify_fail(capitalize(nick) + " is not standing in a location.\n");
	    return 0;
	}
    } else {
	names = (string *)me->get_cfiles(str);
	if(sizeof(names)) {
	    str = names[0];
	} else {
	    notify_fail("No such room.\n");
	    return 0;
	}
	if (!(dest = find_object(str))) {
	    catch(str->come_and_see_the_stars());
	    dest = find_object(str);
	}
	if (!dest) {
	    notify_fail("Failed to load " + str + "\n");
	    return 0;
	} else if(!dest->query_property("location")) {
	    notify_fail("Not a room: " + str + "\n");
	    return 0;
	} else {
	    if (dest == environment()) {
		notify_fail("You look around and realise you are already there.\n");
		return 0;
	    }
	    me->move_player("X", dest);
	    me->set_trivial_action();
	    return 1;
	}
    }
} /* teleport() */

