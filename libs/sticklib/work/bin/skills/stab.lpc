/*
 * Backstabbing skill
 *
 * Copyright (c) 1994 The Stickmud Project,
 * All rights reserved.
 *
 */
#include <cmd.h>
#include <conditions.h>
#include <daemons.h>
#include <room_defs.h>

// inherit "/lib/find_name";

nomask int
stab_cmd(string arg)
{
    object *inv, victim, weapon;
    int i, desc, success, damage, critical, sharp, skv;
    string how, hend;

    if (!CHECK) return 0;

    if (!TP->query_can_see())
    {
	TP->tell_me("You can't see well enough to stab anyone.");
	return 0;
    }

    if (TP->check_fight(1))
    {
	TP->tell_me("You can't, there is a fight going on in here!");
	return 0;
    }

    /* TODO: Prevent auto detection of invisible */

    /* No argument? Then try stabbing nearest opponent */
    if (!arg)
    {
	victim = 0;

	inv = all_inventory(environment(TP));

	for (i = sizeof(inv) - 1; i >= 0; i--)
	{
	    if (living(inv[i]) && inv[i]->query_npc())
	    {
		if (victim)
		{
		    TP->tell_me("Stab which one of them?");
		    return 0;
		}
		victim = inv[i];
	    }
	}

	if (!victim)
	{
	    TP->tell_me("You can't see any opponent to stab here.\n");
	    return 0;
	}

	if (victim->short())
	    TP->tell_me("(" + victim->short() + ")\n");
	else
	    TP->tell_me("(The unseen monster)\n");
    }
    else victim = present(lower_case(arg), environment(TP));

    if (!victim)
    {
	TP->tell_me("You cannot backstab THAT!");
	return 1;
    }

    if ((victim == TP))
    {
	TP->tell_me("You desperately try to stab yourself. How patethic.\n");
	return 1;
    }

    if (!COMBAT_D->is_valid_target(victim))
    {
	TP->tell_me("You can see no back to stab.");
	return 1;
    }

    if (!present(victim, environment(TP)))
    {
	TP->tell_me("You can't see any " + arg + " around here.");
	return 1;
    }

    if (!TP->query_npc() &&
      !victim->query_npc() &&
      environment(victim)->query(NO_PK))
    {
	TP->tell_me("Player killing is not allowed here.\n");
	return 1;
    }

    weapon = (object)TP->query_weapon();

    if (!weapon)
    {
	TP->tell_me("You cannot backstab with your bare hands.");
	return 1;
    }

    if (weapon->query_blunt())
    {
	how = "strike";
	sharp = 0;
    }
    else
    {
	how = "stab";
	sharp = 1;
    }

    /* Are we able to? */
    if (present("paralyzer",victim) ||
      !victim->query_can_move() ||
      TP->query_invis()) {

	/* Prevent cheating with stab... */
	if ((object)victim->query_attack() == TP ||
	  (object)victim->query_alt_attack() == TP)
	{
	    TP->tell_me("Yes, yes.\n");
	    return 1;
	}

	TP->kill((string)victim->query_real_name());

	skv = (int)TP->query_skill_value("backstab");
	damage = (int)TP->query_wc();

	if (random(100) > 4)
	{
	    success = (skv / 900) + random(99);
	    success -=
	    ((int)victim->query_level() / 2 + (int)victim->query_ac());
	} else success = 0;

	if (success > 0)
	{
	    TP->add_exp((int)victim->query_level());

	    damage = (damage + (skv / 3000) + sharp);

	    if ((random(100) < 39) &&
	      ((random(100) < 4) ||
		(skv >= (60000 + random(18000) + random(39000)))))
	    {
		if (random(1200) < 7)
		{
		    damage = damage * 3;
		    critical = 3;
		} else if (random(120) < 9)
		{
		    damage = damage * 2;
		    critical = 2;
		} else
		{
		    damage = ((damage * 150) / 100);
		    critical = 1;
		}
	    } else critical = 0;

	    desc = damage / 23;
	    if (desc > 9) desc = 9;

	    hend = ({ "just barely.", "weakly.", "!",
	      "quite hard!",
	      "hard!", "very hard!",
	      "extremely hard!", "devastatingly!",
	      "into small fragments!",
	      "into tiny bits of quivering flesh!" })[desc];

	    /* Blunt */
	    if (how == "strike")
	    {
		environment(TP)->tell_here("Someone smashes " +
		  (string)victim->query_name() +
		  " from behind " + hend + "\n", ({ TP, victim }), 0);
		TP->tell_me("You smash " + (string)victim->query_name() +
		  " from behind " + hend);
		victim->tell_me(
		  "Suddenly someone smashes you on the head from behind " +
		  hend + " OUCH!!!\n");

		/* Advance here */
	    }
	    else
	    {
		environment(TP)->tell_here("Someone stabs " +
		  (string)victim->query_name() +
		  " from behind " + hend + "\n", ({ TP, victim }), 0);
		TP->tell_me("You backstab " + (string)victim->query_name() +
		  " " + hend);
		victim->tell_me(
		  "You feel a terrible, SHARP pain in your back! "+
		  "It appears that someone has stabbed you " + hend);

		/* Advance here */
	    }

	    if (critical >= 3)
		TP->tell_me(
		  "Your weapon goes right through your opponent, spreading guts and \
blood everywhere! You have done a MIGHTY CRITICAL!");
	    else if (critical == 2)
		TP->tell_me("A CRITICAL HIT! Total massacre!");
	    else if (critical)
		TP->tell_me("Wow, that was a GREAT hit!");

	    if (((int)victim->query_level() < random(45)) &&
	      random(101) < (30 + critical * 5) &&
	      how == "strike")
	    {
		TP->tell_me((string)victim->query_name() +
		  " is stunned and confused!\n");
		victim->tell_me("You feel disoriented and stunned.\n");
		victim->set_condition(C_STUNNED, 2 + random(3));

		/* Hope this helps? */
		victim->stop_fight();
	    }

	    /* Players get less damage than monsters */
	    if (!victim->query_npc())
		damage = ((75 * damage) / 100);

	    if (TP->query_coder_level() ||
	      TP->query_testplayer())
		TP->tell_me("Damage: " + damage + "\n");

	    /* Instant kill with stab is now rare. */
	    /* Players are never slain with a stab. */
	    if (random(100) > (skv / 1300) || !victim->query_npc())
		if (damage > (int)victim->query_hp())
		    damage = ((int)victim->query_hp() - 1) +
		    ((int)victim->query_ac() / 2);

	    victim->hit_player(damage);

	    /* Died? */
	    if (!victim)
		return 1;

	}
	else
	{
	    switch(random(3))
	    {
	    case 0:
		TP->tell_me("You try to " + how + " " +
		  (string)victim->query_name() +
		  ", but " + (string)victim->query_pronoun() +
		  " moves and is just scratched.");
		if (how == "strike")
		    victim->tell_me("Something scratches your head.");
		else
		    victim->tell_me("Something scratches your back.");
		break;
	    case 1:
		TP->tell_me("You stumble and completely miss " +
		  (string)victim->query_name() + ".");
		environment(TP)->tell_here(
		  (string)TP->query_name() + " stumbles noisily.\n",
		  ({ TP }), 1);
		break;
	    default:
		TP->tell_me("You lose your concentration and miss the "+
		  "opportunity.\n");
		break;
	    }

	    /* But we learn from our mistakes. */

	    /* TODO: Advance here */
	}
    }
    else
    {
	TP->tell_me("Your victim was aware of you! You missed!\n");
	if ((object)victim->query_attack() != TP &&
	  (object)victim->query_alt_attack() != TP)
	    TP->set_attacker(victim);
    }

    if (!victim) return 1; /* We killed it already */

    /* The victim strikes back unless paralyzed or immobile */
    if (!victim->query_can_move())
    {
	victim->attack_object(TP);
    }

    return 1;
}
