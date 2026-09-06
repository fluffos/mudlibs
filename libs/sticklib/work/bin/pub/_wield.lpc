// Last change: 23-mar-96 by Doomdark
//
// NEW:
//
// - Now allows left wielding too...


#include <cmd.h>

varargs nomask status
wield_cmd(string s, object me)
{
    object ob;
    string t, u;
    status left;

    if (!me && !(me = this_player())) return 0;

    if (!me -> query_can_move()) return 0;

    if (!s) return notify_fail("Wield what?\n"), 0;

    if (sscanf(s, "the %s", t))
	s  = t;
    if (sscanf(s, "%s in %s", t, u) == 2) {
	s = t;
	if (sscanf(u, "the %s", t))
	    u = t;
	if (u == "left hand" || u == "left")
	    left = 1;
	else if (u != "right hand" && u != "right" &&
	  u != "both hands" && u != "both hands") {
	    return notify_fail("Wield in where? (right hand,\
 left hand, both hands?)\n"), 0;
	}
    }
    if (ob = present(s, me)) {
	notify_fail(sprintf("You can't wield the %s.\n", s));
	return (status) ob->wield_cmd(s, me, left);
    }

    if (environment(me) && present(s, environment(me)))
	return notify_fail("You have to get it first!\n"), 0;
    notify_fail(sprintf("You can't see any \"%s\" here.\n", s)), 0;

    // Let's pass this command to the room, in case it's interested in it... :-7
    if (environment())
	return (status) environment() -> wield_cmd(s);
    return 0;
}
