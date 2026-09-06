/*
 * New extinguish-command (mainly for torches). Same as 'unlight'.
 * 08-jun-94 Doomdark
 */


#include <cmd.h>

nomask status
extinguish_cmd(string s, object me)
{
    object ob;
    string t;

    if (!me && !(me = this_player())) return 0;
    if (!s) return notify_fail("Extinguish what?\n"), 0;

    if (!me -> query_can_see() || !me -> query_can_move()) return 0;

    if (!sscanf(s, "the %s", t)) t  = s;
    if (ob = present(t, me)) {
	notify_fail("You can't extinguish the "+t+".\n");
	return (status) ob -> unlight_cmd(t);
    }
    if (!environment(me)) return 0;
    if (ob = present(t, environment(me)))
	return notify_fail("You have to get it first!\n"), 0;
    notify_fail("You can't see any "+t+" here.\n"), 0;
    return (status) environment(me) -> unlight_cmd(t);
}
