/*
 * New 'unwield'-command (mainly for weapons). Same as 'remove' with weapons.
 * 09-jun-94 Doomdark,
 */


#include <cmd.h>

varargs nomask status
unwield_cmd(string s, object me)
{
    object ob;
    string t;

    if (!me && !(me = this_player())) return 0;

    if (!me -> query_can_move()) return 0;

    if (!s) {
	if (!(ob =(object)me->query_weapon())) {
	    me -> tell_me("You are not wielding a weapon!");
	    return 1;
	    t = s;
	}
    } else {
	if (!sscanf(s, "the %s", t)) t  = s;
	if (!(ob = present(t, me)) &&
	  (ob = present(t, environment(me))))
	    return notify_fail("You have to get it first!\n"), 0;
    }
    if (!ob) {
	notify_fail("You can't see any "+t+" here.\n");
	return (status) environment(me) -> unwield_cmd(t);
    }
    notify_fail("You can't remove"+ (s ? (" the "+t) :
	" your wielded weapon.") + ".\n");
    return (status) ob -> unwield_cmd(t);
}
