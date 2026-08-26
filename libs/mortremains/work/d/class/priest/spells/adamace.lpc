// By Ilzarion
// Repaird by Cyanide, 11 Jul 2000

#include <magic.h>
#include <p_spells.h>

#define COST 44

inherit SPELL;

string help();

int invoke_adamace (string str, int obj) {
    object shield;

    seteuid(getuid());

    if (!obj) {
	if (!invoke_spell(TP, COST)) return 0;

	obj = query_caster_level(TP, "priest");
	say(TPN+" begins mumbling a prayer.\n");
	write ("You begin casting Adamantium Mace.\n");
    }

    shield = clone_object(P_OBJ(adamace_ob.c));
    if (!shield) {
	write("Your spell fizzles.  Contact Cyanide.\n");
	say(TPN+"'s spell fizzles...\n");
	return 0;
    }

    shield->move(TP);
    shield->begin_spell(TP, obj);
    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Adamantium Mace (Priest - Level V - Summoning)

Duration: 1.5 Minutes / Level
Cost: 44 TP 

This spell creates a magical mace to smite the priest's enemies.

EndSpellcraft
    );
}
