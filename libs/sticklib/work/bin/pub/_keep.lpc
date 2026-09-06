#include <cmd.h>

varargs nomask int
keep_cmd(string str, object me)
{
    object ob, *x;
    string s, *s2;
    int i, size;
    if (!me && !(me = this_player())) return 0;

    // If no argument, let's list items we are keeping:
    if (!str) {
	x = (object *) me->query_keep_items();
	if (!x || !(size = sizeof(x)))
	    s = "- Nothing -";
	else {
	    s2 = allocate(size);
	    for (i = 0, s = ""; i < size; i++)
		if (x[i])
		    s2[i] = (string) x[i]->query_name(0, me);
	    s = implode(s2, ", ", " and ");
	}
	this_player()->tell_me("You are keeping: "+s);
	return 1;
    }

    if (sscanf(str, "the %s", s))
	str = s;

    if (str == "eq") {
	x = (object *) me -> query_armour("list");
	if (!x) x = ({ });
	x += ({ (object) me->query_weapon() });
	if (!sizeof(x)) {
	    me->tell_me("No equipment to add to keep-list!");
	    return 1;
	}
	if (!me->add_keep_item(x, 1)) return notify_fail(
	      "Adding equipment to keep-list failed.\n"), 0;
	me->tell_me("Ok.");
	return 1;
    }
    if (str == "all") {
	x = all_inventory(me);
	if (!x || !sizeof(x)) {
	    me->tell_me("No items to keep!");
	    return 1;
	}
	if (!me->add_keep_item(x, 1)) return notify_fail(
	      "Adding all items to keep-list failed!\n"), 0;
	me->tell_me("Ok.");
	return 1;
    }
    if (!(ob = present(str, me))) return notify_fail(
	  "But you don't have any \""+str+"\"!\n"), 0;

    if (!me -> add_keep_item(ob, 1))
	me->tell_me("You are already keeping it!");
    else
	me->tell_me("Ok.");

    return 1;
}
