/*
** File: stoneskin.c
** Purpose: 4th level mage alteration spell.
** Cost 30 spell points
** Credits:
**  27 Sep 97  Cyanide wrote the file.
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 30

inherit SPELL;

int cast_stoneskin (string str, int obj) {
    object skin;
    int lvl;

    seteuid(getuid());

    if (present("#STONESKIN#", TP)) {
	write("You already have a stoneskin active!\n");
	return 0;
    }

    if (!obj) {
	if (!cast_spell(TP, COST)) {
	    write(NOT_ENOUGH_SP);
	    return 0;
	}

	/*
	    if (!TP->debit(1000)) {
	      write("You do not have the resources to cast that!\n");
	      return 1;
	    }
	*/

	write ("You begin casting stoneskin upon yourself.\n");
	say(wrap(TPN+" begins muttering arcane verses and "+
	    "sprinkling diamond dust upon "+
	    objective(TP->query("gender"))+"self."));
	lvl = TP->query_level("wizard");
    } else
	lvl = obj;

    skin = clone_object(M_OBJ(stoneskin_ob.c));
    if (!skin) {
	write("Your spell fizzles.  Contact Cyanide.\n");
	say(TPN+"'s spell fizzles...\n");
	return 0;
    }

    skin->move(TP);
    skin->begin_spell(TP, lvl);
    return 1;
}
string spellcraft() {
    return (@EndSpell
Stoneskin (Level IV Wizard Spell - Alteration)

Cost: 30 Spell Points

This spell turns the caster's skin into hardened stone, protecting
against many attacks. These attacks do no damage to the caster.
EndSpell
    );
}

/* EOF */
