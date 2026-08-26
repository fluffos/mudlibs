/*
** File: mordsword.c
** Purpose: mordenkainen's sword
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 60

string help();

inherit SPELL;

int cast_transform () {
    object shield;

    seteuid(getuid());

    if (present("#TRANSFORM_SPELL#", TP)) {
	write("You are already transformed!\n");
	return 0;
    }

    if (!cast_spell(TP, COST)) {
	write(NOT_ENOUGH_SP);
	return 0;
    }

    write ("You begin casting Tenser's Transformation.\n");

    say ("Begins muttering arcane verses...\n");

    shield = clone_object(M_OBJ(transform_ob.c));
    if (!shield) {
	write("Your spell fizzles.  Contact Ilzarion.\n");
	say(TPN+"'s spell fizzles...\n");
	return 0;
    }

    shield->move(TP);
    shield->begin_spell(TP);
    return 1;
}

string spellcraft() {
    return (@EndSpell
Tenser's Transformation (Level VI Wizard Spell - Alteration, Evocation)

Cost: 60 Spell Points				Area of Effect: Caster
Duration: 20 sec/lvl

	Upon cating, the size and strength of the wizard increase 
to heroic proportions, so he becomes a formidable fighting machine;
the spell causes the caster to become a berserk fighter! 
Hit points double, and the wizard gins the thac0 of a warrior of
the same level. All this power comes with a price, however. The
mage may not cast spells while this spell is in effect, even if it's
duration is ended prematurely, the mage may not cast for the duration
the spell would have lasted.
EndSpell
    );
}

/* EOF */
