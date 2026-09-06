/* 
  STEAL SKILL -- Transferred from mark and cleaned 1/1/96  --Colt

  COMMENTS:  (add changes here)

   Autosteal from players too now. -Kel.

   Now there can be (extremely rare) monsters that cannot be stolen from,
   one of them is Adamantium/etc. Dragon in the Mines, because it has a
   quest item. 20.4.1994 //Frobozz  

*/
#include "../thief.h"
#include "../tune.h"

varargs int
steal(object owner, mixed str)
{
    string who, what, s;
    object *inv, ob, target, tm;
    int i, x, am, taxp, taxplus, wasvis, wild, success;
    int targ_lev;

    if (TP->is_fighting()) 
    {
	TM("Not now, you are fighting!");
	return 0;
    }

    target = 0;

    tm = (object) owner->query_guild_object();
    if (!str)
    {
	x = -1;
	inv = all_inventory(environment(owner));

	for (i = sizeof(inv) - 1; i >= 0; i--) 
	{
	    if (living(inv[i]) && inv[i]->query(LIV_IS_PLAYER_OR_NPC) 
	      && inv[i] != this_player())
		/* And, let's be sure it _is_ player or npc. -+ Doomdark +- */
	    {
		if (x != -1)
		{
		    TM("Huh?  There are many possible victims here...");
		    return 0;
		} 
		else 
		    x = i;
	    }
	}

	if (x == -1)
	{
	    TM("You can't see any suitable victims here.");
	    return 0;
	}

	target = inv[x];
	/* Autodetect invisible :-(... */

	if (!(s = (string) target->query_short(0, this_object())))
	    s = "the unseen monster";

	TPT(sprintf("(Gold from %s)", s));
	what = 0;
    }

    if (!target)
    {
	if (sscanf(str, "%s from %s", what, who) != 2)
	    target = present(lower_case(str), environment(TP));
	else
	    target = present(lower_case(who), environment(TP));
    }

    if (!target)
    {
	TM("There's no one called that here.");
	return 0;
    }

    /* double check  --colt */
    if (target->is_fighting())
    {
	notify_fail("You'd probably lose your head if u tried \
to steal while " + target->query_pronoun() + " is fighting!\n");
	return 0;
    }

    if (what == "money" || what == "gold" || what == "coins") 
	what = 0;

    if (!is_valid_target(target))
	return DELAY_STEAL;

    if (target->query_prevent_steal()
      || target->query_coder_level())
    {
	TPT(sprintf("You don't dare to steal from %s.",
	    (string) target->query_name()));
	return DELAY_STEAL;
    }

    if (((int) target->query_level() < _STEAL_MIN_LVL) &&
      ((int) owner->query_level() > _STEAL_SMALL_THIEF)
      && !target->is_npc())
    {
	TPT("But " + target->query_name() +
	  " is so little and weak. Find a better target.");
	return DELAY_STEAL;
    }

    if (((int) target->query_level() * 3 < (int) owner->query_level())
      && !target->is_npc())
    {
	TPT("But " + target->query_name() +
	  " is so little (less than third of your levels) compared to you! Find bigger victims!");
	return DELAY_STEAL;
    }

    /*
      if ((string)target->query_guild() == GN_HEALER)
	{
	  TPT("Due training cheats, you can't steal from healers at the moment.");
	  return DELAY_STEAL;
	}
    */

    if (target == owner)
    {
	TPT("Ok. You steal everything from yourself.");
	environment(owner)->tell_here(
	  owner->query_name() + " seems to be very confused.", ({ owner }), 0);
	return DELAY_STEAL;
    }

    if (!target->is_npc() && PEACE_D->query_peace())
    {
	TPT("Peace is upon the world, you can't steal from other players.");
	return DELAY_STEAL;
    }

    if (owner->query_sp() < _STEAL_SP)
    {
	TM("You do not have enough spell points.");
	return DELAY_STEAL;
    }

    owner->add_sp(-_STEAL_SP); /* No 1000000 tries for free! */

    targ_lev = target->query_level();

    if (_STEAL_SUCCESS)
    {
	success = random((int)tm->query_skills(SK_STEAL) / 100);
	success += (int)tm->stealth();
	success -= targ_lev * 2;

	/* It's hard to steal when you are all sweating and hot. //Graah */
	if (present("sauna_sweat", owner))
	{
	    owner->tell_me("Your hands are sweating...");
	    success -= _STEAL_SWEAT;
	}

	/* Trolls are BAD with this, yes. But not completely hopeless. */
	if (owner->query_race() == "troll") 
	    success -= _STEAL_TROLL;

	if (owner->query_invis())
	{
	    success += _STEAL_INVIS;
	    wasvis = 0;
	} 
	else 
	    wasvis = 1;
    }
    else
	success = 0;

    /* Paralyzed target: automatic and great success */
    if (!present("paralyzer",target) ||
      target->query_can_move())
	success -= random(100); /* The actual 100-sided dice rolling :-) */

    if (target->query_coder_level()) 
    {
	success = 0;
	tm->test_notice(ob,target);
	return DELAY_STEAL;
    }

    if (!what && success > 0 && !target->query_money())
    {
	TPT("You notice that " + target->query_name() + " has no gold.");
	return DELAY_STEAL;
    }

    if (what && !(ob = present(what,target)) && success > 0)
    {
	TPT("You can't seem to find any " + what + ".");
	return DELAY_STEAL;
    }

    if (!what && success > 0)
    {
	/* Try to guess how much we can steal... */
	am = (target->query_money() /20) * (2 + random(8 + ((int)tm->query_sk_steal() / 1500)));

	if (am > target->query_money())
	    am = target->query_money();

	TPT("Ok. You manage to steal " + am +
	  " gold pieces from " + target->query_name() + ".");

	if (am == 0)
	{
	    owner->tell_me("Quite Impressive!");
	    return DELAY_STEAL;
	}

	owner->add_money(am);
	target->add_money(-am);

	if ((int)tm->query_guildmaster() < TR_CO_GM)
	{
	    taxp = GUILD->query_tax(owner->query_level());

	    if (taxp > 0)
	    {
		taxplus = ((taxp * am) / 100);
		if (taxplus > 0)
		{
		    TPT(sprintf("With your tax of %d%%, your taxes increase by\
 %d gc.", taxp, taxplus));
		    tm->add_steal_tax(taxplus);
		}
	    }
	}
	// pkable if successful steal
	if(!target->is_npc())
	    owner->set(LIV_OK_TO_PK);

#ifdef LOG_STEAL
	if (!owner->is_npc() && !target->is_npc())
	    write_file("/guilds/thieves/STEAL_LOG",
	      ctime(time())[4..9] + ": " + am + " gp from " +
	      Realname(target) + " by " +
	      Realname(owner) + "\n");
#endif
	if (!owner->query_coder_level())
	    call_other(TOP_TEN,"check_top_damage",2,am,owner);

    }

    if (what && success > 10)
    {
	ob = present(lower_case(what), target);

	if (!ob)
	{
	    TPT("Strange, but you can't find that.");
	    return DELAY_STEAL;
	}

	if (ob->is_used())
	    wild = 1;
	else 
	    wild = 0;

	if (!wild)
	{
	    if (ob->drop(1) || ob->no_steal() || ob->query_prevent_steal()
	      || !ob->query_short(0, this_player()))
	    {
		TPT("You cannot steal that.");
		return DELAY_STEAL;
	    }
	}

	if (wild)
	{
	    /* Extremely mega-hyper rare */
	    if (random(100) > 12 ||
	      random(10000) > ((int)tm->query_sk_steal() /1000))
	    {
		TPT("You failed to steal a " +
		  (ob->query_wielded() ? "wielded" : "worn") +
		  " item!");
		success = 0;
		tm->test_notice(ob,target);
		return DELAY_STEAL;
	    } 
	    else 
	    {
		TPT("\n\nTOTALLY COSMIC! You stole a " +
		  (ob->query_wielded() ? "wielded" : "worn") +
		  " item!!!\n\n");
		if(!target->is_npc())
		    owner->set(LIV_OK_TO_PK);
		if (ob->drop(1)) 
		{
		    TPT("But you couldn't yank it from the victim!?!");
		    success = 0;
		    tm->test_notice(ob,target);
		    return DELAY_STEAL;
		}

		write_file("/players/thieves/COSMIC_STEAL",
		  (ctime(time()))[4..9] + ": " +
		  Realname(owner) + " got " +
		  ob->short() + " from " + Realname(target) + "\n");
	    }
	} 
	else
	    TM("Ok. You manage to steal " + ob->short() + "!");

	if (!owner->add_weight(ob->query_weight()))
	{
	    environment(TP)->tell_here("Fumbles with " + ob->short() + 
	      " which " + owner->query_pronoun() + " just stole from " +
	      target->query_name() + "!", owner);
	    move_object(ob, environment(target));
	    TM("Oops, that was too heavy. You drop it.");
	}
	else 
	    move_object(ob, owner);

	if ((int)tm->query_guildmaster() < TR_CO_GM)
	{
	    taxp = GUILD->query_tax(owner->query_level());
	    if (taxp > 0 && ((taxplus = ob->query_value()) >= 10))
	    {
		/* Maximum shop value */
		if (taxplus > 1000) 
		    taxplus = 1000;

		/* Default shop buy value */
		taxplus = ((2 * taxplus + 1) / 3);

		/* Divide item taxes by 2 - it's not certain that we
		   even get a change to sell it. */
		taxplus = ((taxp * taxplus) / 200);

		if (taxplus > 0) 
		{
		    TM("With your tax of " + taxp +
		      "%, your taxes increase by " +
		      taxplus + " gc.");
		    tm->add_steal_tax(taxplus);
		}
	    }
	}
	if(!target->is_npc())
	    owner->set(LIV_OK_TO_PK);

#ifdef LOG_STEAL
	if (!owner->is_npc() && !target->is_npc())
	    write_file("/guilds/thieves/STEAL_LOG",
	      (ctime(time()))[4..9] + ": " +
	      Realname(owner) + " got " +
	      ob->short() + " from " + Realname(target) + "\n");
#endif
    }

    if ((!what && success < 1) || (what && success < 11))
    {
	TM("Your attempt to steal failed.\n");

	/* You can't train steal with other thieves */
	if ((string) target -> query_guild() != GN_THIEF &&
	  (!wasvis || _STEAL_T_RND))
	{
	    if ((object)tm->query_last_steal() != target)
		tm->set_skill(SK_STEAL,tm->advance_skill((int)tm->query_skills(SK_STEAL),DIFF_STEAL));

	    /* Prevent too good cheat */
	    if (random(100) > 15)
		tm->set_last_steal(target);
	}
    }

    tm->test_notice(ob,target);
    return DELAY_STEAL;
}
