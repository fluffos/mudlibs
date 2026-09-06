#include <room.h>

#include <disease_defs.h>

#include "../DEFS.h"

inherit "/basic/misc/emote";

int celcius;

string
extra_look()
{
    return sprintf("The temperature is %d degrees celcius.", celcius);
}

void
create_room()
{
    celcius = 70 + random(40);

    set_short("The Savusauna");
    set_long(
      "You are in the genuine Finnish Savusauna. It is very comfortable and\
 warm in here. You feel great! Note that the emote command is available\
 here too ('help emote' for more information). To start a traditional\
 finnish sauna fight, type 'brawl <opponent>'. The brawling match doesn't\
 do any real harm to anyone. The exit is to the north.");

    add_exit("north", CITY_PATH+"finnclub/dressing");

    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS * 2);
    set(PREVENT_TELEPORT);
    set(NO_PK);
    set(IN_CITY);

    add_permanent(CITY_PATH+"finnclub/kiuas");
    add_permanent(CITY_PATH+"finnclub/saavi");

    set_commands(([
	"emote" : "emote_cmd",
	"awe"	: "nope",
	"frog"	: "nope",
	"help"	: "help",
	"brawl"	: "brawl",
	"wear"  : "nope"
      ]));

    set(IN_CITY);
    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(NO_CLEANUP);
}

int query_celcius() { return celcius; }
void set_celcius(int x) { celcius = x; }

void
init_room()
{
    object ob;

    /* Kick monsters out, but not controlled ones */
    if (this_player()->query_npc())
    {
	if (!this_player()->query_ctrl())
	{
	    tell_here((string)this_player()->query_name() +
	      " can't stand the heat!", ({ this_player() }));
	    this_player()->move_player("north", CITY_PATH+"finnclub/dressing");
	}
	return;
    }

    if (this_player() && !present("sauna_sweat",this_player()))
	move_object(clone_object( CITY_PATH+"finnclub/sauna_sweat"),this_player());

    /* Feet rash. Bathing in the lake before incubation time has
       ended will remove it. */
    if (this_player() && random(300) > 288 && !this_player()->query_npc() &&
      !present("feet_rash", this_player()) && !present("disease", this_player()) &&
      (int)this_player()->query_level() > 5)
    {
	if (random(100) < 97)
	    move_object(clone_object(OBJ_DIR+"feet_rash"), this_player());
	else {
	    /* Sauna is much too good - so let's get really sick */
	    ob = clone_object(DISEASE_FILE);
	    ob->set_disease(({"measles", "chickenpox", "tonsillitis",
		"scarlet fever", "diphtheria", "meningitis",
		"flu", "typhoid fever", "dysentery", "spotted fever",
		"smallpox", "cholera", "plague"})[random(13)]);
	    if (ob) move_object(ob, this_player());
	}
    }
}

status
help(string str)
{
    if (!str || lower_case(str) != "emote") return 0;

    this_player()->tell_me("Command: emote      (Local command - this room only)\n\
Arguments: message\n\n\
Generates a neat feeling which you can design yourself.\n\n\
For example, you (player Foobar), type:\n\
'emote scans the horizon with his bloodshot eyes.'\n\n\
And the other players in this room see:\n\
'Foobar scans the horizon with his bloodshot eyes.'\n\
\nBeware of those who emote 'gives you 10000 gold'... :-)");
    return 1;
}

emote(arg)
{
    if (!arg)
    {
	notify_fail("Emote what?\n");
	return 0;
    }

    if (this_player()->query_invis() && !this_player()->query_coder_level())
    {
	write("Invisible people cannot use emote.\n");
	return 1;
    }

    if(!(arg = we_have_to_do_this(arg))) return 1;

    tell_here(this_player()->query_name() + " " + arg, ({ this_player() }));
    this_player()->tell_me("Others see: \"" + this_player()->query_name() + " " + arg + "\"");
    return 1;
}

we_have_to_do_this(arg)
{
    int i;

    if (sizeof(arg) > 75)
    {
	write("Warning: too long emote - it is truncated.\n");
	arg = arg[0..74];
    }

    for(i=0;i<sizeof(arg);i++)
	if(arg[i] < ' ' || arg[i] > 127) {
	    write("Illegal characters in emote - it failed.\n");
	    return 0;
	}

    return arg;
}

status
nope(string arg)
{
    this_player()->tell_me("A warning nymph tells you: You can't do that here...");
    return 1;
}

brawl(str) {
    object ob,b;
    string tmp1;

    if (!str) {
	notify_fail("With who did you want to brawl?\n");
	return 0;
    }

    if (sscanf(lower_case(str), "with %s", tmp1) == 1) str == tmp1;

    ob = present(lower_case(str), environment(this_player()));

    if (!ob) {
	notify_fail("You can't see " + str + " here.\n");
	return 0;
    }

    if (!living(ob)) {
	notify_fail("Brawling with non-living objects is pointless.\n");
	return 0;
    }

    if (present("sauna_brawl", this_player())) {
	notify_fail("You'd better finish this fight first.\n");
	return 0;
    }

    if (ob == this_player()) {
	notify_fail("You are a masochist, aren't you?\n");
	return 0;
    }

    b = clone_object(CITY_PATH+"finnclub/sauna_brawl");

    move_object(b,this_player());
    b->start_brawl(ob);

    this_player()->tell_me("Ok.");
    return 1;
}
