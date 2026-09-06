/*
 * Special weapon, can only be used successfully when sneaking or invisible.
 *
 * Thieve's backstab skill is used with this, although non-thieves could
 * perhaps strangle successfully too.
 *
 */
#include <treasure.h>
#include <conditions.h>
#include <macros.h>
#include <living_defs.h>
#include <room_defs.h>
#include <guild.h>
#include "dirs.h"

int strangle, lastused, break_change;
object sadist, target, *lastvictim;
string taker; /* Who took this one from wall */

query_thief_item() { return 1; }

set_taker(str) { taker = str; }
query_taker() { return taker; }

void create_treasure()
{
    set_name("garrotte");
    set_short("Garrotte");
    set_long(
      "This thing is basically a very tough, metal-reinforced piece of string. "+
      "It is used, with a suprise attack from behind, to strangle others. "+
      "Wield it for more information.");
    set_weight(1);
    set_value(0);  /* Can't be sold at all any more */

    sadist = target = lastused = 0;
    lastvictim = ({});
}

void init_treasure()
{
    add_action("strangle_cmd", "strangle");
    add_action("stop_cmd", "stop");
    add_action("wield", "wield");
}

wield(string str) 
{
    if (!id(str)) 
	return 0;

    if (environment() != this_player()) 
    {
	notify_fail("You must get it first!\n");
	return 0;
    }

    TP->tell_me(
      "This weapon isn't actually wielded. To use it, you must first have both \
hands free. Then you must surprise your enemy, which can only be done \
by going invisible or sneaking. Then \"strangle <name>\" to do the job.  \
If you wish to stop strangling someone, just \"stop strangling\".");
    return 1;
}

strangle_cmd(arg)
{
    object victim, inv;

    if (!TP->query_can_move())
    {
	notify_fail("You can't do that now!\n");
	return 0;
    }

    if (!arg) 
    {
	notify_fail("Strangle whom?\n");
	return 0;
    }

    victim = present(arg, environment(this_player()));

    if (!victim) 
    {
	notify_fail("You can't see any \"" + arg + "\" around here.\n");
	return 0;
    }

    if (!environment() || environment() != this_player()) 
    {
	notify_fail("What? With your bare hands?\n");
	return 0;
    }

    if (!living(victim)) 
    {
	notify_fail("Why strangle it? It isn't even alive.\n");
	return 0;
    }

    if (!victim->query(LIV_IS_PLAYER_OR_NPC))
    {
	notify_fail("Hmm, it seems that you can't reach its neck...\n");
	return 0;
    }
    if (victim == this_player()) 
    {
	notify_fail("You try to strangle yourself, but it doesn't work.\n");
	return 0;
    }

    if (!victim->attacked_by(this_player(), -1))
    {
	notify_fail("You can't do; probably due to PK-restrictions...\n");
	return 0;
    }

    if (this_player()->is_fighting())
    {
	notify_fail("You can't do that in the middle of a fight!\n");
	return 0;
    }

    if (this_player()->query_weapon()) 
    {
	notify_fail(
	  "Both hands must be free before you can use the garrotte.\n");
	return 0;
    }

    if (this_player()->is_wearing("shield")) {
	notify_fail("Your shield is on the way. Remove it first.\n");
	return 0;
    }

    /* Boo. It should just miss every time when done too quickly.
       But since we are so nice, we tell it... */
    if (lastused > time()) 
    {
	notify_fail("Relax! You can't try this if you are in a hurry.\n");
	return 0;
    }

    lastused = (time() + 3);

    if (this_player()->query_sp() < 30)
    {
	notify_fail("You feel too stressed to do this now. Rest a bit first.\n");
	return 0;
    }

    if (member(lastvictim, victim) != -1)
    {
	notify_fail(victim->query_name() +
	  " is aware of you sneaking around with the garrotte.\n");
	return 0;
    }

    lastvictim += ({ victim });

    if (sizeof(lastvictim) > 2)
	lastvictim -= ({ lastvictim[0] });

    this_player()->add_sp(-30);

    if (victim->is_fighting(this_player()))
    {
	notify_fail("But " + victim->query_name() + " is fighting you!\n");
	return 0;
    }

    TP->tell_me("Ok. You approach " + victim->query_name() + 
      " from behind...");
    call_out("weapon_hit", 1, victim);

    return 1;
}

weapon_hit(ob)
{
    object t;
    int adj, fail;

    if (!environment() || !living(environment()) ||
      environment()->query_dead() || !environment()->query_can_move())
	return;

    if (environment()->is_fighting())
	return;

    if ((string)environment()->query_guild() == GN_THIEF)
	t = (object) environment()->query_guild_object();

    adj = 2 + (environment()->query_level() / 3);

    if (adj > 16)
	adj = 16;

    if (t) 
	adj += ((t)->query_skills(0) / 340);
    else 
	adj = (environment()->query_level());

    adj += environment()->query_stat(ST_DEX) / 5;
    if (ob) 
	adj -= ob -> query_level();
    /* Previous line was causing errors in lpmud.log; not sure if this fixes it.-DD */

    if (random(100) < 6) 
	adj -= 100;

    if (t) 
	break_change = (33 - ((t)->query_skills(0) / 600));
    else 
	break_change = 45;

    fail = 0;

    /* Be careful not to allow cheating */
    if (!environment()->query_invis() || ob->query_attack() == environment())
	fail = 1;

    if (adj <= 0 && !fail) 
    {
	fail = 1;
	if (t && ob->query_npc()) 
	    t->add_stab_skill();
    }

    if (fail) 
    {
	environment()->tell_me(sprintf("%-=78s\n","You try to strangle " +
	    ob->query_name() + ", but he notices your attempt and dodges."));
	ob->tell_me(sprintf("%-=78s\n", "You notice that " +
	    environment()->query_name() + " tried to strangle you from behind "+
	    "with a garrotte! You barely manage to dodge the attempt."));
	environment(ob)->tell_here(sprintf("%-=78s\n",
	    environment()->query_name() + " tries to strangle " +
	    ob->query_name() + " from behind with a garrotte, but " +
	    ob->query_pronoun() + " manages to dodge."),
	  ({ environment(), ob }));
	ob->attack_object(environment());
	return 0;
    }
    environment()->set(LIV_OK_TO_PK);

    environment()->tell_me(sprintf("%-=78s\n",
	"You slip the garrotte around throat of the poor " +
	ob->query_name() + ", and start tightening it!"));
    ob->tell_me(sprintf("%-=78s\n", environment()->query_name() +
	" has placed a garrotte around your neck, from behind, and "+
	"starts to tighten it! You can't breathe!!!"));
    environment(ob)->tell_here(sprintf("%-=78s\n",
	environment()->query_name() + " has placed a garrotte around the "+
	"neck of the poor " + ob->query_name() +
	" and starts to tighten it!"), ({ environment(), ob }));
    environment()->stop_fight(ob);
    //++Tron ob->stop_fight(environment());
    ob->set_condition(C_STUNNED, 3 + random(7) + random(6));
    strangle = 0; 
    sadist = environment(); 
    target = ob;
    call_out("strangle", 1);
}

strangle()
{
    if (!sadist) 
    {
	if (target) 
	{
	    target->tell_me("Aaah...you can breathe again!");
	    target->set_condition(C_STUNNED, 0);
	}
	target = 0; 
	return;
    }

    if(target->query_ghost()) {
	sadist->tell_me("You unwrap the garrotte from around the carcass' neck.");
	sadist = target = 0;
    }
    if (!target || (environment(target) != environment(sadist))) 
    {
	if (sadist) 
	    sadist->tell_me("Your victim has escaped.");
	if (target) 
	{
	    target->tell_me("Aaah...you can breathe again!");
	    target->set_condition(C_STUNNED, 0);
	}
	sadist = target = 0; 
	return;
    }

    if (!sadist->query_can_move())
    {
	if (target) 
	{
	    target->tell_me("Aaah...you can breathe again!");
	    target->set_condition(C_STUNNED, 0);
	}
	sadist = target = 0; 
	return;
    }

    //if (target->query_attack() == sadist) 
    //target->stop_fight(sadist);

    if (sadist->query_attack() == target) 
	sadist->stop_fight(target);

    if (sadist->query_attack() || sadist->query_alt_attack()) 
    {
	target->tell_me(sadist->query_name() +
	  " was attacked and stops strangling you.");
	sadist->tell_me("You can't strangle " + target->query_name() +
	  " and fight at the same time.");
	target->tell_me("Aaah...you can breathe again!");
	target->set_condition(C_STUNNED, 0);
	target = sadist = 0; 
	return;
    }

    if (sadist->query_weapon()) 
    {
	sadist->tell_me("You let go of the garrotte when you \
wield the weapon.");
	target->tell_me("Aaah...you can breathe again!");
	target->set_condition(C_STUNNED, 0);
	target = sadist = 0; 
	return;
    }

    /* Monsters and players may break it. */
    if (target->query_npc()) 
    {
	if (target->query_level() > (random(30) + random(26)) &&
	  random(100) < break_change) 
	{
	    target->tell_me("You manage to free yourself from strangle!");
	    environment(sadist)->tell_here(target->query_name() +
	      " manages to free " + target->query_objective() +
	      "self from strangle!\n", ({ target }));
	    target->tell_me("Aaah...you can breathe again!");
	    target->set_condition(C_STUNNED, 0);
	    target->attack_object(sadist);
	    target = sadist = 0; 
	    return;
	}
    }
    strangle++;
    target->tell_me(sadist->query_name() + " is strangling you!");
    sadist->tell_me( ({
	"You twist the garrotte tighter and tighter...",
	"You laugh evilly and twist the garrotte tighter and tighter...",
	"You tighten the garrotte as hard as you could..."})[random(3)]);
    environment(target)->tell_here(sadist->query_name() + " is strangling " +
      target->query_name() + "!", ({ sadist, target }));

    if (target->query(LIV_NOT_UNDEAD)) 
    {
	if (strangle == 5)
	{
	    target->tell_me("Your face turns blue!");
	    sadist->tell_me(target->query_name() + "'s face turns blue!");
	} 
	else 
	if (strangle == 9)
	{
	    target->tell_me("You piss and shit uncontrollably!");
	    sadist->tell_me(target->query_name() +
	      " pisses and shits uncontrollably. Yuk.");
	    environment(target)->tell_here(target->query_name() +
	      " pisses and shits uncontrollably.\n", ({ sadist, target }));
	} 
	else 
	if (strangle == 12)
	{
	    target->tell_me("Some blood vessels in your eyes rupture!");
	    sadist->tell_me(target->query_name() +
	      "'s eyes are filled with blood!");
	    environment(target)->tell_here(target->query_name() +
	      "'s eyes are filled with blood!", ({ sadist, target }));
	} 
	else 
	if (strangle == 15)
	{
	    target->tell_me("Your face turns black!");
	    sadist->tell_me(target->query_name() + 
	      "'s face turns black!");
	    environment(target)->tell_here(target->query_name() +
	      "'s face turns black!", ({ sadist, target }));
	} 
	else 
	if (strangle >= 19)
	{
	    target->tell_me("You suffocate!");
	    sadist->tell_me(target->query_name() + " suffocates!");
	    environment(target)->tell_here(target->query_name() +
	      " suffocates!", ({ sadist, target }));
	    sadist->add_alignment(-(target->query_level()/2));
	    target->hit_player(300);
	    sadist = target = 0;
	    return;
	}

	/* Do damage, ignore victim's ac */
	target->add_hp(-((strangle * 2) + random(4) + random(8) + 12),1);

    } 
    else 
    {
	/* Undead target */
	sadist->tell_me(target->query_name() + " doesn't seem to choke!");
	environment(target)->tell_here(sadist->query_name() +
	  " strangles " + target->query_name() + ", but without effect.",
	  ({ sadist, target }));
    }
    call_out("strangle", 1);
}

stop_cmd(arg)
{
    if (!arg || lower_case(arg)[0..5] == "strang") 
    {
	if (!target || !sadist) 
	{
	    notify_fail("Stop what did you say?\n");
	    return 0;
	}

	this_player()->tell_me("Ok, you stop strangling " + 
	  target->query_name() + ".");
	target->tell_me("You are freed from the strangle.");
	target->set_condition(C_STUNNED, 0);
	sadist = target = 0;
	return 1;
    }
    return 0;
}
