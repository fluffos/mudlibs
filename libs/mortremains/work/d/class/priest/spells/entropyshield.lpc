//ilz
// Cyanide touched up - 14 July 2000

#include <magic.h>
#include <p_spells.h>

#define COST 60

string help();

inherit SPELL;

int invoke_entropyshield () {
    object shield;

    seteuid(getuid());

    if (present("#ENTROPY_SHIELD#", TP)){
	write("You already have an entropy shield active!\n");
	return 0;
    }

    if (!invoke_spell(TP, COST)) return 0;

    write ("You begin casting entropy shield.\n");

    shield = clone_object(P_OBJ(entropy_shield_ob));
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
    return (@EndSpellcraft
Entropy Shield (Priest - Level VI - Chaos)

Duration: 30 sec/lvl 		Area of Effect: Caster
Cost: 60 TP

	One of the most powerful defensive spells known, Entropy 
Shield confers a random chance to avoid any form of attack. The chance
of this occuring is based upon the level of the priest.
EndSpellcraft
    );
}
