/* Track garrottes and players */
//some changes 7-Nov-1996 Skarda

inherit "/basic/id";


#include <room_defs.h>
#include <guild.h>

#define TP this_player()

string *track(string arg);

void
create()
{
    set_name("crystal ball");
    set_id(({"crystal", "ball"}));
    set_short("Shining Crystal ball");
    set_long(
      "In the middle of the room stands a large crystal ball. Perhaps you \
could \"gaze\" in it? Or try to 'gaze for <someone/something>'?");
}

init()
{
    add_action("gaze", "gaze");
}

get() { return 0; }

status
gaze(string arg)
{
    object ob, tm;
    string *who, tmp;

    if (!TP->query_can_see()) return 0;
    // Added 28-aug-95 by Doomdark.
    if ((string) TP->query_guild() != GN_THIEF || !(tm = (object) TP->query_guild_object()))
    {
	notify_fail("You just see your ugly face.\n");
	return 0;
    }

    if (arg)
    {
	if (sscanf(arg, "for %s", tmp)) arg = tmp;

	if (lower_case(arg[0..7]) != "garrotte")
	{
	    ob = find_player(lower_case(arg));

	    if (!ob)
	    {
		notify_fail("You try to gaze for \"" + arg +
		  "\", but see nothing.\n");
		return 0;
	    }

	    //++Tron
	    // And, 2nd check by Doomdark 28-aug-95.
	    if (ob->query_prevent_where() || environment(ob)->query(ROOM_PREVENT_WHERE)) {
		notify_fail("The ball goes dark and you see a bunch of green sparks in the ball right after.\n");
		return 0;
	    }
	    if (ob->query_coder_level() &&
	      !this_player()->query_coder_level())
	    {
		notify_fail("The crystal ball just goes dark.\n");
		return 0;
	    }

	    tmp = 0;

	    if (environment(ob))
		tmp = (string)environment(ob)->query_short(2, ob);

	    if (!tmp)
	    {
		this_player()->tell_me("Somehow, you see nothing at all - a void.");
		return 1;
	    }

	    if (!tm->query_guildmaster())
	    {
		if ((int)this_player()->query_sp() < 25) {
		    notify_fail("You are too tired to concentrate enough.\n");
		    return 0;
		}
	    }

	    if (!tm->query_guildmaster())
		this_player()->add_sp(-5);
	    else
		this_player()->add_sp(-5);

	    /* It doesn't work every time...should perhaps give false
	       information sometimes? */
	    if (random(100) > 80 ||
	      random((int)ob->query_level())>(int)this_player()->query_level())
	    {
		this_player()->tell_me("You lost your concentration.");
		return 1;
	    } else if (random(100) > ((int)this_player()->query_level() + 50))
	    {
		tmp = ({
		  "Suite of Gangbuster", "The Savusauna",
		  "Fighters' Inn", "Death's workroom",
		  "Dark room", "Elven Guardpost", "Plain",
		  "Road", "Dagger Alley, at a temple",
		  "Private home", "Guild Hall",
		  "The inner holy sanctum",
		  "The House of the Farmer"
		})[random(13)];
	    }

	    write(sprintf("%-=78s\n", "You get a feeling that " +
		capitalize(arg) +
		" is at \"" + tmp + "\"."));

	    return 1;
	}
    }

    if (!(tm->query_guildmaster()))
    {
	notify_fail("You gaze and gaze, but see nothing special.\n");
	return 0;
    }

    who = track("garrotte");

    if (who && sizeof(who) > 0)
	write("The crystal ball shows you all those who carry a garrotte:\n"+
	  implode(who, " and ", ", ") + "\n");
    else
	write("You see nothing unusual.\n");

    return 1;
}

/* Track all players for certain items */
string *
track(string arg)
{
    string *n;
    object *u, *inv;
    int i, j;

    n = ({});

    if (!arg) {
	notify_fail("Track what?\n");
	return 0;
    }

    u = users();

    for (i = sizeof(u) - 1; i >= 0; i--)
    {
	if (!u[i]->query_coder_level())
	{
	    inv = deep_inventory(u[i]);
	    for (j = sizeof(inv) - 1; j >= 0; j--)
	    {
		if (inv[j]->id(arg))
		{
		    n += ({ capitalize((string)u[i]->query_real_name()) });
		    break;
		}
	    }
	}
    }

    return n;
}
