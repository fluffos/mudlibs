#ifndef TMARK_C

#include <living_defs.h>
#include "../thief.h"

object owner, target;
int t_level, show_tattoo, success;

#endif

string
random_taunt()
{
    string inslt;
    int t;

    t = 1 + random(9);
    if (t == 1) return "insults your mother";
    if (t == 2) return "gives you the finger";
    if (t == 3) return "humiliates you";
    if (t == 4) return "pisses on your leg";
    if (t == 5) return "defiles you";
    if (t == 6) return "dances around you";
    if (t == 7) return "makes obscene gestures at you";
    if (t == 8) return "moons you";
    if (t == 9)
    {
	inslt = "says: 'You are just ";
	t = random(7);
	if (t == 0) return inslt + "a fetid dingo kidney'";
	if (t == 1) return inslt + "a pool of putrescent pus'";
	if (t == 2) return inslt + "a boiled eye-ball gobbling hairy-nosed git'";
	if (t == 3) return inslt + "a geriatric pensioner molesting pervert'";
	if (t == 4) return inslt + "a scabby-bottomed spotted toad'";
	if (t == 5) return inslt + "an embryo sucking fiend'";
	if (t == 6) return inslt + "a shaved gerbil tail puller'";
    }
    return "insults you";
}

status taunt(string str)
{
    string msg;

    if (!str)
    {
	notify_fail("You must specify a victim.\n");
	return 0;
    }
    target = (present(lower_case(str),environment(TP)));
    if (!target)
    {
	notify_fail("There's no one with that name here.\n");
	return 1;
    }

    if (!living(target) || target==owner ||
      (!target->query(LIV_IS_PLAYER_OR_NPC)))
    {
	notify_fail("That's pointless.\n");
	return 1;
    }

    msg = sprintf("%s %s!",
      (string) owner->query_name(),
      random_taunt());
    TPT(sprintf("Ok. %s gets: \"%s\"",
	(string)target->query_name(), msg));

    target->tell_me(msg);

    return 1;
}

status tpose()
{
    int sp;

    sp = owner->query_sp();

    if (sp < POSE_SP_COST)
    {
	notify_fail("You fail to pose.\n");
	environment(owner)->tell_here(owner->query_name() + " fails miserably \
while trying to pose.");
    }
    else
    {
	random_pose();
	owner->add_sp(- POSE_SP_COST);
    }
    return 1;
}

status random_pose()
{
    string his,nm,um,om;
    int p;

    his = owner->query_possessive();
    nm = owner->query_name();
    p = random(t_level) + 1;
    if (p > 18)
	p = 18;

    switch (p)
    {
    case 1:
	um="You perform a small cardtrick";
	om=nm+" plays around with some marked cards";
	break;
    case 2:
	um="You wiggle your ears alternately";
	om=nm+" wiggles "+his+" ears";
	break;
    case 3:
	um="You nimbly tie yourself into a knot";
	om=nm+" ties self into a knot and needs help to get untangled";
	break;
    case 4:
	um="You juggle with a variaty of items such as daggers, apples, eyes etc";
	om=nm+" juggles with daggers, apples, eyes, fishbones etc";
	break;
    case 5:
	um="You steal the underwear off every person in the room";
	om=nm+" takes your underwear and turns it inside out before replacing it";
	break;
    case 6:
	um="You show your skills in a game of dice";
	om=nm+" cheats in a game of dice";
	break;
    case 7:
	um="You count the money in everybody else's pockets";
	om=nm+" counts your money and kindly asks you to check the result";
	break;
    case 8:
	um="You balance a pocketknife on your tongue";
	om=nm+" balances a pocketknife on "+his+" tongue";
	break;
    case 9:
	um="You get coins from everybody's ears";
	om=nm+" pulls your ears in an attempt to produce coins";
	break;
    case 10:
	um="You hide behind your own shadow";
	om=nm+" tries to hide behind "+his+" own shadow";
	break;
    case 11:
	um="You make greed dance with bloodlust in your eyes";
	om=nm+"'s eyes are filled with greed and bloodlust..";
	break;
    case 12:
	um="You steal excalibur from a bag - nobody notices";
	om=nm+" steals excalibur from his own bag";
	break;
    case 13:
	um="You sneak into somebody's pocket and hide there";
	om=nm+" tries to hide in your pocket";
	break;
    case 14:
	um="You slip fireworks into the pockets of everybody in the room";
	om="Your pocket explodes with the fireworks "+nm+" has put there";
	break;
    case 15:
	um="You steal a book which, inscribed with large friendly letters, " +
	"says DON'T PANIC";
	om=nm+" fiddles with a book whose cover says DON'T PANIC";
	break;
    case 16:
	um="You steal the ozone layer and get a good suntan";
	om=nm+" steals the ozone layer and starts sprouting extra limbs, " +
	"ears and toes";
	break;
    case 17:
	um="With few tools you skillfully open the door to the universe";
	om=nm+" opens the doors to the universe. Close it, there's a cold draft";
	break;
    case 18:
	um="You steal the universe, but have problems fitting it into your pocket";
	om=nm+" steals the universe and tries to fit it into "+his+" pocket";
	break;
    }
    /* This cannot happen... */
    if (!um)
	um="You fail to pose";
    if (!om)
	om=nm+" fails miserably while trying to pose";

    TM(um + ".");
    environment(TP)->tell_here(om + ".", this_player());
    return 1;
}

status disguise(string str)
{

    if (!str || str != "tattoo")
	return notify_fail("Disguise what?\n"), 0;

    show_tattoo = (!show_tattoo);

    TPT("Ok.");
    if (show_tattoo)
	TPT("You let the others see your tattoo again.");
    else
	TPT("You hide your tattoo.");

    return 1;
}

status consider(string str)
{
    int magic;
    object ob;

    if (!str)
    {
	TM("You must give the creature a name.");
	return 1;
    }
    ob = present(str, environment(TP));

    if (!ob)
    {
	TM("You cannot see any " + str + " here.");
	return 1;
    }

    if (!living(ob))
    {
	TM("Why do you consider THAT?");
	return 1;
    }

    if (ob == owner)
	return 0;

    if (ob->query_wc() > 15)
	TM("Beware...this one seems to be well armed...");

    if (ob->query_alignment() > 100)
	TM("You sense goodness.");

    if (ob->query_alignment() < -100)
	TM("You sense evil.");

    return 0; /* Continue with official consider */
}

status tlook(string arg)
{
    string *dd, tmp;
    object place, *inv;
    int i;

    if (!arg)
    {
	notify_fail("You need to give the direction too.\n");
	return 0;
    }

    arg = lower_case(arg);

    dd = environment(owner)->query_dest_dir();
    if (!dd)
    {
	notify_fail("You try to peek " + arg + ", but you can see only mist.\n");
	return 1;
    }

    if (owner->query_sp() < TLOOK_SP_COST)
    {
	notify_fail("You are not able to concentrate enough now.\n");
	return 1;
    }

    if ((i = member(dd, arg)) == -1 || (sizeof(dd) < i))
    {
	TM("There's nothing in the direction " + arg + ".\n");
	return 1;
    }

    i--;

    place = find_object(dd[i]);
    if (!place)
    {
	catch(call_other(dd[i], "???")); /* Buu. But it's nicer to catch it. */
	place = find_object(dd[i]);
	if (!place)
	{
	    TM("There's nothing but darkness there.\n");
	    return 1;
	}
    }

    owner->add_sp(- TLOOK_SP_COST);

    success = (thief_dex() * 40 / 20 + t_level * 45 / 20) - random(100);

    if (success > 0)
    {
	TM("Ok, you peek " + arg + " and see...\n\n");
	place->long();

	/* Check what living creatures we can detect */
	if (place->query_light() || owner->query_infravision())
	{
	    inv = all_inventory(place);
	    for (i = sizeof(inv) - 1; i >=0; i--)
		if (living(inv[i]) && !inv[i]->query_invis() &&
		  !inv[i]->query_undead())
		{
		    tmp = inv[i]->short();
		    if (tmp)
			TM(tmp + ".");
		}
	}

	TM("\n");
	return 1;
    }
    TM("Hmm, perhaps you need glasses. Can't see anything there.\n");
    return 1;
}
