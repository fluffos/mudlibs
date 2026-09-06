/* New unwear-command, for clothing and armour. Same as 'remove'.
 *
 * -Doomdark 19-sep-94.
 */



#include <cmd.h>
#include <daemons.h>
#include <living_defs.h>

varargs nomask int
unwear_cmd(string arg, object me)
{
    string s;
    object ob, *a;
    int i, j;
    if (!me && !(me = this_player())) return 0;

    if (!me -> query_can_move()) return 0;

    if (!arg) return notify_fail("Unwear what?\n"), 0;

    if (arg == "all") {
	a = (object *) me->query_armour("list");
	if (!a || !sizeof(a)) {
	    me->tell_me("You aren't wearing any armours.");
	    return 1;
	}
	i = sizeof(a); j = 0;
	while (--i >= 0) {
	    /* Won't take mage's hat off, avoids bugs... //Graah */
	    if (!a[i]->drop())
	    {
		me->unwear(a[i], 0);
		j++;
	    }
	}

        if (me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
            TELOPT_D->send_char_items_list(me, "inv");
        }

	if (!j) me->tell_me("You aren't wearing any real armours.");
	return 1;
    }

    if (!sscanf(arg, "the %s", s)) s = arg;

    if (ob = present(s, me)) {
	notify_fail("You can't remove the "+arg+".\n");
	return (status) ob -> remove_cmd(s);
    }
    if (present(s, environment(me))) {
	me -> tell_me("You have to get it first!");
	return 1;
    }
    notify_fail("You can't see any "+s+" here.\n");

    if (me -> strip_clothes(s)) return 1;
    return (status) environment(me)->unwear_cmd(s);
}
