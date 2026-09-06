// General 'knock'-command 18-may-95 by Doomdark.
//
// At the moment used only by standard door (/lib/door).


#include <cmd.h>

varargs nomask status
knock_cmd(string s, object me)
{
    object ob;
    string t;

    if (!me && !(me = this_player())) return 0;

    if (me->test_dark() || !me->query_can_move()) return 0;

    if (!s) return notify_fail("Knock what?\n"), 0;

    if (sscanf(s, "the %s", t)) s  = t;
    if ((ob = present(s, me)) || (ob = present(s, environment(me)))) {
	notify_fail("Hmmm... Why would you knock it?\n");
	return (status) ob -> knock_cmd(s);
    }
    notify_fail("You can't see any "+s+" here.\n");
    return (status) environment(me) -> knock_cmd(s);
}
