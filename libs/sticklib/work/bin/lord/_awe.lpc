#include <lord.h>

#define	CHURCH_NAME	"room/church"

/*
	Lord command:	awe
	Syntax:		awe <player>
	Conditions:	
		User level 28-34 can awe non-lords.
		User level 35+ can awe lesser lords as well.
		User must be able to move.
		User must have required number of SP.
		Target must be a player.
		Target player must have wimpy on.
	Effects:
		Targeted player will wimpy.
	Notes:
		We can awe ourselves.
*/

int
awe_cmd(string str)
{
    object target;
    int tlevel, mlevel;
    string tname, mname;
    string tmp;

    if ((LL < LORD) && !(CODER))
	return 0;

    if (!str) return notify_fail("Usage: awe <player>\n"), 0;

    if (!(CAN_MOVE(TP))) {
	//		notify_fail(MOVE);
	// No need for this... query_can_move() sets notify_fail. -+ Doomdark +-
	return 0;
    }

    tmp = lower_case(str);

    if (!(target = present(tmp,environment(TP))))
	return notify_fail("Nope, I do not see a "+str+" here.\n"), 0;

    if (!living(target)) return notify_fail(
	  "You look all big and scary but it doesn't seem to affect the "+ tname
	  + " one little bit.\n"), 0;

    if (target->is_npc()) return notify_fail(
	  "Your not ugly enough to scare that monster.\n"), 0;

    if(target == TP) {
	TM("Allright, you look in the mirror for the first time in years!");
	target->run_away();
	return 1;
    }

    if (object_name(environment(target)) == CHURCH_NAME) {
	if(!((int)TP->query_coder_level())) {
	    notify_fail("You can't awe anyone here!\n");
	    return 0;
	}
    }

    mname  = (string)TP->query_name();
    mlevel = (int)TP->query_level();
    tlevel = (int)target->query_level();

    str = capitalize(str);

    /* We need to be at least level 34 to scare other lords */
    if( (LL < AWE_LORDS) && (tlevel > LORD) ) {
	if(!((int)TP->query_coder_level())) { 
	    return notify_fail("You cannot scare that person.\n"), 0;
	}
    }

    if( (tlevel >= mlevel) || target->query_coder_level() )
    {
	target->tell_me(capitalize((string)TP->query_real_name()) +
	  " tried to scare you!");
	return notify_fail(str+" is of too high a level.\n"), 0;
    }

    if (!target -> query_wimpy()) {
	if(!((int)TP->query_coder_level())) {
	    return notify_fail("You notice that "
	      + (string) target->Pronoun() + " is too brave to be scared.\n"), 0;
	}
    }
    if (!(CAN_MOVE(target))) return notify_fail(str+" is unable to move.\n"), 0;

    if (SP < CO_AWE) return notify_fail(SP_MES), 0;

    // Tell me.

    tname  = (string)target->query_name();

    TM(
      "You look at "+str+" in anger.\n"
      +capitalize(str)+" quivers in fear at the sight of you.\n"
      +capitalize(str)+" runs from you as fast as he can."
    );

    if (TP->query_invis()) {
	/* Tell him */
	target->tell_me(
	  "Suddenly a pair of red eyes appear before you.\n\
An incrediable wave of fear strikes you.\n\
You cannot help yourself, you *MUST* leave this place.");

	/* Tell everyone else */
	environment(target) -> tell_here(
	  "A pair of burrning red eyes suddenly appear before "+tname+".\n"
	  +tname+" flees from the room in a panic.\n", ({ target, TP }));
    } else {

	/* Tell him */
	target->tell_me(
	  mname+ " looks at you with burning eyes.\n\
Your heart begins to beat rapidly as fear flows through you.\n\
The fear grows and grows until it is too much for you to withstand!");

	/* Tell everyone else */
	environment(target) -> tell_here(mname+" looks at "+tname+
	  " with rage glowing in his eyes.\n"+tname+" trembles with fear and suddenly\
 flees from the room.",({ target,TP }));
    }

    target->run_away();

    if ((mlevel - tlevel) > 10)
	target->run_away();

    if(TP->query_coder_level()) {
	while(!(random(3))) target->run_away();
    }

    TP->add_sp(-CO_AWE);

    return 1;
}
