/*
 * New general 'unlock'-command.
 * 19-sep-94 Doomdark,
 */


#include <cmd.h>

varargs nomask status
unlock_cmd(string s, object me)
{
    object ob;
    string t, s2;

    if (!me && !(me = this_player())) return 0;

    if (!me->query_can_see() || me->test_dark() || !me->query_can_move())
	return 0;

    if (!s) return notify_fail("Unlock what?\n"), 0;

    if (sscanf(s, "the %s", t)) s  = t;
    if ((ob = present(s, me)) || (ob = present(s, environment(me)))) {
	notify_fail("You don't seem to be able to unlock the "+s+".\n");
	return (status) ob -> unlock_cmd(s);
    }
    if (sscanf(s, "%s with %s", t, s2) == 2) {
	if ((ob = present(t, me)) || (ob = present(t, environment(me)))) {
	    notify_fail("You don't seem to be able to unlock the "+t+".\n");
	    return (status) ob -> unlock_cmd(s);
	}
    }

    notify_fail("You can't see any "+s+" here.\n");
    return (status) environment(me) -> unlock_cmd(s);
}
