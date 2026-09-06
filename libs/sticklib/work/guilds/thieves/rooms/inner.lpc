#include <room.h>
#include <stats.h>

#include <coder_levels.h>
#include <door_defs.h>

#include "dirs.h"

#define REALNAME(x) ((string)(x)->query_real_name())
#define Realname(x) (capitalize((string)(x)->query_real_name()))
#define TP this_player()

object master, door, guard;
int garrottes;
string *whotook;

void reset_room();

void
create_room() {
    set_short("Guildmaster's Room");
    set_long(
      "This is the private chamber of the Guildmaster. From here he rules " +
      "The Guild of Thieves and collects the taxes. On the wall hangs some "+
      "garrottes. On the wall is also some writing. Perhaps you could try to "+
      "read it?");
    add_exit("west", GDIR + "rooms/guild");
    add_exit("south", GDIR + "rooms/gmstorage");
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(ROOM_PREVENT_WHERE);
    set(ROOM_GUILD);

    // No crystal nor where! Unfair!!! //Graah
    // where is back..all other guilds have their where object..
    // thought i'd put the ball back..--Colt :)
    add_permanent(GDIR+"obj/crystal_ball");

    garrottes = 6; whotook = ({});

    reset_room();
}

void
reset_room() {
    if (!present("door", this_object())) {
	if ((door = clone_object(DOOR_FILE))) {
	    door->add_door( ({
		"It is a reinforced wooden door.",
		"It is a reinforced wooden door." }),
	      "west", GDIR + "rooms/guild", "firm steel",
	      "canthavethiskey", 1, 1, 1, 5,
	      "It is an easy lock to pick.\n" );
	}
    }

    if (!guard) {
	guard = clone_object(GDIR + "npc/gmguard");
	move_object(guard, this_object());
    }
}

query_drop_castle() { return 1; }

init_room(zoppa) {
    add_action("gc", "get"); add_action("gc", "take");
    add_action("replace", "replace");
    add_action("read", "read"); add_action("read", "exa", 1);
    //    add_action("east","east");
    add_action("south", "south");

    /* Most Ninja skills are too small to harm gargantuan guard! */
    add_action("kick_handler", "kick");
    add_action("kick_handler", "mkick");
    add_action("kick_handler", "assassin");

    /* Fighters can't aim, bash, slash nor smash */
    add_action("figh_handler", "aim");
    add_action("figh_handler", "bash");
    add_action("figh_handler", "slash");
    add_action("figh_handler", "smash");

    /* We are more clever than Frobozz! :-D :-D */
    if (!zoppa && present("fsymbol", TP))
	call_out("_do_kludgy_stuff", 1, TP);

    /* Guard teleports always back */
    if (guard && !present(guard, this_object())) {
	guard->move_player("X#" + GDIR + "rooms/inner");
    }
}

/* High Magick! :-) */
nomask void
_do_kludgy_stuff(object ob)
{
    if (!ob || environment(ob) != this_object()) return;

    ob->_very_strange_kludge();
    call_out("_do_kludgy_stuff", 1, ob);
}

/* Ninjas will love this! */
int
kick_handler(string arg)
{
    /* No gargantuan guard, ignore this. */
    if (!guard) return 0;

    /* Not a ninja? */
    if (!present("nmark", TP)) return 0;

    if ((!arg && (object)TP->query_attack() == guard) ||
      (arg && present(arg, environment(TP)) == guard)) {
	write(({
	    "Gargantuan guard is far too BIG to be harmed by martial arts!",
	    "You can't possibly harm so BIG creature with martial arts!",
	    "Yeah, sure. It would be like karate-chopping a mountain!"
	  })[random(3)] + "\n");
	return 1;
    }

    return 0;
}

/* And fighters will love this! */
int
figh_handler(string arg)
{
    /* No gargantuan guard, ignore this. */
    if (!guard) return 0;

    /* Not a fighter? */
    if (!present("fsymbol", TP)) return 0;

    if ((!arg && (object)TP->query_attack() == guard) ||
      (arg && present(arg, environment(TP)) == guard)) {

	switch(query_verb()) {
	case "aim":
	    write(
	      "Gargantuan guard is too large, you can just aim at his feet!\n");
	    return 1;
	    break;
	case "bash":
	    write(
	      "Bashing won't do anything special on a creature this big!\n");
	    return 1;
	    break;
	case "slash":
	    write("It would be like slashing a mountain!\n");
	    return 1;
	    break;
	case "smash":
	    write("It would be like smashing a mountain!\n");
	    return 1;
	    break;
	default:
	    return 0;
	}

	return 1;
    }

    return 0;
}

int
read(string arg) {
    if (arg != "wall" && arg != "writing") {
	notify_fail("What did you want to read?\n");
	return 0;
    }

    write("Thieves can \"get garrotte\" and \"replace garrotte\" here.\n");

    if (garrottes > 0) {
	if (garrottes == 1)
	    write("There is only one garrotte left.\n");
	else
	    write("There are " + garrottes + " garrottes remaining.\n");
    } else
	write("Currently there is none of them left.\n");

    if (whotook && sizeof(whotook) > 0) {
	if (sizeof(whotook) == 1)
	    write(whotook[0] + " has recently taken one.\n");
	else
	    write("These thieves have recently taken a garrotte here:\n" +
	      implode(whotook, ", ", " and ") + ".\n");
    }

    return 1;
}

int
gc(string arg)
{
    object tm, gr, *inv;
    int i;

    if (arg != "garrotte") return 0;

    if (present("garrotte", this_object())) return 0;

    /*
	write("Due the Link Death cheaters garrotte has been removed.\n");
	return 1;
    */

    /* Rules: Either an Enforcer/GM or Level 25, Str 25 and Dex 25. */

    if (!(tm = present("tmark", TP))) {
	write("Your hand passes through it.\n");
	return 1;
    }

    inv = deep_inventory(TP);
    for (i = 0; i < sizeof(inv); i++) {
	if (inv[i]->id("garrotte")) {
	    write("You already have one.\n");
	    return 1;
	}
    }

    if (garrottes < 1) {
	write("There are none left.\n");
	return 1;
    }

    if (member(whotook, Realname(TP)) != -1) {
	write("But you just recently took one!\n");
	return 1;
    }

    whotook += ({ Realname(TP) });

    call_other(GDIR + "rooms/treasury", "???");

    if (!(gr = present("garrotte", find_object(GDIR + "rooms/treasury"))))
	gr = clone_object(GDIR + "obj/garrotte");

    say((string)TP->query_name() +
      " gets one garrotte from the wall.\n");

    if (!TP->add_weight((int)gr->query_weight())) {
	write("Ok. Oops, it slips from your fingers.\n");
	say(capitalize((string)TP->query_pronoun()) +
	  " fumbles and drops it.\n");
	move_object(gr, this_object());
    } else {
	write("Ok. You take one garrotte.\n");
	move_object(gr, TP);
    }

    gr->set_taker(Realname(TP));

    if (!TP->query_coder_level()) garrottes--;

    if (!garrottes) write("That was the last one.\n");
    else if (garrottes == 1) write("There is only one left on the wall.\n");
    else write("There are still " + garrottes + " of them remaining.\n");

    write("You can 'replace garrotte' to put it back.\n");

    return 1;
}

int
replace(string arg)
{
    string taker;
    object gr;

    if (!arg) {
	notify_fail("What do you want to replace?\n");
	return 0;
    }

    if (arg[0..7] != "garrotte") {
	notify_fail("How do you replace " + arg + "???\n");
	return 0;
    }

    if (!(gr = present("garrotte", TP))) {
	write("You are not even carrying one.\n");
	return 1;
    }

    if (!gr->query_thief_item()) {
	write("That is not a real garrotte!\n");
	return 1;
    }

    write("Ok. You put your garrotte back on the wall.\n");
    say((string)TP->query_name() + " hangs " +
      (string)TP->query_possessive() +
      " garrotte on the wall.\n");
    TP->add_weight((int)gr->query_weight());
    move_object(gr, GDIR + "rooms/treasury");

    if (garrottes < 6) garrottes++;

    taker = (string)gr->query_taker();
    if (!taker) taker = Realname(TP);

    if (member(whotook, taker) != -1)
	whotook -= ({ taker });

    return 1;
}

void set_garrottes(int g) { garrottes = g; }
void set_whotook(string *w) { whotook = w; }

int
south()
{
    object tm;

    if (!guard) return 0;

    if(this_player()->query_coder_level())
	return 0;

    if (!(tm = present("tmark", TP))) {
	write(
	  "Guard blocks your way and rumbles: PISS OFF INSECT!\n");
	return 1;
    }

    if (tm->query_guildmaster() < 1) {
	write(
	  "Guard blocks your way and says: YOU IS NOT ONE OF LEADER!\n");
	return 1;
    }

    write("Guard lets you pass.\n");

    return 0;
}
