/* Short inventory command (experimental) */

// 23-Apr-97 / Graah: Now using present4() *GRIN*

#include <cmd.h>
#include <living_defs.h>
#include <invis_levels.h>

varargs nomask int
si_cmd(string arg, object me)
{
    int i, flag, see_level, see_in_dark_level;
    object who;
    mixed *ob;

    if (!me && !(me = this_player())) return 0;

    if (me->query_coder_level()) see_level = IL_TOTALLY_INVISIBLE;
    else see_level = IL_VISIBLE;

    // No arg, si self, always works even in dark.
    if (arg) {
	see_in_dark_level = (int) me->test_dark2();
	if (see_in_dark_level) {
	    if (see_in_dark_level < 4) return 0;
	} else see_in_dark_level = 7;
	if (arg == "here") {
	    arg = "your location";
	    who = environment(me);
	} else {
	    who = present4(lower_case(arg), environment(me), me, see_level);
	}
    } else who = me;
    if (!who) {
	me->tell_me(sprintf("You can't see any '%s' around here.", arg));
	return 1;
    }
    if (!arg) arg = (string)who->query_name(0, me);
    if (!arg) arg = (string)who->query_short(0, me);
    if (!arg) arg = "something";

    ob = all_inventory(who);

    if (pointerp(ob))
	i = -1;
    while (++i < sizeof(ob)) {
	if (ob[i] == me) continue;
	if (see_in_dark_level < 7 && (!living(ob[i]) ||
	    !ob[i]->query(LIV_NOT_UNDEAD))) continue;
	if (ob[i] = (string)ob[i]->short(see_level, me)) flag++;
    }
    if (living(who) && who != environment(me)) {
	if (!flag) me->tell_me(sprintf("%s is carrying: nothing.",
		capitalize(arg)));
	else me->tell_me(sprintf("%s is carrying: %s.",
		capitalize(arg), implode(ob, ", ", " and ")));
	if (who != me && see_level != IL_TOTALLY_INVISIBLE)
	    who -> tell_me(sprintf("%s looks at your inventory.",
		(string)me->query_name(0, who)));
    } else {
	if (!flag) me->tell_me(sprintf("%s contains: nothing.",
		capitalize(arg)));
	else me->tell_me(sprintf("%s contains: %s.",
		capitalize(arg), implode(ob, ", ", " and ")));
    }

    return 1;
}
