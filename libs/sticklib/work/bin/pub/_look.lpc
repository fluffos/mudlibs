#include "/sys/tls.h"

#include <cmd.h>
#include <living_defs.h>
#include <invis_levels.h>
#include <room_defs.h>
#include <conditions.h>
#include <daemons.h>

#include <tell_me.h>
#include <client_defs.h>

#define MAX_ITEMS	80
#define	MAX_LINES	20
#define	SEE_INVIS_LEVEL	IL_VISIBLE

// 16-jun-96: Testing something new... Instead of displaying all the
//	similar items on their own lines, we'll do "3 x An item", if the
//	similar items are next to each other on the room. -+ Doomdark +-
// 10-Jan-98, Doomdark: Adding support for the java-client

void
print_items(object me, mixed *items)
{
    int i, last, amount, same_amount;

    for (i = same_amount = amount = 1, last = 0; i < sizeof(items); i++) {
	if (!stringp(items[i])) continue;
	if (items[i] == items[last]) {
	    same_amount++;
	    items[i] = 0;
	    continue;
	} else if (same_amount > 1) {
	    items[last] = sprintf("%d x %s", same_amount, items[last]);
	    same_amount = 1;
	}
	amount++;	// Amount of lines we'll get...
	last = i;
    }
    if (same_amount > 1) {
	items[last] = sprintf("%d x %s", same_amount, items[last]);
	same_amount = 1;
    }
    if (stringp(items[last]))
	items[last] += ".";
    if (amount > 20)
	me->tell_me(implode(items, ", ", " and "), 0, TELL_TYPE_ROOM_ITEM, 0, 0, 0);
    else
	me->tell_me(implode(items, ".\n"), 0, TELL_TYPE_ROOM_ITEM, 0, 0, 0);
}

varargs int
look_cmd(string arg, object me)
{
    object ob;
    mixed *inv, x, y;
    string *inv2;
    string item, short_str;
    int see_ilevel, see_level;
    int i, is_living, max, client;

    if (!me && !(me = this_player())) return 0;
    if (interactive(me) && me->query_coder_level())
	see_ilevel = IL_TOTALLY_INVISIBLE;
    else see_ilevel = SEE_INVIS_LEVEL;

    // So, coders will see _everything_; including items normally invisible
    // for _all_ mortals. -+ Doomdark 14-nov-95 +-
    if (!arg) {

	if (see_ilevel == IL_TOTALLY_INVISIBLE)
	    me->tell_me(object_name(environment(me)));

	// Let's first print the appropriate long description; can be short in case
	// it's dark and we have partial infravision and so on...

	client = environment(me) -> long(0, me);
	/* Btw; long() also sets the begin-tag for client... */

	see_level = (int)me->test_dark2((int)environment(me)->query_total_light(),
	  (int) environment(me)->query_light_level(),
	  (int) environment(me)->query(ROOM_WD));

	if (see_level < 0) see_level = -see_level;

	if (see_level < 4) {
	    // But we need to remember the client application...
	    if (client == TELL_RETURN_CLIENT_IN_USE) {
		tell_object(me,
		  CLIENT_TAG_BEGIN CLIENT_TAG_NEGATE CLIENT_TAG_RDESC CLIENT_TAG_END);
	    }
	    return 1;	// Can't see any objects anyway.
	}
	if (sizeof(inv = all_inventory(environment(me))) < 2) return 1;
	// Only us in the room... Not worth checking.
	if (me->query_condition(C_HALLUCINATING)) y = 1;
	// So; with see_level of 7 we see all the objects, with 4-6 only
	// non-undead NPCs and players, otherwise nothing...
	for(i = x = max = 0; i < sizeof(inv); i++) {
	    if ((ob = inv[i]) == me || (see_level < 7
		&& (!living(ob) || !ob->query(LIV_IS_PLAYER_OR_NPC)
		  || ob->query(LIV_UNDEAD)))) {
		inv[i] = 0;
		continue;
	    }
	    // We may be hallucinating. *GRIN*
	    if (y && random(100) > 74) {
		if (living(ob)) short_str = (string) HALLU_D->random_short(1);
		else short_str = (string) HALLU_D->random_short(2);
	    } else short_str = (string) ob->short(see_ilevel, me);
	    if(inv[i] = short_str) x++;
	    if (++max > MAX_ITEMS) {
		inv = inv[0..i] + ({ "*** TRUNCATED ***" });
		break;
	    }
	}
	// Let's not print that empty line if we couldn't see any items  - Chopin
	if(x) print_items(me, inv);
	if (client == TELL_RETURN_CLIENT_IN_USE) {
	    if (x = (string) environment(me)->query(ROOM_SHORT_EXIT_LIST)) {
		tell_object(me, sprintf(
		    CLIENT_TAG_BEGIN CLIENT_TAG_EXITS " %s" CLIENT_TAG_END
		    //CLIENT_TAG_BEGIN CLIENT_TAG_NEGATE CLIENT_TAG_EXITS CLIENT_TAG_END
		    CLIENT_TAG_BEGIN CLIENT_TAG_NEGATE CLIENT_TAG_RDESC CLIENT_TAG_END
		    , x));
	    } else {
		tell_object(me,
		  CLIENT_TAG_BEGIN CLIENT_TAG_EXITS CLIENT_TAG_END
		  //CLIENT_TAG_BEGIN CLIENT_TAG_NEGATE CLIENT_TAG_EXITS CLIENT_TAG_END
		  CLIENT_TAG_BEGIN CLIENT_TAG_NEGATE CLIENT_TAG_RDESC CLIENT_TAG_END
		);
	    }
	}
	return 1;
    }

    // Looking at self? That works everywhere...

    if (arg == "at me" || arg == "at self" || arg == "at myself")
    {
	if (!me->query_can_see()) return 0;
	item = (string)me->query_real_name();
	see_level = 7;		// Hack to by-pass light checks.
	ob = me;
    } else
    {
	if (!sscanf(arg, "at %s", item) &&
	  !sscanf(arg, "in %s", item)) {
	    me -> tell_me("Look AT something, or what?");
	    return 1;
	}
	item = lower_case(item);

        // Now possible for players to "look at" an item by its hash too.
        if (sizeof(item) == 40 && me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
            // First take a look at our inventory.
            foreach (object thing : all_inventory(me)) {
                if (item == hash(TLS_HASH_SHA1, object_name(thing))) {
                    ob = thing;
                    break;
                }
            }

            // Next take a look around us.
            if (!ob) {
                foreach (object thing : all_inventory(environment(me))) {
                    if (item == hash(TLS_HASH_SHA1, object_name(thing))) {
                        ob = thing;
                        break;
                    }
                }
            }
        }

	if (!ob) ob = present(item, me);
	if (!ob && environment(me)->id(item))
	    ob = environment(me);
	if (!ob) ob = present(item, environment(me));

	if (!ob)
	{
	    return notify_fail(sprintf(
		"You can't see any \"%s\" here.\n", item)), 0;
	}

	see_level = (int) me->test_dark();
	if (see_level < 0) see_level = -see_level;
	if (see_level == 1) return 0;	// == !query_can_see()

	// Now we'll check if we can see it here.
	switch (see_level) {
	case 2:
	    return notify_fail("It's too dark here for you to examine it.\n"), 0;
	case 3:
	    return notify_fail("It's too bright here for you to examine it.\n"), 0;
	case 4: case 5: case 6:
	    if (!ob->query(LIV_IS_PLAYER_OR_NPC) || ob->query(LIV_UNDEAD))
		return notify_fail("It's too dark here for \
you to examine it.\n"), 0;
	    is_living = 1;
	    break;
	}
    }

    if (!is_living) is_living = (int) ob->query(LIV_IS_PLAYER_OR_NPC);

    //ob -> long(item, me);

    me->tell_me(ob->query_long(item,me));

    if (!is_living) {
	i = (int) ob -> query_weight();
	if (i >= 10) me -> tell_me("It seems to be extremely heavy.");
	else
	if (i >= 5) me -> tell_me("It seems to be very heavy.");
	else if (i >= 3) me -> tell_me("It seems to be quite heavy.");
    }

    if (!ob->can_put_and_get(item)) return 1;

    if (!(inv = all_inventory(ob)) || !(max = sizeof(inv)))
	return 1;

    item = (string) ob->query_name(see_ilevel, me);
    if (!item) item = "Something";
    else item = capitalize(item);

    /* Extra looks */
    if (is_living) {
	inv2 = allocate(sizeof(inv));
	for(i = sizeof(inv) - 1, x = 0; i >= 0; i--)
	    if (inv2[i] = (string)inv[i]->extra_look(me))
		x++;
	if (x) me->tell_me(efun::implode(inv2, "\n"));
    }

    if (max > MAX_ITEMS) {
	inv = inv[0..MAX_ITEMS] + ({ "*** TRUNCATED ***" });
	max = MAX_ITEMS;
    }

    for(i = x = 0; i < max; i++) {
	if (!is_living || inv[i] -> is_used()
	  // 'Is_used' means that it's used somehow; worn, wielded... maybe
	  // torches would be used when they are lit and carried?
	  || inv[i] -> query_light_level())
	    if (inv[i] =  inv[i] -> short(see_ilevel, me)) x++;
    }

    if (is_living) {
	if (short_str = (string) ob -> query_clothing_text()) {
	    if (!x) me->tell_me(short_str);
	    else {
		me->tell_me(sprintf("%s\n%s is using:",
		    short_str, item));
		print_items(me, inv);
	    }
	} else {
	    if (!x) me->tell_me(sprintf("%s is using:\n- Nothing -",
		    item));
	    else {
		me->tell_me(sprintf("%s is using:", item));
		print_items(me, inv);
	    }
	}
    } else  {
	if (!x) me->tell_me(sprintf("%s contains:\n- Nothing -",
		item));
	else {
	    me->tell_me(sprintf("%s contains:", item));
	    print_items(me, inv);
	}
    }

    if (is_living && !me->query_coder_level() && me != ob)
	ob->tell_me(sprintf("%s looks at you.",
	    (string)this_player()->query_name()));
    return 1;
}
