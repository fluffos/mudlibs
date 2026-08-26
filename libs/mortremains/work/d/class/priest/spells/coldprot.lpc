//ilz

#include <magic.h>
#include <p_spells.h>
#include <mudlib.h>

#define COST 12

string help();

inherit SPELL;

int invoke_coldprot () {
    object shield;

    seteuid(getuid());

    if (present("#PROT_COLD#", TP)) {
	write("You are already protected from cold.\n");
	return 0;
    }

    if (!invoke_spell(TP, COST)) return 0;

    write ("You begin casting protection from cold.\n");

    shield = clone_object(P_OBJ(coldprotection_ob));
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
Protection from Cold (Priest - Level II - Protection)

Duration: 30 sec/lvl 		Area of Effect: Caster
Cost: 12 TP

	This spell partially protects the priest from damage
caused by attacks involving extreme cold.
EndSpellcraft
    );
}
