/*
** File: mordsword.c
** Purpose: mordenkainen's sword
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 80

string help();

inherit SPELL;

varargs int cast_mordsword (int obj) {
    object shield;

    seteuid(getuid());

    if (present("#MORDSWORD_SPELL#", TP)) {
	write("You already have a Mordenkainen's sword!\n");
	return 0;
    }

    if (!obj) {
	if (!cast_spell(TP, COST)) { 
	    write(NOT_ENOUGH_SP);
	    return 0;
	}

	write ("You begin casting Mordenkainen's sword.\n");
	say (TPN+" begins muttering arcane verses...\n");
	obj = query_caster_level(TP, "wizard");
    }

    shield = clone_object(M_OBJ(mordsword_ob.c));
    if (!shield) {
	write("Your spell fizzles.  Contact Cyanide.\n");
	say(TPN+"'s spell fizzles...\n");
	return 0;
    }

    write("Lvl: "+obj+"\n");
    shield->move(TP);
    shield->begin_spell(TP, obj);
    return 1;
}

string spellcraft() {
    return (@EndSpell
Mordenkainen's Sword (Level VII Wizard Spell - Evocation)

Cost: 80 Spell Points

Upon casting this spell, the wizard brings into being a 
shimmering, swordlike plane of force. The spellcaster is
able to wield this weapon as if it was a dagger.
EndSpell
    );
}

/* EOF */
