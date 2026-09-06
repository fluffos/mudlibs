#include <room.h>
#include <macros.h>
#include <conditions.h>
#include <door_defs.h>
#include "dirs.h"

inherit "/basic/misc/emote";

#define	THIEF	"/guilds/thieves/colt/old_thief"

void
create_room()
{
    set_short("Shower Room");
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set(ROOM_GUILD);
    set_long(
      "You are in the Showers of Thieves' Guild. You can see a tube which goes \
down around the walls, then the water flow comes out and turns a wheel, \
which apparently gives power to a water pump. There are many showers \
here, with red taps for hot and blue taps for cool water. How they heat \
the water remains a mystery. The water pump system also looks really weird. \
Like it was made with plans by Mr. Escher. Note: emote works here too.");

    add_exit("east", GDIR + "rooms/attic");

    add_item(({ "shower", "showers", "tap", "taps" }),
      "Just wash yourself (or someone else) if you want.");

    add_item(({ "pump", "water pump", "tube", "tubes", "flow" }),
      "You can't figure it out, the mechanism is too weird.");

    add_command("wash", "wash_cmd");
    add_command("emote", "emote_cmd");
    add_monster(THIEF, "An old thief arrives.", 1);
}

status
wash_cmd(string argu)
{
    object ob, sewage_ob;
    string arg;

    if (argu)
    {
	arg = lower_case(argu);

	if (arg == "yourself")
	{
	    notify_fail(
	      "I didn't mean it like that! You have to 'wash myself', not 'wash yourself',\n\
because that would mean that you are going to wash someone else, though\n\
actually 'yourself' here can't mean anyone else but you...but anyway, you\n\
should type 'wash myself'.\n");
	    return 0;
	}

	if (arg == "myself" ||
	  arg == "me" ||
	  arg == "self")
	    ob = TP;
	else
	{
	    ob = present(arg, this_object());
	    if (!ob) ob = present(arg, TP);

	    if (!ob)
	    {
		notify_fail("You try to wash " + arg + ". How silly!\n");
		return 0;
	    }
	}
    }
    else
	ob = TP;


    if (ob == TP)
    {
	TP->tell_me(({
	    "You take a long, refreshing shower, and feel really good after that!",
	    "You wash yourself throughly. Isn't this a great guild!",
	    "Aaahhh! Just what you needed! You feel very clean."
	  })[random(3)]);
	tell_here((string)TP->query_name() + " takes a shower.\n", TP, 1);
    }
    else
    {
	if (living(ob))
	{
	    ob->tell_me((string)TP->query_name() +
	      " washes you throughly. How pervert!");
	    TP->tell_me("You wash " + (string)ob->query_name() +
	      " througly. Foreplaying?");
	    tell_here((string)TP->query_name() +
	      " washes " + (string)ob->query_name() +
	      " througly.\n", ({ ob, TP }), 1);
	}
	else
	{
	    TP->tell_me("You wash " + ob->short() +
	      ", but it doesn't look any cleaner.");
	    tell_here((string)TP->query_name() +
	      " washes " + (string)ob->short() +
	      " without much success.\n", TP, 1);
	}
    }

    /* Benefits? */
    /* TODO: Rust metal things! */

    /* Temporarily just removes hallucination...nothing too good. */
    if (living(ob))
    {
	if (ob->query_condition(C_HALLUCINATING))
	    ob->set_condition(C_HALLUCINATING, 0);
	if (sewage_ob = present("sewage",ob))
	    destruct(sewage_ob);
	if (sewage_ob = present("sauna_sweat", ob))
	    destruct(sewage_ob);

	if ((sewage_ob = present("on_fire", ob)))
	    ob->tell_me("The magical flames do not go out in water!");
    }

    return 1;
}
