/*
 * New 'light' command for torches.
 * 08-jun-94 Doomdark,
 */


#include <cmd.h>

varargs nomask status
light_cmd(string s, object me)
{

    object ob;
    string t;

    if (!me && !(me = this_player())) return 0;

    if (!me -> query_can_see() ||  !me -> query_can_move()) return 0;

    if (!s) return notify_fail("Light what?\n"), 0;

    if (!sscanf(s, "the %s", t)) t  = s;
    if (ob = present(t, me)) {
	notify_fail("You can't light the "+t+".\n");
	return (status) ob -> light_cmd(t);
    }
    if (ob = present(t, environment(me)))
	return notify_fail("You have to get it first!\n"), 0;
    notify_fail("You can't see any "+t+" here.\n"), 0;
    return (status) environment(me) -> light_cmd(t);
}
