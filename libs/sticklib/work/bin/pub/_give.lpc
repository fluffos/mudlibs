/* Moved to /bin/pub 22-sep-94. */
/* Could give nondroppable items...not anymore 23-10-94 ++Tron */
/* Can now give while resting. Why not? //Graah 23-Jun-96 */

#include <cmd.h>

varargs nomask status
give_cmd(string str, object me)
{
    string item, dest, s, s2;
    object item_ob, dest_ob;
    int weight, coins, money;
    int i;

    if (!me && !(me = this_player())) return 0;
    if (interactive(me) && me != this_player() && (int) me->query_coder_level())
	return 0;
    /* Can't 'force' a coder to give things... */

    if (!str) return notify_fail("Give what to whom?\n"), 0;
    if (!me->query_can_move())
	return 0;
    i = (int) me->test_dark();
    if (i && i > -4 && i < 4)
	return 0;
    if (me->is_fighting()) {
	notify_fail("Not now, you are fighting!\n");
	return 0;
    }

    if(sscanf(str, "%d coins to %s", coins, dest) == 2) item = 0;
    else if( sscanf(str, "1 coin to %s", dest) == 1) coins = 1;
    else if( sscanf(str, "coin to %s", dest) == 1) coins = 1;
    else if(sscanf(str, "one coin to %s", dest) == 1) coins = 1;
    else if(sscanf(str, "%s to %s", item, dest) != 2)
	return notify_fail("Give what to whom?\n"), 0;
    dest = lower_case(dest);
    /* Let's remove "the"s in case someone uses them... */
    if (sscanf(dest, "the %s", s)) dest = s;

    if (item) {
	item = lower_case(item);
	if (sscanf(item, "the %s", s)) item = s;
	if (!(item_ob = present(item, me))) {
	    me -> tell_me("You don't have any \""+item+"\".");
	    return 1;
	}
	if (item_ob->drop(1)) {
	    me -> tell_me("You can't give that away.");
	    return 1;
	}
    }
    if (!(dest_ob = present(dest, environment(me)))) {
	me -> tell_me("There is no " + capitalize(dest) + " here.");
	return 1;
    }
    if(!living(dest_ob)) {
	me -> tell_me("You can't do that.");
	return 1;
    }
    if(dest_ob == me) {
	me -> tell_me("You say to yourself: Damn, I am a loonie.");
	return 1;
    }

    s = (string) me -> query_name(0, dest_ob);
    s2 = (string) dest_ob -> query_name(0, me);

    if (!item) {
	if (coins <= 0)
	    return notify_fail("And you just had to try this, hadn't you?"), 0;
	if ((money = (int) me -> query_money()) < coins) {
	    me -> tell_me("You don't have that much money to give.");
	    return 1;
	}
	me -> add_money(-coins);
	/* Checkpoint the character, to prevent cheating */
	if (coins > 1000 && !me -> query_coder_level()) me -> save_me(1);
	dest_ob -> add_money(coins);

	dest_ob -> tell_me(s + " gives " + coins + " gold coins to you.");
	environment(me) -> tell_here(s + " gives " + coins + " gold coins to "
	  + s2 + ".",({ me, dest_ob }));
	me -> tell_me("Ok.");
	dest_ob -> give_object_by(me, coins);
	/* NEW! Inform also when players give money. */
	return 1;
    }
    if (!dest_ob -> add_weight(weight = (int)item_ob -> query_weight())) {
	me -> tell_me(s2 + " can't carry any more.");
	return 1;
    }
    me -> add_weight(-weight);
    move_object(item_ob, dest_ob);
    dest_ob -> tell_me(s + " gives " + item + " to you.");
    environment(me) -> tell_here(s + " gives " + item + " to " + s2 +
      ".", ({ me, dest_ob }));
    me -> tell_me("Ok.");

    /* Call the event function */

    dest_ob->give_object_by(me, item_ob);

    return 1;
}
