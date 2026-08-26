//God thank YOU CYANIDE and ILZARION
//for your code
#include <magic.h>
#include <mudlib.h>
#include <m_spells.h>

#define COST 20

int invoke_bodyblades() {
    object blade;

    seteuid(getuid());
    if (present("#BODYBLADES#", TP)) {
	write("You already have a Body Blades active.\n") ;
	return 0;
    }

    if (!TP->invoke_spell(COST)) {
	write(NOT_ENOUGH_SP);
	return 0;
    }
    write ("You begin invoking Body Blades.\n");

    blade = clone_object("/d/class/priest/obj/bodyblades_ob");
    if (!blade) {
	write("Your prayer fizzles.  Contact Ilzarion.\n");
	say(TPN+"'s prayer fizzles...\n");
	return 0;
    }

    blade->move(TP);
    blade->start_spell(TP);
    return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Body Blades (Priest - Level III - Combat)

Duration: 10 rounds/lvl			Area of Effect: Caster
Cost: 20 TP

	This spell causes blades to sprout from the caster's
body. It damages opponents in melee without hampering
the caster or his equipment.
EndSpellcraft
    );
}
