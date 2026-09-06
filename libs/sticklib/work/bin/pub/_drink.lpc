/*
 * New general 'drink'-command.
 * 30-sep-94 Doomdark.
 */


#include <cmd.h>

varargs nomask status
drink_cmd(string s, object me)
{
    object ob;
    if (!me && !(me = this_player())) return 0;

    if (!me->query_can_move()) return 0;
    // Was me->test_dark() too, removed it. Doomdark 23.11.95

    if (!s) return notify_fail("Drink what?\n"), 0;

    sscanf(s, "the %s", s);
    s = lower_case(s);
    if ((ob = present(s, me)) || (ob = present(s, environment(me)))) {
	notify_fail("You don't seem to be able to drink the "+s+".\n");
	if ((status) ob -> drink_cmd(s, me))
	    return 1;
	return 0;
    }
    notify_fail(sprintf("You can't see any \"%s\" here.\n", s));
    return (status)environment(me)->drink_cmd(s,me);
}
