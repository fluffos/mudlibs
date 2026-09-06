// General 'go'-command 18-may-95 by Doomdark.
//
// At the moment used only by standard door (/lib/door).


#include <cmd.h>

varargs nomask status
go_cmd(string s, object me)
{
    object ob;
    string t;
    status through;
    if (!me && !(me = this_player())) return 0;

    if (me->test_dark() || !me->query_can_move()) return 0;

    if (!s) return notify_fail("Knock what?\n"), 0;

    if (sscanf(s, "the %s", t)) s  = t;
    if (!sscanf(s, "through the %s", t) && !sscanf(s, "through %s", t))
	t = s;
    else
	through = 1;
    if ((ob = present(t, me)) || (ob = present(t, environment(me)))) {
	notify_fail(through ? "How could you go through it?\n" :
	  "How could you go there?\n");
	return (status) ob -> go_cmd(s);
    }
    notify_fail("You can't see any "+s+" here.\n");
    return (status) environment(me) -> go_cmd(s);
}
