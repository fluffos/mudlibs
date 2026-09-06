/*
 * Standard get-command. Also used by take-command.
 *
 * Moved to /bin/pub 22-sep-94.
 *
 * V1.1 10-may-95
 *
 * NEW:
 *
 * - You can use form "take armour and wear it"; this helps if you
 *   couldn't carry armour in question, but could carry it after
 *   wearing (as worn armour weighs less than carried armour!)
 */
/* 18-Jan-96: extra_move_object()  //Graah */

#include "/sys/tls.h"

#include <daemons.h>
#include <living_defs.h>

public status
get_all(string place, object from, object me)
{
    status is_cont;
    int i, s, wt, hv, x;
    string item, myname;
    mixed *inv;
    string *txt2;

    if (!place) place = "";
    else is_cont = 1;

    if (!(s = sizeof(inv = all_inventory(from)))) {
	if (is_cont) notify_fail("But it's empty!\n");
	return 0;
    }

    if (!(myname = (string) me -> query_name(0, me))) myname = "Someone";
    else myname = capitalize(myname);

    me -> recount_weight();

    /* Let's be more efficient here. We'll only recount_weight once; in the
       beginning. After that we use 2nd parameter to add_weight to prevent
       further recount_weight's
       -+ Doomdark +- 10-may-95 */

    txt2 = allocate(s);
    for (i = hv = x = 0; i < s; i++) {
	if (inv[i] -> get() && (item = (string) inv[i] -> query_name())) {
	    x++;
	    wt = (int)inv[i]->query_weight();
	    if (wt && !me -> add_weight(wt, 1)) {
		inv[i] = sprintf("%s: Too heavy.", item);
		if (++hv > 3) {
		    inv[i] = "Lots of heavy stuff here. Stopped getting.";
		    break;
		}
	    } else {
		if (wt && is_cont)
		    from->add_weight(-wt); /* This line should fix bag bug */
		move_object(inv[i], me);
		environment(me)->extra_move_object(inv[i], me);
		inv[i] = sprintf("%s: Ok.", item);
		txt2[i] = item;
		/* myname + " takes: "	+ item + place + ".\n"; */
	    }
	}
    }
    if (x) {
	me->tell_me(implode(inv, "\n"));
	if (environment(me)) {
	    item = sprintf("%s.\n%s takes the ", place, myname);
	    environment(me)->tell_here(
	      sprintf("%s takes the %s%s.", myname, implode(txt2, item),
		place), me);
	}
    }
    return 1;
}

varargs public status
get_one_item(string str, object me, int weight)
{
    int i;
    object ob;
    string v;

    if (!str || !me) return 0;

    str = lower_case(str);

    // Now possible for players to "get" an item by its hash too.
    if (sizeof(str) == 40 && me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
        foreach (object thing : all_inventory(environment(me))) {
            if (str == hash(TLS_HASH_SHA1, object_name(thing))) {
                ob = thing;
                break;
            }
        }
    }

    if (!(ob = present(str, environment(me))))
	if (environment(me) -> id(str)) {
	    notify_fail(({"You cannot take that!\n",
		"But how did you thought you could carry that!\n",
		"You certainly can't pick up that!\n"})[random(3)]);
	    return (status) environment(me) -> get_cmd(str);
	} else return notify_fail("You can't see any \""+str+"\" here.\n"), 0;

    if (me -> query_ghost())
	return notify_fail("Your hand passes through it.\n"), 0;

    if (environment(ob) == me) 
	return notify_fail("You already have it!\n"), 0;

    if (!ob -> get()) return notify_fail("You can not take that!\n"), 0;

    if (weight)
	i = weight;
    else
	i = (int)ob->query_weight();

    if (me -> add_weight(i)) {
	move_object(ob, me);
	environment(me)->extra_move_object(ob, me);
	if (!ob) {
	    me->add_weight(-i);
	    /* Let's just return if it was dested at init. :-/ */
	    return 1;
	}
	if (!(str = (string) ob -> query_name(0, me)))
	    str = "something";
	else str = "the "+str;
	environment(me) -> tell_here(sprintf("%s %ss %s.",
	    (string) me -> query_name(0,me),
	    (v = query_verb()), str), me);
	me -> tell_me(sprintf("Ok, you %s %s.", v, str));
	return 1;
    }
    return notify_fail("You can't carry anything more!\n"), 0;
}

nomask varargs status
get_cmd(string str, object me)
{
    string item, container, s;
    object item_o;
    object container_o, env;
    int weight;
    string vrb;

    if (!me && !(me = this_player())) return 0;

    if (!(vrb = query_verb())) vrb = "take";
    if (!str) return notify_fail(capitalize(vrb)+" what?\n"), 0;

    if (me -> query_ghost())
	return notify_fail("Your hand passes through everything.\n"), 0;
    if (!me->query_can_move()) return 0;

    str = lower_case(str);

    if (str == "all") {
	if (weight = (int) me->test_dark()) {
	    if (weight < 0) weight = -weight;
	    if (weight < 3) return 0;	/* test_dark sets notify_fails! */
	}
	return get_all(0, environment(me), me);
    }
    if (sscanf(str, "the %s", s)) str = s;

    if (sscanf(str, "%s and wear it", s)) {
	item = s;

	/* Let's implement this later when we have (if?) time...
	   (ie. something like "take helmet from bag and wear it") */

	if (sscanf(item, "%s from %s", item, container)) { }

	env = environment(me);

	if (!env || !(item_o = present(item, env)))
	    return notify_fail("You can't see any \""+item+"\" here.\n"), 0;

	if (!item_o -> is_armour())
	    return notify_fail("But it's not an armour!\n"), 0;

	if (!get_one_item(item, me, (weight + 1) / 2))
	    return 0;

	if (!item_o || !item_o -> wear_cmd(item)
	  || environment(item_o) != me) {
	    /* Something went wrong... Let's set weight back,
	       and possibly drop this armour. */
	    if (item_o && environment(item_o) == me) {
		move_object(item_o, env);
		call_other(env, "extra_move_object", item_o, environment(me));
		me->add_weight(- ((weight + 1) / 2), 1);
		notify_fail("You drop the "+(s = (string)item_o->
		    query_name(0, me))+".\n");
		env->tell_here((string)me->query_name()+" drops the "+s+".", me);
	    } else {
		/* Shouldn't usually happen? */
		me->add_weight(- ((weight + 1) / 2), 1);
		notify_fail("Couldn't do that.\n");
	    }
	    return 0;
	}
	/* If it worked ok, let's set weight to normal. */
	me->add_weight(weight / 2, 1);
	return 1;
    }

    if (sscanf(str, "%s from %s", item, container) < 2)
	return get_one_item(str, me, 0);

    container = lower_case(container);
    if (sscanf(container, "the %s", s)) container = s;
    if (!(container_o = present(container, me)) &&
      !(container_o = present(container, environment(me)))) {
	me -> tell_me("You can't see any \"" + container + "\" here.");
	return 1;
    }

    container = (string) container_o -> query_name(0, me);

    if (!container_o -> can_put_and_get()) {
	me -> tell_me("You can't "+vrb+" anything from the "+container+".");
	return 1;
    }

    if (item == "all") return get_all(" from "+container, container_o, me);

    if (!(item_o = present(item, container_o))) {
	me->tell_me(sprintf("There is no %s in the %s.", item, container));
	return 1;
    }

    item = (string) item_o -> query_name(0, me);

    if (!item_o -> get()) {
	me -> tell_me("You can't "+vrb+" "+item+" from "+container+".");
	return 1;
    }

    weight = (int)item_o->query_weight();

    if (!me -> add_weight(weight)) {
	me -> tell_me("You are carrying too much already.");
	return 1;
    }

    container_o -> add_weight(-weight);

    move_object(item_o, me);
    call_other(environment(me), "extra_move_object", item_o, me);

    me -> tell_me("Ok.");

    if (env) /* Tron */
	env->tell_here(sprintf("%s %ss %s from %s.",
	    (string) me -> query_name(0, me), vrb, item, container), me);

    return 1;
}
