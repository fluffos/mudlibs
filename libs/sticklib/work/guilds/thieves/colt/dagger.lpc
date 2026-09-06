/****************************************************
*                                                   *
* object: Thief dagger                              *
* coder: Colt                                      *
* description: When thrown the dagger breaks in    *
*              two.  The two pieces are held       *
*              together by a rope which tangles    *
*              the victim up.                      *
***************************************************/


#include <treasure.h>
#include "/guilds/thieves/colt/defines.h"
#include <conditions.h>
#include <invis_levels.h>
#include <stats.h>
#include <guild.h>

/* Define LOG to keep logs */

#define LOG

/* formula for success against players.  Based on */
/* attacker level and tth skill vs target level,  */
/* dexterity                                    */

#define formula ((((int) tm->QTTH / 1000) + (int) TP->QLEV + random(20)) - ((int) target->QLEV + ((int) target->QDEX / 3)) > 0)

int active, PREV_STUN;
object target;

status check_suc();
status target_monster(object target, object tm);
status escape(object target);


create_treasure()
{
    set_name("oddly shaped dagger");
    set_short("An oddly shaped Dagger");
    set_long ("This appears to be a dagger.  It has an oddly \
shaped hilt.\nYou might try to 'throw <target>'.");
    set_id ("dagger");
    set_weight(2);
}
get ()
{
    return 1;
}
init_treasure()
{
    /* Only thieves can have one of these */

    if (TP != environment()) return;
    if (TP->query_guild() != GN_THIEF)
    {
	TP->tell_me("The Godly voice of Skert echos through your head: \
You'll have to join thieves if you want one of those.");
	if (!environment(TP)) return;
	environment(TP)->tell_here("The dagger suddenly, and \
mysteriously disappears!");
	destruct(TO);
	return;
    }
    add_action("throw_1", "throw");
}

status
throw_1(string arg)
{
    if (!arg)
    {
	notify_fail("Throw at what?\n");
	return 0;
    }

    target = present4(arg, environment(TP), TP, IL_SNEAKING);

    if (!target)
    {
	notify_fail("You can't see anything like that around here.\n");
	return 0;
    }

    if (target == TP)
    {
	notify_fail("You'd like to throw it at yourself wouldn't you?\n");
	return 0;
    }

    if (active == 1)
    {
	notify_fail("Duh, you just threw it!\n");
	return 0;
    }

    /* check if fight is going on, can't throw dagger if there is */
    if (TP->is_fighting())
    {
	notify_fail("You're too busy fighting to throw the dagger.\n");
	return 0;
    }

    TP->tell_me("You throw the dagger at " + target->QN);
    target->tell_me(TP->QN + " throws a dagger at you, something \
about it looks wierd.");
    environment(TP)->tell_here(TP->QN + " throws an odd shaped dagger at "
      + target->QN,({ TP, target }));
    call_out("check_suc",1);
    return 1;
}
status check_suc()
{
    object tm, oba;

    tm = (object) TP->query_guild_object();

    if (environment(target) != environment(TP))
    {
	TP->tell_me("Hmm, you seem to have lost your target.");
	return 1;
    }
    if (!target->query_npc())
    {
	if (formula)
	{

#ifdef LOG
	    write_file("/guilds/thieves/colt/SUCVSPLAYER", TP->QRN
	      + " successfully roped " + target->QRN + "\nAttacker "
	      + "level: " + TP->QLEV + " Attacker TTH: " + tm->QTTH
	      + "\nTarget level: " + target->QLEV + " Target Dex: "
	      + target->QDEX + "\n\n");
#endif

	    environment(TP)->tell_here("The hilt and blade separate, \
joined by a rope, which coils tightly around "
	      + target->QN, target);
	    target->tell_me("Uh oh, the hilt and blade have separated, \
joined by a rope, which i now tightly coiled around you!");
	    active = 1;
	    if ((string) target->QRN != "colttest")
		TP->attack_object(target);
	    PREV_STUN = (int) target->query_condition(C_STUNNED);
	    target->add_condition(C_FORCE_FLAG | C_STUNNED,5);
	    escape(target);
	}
	else 
	{
	    environment(TP)->tell_here("The hilt and blade split apart \
joined by a rope, which barely misses " + target->QN, target);

	    target->tell_me("The hilt and blade have split, joined by \
a rope, which you barely dodge!");
	    TP->attack_object(target);
	    destruct(TO);
	}
    }
    else
    {
	target_monster(target, tm);
    }
    return 1;
}

status target_monster(object target, object tm)
{
    int time1, time2, time_stun;
    environment(TP)->tell_here("The hilt and blade of the dagger split \
apart, joined by a rope which coils around " + target->QN);

    TP->attack_object(target);
    time1 = (((int) tm->QTTH / 1000) + (int) TP->QLEV);
    time2 = (int) target->QLEV + random(10);
    if (time1 > time2)
    {
	if ((time1 - time2) > 7)
	{
	    time_stun = 7;
	}
	else
	{
	    time_stun = (time1 - time2);
	}
	target->set_condition(C_STUNNED, time_stun);

#ifdef LOG
	write_file("/guilds/thieves/colt/NPCSTUNTIME", TP->QN +" stunned " + target->QN
	  +" for " + time_stun + " secs.\n Attacker level: " 
	  + TP->QLEV + " Attacker TTH: " + tm->QTTH +" Monster level: "
	  + target->QLEV + "\n\n");
#endif

    }
    else
    {
	TP->tell_me(target->QN + " immediately escapes your puny rope!");
	environment(TP)->tell_here(target->QN + " escapes from the puny \
rope!", TP);
    }
    destruct(TO);
    return 1;
}
status escape(object target)
{
    // Added by Doomdark 14-jan-96. Let's hope this works.
    if (!target) {
	destruct(this_object());
	return 1;
    }
    if ((int) target->query_condition(C_STUNNED) <= 5)
    {
	if ((int) target->query_condition(C_STUNNED) > 0)
	{
	    target->tell_me("You twist and turn trying to escape!");
	    environment(target)->tell_here(target->QN + " twists and turns \
trying to escape!", target);
	    if (((int) target->QSTR + random(20)) > 45)
	    {
		target->tell_me("You manage to snap the rope and escape!");
		environment(target)->tell_here(target->QN + " snaps the rope \
and escapes!", target);
		target->set_condition(C_STUNNED, 0);
#ifdef LOG
		write_file("/guilds/thieves/colt/SUCESCAPE", target->QN +
		  " successfully escaped.  Target str: " + target->QSTR + "\n\n");
#endif
		destruct(TO);
	    }
	    else
	    {
		call_out("escape",1,target);
	    }
	}
	else
	{
	    target->tell_me("You manage to escape the rope!");
	    environment(target)->tell_here(target->QN + " manages to escape \
the rope!", target);
	    destruct(TO);
	}
    }
    else
	call_out("escape",PREV_STUN, target);
    return 1;
}

