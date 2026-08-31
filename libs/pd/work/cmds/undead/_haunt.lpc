//	/bin/high_mortal/_teleport.c
//	from the Nightmare mudlib
//	A high mortal goto
//	created by Descartes of Borg 09 december 1992

#include <std.h>

inherit DAEMON;

int cmd_teleport(string str) {
    object location, ob;

    if(!(ob = find_player(str))) return notify_fail("You cannot "
	"find that person.\n");
    if(!this_player()->query_ghost()) return notify_fail(
	"You must be dead to haunt people.\n");
    if(environment(ob)->query_property("no teleport"))
	return notify_fail("A magical force prevents you from doing "
		"that.\n");
    if(wizardp(ob)) {
        notify_fail("Some strange power prevents you from doing "
		"that.\n");
        return 0;
    }
    location = environment(ob);
    this_player()->move_player(location, "into a hazy mist");
    return 1;
}

void help() {
    write("
Syntax: <haunt [player]>
This undead command allows you to haunt your target.
");
}
