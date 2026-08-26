/*
** FILE:        globe.c
** PURPOSE:     6st level abjuration spell.
** COST:        60 SP
** EFFECTS:     Blocks all spells of about 4th level and below.
** DURATION:    30 seconds/level.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell (minorglobe).
**    10 Oct 97  Cyanide changed a little to make it into "globe."
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 20

inherit SPELL;

int cast_haste(string str, int obj) {
    object ob;

    seteuid(getuid());

    if ((environment(TP)->local_spell_effects(({"alteration"})))==-1)
	return 1;

    if (present("#HASTE#", TP)) {
	write("You are already hasted!\n");
	return 0;
    }

    if (!obj) {
	if (!TP->cast_spell(COST)) { 
	    write(NOT_ENOUGH_SP);
	    return 0;
	}

	write("You attempt to cast Haste\n");
	say(TPN+" mumbles something in an arcane language.\n");
	obj = query_caster_level(TP, "wizard");
    }

    ob = clone_object(M_OBJ(haste_ob));
    if (!ob) {
	write("Your spell fails.  Notify Cyanide.\n");
	return 0;
    }

    ob->move(TP);
    ob->begin_spell(TP, obj);
    return 1;
}
string spellcraft() {
    return (@EndSpell
Haste (Level III Wizard Spell - Alteration)

Cost: 20 Spell Points

The caster gains startling speed, doubling
his melee attacks for the duration of the spell.
EndSpell
    );
}

/* EOF */
