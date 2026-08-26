/*
** FILE:        enlarge.c
** PURPOSE:     2st level alteration spell.
** COST:        12 SP
** EFFECTS:     Increases subject's strength by an abount from 1-4 to
**              1-6, depending on level (max 18)
** DURATION:    1 minute/level.
** CREDITS: 
**    29 Sep 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 12

int cast_strength (string str, int obj) {
    object targ, ob;
    int lvl = 0;

    seteuid(getuid());

    if (!str) str = TP->query("name");

    targ = present(str, environment(TP));
    if (!targ) {
	write("That isn't here!\n");
	return 1;
    }

    if (!living(targ)) {
	write("That spell works better when cast on something living.\n");
	return 0;
    }

    if ((environment(TP)->local_spell_effects(({"abjuration"})))==-1)
	return 1;

    if (present("#STRENGTH_OB#", targ)) {
	write("That target has already been magically strengthened.\n");
	return 0;
    }

    if (!obj) {
	if (!TP->cast_spell(COST)) { 
	    write(NOT_ENOUGH_SP);
	    return 0;
	}
	lvl = this_player()->query_level("wizard");

	write("You cast Strength at ");
	say (TPN+" casts Strength at ");
	if (targ == TP) {
	    write("yourself.\n");
	    say(objective(TP->query("gender"))+"self.\n");
	} else {
	    write(targ->query("cap_name")+".\n");
	    say(targ->query("cap_name")+".\n", targ);
	    tell_object(targ, "you.\n");
	}
    } else {
	lvl = obj;
    }

    ob = clone_object(M_OBJ(strength_ob));
    if (!ob) {
	write("Your spell fails.  Notify Cyanide.\n");
	return 0;
    }

    ob->move(targ);
    ob->begin_spell(targ);
    return 1;
}
string spellcraft() {
    return (@EndSpell
Strength (Level II Wizard Spell - Alteration)

Cost: 12 Spell Points

This spell increases the strength of the target
for a time.
EndSpell
    );
}

/* EOF */
