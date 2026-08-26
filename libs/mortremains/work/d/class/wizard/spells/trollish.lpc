/*
** File:trollz
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 60

inherit SPELL;

string help();

int cast_trollish () {
    object shield;

    seteuid(getuid());

    if (present("#TROLLISH_SPELL#", TP)) {
	write("You already have a Trollish Fortitutde spell active!\n");
	return 0;
    }

    if (!cast_spell(TP, COST)) {
	write(NOT_ENOUGH_SP);
	return 0;
    }

    write ("You begin casting Trollish Fortitude.\n");
    say ("begins muttering arcane verses...\n");

    shield = clone_object(M_OBJ(trollish_ob.c));
    if (!shield) {
	write("Your spell fizzles.  Contact Cyanide.\n");   
	say(TPN+"'s spell fizzles...\n");
	return 0;
    }

    shield->move(TP);
    shield->begin_spell(TP);
    return 1;
}

string spellcraft() {
    return (@EndSpell
Trollish Fortitude (Level VI Wizard Spell - Alteration, Necromancy)

Cost: 60 Spell Points				Area of Effect: Caster
Duration: 20 sec/lvl

This powerful spell imbues the caster with the physical fortitude
and resilience of a troll. While the spell is in effect,
the caster regenerates.
EndSpell
    );
}

/* EOF */
