#include <room.h>
#include <corpse_defs.h>
#include "/areas/tristeza/DEFS.h"

#include <tune.h>

#include "dirs.h"

#define EXP_COST 2979

/* Don't log blessings & sacrifices now */
#undef LOG_EVENTS

object priestess, key;

void
create_room()
{
    object ob;

    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(IN_CITY);
    set_short("Temple");
    set_long(
      "You are in the Temple of Skert. This room is very cold and dark. "+
      "You feel uneasy and alert. Here's a large altar covered with cloth. "+
      "Many black candles light the room. There is an entrance to the "+
      "Priestess' room to the north.");
    add_exit("west", CITY_DIR+"S10_11");
    add_item(({ "altar" }), "It is covered with black cloth.");
    add_item(({ "candles" }), "The light is dim and eerie.");
    add_item(({ "cloth", "black cloth" }), "It is sewn with evil symbols.");
    add_monster(GDIR + "npc/priestess", "Priestess arrives.", 1);
    set_commands(([
	"pray"	: "pray",
	"kneel"	: "pray",
	"east"	: "pray",
	"sacrifice" : "sacrifice",
	"offer"	: "sacrifice",
	"cremate"	: "cremate",
	"touch"	: "touch",
	"north"	: "north"
      ]));
}

/* No need for init. Commands added with "set_commands".
init_room() {
    add_action("pray","pray");
    add_action("pray","kneel");
    add_action("pray", "east");	// Shortcut for thieves (don't need to pray)
    add_action("sacrifice","sacrifice");
    add_action("sacrifice","offer");
    add_action("cremate","cremate");
    add_action("north","north");
    add_action("touch","touch");
}
*/

pray(str) {
    object d;

    if (!present("tmark",this_player())) return 0;

    write("Ok.\n");

    write("You are momentaily blinded. When you can see again, you\n" +
      "find yourself in another place...\n\n");

    this_player()->move_player("X#" + GDIR2 + "rooms/entry");
    return 1;
}


sacrifice(str)
{
    string tmp;
    int value,exp;
    object thief;
    object obj;

    thief = this_player();

    if (!present("tmark",thief)) return 0;

    /* Now we can!
       if (!present("priestess")) {
	  notify_fail("The Priestess is not here. You cannot do this yourself.\n");
	  return 1;
       }
    */
    if (!str) {
	notify_fail("What do you want to sacrifice?\n");
	return 1;
    }

    tmp = lower_case(str);

    if (tmp == "gold" || tmp == "money" || tmp == "coins") {
	notify_fail("Skert doesn't want money.\n");
	return 0;
    }

    obj = present(tmp);

    if (!obj) obj = present(tmp, this_player());
    if (!obj) {
	notify_fail("That is not here.\n");
	return 0;
    }

    if (living(obj)) {
	notify_fail("You cannot sacrifice living things.\n");
	return 0;
    }

    if (tmp == "corpse") {
	notify_fail("You should 'cremate corpse' to honour the dead one.\n");
	return 0;
    }

    value = call_other(obj,"query_value",0);

    if (!value) {
	notify_fail("It's worthless. You can't sacrifice it.\n");
	return 0;
    }

    write("You sacrifice an item that equals " + value + " gold coins.\n");
    if (value > 2200) value = 2200;

    exp = value * EXP_COST / 2979;

    write("You are rewarded by "+exp+" experience points!\n");
    say(call_other(thief, "query_name") + " sacrifices the " + tmp + ".\n");

#ifdef LOG_EVENTS
    log_file("thief_guild", thief->query_real_name() + " sacrificed " +
      obj->short() + " (" + object_name(obj) + ") for " + exp + " xp\n");
#endif
    call_other(thief, "add_exp", exp);
    destruct(obj);
    return 1;
}

north() {
    if(present("priestess")) {
	if (!present("tmark",this_player())) {
	    write("The Priestess smiles and says: Hey, that's my room!\n");
	    if(!this_player()->query_coder_level()) {
		write("You decide to avoid offending her.\n");
		say(this_player()->query_name() + " tries to go north, but "+
		  "the Priestess stops " + this_player()->query_objective() +
		  ".\n");
		return 1;
	    }
	    write("But, since you are a coder, you walk through her.\n");
	} else
	    write("The Priestess smiles knowingly and lets you pass.\n");
    }
    this_player()->move_player("north#" + GDIR2 + "rooms/prs_room");
    return 1;
}

touch(str) {
    if(!str) return 0;
    if(str != "altar") return 0;

    write("Woosh! (Oh no...)\n");
    this_player()->move_player("X#" + GDIR2 + "rooms/skert_home");
    return 1;
}

/* New: cremate corpses to honour the dead being */
cremate(str) {
    string tmp;
    int i;
    object thief, ob, *inv;

    thief = this_player();

    if(!present("tmark",thief)) return 0;

    if (!str) {
	write("What do you want to cremate?\n");
	return 1;
    }
    if(str == "gold" || str == "money" || str == "coins") {
	write("You try to burn your money, but it doesn't work.\n");
	return 1;
    }
    tmp = str;
    ob = present(str);
    if (!ob) ob = present(str,thief);
    if (!ob) {
	write("That is not here.\n");
	return 1;
    }
    if(living(ob)) {
	write("I'm afraid that " + ob->query_name() +
	  " is still alive.\n");
	return 1;
    }
    if (!sscanf(object_name(ob), (CORPSE_FILE)[1..<1]+"#%s", tmp)) {
	write("You can cremate only dead beings.\n");
	return 1;
    }
    write(
      "You set the corpse in front of the altar and pray Skert.\n");
    say(thief->query_name() +
      " places a corpse in front of the altar and chants something.\n",thief);

    inv = all_inventory(ob);

    /* Drop the things from it first */
    for (i = 0; i < sizeof(inv); i++) {
	if (!inv[i]->drop()) transfer(inv[i],this_object());
    }

    if (present(ob,thief)) thief->add_weight(-(ob->query_weight()));

    destruct(ob);

    if (ob) {
	write("Something went wrong. The corpse remains.\n");
	return 1;
    }

    write(
      "Your prayer is answered! White-hot flames consume the corpse!\n");
    say("\nThe corpse is consumed in white-hot flames!\n",thief);

    thief->add_exp(5 + random(thief->query_level()));

    write(
      "You feel self-contented. Yet another one laid to rest honourably.\n");

    return 1;
}
