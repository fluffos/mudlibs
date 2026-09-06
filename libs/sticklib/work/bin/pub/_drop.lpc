/* You can now drop some coins (helpful in mazes). Graah 29.7.1991 */
/* Moved to /bin/pub 23-sep-94. */
/* 18-Jan-96 extra_move_object() - not with coins. //Graah */

#include "/sys/tls.h"

#include <cmd.h>
#include <player_defs.h>
#include <generic_items.h>

closure *action;
mapping players;

varargs nomask status
drop_cmd(string s, object me)
{
    object ob, env;
    string tmp, tmp2;
    int coins,i;

    if (!me && !(me = this_player())) return 0;

    if (!s) return notify_fail("Drop what?\n"), 0;

    if (!me -> query_can_move()) return 0;

    if (s == "all") {
	me -> drop_all(0);
	return 1;
    }
    if (sscanf(s, "the %s", tmp)) s = tmp;
    if (sscanf(s, "%s in %s", tmp, tmp2) == 2) {
	"/bin/pub/_put" -> put_cmd(s);
	return 1;
    }
    if(s == "money" || s == "all money") {
	me -> drop_all_money(1);
	return 1;
    }
    if(sscanf(s,"%d coins",coins) || sscanf(s,"%d gold coins",coins)) {
	int money;
	money = (int) me -> query_money();
	if(money < coins) {
	    me -> tell_me("You don't have that many coins.");
	    return 1;
	}
	if(coins < 1) {
	    me -> tell_me("Trying to cheat, aren't you?");
	    return 1;
	}
	me -> tell_me("Ok.");
	if ((env = environment(me)))
	    env->tell_here(sprintf("%s drops %d coins.",
		me->query_name(), coins), me);
	me -> add_money(-coins);
	if (ob = present("money", env)) {
	    ob -> set_money(coins + (int) ob->query_money());
	} else {
	    ob = clone_object(GENERIC_MONEY_OBJECT);
	    ob -> set_money(coins);
	    move_object(ob, environment(me));
	}

	me->save_me(0); /* Checkpoint */

        // Env may want to respond...
        env->item_dropped(ob);
	return 1;
    }

    s = lower_case(s);

    // Now possible for players to "drop" an item by its hash too.
    if (sizeof(s) == 40 && me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
        foreach (object thing : all_inventory(me)) {
            if (s == hash(TLS_HASH_SHA1, object_name(thing))) {
                ob = thing;
                break;
            }
        }
    }

    if (!(ob = present(s, me))) {
	me -> tell_me(sprintf("You don't have any \"%s\".", s));
	return 1;
    }

    if (me->set(PLR_COMBAT_QUEUE_OPTIONAL, action)) {
	mixed foo;
	if (!(foo = players[me]))
	    players[me] = ob;
	else if (pointerp(foo))
	    players[me] = foo + ({ ob });
	else players[me] = ({ foo, ob });
	return 1;
    }

    notify_fail("You can't drop that!\n");

    if (me -> drop_one_item(ob, 0)) {
	me -> tell_me("Ok.");
	me -> recount_weight();
	if (!(tmp = (string) ob->query_name(0, me))) tmp = "<something>";
	if (environment(me)) environment(me)->tell_here(
	      sprintf("%s drops the %s.", (string)me->query_name(),
		tmp), me);
    } else return 0;

    return 1;
}

void
end_drop(object plr)
{
    mixed tmp;
    object ob;
    if (!tmp = players[plr])
	return;
    if (pointerp(ob)) {
	players[plr] = tmp[1..];
	ob = tmp[0];
    } else ob = tmp;
    if (!objectp(ob))
	return;
    if (!(tmp = (string) ob->query_name(0, plr)))
	tmp = "<something>";
    if (plr -> drop_one_item(ob, 0)) {
	plr -> recount_weight();
	plr -> tell_me(sprintf("Ok, you drop %s", tmp));
	if (environment(plr))
	    environment(plr)->tell_here(
	      sprintf("%s drops the %s.", (string)plr->query_name(),
		tmp), plr);
    } else {
	plr->tell_me(sprintf("You can't drop %s!", tmp));
    }
}

void
create()
{
    action = ({ 0, #'end_drop });
    players = ([ ]);
}

void
reset()
{
    // This'll remove dested players...
    m_values(players);
}
