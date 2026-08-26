/*
**  File: kill.c (Power Word Blind)
**  Purpose: Level 9 mage conjuration spell.
**  Cost: 120 SP (9th lvl Conjuration)
*/

#define COST 120
#define SYNTAX "Syntax: cast kill at target\n"  
#define MAX_HP_AFFECTED 200

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

varargs int cast_kill (string str, int obj) {   
    object target;
    int rolled;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }   
    if (!check_valid_targ(TP, target)) return 0;
    if (!obj) {
	if (!TP->cast_spell(COST)) {
	    write(NOT_ENOUGH_SP);
	    return 0;
	}
	write("You invoke ancient magicks to slay "+target->query("cap_name")+".\n");
	say(TPN+" invokes ancient magicks to slay "+target->query("cap_name") + ".\n");
    }
    if ((int)target->query("hit_points") <= MAX_HP_AFFECTED) {
	tell_object(target, "You feel a great sennse of dread, and see no more.\n");
	tell_room(environment(TP), target->query("cap_name") + " is slain with a single word!\n", ({ target }) );

	target->set("last_attacker", TP);
	target->set("hit_points", -1);
    } else {
	tell_object(target, "You hear the word of death, but you resist it's call.\n");
	tell_room(environment(TP), target->query("cap_name") + " resists the call of the grave.\n", ({ target }));
    }

    target->kill_ob(TP);
    return 1;
}
string spellcraft() {
    return (@EndSpell
Power Word Kill (Level IX Wizard Spell - Conjuration)

Cost: 120 Spell Points

This spell kills a target. Resistance is determined
by the hit points of the target. Very high hit points
make one immune.
EndSpell
    );
}



