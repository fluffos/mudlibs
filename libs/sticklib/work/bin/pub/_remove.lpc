/* New remove command, for clothing.
   Armour remove is currently in /lib/armour. */
/* Not anymore. Neither is weapon's remove in standard weapon's code.
 * -Doomdark 09-jun-94.
 */



#include <cmd.h>
#include <daemons.h>

varargs nomask int
remove_cmd(string arg, object me)
{
    string s;
    object ob, *a;
    int i, j;
    if (!me && !(me = this_player())) return 0;

    if (!me -> query_can_move()) return 0;

    /* Trying to remove wielded weapon... */
    if (!arg) {
	if (!(ob =(object)me->query_weapon())) {
	    TP -> tell_me("You are not wielding a weapon!");
	    return 1;
	}
	else return (status) ob -> unwield_cmd(0);
    }

    if (arg == "all") {
	a = (object *) me->query_armour("list");
	if (!a || !sizeof(a)) {
	    me->tell_me("You aren't wearing any armours.");
	    return 1;
	}
	i = sizeof(a); j = 0;
	for (i = sizeof(a) - 1; i >= 0; i--) {
	    if (a[i])
	    {
		me->unwear(a[i], 0);
		j++;
	    }
	}
	if (!j) me->tell_me("You aren't wearing any real armours.");
	return 1;
    }

    if (sscanf(arg, "the %s", s)) arg = s;

    if (ob = present(arg, me)) {
	notify_fail("You can't remove the "+arg+".\n");
	return (status) ob -> remove_cmd(arg);
    }
    if (present(arg, environment(me))) {
	me -> tell_me("You have to get it first!");
	return 1;
    }
    notify_fail("You can't see any "+arg+" here.\n");

    if (me -> strip_clothes(arg)) return 1;
    return (status) environment(me)->remove_cmd(arg);
}
