#include <room.h>
#include <corpse_defs.h>
#include <door_defs.h>

#include "dirs.h"

#define TP this_player()
#define QN query_name()

#define BERRY "1"
#define MIX   "2"
#define BEEF  "3"
#define BREW  "4"

#define BERRY_COST 50
#define MIX_COST  150
#define BEEF_COST 300
#define BREW_COST 500

int amount_brew;

object door;
int dip_sauce, goppa, poison_str;
string maker, corpse_name;

void
create_room() {
    amount_brew = 5;
    set_short("Kitchen");
    set_long(
      "The walls of this large room are covered by polished white stone tiles. "+
      "There's a kitchen sink in here, and a huge cauldron hangs above a "+
      "fireplace in the middle of the room.  Against a dark corner \
in the back of the room, you see counter with a man standing \
behind it.  There is a sign on the counter.");
    add_exit("southwest", GDIR + "rooms/guild");
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT_TO);
    set(ROOM_WD,WD_INDOORS);

    add_item(({ "sink", "kitchen sink" }),
      "This sink doesn't have any taps, just two sinks.");

    add_item(({ "cauldron", "huge", "huge cauldron" }),
      "The cauldron has a plaque on the side. Perhaps you should read it.");

    add_item("counter", "A low, wooden counter.  There is a \
sign posted on it.");
    add_item("man", "He is preparing something behind the counter.  \
He feels your eyes on him and looks up at you.");

    add_item("sign", "Written rather small in Thieves cant you \
read:\n\n\t1) Dried berries ... "+BERRY_COST+" coins\n\t2) Trail \
mix ... "+MIX_COST+" coins\n\t3) Dried beef ... "+BEEF_COST+" coins\n\
\t4) Thieves brew["+amount_brew+"] ... "+BREW_COST+" coins\n\nTo \
buy food use the \
command 'buy <number>'.");
    dip_sauce = poison_str = 0;

    this_object()->reset_room();
}

void
reset_room()
{
    if (!door) {
	if ((door = clone_object(DOOR_FILE))) {
	    door->add_door( ({
		"It is a reinforced ebony door.\n",
		"It is a reinforced ebony door.\n" }),
	      "southwest", GDIR + "rooms/guild", "delicate mithril",
	      "thief_master_key", 1, 1, 1, 10,
	      "It is lock which can be picked, though not very easily.\n" );
	}
    }
    amount_brew = 5;
}

string
extra_look()
{
    add_item("sign", "Written rather small in Thieves cant you \
read:\n\n\t1) Dried berries ... "+BERRY_COST+" coins\n\t2) Trail \
mix ... "+MIX_COST+" coins\n\t3) Dried beef ... "+BEEF_COST+" coins\n\
\t4) Thieves brew["+amount_brew+"] ... "+BREW_COST+" coins\n\nTo \
buy food use the \
command 'buy <number>'.");
    if (dip_sauce) return "The cauldron contains some icky green stuff.\n";
    else return "The cauldron is empty.\n";
}

void
init_room()
{
    add_action("read", "read");
    add_action("make", "make");
    add_action("dip", "dip");
    add_action("buy_food","buy");
}

int
read(string str)
{
    if (!str || (lower_case(str) != "plaque" && lower_case(str) != "sign")) {
	notify_fail("What did you say you wanted to read?\n");
	return 0;
    }

    if (!present("tmark", TP)) {
	notify_fail("You can't understand what it says.\n");
	return 0;
    }

    write("It is written in Thieves' Cant, and says:\n\n"+
      "\"Weapon poison recipe:\n\n"+
      " -\tCorpse of a player (Level 20 or more)\n"+
      " -\tone Jojojopo plant\n"+
      " -\tlump of cow shit\n"+
      " -\tone hallucinogenic mushroom\n\n"+
      " Gather and _carry_ all the ingredients and 'make poison'.\n"+
      " Poison your weapons by dipping them in poison ('dip <weapon>')\n"+
      " Multiple dippings give a coating which lasts longer.\n"+
      " Note that the tougher the player corpse is the stronger\n"+
      " poison you will get.\n");
    return 1;
}

status
make(string str)
{
    string tmp1, tmp2;
    object *ingr;
    int i;

    if (!str || lower_case(str) != "poison" || !present("tmark", TP)) {
	notify_fail("What did you want to make?\n");
	return 0;
    }

    if (dip_sauce > 0) {
	notify_fail("But there already is poison in the cauldron!\n");
	return 0;
    }

    ingr = ({ 0,0,0,0 });

    if (!(ingr[0] = present("corpse", TP)) ||
      (sscanf(object_name(ingr[0]), (CORPSE_FILE)[1..<1]+"#%s", tmp1) != 1) ||
      !ingr[0]->query_was_player() ||
      ((int)ingr[0]->query_orig_level() < 20)) {
	notify_fail("You need a player corpse, level at least 20.\n");
	return 0;
    }

    poison_str = (int)ingr[0]->query_orig_level() - 15;
    corpse_name = (string)ingr[0]->query_orig_name();

    if (!(ingr[1] = present("jojojopo", TP))) {
	notify_fail("You don't have a Jojojopo plant.\n");
	return 0;
    }

    if (!(ingr[2] = present("cow shit", TP))) {
	notify_fail("You don't have cow shit.\n");
	return 0;
    }

    if (!(ingr[3] = present("small mushroom", TP)) ||
      (sscanf(object_name(ingr[3]),
	  GDIR + "obj/psilocybe#%s", tmp1) != 1)) {
	notify_fail("You don't have the mushroom.\n");
	return 0;
    }

    write("Great! You have all the correct ingredients.\n"+
      "You place them in the cauldron and wait.\n");
    say(TP->query_name() + " places some stuff in the cauldron.\n");

    for (i = 0; i < 4; i++) {
	TP->add_weight(-((int)ingr[i]->query_weight()));
	destruct(ingr[i]);
    }

    maker = (string)TP->query_real_name();

    goppa = 0;
    call_out("makepoison", 2);
    return 1;
}

void makepoison()
{
    if (goppa < 3) {
	tell_room(this_object(), ({
	    "Magical fire starts heating the cauldron.",
	    "A foul smell fills the room.",
	    "The cauldron steams and bubbles."
	  })[goppa] + "\n");
	goppa++;
	call_out("makepoison", 2);
	return;
    }

    tell_room(this_object(),
      "The poison is ready! You can now dip weapons into it.\n");

    dip_sauce = 20 + random(10);

    "/secure/master"->thief_log("POISON_MAKERS",
      ctime(time())[4..9] + ": " + maker + ", corpse level " +
      poison_str + " (" + corpse_name + ")\n");
}

int
dip(string str)
{
    object ob;

    if (!str) {
	notify_fail("Dip what?\n");
	return 0;
    }

    if (!(ob = present(lower_case(str), TP))) {
	notify_fail("You don't seem to carry any \"" + str + "\".\n");
	return 0;
    }

    if (!dip_sauce) {
	notify_fail("You can see nothing to dip " + ob->short() + " into.\n");
	return 0;
    }

    write("Ok. You dip " + ob->short() + " into the poison.\n");
    say(TP->query_name() + " dips " + ob->short() + " into the cauldron.\n");

    /* Add more poisoning if already done */
    ob->set_poisoned((int)ob->query_poisoned() + 80 + random(80));
    ob->set_poison_strength((poison_str / 2) + random(4));

    if (!ob->query_poisoned()) {
	write(
	  "The icky green stuff doesn't stick into " + ob->short() + ".\n");
	return 1;
    }

    /* Only if it really worked */

    write("How nice, " + ob->short() + " is now poisoned!\n");

    dip_sauce--;
    if (dip_sauce < 1) {
	dip_sauce = 0;
	write("There is no more poison in the cauldron.\n");
	say("There seems to be no more icky green stuff left.\n");
    } else if (dip_sauce < 5) {
	write("There is poison for only a few dippings left.\n");
	say("There is not much icky green stuff left.\n");
    } else if (dip_sauce < 10) {
	write("There is still a fair amount of poison in the cauldron.\n");
	say("There is still a fair amount of the stuff remaining.\n");
    } else {
	write("There is plenty of poison left.\n");
	say("There is still plenty of the icky green stuff left.\n");
    }

    return 1;
}
status buy_food(string what)
{
    string give, *types;
    mapping foods;
    object ob;
    int i;

    foods = ([ BERRY : BERRY_COST, MIX : MIX_COST, BEEF : BEEF_COST, BREW : BREW_COST ]);

    if (!(present("tmark",TP)))
    {
	notify_fail("The man barks at you: I don't sell to your kind.  \
Get lost!!");
	return 0;
    }

    types = m_indices(foods);

    for(i=0;i < sizeof(types);i++)
    {
	if ( what == types[i] )
	{
	    give = what;
	    if ((int) TP->query_money() < foods[types[i]])
	    {
		notify_fail("The man barks:  Go get a job and come \
back when you can afford something!\n");
		return 0;
	    }
	    else
	    {
		TP->tell_me("You slide your money across the counter to \
the man.");
		environment(TP)->tell_here(TP->QN + " slides some money \
across the counter to the man.",TP);
		TP->add_money(-(foods[types[i]]));
	    }
	    continue;
	}
    }

    if (!give)
    {
	notify_fail("The man growls: Pick something from the list!\n");
	return 0;
    }

    if (give == "4")
	ob = clone_object("/obj/drink");
    else
	ob = clone_object("/obj/food");

    switch (give)
    {
    case "1":
	ob->set_name("dried berries");
	ob->set_short("Dried berries");
	ob->set_long("A small assortment of dried berries.");
	ob->set_id(({ "berries", "dried berries" }));
	ob->set_strength(50);
	ob->set_max_full(1);
	ob->set_eater_mess("You eat the dried berries.  YUM!");
	ob->set_eating_mess(TP->QN+" eats some dried berries.  They \
look really tasty!");
	TP->tell_me("The man hands you the dried berries.");
	environment(TP)->tell_here("The man hands " + TP->QN + 
	  " some dried berries.",TP);
	break;
    case "2":
	ob->set_name("trail mix");
	ob->set_short("Trail mix");
	ob->set_long("An assortment of nuts.");
	ob->set_id(({ "trail mix", "nuts", "mix" }));
	ob->set_strength(120);
	ob->set_max_full(1);
	ob->set_eater_mess("You crunch on the trail mix.");
	ob->set_eating_mess(TP->QN + " crunches on some nuts!");
	TP->tell_me("The man hands over some trail mix.");
	environment(TP)->tell_here("The man hands some trail mix \
to " + TP->QN + ".",TP);
	break;
    case "3":
	ob->set_name("dried beef");
	ob->set_short("Dried beef");
	ob->set_long("A slice of dried beef.");
	ob->set_id(({ "beef", "dried beef" }));
	ob->set_strength(150);
	ob->set_max_full(3);
	ob->set_eater_mess("You devour the beef.  What an animal!");
	ob->set_eating_mess(TP->QN + " hungrily devours some beef.");
	TP->tell_me("The man hands you some dried beef.");
	environment(TP)->tell_here("The man hands " + TP->QN 
	  + " some dried beef.",TP);
	break;
    case "4":
	if (amount_brew > 0)
	{
	    amount_brew -= 1;
	    ob->set_name("Thieve's brew");
	    ob->set_short("Thieve's brew");
	    ob->set_long("A strange concoction of fermented...\
well, fermented something!?");
	    ob->set_id(({ "brew", "thieves brew" }));
	    ob->set_liquid("brew");
	    ob->set_strength(-10);
	    ob->set_drinking_mess(TP->QN + " gulps down some brew.  \
Strange, he seems more stable on his feet.");
	    ob->set_drinker_mess("You drain the bottle of brew.  Wow, \
you feel more grounded!");
	    ob->set_max_full(1);
	    TP->tell_me("The man tosses you a bottle of brew!");
	    environment(TP)->tell_here("The man tosses a bottle \
of brew to " + TP->QN,TP);
	    extra_look();
	}
	else
	{
	    environment(TP)->tell_here("The man goes to get some of \
the brew, but returns empty handed, and says: Sorry pal, all out.");
	    environment(TP)->tell_here("The man says, here is your \
money back.");
	    TP->add_money(BREW_COST);
	    destruct(ob);
	    return 1;
	}
	break;
    }
    ob->set_value(50);
    move_object(ob,TP);
    return 1;
}
