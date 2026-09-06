// Moved this command to /bin/pub 17-oct-95. -+ Doomdark +-
// Can see own inventory in any light condition. Graah 23-Jun-96

/* Now also supports the 'Murder'-client. -+ Doomdark 23-Jan-98 +- */


#include <tell_me.h>
#include <player_defs.h>
#include <client_defs.h>

int
print_items(object me, mixed *items, int tell_type)
{
    int i, last, amount, same_amount;
    if (!sizeof(items)) return 0;
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
    me->tell_me(implode(items, ".\n"), 0, tell_type, 0, 0, 0);
    return amount;
}

int
inventory_cmd(string arg, object me)
{
    string text;
    object who;
    mixed *ob;
    int i;

    if (!me && !(me = this_player())) return 0;
    if (!me->query_can_move()) return 0;
    if (me->test_dark()) return 0;

    if (arg)
    {
	//       Moved up to include !arg  Nov 13, 1998 - Kieve
	//      if (me->test_dark()) return 0;
	who = present(lower_case(arg),environment(me));
	if(!who) {
	    notify_fail("You can't see any " + arg + " around here.\n");
	    return 0;
	}
	if(living(who)) {
	    text = "\t" + capitalize(arg) + " is carrying:";
	    if (who != me && !me->query_coder_level())
		who -> tell_me((string) me->query_name(0, who) +
		  " looks at your inventory.");
	}
	else text = "\t" + capitalize(arg) + " contains:";
	me->tell_me(text);
	ob = all_inventory(who);
	while (i < sizeof(ob)) {
	    ob[i] = (string) ob[i]->query_short(0, me);
	    i++;
	}
	if (!print_items(me, ob, TELL_TYPE_INV_ITEM))
	    me->tell_me("- Nothing -");
	return 1;
    }

    /* Client-proggy may want different input: */
    if ((int) me->query_client() == CLIENT_MURDER) {
	ob = all_inventory(me);
	// Do we care about hallucinations? No?
	tell_object(me, 
	  CLIENT_TAG_BEGIN CLIENT_TAG_INV CLIENT_TAG_END);
	for (i = 0; i < sizeof(ob); i++) {
	    if ((who = ob[i]) == me)
		continue;
	    if (text = (string) who->short(0, me)) {
		tell_object(me, sprintf(
		    CLIENT_TAG_BEGIN CLIENT_TAG_ITEM " %x" CLIENT_TAG_END
		    "%s",
		    /* Depending on can we get a unique id with objectp(): */
#if 1
		    objectp(who)
#else
		    -1
#endif
		    ,text));
	    }
	}
	tell_object(me, CLIENT_TAG_BEGIN
	  CLIENT_TAG_NEGATE CLIENT_TAG_INV CLIENT_TAG_END);
	return 1;
    }

    me->tell_me("You are carrying:");
    ob = all_inventory(me);
    while (i < sizeof(ob)) {
	ob[i] = (string) ob[i]->query_short(0, me);
	i++;
    }
    if (!print_items(me, ob, TELL_TYPE_INVENTORY))
	me->tell_me("- Nothing -");

    return 1;
}
