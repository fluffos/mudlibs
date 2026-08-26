/*
** File: fireshield.c
** Credits:
**  21 Jul 97  Cyanide wrote the file.
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 30

string help();

inherit SPELL;

string *hot_cold = ({ "hot", "cold" });
int hc_int = 0;

int cast_fireshield (string hc) {
    object shield;

    seteuid(getuid());

    if (hc) {
	switch (hc) {
	case "hot" : hc_int = 0; break;
	case "cold" : hc_int = 1; break;
	default : write(help()); return 0;
	}
    }

    if (present("#FIRE_SHIELD#", TP)) {
	write("You already have a fire shield active!\n");
	return 0;
    }

    if (!cast_spell(TP, COST)) {
	write("You cannot muster the strength to cast that spell.\n");
	return 0;
    }

    write ("You begin casting the "+hot_cold[hc_int]+
      " version of fire shield.\n"); 
    say(TPN+" begins muttering arcane verses...\n"); 

    shield = clone_object(M_OBJ(fireshield_ob.c));
    if (!shield) {
	write("Your spell fizzles.  Contact Cyanide.\n");
	return 0;
    }

    shield->move(TP);
    shield->start_spell(TP, hc_int);
    return 1;
}

string spellcraft() {
    return (@EndSpell
Fire Shield (Level IV Wizard Spell - Evocation, Alteration)

Cost: 30 Spell Points

The caster can choose whether to cast a cold or hot version
of the shield. The shield confers resistance to the type of
damage selected. It also damages opponents that damage the
caster in hand to hand combat.
EndSpell
    );
}
