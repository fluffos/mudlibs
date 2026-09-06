#include <daemons.h>
#include <living_defs.h>
#include <treasure.h>

#define TOSS_VALUE	19	/* What's the max. value of 'tossable' items. */
#define	TOSS_RECEIVE	5	/* How much player gets for tossing. */
#define TP this_player()


status get() { return 0; }

void create_treasure()
{
    set_name("trashcan");
    set_id(({"can","the trashcan","green trashcan"}));
    set_short("A trashcan");
    set_long(
      "It is a green trashcan. You can toss unneccessary items and trashes into it.\
 It is better to drop them in trashcan than on the ground! To waste something\
 into the can it you should type:\t toss <object>\n\
Only things with a value below "+(TOSS_VALUE+1)+" can be dropped in it.\
 For keeping the Mud clean, you will receive "+TOSS_RECEIVE+" gold coins\
 for each item you toss.");
}


void init_treasure() {
    add_action("toss_cmd","toss");
}


int toss_item(object item, object me)
{
    if (!objectp(item) || !objectp(me)) return 0;

    move_object(item, "/room/void");

    if (!item->id("form")) {
	me->add_money(TOSS_RECEIVE);

	// Log cheaters
	log_file("TRASHCAN", (string)me->query_real_name()
	  + " tossed " + object_name(item)
	  + " at " + ctime(time()) + "\n");
    }

    me->add_weight(-(int)item->query_weight());

    if (me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
	TELOPT_D->send_char_items_remove(me, "inv", item);
    }

    destruct(item);

    return 1;
}


status toss_cmd(string str, object me)
{
    if (!str) return notify_fail("Toss what?\n"), 0;
    if (!me && !(me=this_player())) return 0;

    string a,b;
    if (sscanf(str,"%scoin%s", a, b) == 2) {
	me->tell_me("Throw away money?");
	return 1;
    }

    object item;

    if (str == "all")
    {
	string trash = query_name();
	string item_name, me_name = (string)me->query_name(0,me);
	object *stuff, *obs = all_inventory(me);
	int count = 0;

	foreach(item : obs) {
	    if (!item || item->drop(1) || !item->short()) continue;
	    if ((int)item->query_value() >= TOSS_VALUE) continue;
	    if (item->is_used() || item->is_held()) continue;
	    stuff = all_inventory(item);
	    if (stuff && sizeof(stuff)) continue;
	    item_name = (string)item->query_name()||"something";
	    if (!toss_item(item, me)) continue;
	    me->tell_me("You toss "+item_name+" in the "+trash+".");
	    environment(me)->tell_here(me_name+ " tossed "+item_name+" in the "+trash+".", me);
	    count++;
	}
	if (!count)  me->tell_me("You don't have anything worth tossing.");
	return 1;
    }


    if (!(item = present(str, me)))
	return notify_fail("You don't have any '"+str+"'.\n"), 0;

    if ((int)item->query_value() >= TOSS_VALUE) {
	me->tell_me("That is worth "+(TOSS_VALUE + 1)
	  +" coins or more. You'd better sell it in a shop.");
	return 1;
    }

    if (item->is_used() || item->is_held()) {
	me->tell_me("You must remove it first.");
	return 1;
    }

    object *stuff = all_inventory(item);
    if (stuff && sizeof(stuff)) {
	me->tell_me("There is something inside that item. Empty it before tossing.");
	return 1;
    }

    // Hmmm... Being living-object doesn't mean anything nowadays... *shrug*
    if (living(item)) {
	me->tell_me ("But...but... you don't have the heart to toss that. It's alive!");
	return 1;
    }

    if (item->id("form")) {
	me->tell_me("You toss a form into the "+query_name()+".");
	me->add_weight(-(int)item->query_weight());

	if (me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
	    TELOPT_D->send_char_items_remove(me, "inv", item);
	}

	destruct(item);

	return 1;
    }

    if (item->id("baby")) {
	me->tell_me("You toss the whining brat in the "+query_name()+". How cruel of you. ");
	me->add_weight(-(int)item->query_weight());

	if (me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
	    TELOPT_D->send_char_items_remove(me, "inv", item);
	}

	destruct(item);
	me->set_luck(-5+(-random(3)));
	me->add_alignment(50000); // We sort of kill a "good" baby
	return 1;
    }

    if (item->drop(1) || !item->short()) {
	me->tell_me("You can't toss that!\n");
	return 1;
    }

    if (!toss_item(item, me)) {
	me->tell_me("You can't toss that.");
	return 1;
    }

    me->tell_me("You toss it in the "+query_name()+".");
    environment(me)->tell_here((string)me->query_name(0, me)
      + " tossed something in the "+query_name()+".", me);
    return 1;
}
