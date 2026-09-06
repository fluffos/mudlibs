

#include <cmd.h>
#include <daemons.h>
#include <living_defs.h>

inherit "/lib/find_name";

varargs nomask int
wear_cmd(string arg, object me)
{
    object ob;
    string cn, s;
    int i;
    object *worn;

    if (!me && !(me = this_player())) return 0;

    if (!me->query_can_move()) return 0;

    if (!arg) return notify_fail("Wear what?\n"), 0;

    if (arg == "all") {
	ob = first_inventory(me);
	if (!(worn = (object*) me -> query_armour("list")))
	    worn =({});
	while (ob) {
	    if (member(worn, ob)<0 && ob->is_armour())
		me -> wear(ob, 0);
	    ob = next_inventory(ob);
	}

        if (me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
            TELOPT_D->send_char_items_list(me, "inv");
        }

	return 1;
    }

    if (!sscanf(arg, "the %s", s)) s = arg;
    s = lower_case(s);

    ob = present(s, me);

    if (!ob) {
	/* Monsters don't often have environment when wearing something  */
	if (environment(me)) {
	    if (present(s, environment(me))) {
		me->tell_me("You have to get it first.");
		return 1;
	    } else {
		/* If no, let's check if there's some special actions in room-code. */
		notify_fail(sprintf("You can't see any \"%s\" here.\n", s));
		return (status) environment(me) -> wear_cmd(s);
	    }
	}
	return 1;
    }
    /* If the player has an object that matches the name given with the command,
     * let's check if it wants to be worn... :-)
     */ 
    if (ob -> wear_cmd(s)) return 1;
    /* If yes, let's just return. */
    /* Else, let's check if it's a cloth. */

    if (!ob -> is_clothing() || !(cn = (string) ob -> query_cloth_type())) return
	notify_fail(sprintf("You can't wear %s.\n", find_name(ob), 0)), 0;
    /* If not, we'll give a short note telling we can't wear it. */

    if (!(s = (string) ob -> query_short(0, me))) {
	me -> tell_me("Strange, you got Caesar's New Clothes?!?!?!");
	return 1;
    }

    /* If we managed to wear it, we can get rid of the object. */
    if (me->wear_clothes(cn, s, (int)ob->query_value(),
	(i = (int)ob->query_weight()) )) {
	me->add_weight(-i);
	destruct(ob);
    }
    return 1;
}
