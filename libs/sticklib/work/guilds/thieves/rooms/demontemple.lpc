/*

clone ~frobozz/OV/bonecrusher
goto /areas/mansion_of_kantele/room/hellgate
zap gatekeeper
get all from corpse
cc here
cd
clone obj/gold_ring
in /room/lords_pub buy fire
goto ~flathead/toptower
zap sauron
get palandir
cc here
home

*/

#include <room.h>

#include "thief.h"
#include <weapon_defs.h>
#include <bboard_defs.h>
#include <generic_items.h>
#include <guild.h>
inherit "/basic/misc/emote";

#define TP this_player()

int valid_board_access(object me);
int clean_up(status flag) { return 0; }

void
create_room()
{
    set_short("Demons' Temple");
    set_long(
      "The walls of this large hall are all covered by black silk curtains. \
The floor and ceiling are covered by shining black obsidian tiles. \
There is a huge block of obsidian, a some kind of an altar, \
at the other end of the room.");
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_NONE);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);

    add_exit("north", GDIR + "rooms/inst_bot");

    add_item(({ "block", "altar" }),
      "There are some letters carved into the stone. Perhaps you should \
\"read altar?\"");
    add_item(({ "curtains", "black", "silk" }),
      "The curtains are made of the finest black silk.");
    add_item(({ "floor", "tiles", "obsidian", "ceiling" }),
      "The obsidian is perfectly smooth and magically enhanced.");

    add_command("strike", "strike");
    add_command("make", "make");
    add_command ("emote","emote_cmd");

    add_object( ({ GENERIC_BBOARD,
	({ "set_board", 100, ([ BB_WRITE_CLOSURE : #'valid_board_access,
	    BB_READ_CLOSURE : #'valid_board_access, ]), "thief_dem_board", 0 }),
      }), 0, 1);
}

int valid_board_access(object me)
{
    return (this_player()->query_coder_level()  ||
      (string)this_player()->query_guild() == GN_THIEF);
}

status
read_cmd(string arg)
{
    object tm;
    string ntmp;
    string *names;
    int i;

    names = GM_D->query_demons();
    ntmp = "";
    if (!arg ||
      lower_case(arg) != "altar")
	return 0;

    if (!(tm = present("tmark", TP)))
    {
	TP->tell_me("You can't understand the writing.");
	return 1;
    }

    TP->tell_me(
      "There are names: "
    );
    for(i=0;i<sizeof(names);i++) {
	ntmp += capitalize(names[i])+"\n";
    }
    TP->tell_me(ntmp+"written in fiery lettering on the altar. ");

    if ((int)tm->query_guildmaster() < TR_DEMON)
	return 1;

    TP->tell_me(
      "\nYou can also read a smaller text:\n\
\"Wield a powerful weapon, carry lots of gold, strike altar. \
Something might happen...\"");

    TP->tell_me(
      "\nA new engraving says: Get a Golden Ring and a Firebreather, \
wield the Hammer of Bonecrushing, wear the Robes of the Gatekeeper \
of Hell, hold the Palandir, and be ready to sacrifice five thousand \
in gold, and you will be able to make the Ring - an obsidian ring \
which will resist stunning and freezing.");

    return 1;
}

status
strike(string arg)
{
    object tm, wep;
    int cost, wc;

    if (!arg ||
      lower_case(arg) != "altar")
	return 0;

    if (!(tm = present("tmark", TP)) ||
      ((int)tm->query_guildmaster() < TR_DEMON) ||
      !(wep = (object)TP->query_weapon()))
    {
	TP->tell_me("You strike the altar. Nothing happens.");
	tell_here((string)TP->query_name() + " hits the altar.", ({ TP }));
	return 1;
    }

    wc = (int)wep->query_wc();
    if (wc > 19) wc = 19; /* Never more than this now. //Graah */
    cost = (wc * 200) + ((wc / 5) * 200);
    if (wc > 19) cost += 500;
    if (wc > 20) cost += 500;

    TP->tell_me("You strike the altar with your " +
      (string)wep->query_name() + ".");
    tell_here((string)TP->query_name() + " hits the altar with " +
      (string)wep->query_name() + "!", ({ TP }));

    if ((int)TP->query_money() < cost)
    {
	TP->tell_me("Nothing happens. Perhaps you didn't have enough gold.");
	return 1;
    }

    if (wep->drop(1) ||
      wep->id("obsidian"))
    {
	TP->tell_me("Nothing happens.");
	return 1;
    }

    TP->add_money(-cost);
    TP->tell_me(cost + " gold coins vanish from your purse!");

    tell_here("In a puff of black smoke, " +
      (string)wep->query_name() + " changes into something else!");

    TP->unwield(wep, 0);
    TP->add_weight(-((int)wep->query_weight()));
    destruct(wep);

    wc += 4;
    /* if (wc > 25) wc = 25; */
    /* Never make two-handed for now - it's throwable. //Graah */
    if (wc > 20) wc = 20;

    wep = clone_object(WEAPON_FILE);

    if (wc > 20)
    {
	wep->set_name("two-handed black obsidian sword");
	wep->set_id(({"two-handed","black","obsidian",
	    "sword","demon_2H_sword"})); // To allow tth and wield
	wep->set_short("Two-Handed Black Obsidian Sword");
	wep->set_long(
	  "It's a neat two-handed sword made of magical black obsidian!");
	wep->set(WP_TWO_HANDED);
	wep->set_weight(3);
    }
    /* Was 10, now _only_ makes daggers! */
    else if (wc > 20)
    {
	wep->set_name("black obsidian sword");
	wep->set_short("Black Obsidian Sword");
	wep->set_id(({ "black", "obsidian", "sword" }));
	wep->set_long("It's a neat broad sword made of magical black obsidian!");
	wep->set_weight(2);
    }
    else
    {
	wep->set_name("black obsidian knife");
	wep->set_short("Black Obsidian Knife");
	wep->set_id(({ "black", "obsidian", "knife", "dagger" }));
	wep->set_long("It's a neat knife made of magical black obsidian!");
	wep->set_weight(1);
    }

    wep->set(WP_TROLL_WEAPON);
    wep->set_wc(wc);
    wep->set(WP_SHARP);
    wep->set_value(cost / 10 + random(cost / 10));

    MASTER_OB->thief_log("DEMONSWORD",
      (string)this_player()->query_real_name() + "/" +
      ctime(time())[4..9] + "/" +
      "wc" + wc + "/gp" + cost + "\n");

    if (random(100) < 20)
    {
	TP->tell_me(
	  "Oops. Your new weapon is dull. You'll have to get it sharpened.");
	wep->set_bluntness(random(wc / 2));
    }

    if (!TP->add_weight(3))
    {
	TP->tell_me("You drop the weapon in amazement.");
	tell_here((string)TP->query_name() + " drops " +
	  (string)wep->query_name() + ".", ({ TP }));
	move_object(wep, this_object());
    }
    else
    {
	move_object(wep, TP);
	if (wep->query_bluntness())
	    TP->tell_me("You decide not to wield it for now.");
	else
	    TP->wield(wep, 0);
    }

    return 1;
}


status
make(string arg)
{
    object tm, ob, *ingr;
    int i, cost;

    notify_fail("Make what?\n");

    if (!arg ||
      member(({ "ring", "the ring", "obsidian ring" }), lower_case(arg)) == -1)
    {
	if (arg) notify_fail("Make \"" + arg + "\"? Interesting attempt...\n");
	return 0;
    }

    if (!(tm = present("tmark", TP)) ||
      ((int)tm->query_guildmaster() < TR_DEMON))
    {
	return 0;
    }

    cost = 5000;

    /* Ingredients? */
    ingr = ({ });

    /* A golden ring */
    if ((ob = present("ring", TP)) &&
      (ob->id("gold") || ob->id("golden"))) ingr += ({ ob });
    else
	TP->tell_me("You don't have one of the proper golden rings.\n");

    /* Titan's Bonecrusher Hammer */
    if ((ob = present("bonecrusher hammer", TP)))
	ingr += ({ ob });
    else
	TP->tell_me("You need the Bonecrusher Hammer to forge the ring.");

    if ((ob = present("firebreather", TP)))
	ingr += ({ ob });
    else
	TP->tell_me("You need a firebreather to drink during this hard work!");

    if ((ob = present("robe of hellgate", TP)))
	ingr += ({ ob });
    else
	TP->tell_me("You have to wear the robes of the Gatekeeper of Hell \
during the work.");

    if ((ob = present("sauron's palandir", TP)))
	ingr += ({ ob });
    else
	TP->tell_me("You need the Palandir for guidance.");

    if ((int)TP->query_money() < cost)
    {
	TP->tell_me("You need " + cost + " gold coins as a sacrifice.");
	return 1;
    }

    if (sizeof(ingr) < 5)
	return 1;

    for (i = (sizeof(ingr) - 1); i >= 0; i--)
    {
	if (!ingr[i])
	{
	    TP->tell_me("One of the ingredients is somehow missing?!?");
	    return 1;
	}

	if (ingr[i]->id("bonecrusher hammer"))
	    TP->tell_me("The bonecrusher hammer is totally worn out \
after this kind of work. You throw the remains away.");
	else if (ingr[i]->id("firebreather"))
	    TP->tell_me("You drink the firebreather, which gives you strength.");
	else if (ingr[i]->id("robe of hellgate"))
	    TP->tell_me("Gray robes get burned full of holes during the work. \
You throw the rags away.");
	else if (ingr[i]->id("sauron's palandir"))
	    TP->tell_me("The Palandir shatters after you've finished the task.");
    }

    tell_here((string)TP->query_name() +
      " sacrifices some things on the altar.", ({ TP }));

    TP->add_money(-cost);
    TP->tell_me("You sacrifice " + cost + " gold coins.");

    for (i = (sizeof(ingr) - 1); i >= 0; i--)
    {
	TP->add_weight(-((int)ingr[i]->query_weight()));
	destruct(ingr[i]);
    }

    ob = clone_object(GDIR + "obj/obsidian_ring");

    TP->tell_me(
      "With the help of the Great Demon Skert, you manage to forge an \
obsidian ring!");
    tell_here((string)TP->query_name() +
      " forges something furiously with an unnatural skill!",
      ({ TP }));

    // Important!!!
    ob->set_owner(TP);

    move_object(ob, TP);
    TP->tell_me("You get the ring.\n");

    master_object()->thief_log("RING", ctime(time())[4..9] + ": " +
      capitalize((string)TP->query_real_name()) + "\n");

    return 1;
}
