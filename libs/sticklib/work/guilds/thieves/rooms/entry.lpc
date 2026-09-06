#include <room.h>
#include <daemons.h>
#include <guild.h>

#include "dirs.h"

#define LOG_THIEF
// WIZLOCK will stop players from joining and getting the form
#undef WIZ_LOCK

#define TP this_player()
#define TO this_object()

object cand, guard, door;

status join_to_guild(object ob);

void
reset_room()
{
    int i;
    object ob;

    if (!guard)
    {
	guard = clone_object(GDIR + "npc/thief_guard");
	guard->add_block("east", "guild", 0, GN_THIEF,
	  ":%<me.capname>% blocks your way.",
	  ":%<me.capname>% blocks the way of %<him.capname>%.", 0, 0);
	guard->add_block("south", "guild", 0, GN_THIEF,
	  ":%<me.capname>% blocks your way.",
	  ":%<me.capname>% blocks the way of %<him.capname>%.", 0, 0);

	// Oops, these were accidentally put here...wonder how? /Graah
	guard->add_block("west", "name", "eomer", 0,
	  ":%<me.capname>% blocks your way.",
	  ":%<me.capname>% blocks the way of %<him.capname>%.", 0, 0);
	guard->add_block("west", "name", "traquair", 0,
	  ":%<me.capname>% blocks your way.",
	  ":%<me.capname>% blocks the way of %<him.capname>%.", 0, 0);

	move_object(guard, TO);

	for (i = 0; i < 5; i++)
	{
	    ob = clone_object(GDIR + "npc/treasure_guard");
	    ob->add_block("east", "guild", 0, GN_THIEF,
	      ":%<me.capname>% blocks your way.",
	      ":%<me.capname>% blocks the way of %<him.capname>%.", 0, 0);
	    ob->add_block("south", "guild", 0, GN_THIEF,
	      ":%<me.capname>% blocks your way.",
	      ":%<me.capname>% blocks the way of %<him.capname>%.", 0, 0);
	    move_object(ob, TO);
	}
    }
}

void create_room()
{
    set_short("Entrance");
    set_long("This cave seems to be the entrance of a mysterious guild. "+
      "On the south wall there is a shimmering portal. A large stone "+
      "arch, to the east, bares the symbol of a dagger, with blood.");

    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT_TO);

    set_items( ([
	"floor" :  "You notice a cleverly hidden trap door on the floor. "+
	"It seems to be very strongly barred and closed though.",
	({ "south wall", "wall", "portal" }) :
	"The portal shimmers, enticing you to walk through it.",
	({ "arch", "stone arch", "large stone arch" }) :
	"The arch is the doorway leading into the guild.",
	({ "symbol", "dagger", "symbol of a dagger" }) :
	"The blood is not red blood, but green.",
      ]) );

    add_exit("south", GDIR + "rooms/temple");
    add_exit("west", GUILD_LOCATION);

    add_command("join", "join");
    add_command("east","east");
    add_command("south", "back");
    add_command("south", "south");

    reset_room();
}

void init_room()
{
    object shieldd, ob;
    int duration, type, sps;

    if (TP->query_npc()  &&  !TP->query_ctrl()  &&
      !sscanf(object_name(TP), GDIR2 + "%~s"))
    {
	// Tried to get "ob->query_name"; although ob isn't fetched yet... :-(
	// Kludged by Doomdark 04-apr-95.
	tell_here("Guard kicks a monster out from the guild.");
	TP->move_player("X", GUILD_LOCATION);
	return;
    }

    if ((string)TP->query_guild() == GN_PRIEST)
    {
	shieldd = find_object("/guilds/priests/daemons/shield_d");
	if (shieldd)
	{
	    duration = shieldd->query_shield(TP, type, sps);
	    if(duration > 0)
	    {
		shieldd->remove_pl(TP);
		TP->tell_me("Suddenly there is a loud clap of thunder and "+
		  "your energy shield disrupts.\nYou hear a whisper: "+
		  "You just annoyed Skert.");
		environment(TP)->tell_here("Suddenly, there is a loud clap "+
		  "of thunder from overhead and " + TP->query_name() +
		  " looks rather pale and weak.", TP);
	    }
	}
    }
}

string gnd_prn()
{
    int gnd;

    if(TP->query_coder_level())
	return "Your Highness";

    switch(TP->query_gender())
    {
    case 1 : return "Sir";
    case 2 : return "Madam";
    default : return "Monster";
    }
}


status east()
{
    TP->move_player("into guild", GDIR2 + "rooms/guild");
    return 1;
}

status join()
{
    object ob;

    if (!(ob = present("guild_guard",this_object())))
    {
	TP->tell_me("You cannot join now - there are no guild officers "+
	  "present.");
	return 1;
    }

    cand = TP;

    if (!cand  ||  !living(cand)  ||
      (!interactive(cand)  &&  !cand->query_ctrl()))
    {
	cand->tell_me("Huh? Is it you who is joining or your dictionary?");
	return 1;
    }

#ifdef WIZ_LOCK
    if(!cand->query_coder_level()) {
	environment(ob)->tell_here(ob->query_name() + " says: Sorry, but "+
	  "this guild is currently closed. Please come back later.");
	return 1;
    }
#endif

    if (cand->query_real_name() == "guest")
    {
	cand->tell_me("Sorry, but guests cannot join the guild. You "+
	  "should start really playing StickMUD and then join this "+
	  "guild immediately.");
	return 1;
    }

    if (cand->query_title() == "the ex-thief")
    {
	cand->tell_me(ob->query_name() + " says: 'You again? Get lost!'");
	return 1;
    }

    if (present("tmark", cand))
    {
	cand->tell_me(ob->query_name() + " says: You have joined already, "+
	  "remember?");
	tell_here(ob->query_name() + " says something to " +
	  cand->query_name() + ".", ({ cand }));
	cand->tell_me(ob->query_name() + " pats you on the head.");

	tell_here("%<me.capname>% pat%<me.ending_s>% %<him.capname>% "+
	  "on %<him.possessive>% head.", 0, 0, ob, cand, 0);
	return 1;
    }

    /* test the other guilds */
    // Hmmm  Maybe this isn't the best way to check for other guilds. --Kieve
    if (present("guild_mark", cand)  ||  present("mark", cand))
    {
	cand->tell_me(ob->query_name() + " says: You are already in "+
	  "another guild!");
	return 1;
    }

    if (present("healer_accept_form", cand))
    {
	cand->tell_me(ob->query_name() + " says: Shove that healer paper "+
	  "up into your asshole first.");
	return 1;
    }

    if (present("thief_accept_form", cand))
    {
	cand->tell_me(ob->query_name() + " says: You are already trying "+
	  "to join the guild.");
	return 1;
    }

    join_to_guild(cand);
    /* 
	move_object(clone_object(GDIR + "obj/paper"), cand);

	cand->tell_me(ob->query_name() + " says: Here is your application "+
	    "form. Examine it, it tells you what to do.");
    */
    return 1;
}

status south()
{
    if (present("tmark", TP))
    {
	TP->tell_me("You are magically transferred to the temple.");
	TP->move_player("X", GDIR2 + "rooms/temple");
	return 1;
    }
    TP->tell_me("Ouch! You just bang your head into the stone wall when "+
      "you try to go south.");
    return 1;
}

/* Nasssty! */
void trap_door()
{
    object *inv, ob;
    int i;

    call_other(GDIR + "rooms/trap", "haloo");

    (GDIR+"rooms/trap")->XXX();
    ob = present("door", find_object(GDIR+"rooms/trap"));
    ob->set_closed(1,0,1);
    ob->set_locked(1,0,1);

    inv = all_inventory(this_object());

    if (!inv || sizeof(inv) < 1) return;

    tell_here("\nSuddenly floor of the room swings open! It's a TRAP!\n\n");

    for (i = sizeof(inv) - 1; i >= 0; i--)
    {
	ob = inv[i];

	if (living(ob))
	{
	    if (ob->query_npc()  ||  ob->query_guild() == GN_THIEF ||
	      (int)ob->query_level() > random(200))
	    {
		tell_here(ob->query_name() +
		  ({
		    " jumps away from the trap",
		    " manages to avoid the trap",
		    " barely avoids the pit",
		    " staggers on the edge of the pit, but doesn't fall in",
		    " almost falls in",
		    " twists on the edge, but doesn't fall in",
		    " skillfully leaps away from the trap"
		  })[random(7)] +
		  "!", ({ ob }));
		ob->tell_me(
		  ({
		    "You avoid the trap easily",
		    "You stagger on the edge, but manage not to fall in",
		    "You throw yourself into a corner to avoid it",
		    "You twist on the edge for a while, but don't fall in"
		  })[random(4)] +
		  ".");
	    }
	    else
	    {
		/* Wheeeee.... */
		ob->hit_player(random(250)+100);
		ob->tell_me("\n\nYou FALL!\n\n");
		ob->move_player("Vfalls into the trap", GDIR2 + "rooms/trap");
	    }
	} // living(ob)
	else
	{
	    /* Nonliving things must not fall. */
	    /* It looked funny when the door to the guild fell in... */
	    // *LAUGH* --Kieve
	}
    }
}

/* We must get rid of a lost key */
void key_kludge(object ob)
{
    call_out("keydest", 60 * 5, ob);
}

void keydest(object ob)
{
    if (!ob) return;

    if (environment(ob))
    {
	if (living(environment(ob)))
	{
	    environment(ob)->tell_me(ob->query_name() + " disappears in "+
	      "a bright flash of light!");
	    environment(ob)->add_weight(-((int)ob->query_weight()));
	}
	else
	    environment(ob)->tell_here(ob->query_name() +
	      " disappears in a bright flash of light!");
    }
    destruct(ob);
}

status join_to_guild(object ob)
{
    object cand;
    object mark;

    cand = ob;

    if (!cand  ||  !living(cand)  ||
      (!interactive(cand) && !cand->query_ctrl()))
	return 0;

#ifdef WIZ_LOCK
    return 0;
#endif

    if (cand->query_guild()  ||  present("guild_mark", cand)  ||
      present("mark", cand))
	return 0;

    cand->set_guild("thief");
    cand->set_guild_object_name(GDIR+"thief_mark_new");
    cand->initialize_guild();
    CHANNEL_D->check_channels(cand);

    cand->move_player("into guild", GDIR2 + "rooms/guild");

    mark = present("tmark", cand);

    if (!cand->query_npc())
    {
	find_object(GDIR + "rooms/guild")->tell_here("\nThe thieves around the "+
	  "mud cheer at a new member,\n" +
	  capitalize((string)cand->query_real_name()) + " " +
	  (string)cand->query_title() + "!");

	mark->chant(capitalize((string)cand->query_real_name()) +
	  " has joined the Guild of Thieves!");
    }

    /* Convert. It doesn't give too good skills, but makes it more fair
       to high level players who join the guild. */
    mark->convert();
    return 1;
}
