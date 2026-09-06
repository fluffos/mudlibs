/*
 * /bin/daemons/fumbled.c - Slapstick comedy
 *
 * Copyright 1994 StickMUD RY.
 * All Rights Reserved
 *
 */

#include <conditions.h>
#include <fumble.h>

inherit "/lib/find_name";

#define TM fumbler->tell_me
#define TH environment(fumbler)->tell_here
#define HIS (string)fumbler->query_possessive()
#define HIM (string)fumbler->query_objective()

varargs void
fumble(object fumbler, object target, object weapon, int ft)
{
    string fn, tn, wn;
    string *ex;
    object r;
    int i;

    if (!fumbler || !living(fumbler) || !environment(fumbler)) return;

    fn = find_name(fumbler, 1);
    if (target) tn = find_name(target, 1);
    if (weapon) wn = find_name(weapon, 0);

    switch(random(7))
    {
    case 0:
	if (wn)
	{
	    TM(
	      "You lose your grip and the opportunity to get in an open blow. \
Maybe you will improve.");
	    TH(fn + " loses " + HIS +
	      " grip and fumbles.", ({ fumbler }), 0);
	    return;
	}
	TM("You attack into wrong direction. Perhaps next time.");
	TH(fn + " attacks thin air.", ({ fumbler }), 0);
	return;
    case 1:
	if (!wn)
	{
	    TM("You slip with grace and lose the opportunity.");
	    TH(fn + " slips with grace.", ({ fumbler }), 0);
	    return;
	}
	TM("You drop your weapon!");
	TH(fn +
	  " drops " + HIS +
	  " weapon!", ({ fumbler }), 0);
	fumbler->drop_one_item(weapon);
	return;
    case 2:
	TM(
	  "Bad follow through. You lose your opportunity and scratch yourself. \
Real weak.");
	TH(fn + " scratches " + HIM +
	  "self while attacking.", ({ fumbler }), 0);
	// Normally use hit_player though...
	fumbler -> add_hp(-(random(10) + random(10)));
	return;
    case 3:
	TM("You slip without grace and stun yourself. Good luck pal.");
	TH(fn + " slips without grace and stuns " + HIM + "self.",
	  ({ fumbler }), 0);
	fumbler->set_condition(C_STUNNED, 1);
	return;
    case 4:
	if (wn)
	{
	    TM("You lose your grip and juggle your " + wn + " for a while.");
	    TH(fn + " loses " + HIS + " grip and juggles " + HIS +
	      " " + wn + " for a while.", ({ fumbler }), 0);
	    /* Can only parry for two rounds. But there's no condition
	       for that. */
	    return;
	}
	TM("You get tangled into your own legs. Everyone laughs at you.");
	TH("Everyone laughs when " + fn + " gets tangled into " + HIS +
	  " own legs.", ({ fumbler }), 0);
	fumbler->set_condition(C_STUNNED, 1);
	return;
    case 5:
	if (!wn)
	{
	    TM("You fumble and become very disoriented.");
	    TH(fn + " is dazed.",
	      ({ fumbler }), 0);
	}
	else
	{
	    TM(
	      "You juggle with your weapon for a moment, and then it hits your forehead!");
	    TH(fn + " juggles with " +
	      HIS + " " + wn +
	      ", which then hits " + HIS +
	      " forehead!", ({ fumbler }), 0);
	}
	fumbler->set_condition(C_STUNNED, 1);
	return;
    case 6:
	/* Rare! */
	if (wn && random(100) < 17)
	{
	    /* Throw weapon into other room! */
	    TM(
	      "You lose your grip and throw your weapon as far away as possible! \
Wow, that fumble was so COSMIC!");
	    TH(fn + " loses " + HIS +
	      " grip and throws " + HIS + " weapon away!",
	      ({ fumbler }), 0);

	    if (weapon->drop())
	    {
		TM("Fortunately your weapon doesn't want to go away.");
		TH("Or, " + (string)fumbler->query_pronoun() +
		  " would if " + HIS + " weapon would let " + HIM + ".",
		  ({ fumbler }), 0);
		return;
	    }

	    ex = (string *)environment(fumbler)->query_dest_dir();
	    i = random(sizeof(ex) / 2) * 2;
	    r = find_object(ex[i]);
	    if (!r) call_other(ex[i], "???");
	    r = find_object(ex[i]);
	    if (!r) r = environment(fumbler);

	    fumbler->add_weight(-((int)weapon->query_weight()));
	    move_object(weapon, r);
	    if (r != environment(fumbler))
	    {
		r->tell_here(wn +
		  " suddenly flies into the room and lands on the floor!");
	    }

	    return;
	}
	TM("You swallow your tongue in the excitement. Gakk!");
	TH(fn + " swallows " + HIS + " your tongue in the excitement.",
	  ({ fumbler }), 0);
	fumbler->set_condition(C_STUNNED, 2);
	return;
    default:
	/* Rare: Stuck weapon - if sharp */
	if (wn && random(300) > 293)
	{
	    if (!weapon->is_blunt())
	    {
		TH(wn + " gets stuck into " + tn + "!",
		  ({ target }), 0);
		target->tell_me(wn + " gets stuck into you!");

		if (weapon->drop())
		{
		    TH("But it comes loose immediately.", ({ target }), 0);
		    return;
		}

		/* Just drop it. Can't actually glue it to living. */
		fumbler->add_weight(-((int)weapon->query_weight()));
		move_object(weapon, environment(fumbler));
		return;
	    }
	}
	TM("Yo! Fumble!");
	if (wn)
	    TH(fn + " fumbles with " +
	      HIS + " " +
	      wn + ".", ({ fumbler }), 0);
	else
	    TH(fn + " fumbles.",
	      ({ fumbler }), 0);
	return;
    }
}
