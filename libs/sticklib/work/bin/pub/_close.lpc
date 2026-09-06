/*
 * New general 'close'-command.
 * 19-sep-94 Doomdark,
 */


#include <cmd.h>

varargs nomask status
close_cmd(string s, object me)
{
    object ob;
    string t;

    if (!me && !(me = this_player())) return 0;

    if (me->test_dark() || !me->query_can_move()) return 0;

    if (!s) return notify_fail("Close what?\n"), 0;

    if (sscanf(s, "the %s", t)) s  = t;
    if ((ob = present(s, me)) || (ob = present(s, environment(me)))) {
	notify_fail("You don't seem to be able to close the "+s+".\n");
	return (status) ob -> close_cmd(s);
    }
    notify_fail("You can't see any "+s+" here.\n");
    return (status) environment(me) -> close_cmd(s);
}
